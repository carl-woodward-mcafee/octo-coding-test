#pragma once
#include <mutex>

template <class T>
class linkList
{
private:
    struct node
    {
        node(T *pItem) 
        { 
            mpItem = pItem;
            mpNext = nullptr;
        }

        T* mpItem;
        node* mpNext;
    };

    node* mpHead, *mpTail;
    std::mutex mutexList;

    node* createNode(T *pItem) 
    { 
        return new node(pItem);
    }

 public:
    linkList()
         : mpHead(nullptr)
         , mpTail(nullptr)
     {
     }

    void insert(T* pItem) 
    { 
        node* newNode = createNode(pItem);

        {
            const std::lock_guard<std::mutex> lock(mutexList);

            if (nullptr == mpHead)
                mpHead = newNode;

            if (nullptr == mpTail)
                mpTail = newNode;
            else
            {
                mpTail->mpNext = newNode;
                mpTail = newNode;
            }
        }

    }

    void clear() 
    {
        const std::lock_guard<std::mutex> lock(mutexList);
        node* begin = mpHead;

        while (nullptr != begin)
        {
            delete begin->mpItem;
            begin = begin->mpNext;
        }
    }

    T* removeFromTop() 
    { 
        const std::lock_guard<std::mutex> lock(mutexList);

        if (nullptr == mpHead)
            return nullptr;

        T* retVal = mpHead->mpItem;
        mpHead = mpHead->mpNext;
        return retVal;
    }



};