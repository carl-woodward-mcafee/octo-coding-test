# McAfee OCTO User Test
The goal of the executable is receive and process file system event notifications. For every notification, the application must open the file and get the file's attributes ready for the next stage of processing. However, the application must process the notification (not the file) as fast as is possible so the opening of the file must be done in another thread.

Candidates are expected to edit the function `notify_callback` in (main.cpp)[main.cpp]:
1. Design a linked list data structure and algorithms for storing information passed to the notification function for deferred processing. NOTE: you must implement your own linked list and may not use any libraries to help you.
1. Add the data in the `notify callback` to the linked list in a thread safe manner.
1. In a worker thread thread open the file from a previous notification and retrieve its attributes.
1. Release resources.

Candidates should spend no more than 2 hours on this test and can document functionality they didn't get time to complete in the source code as comments.

## Task Requirements
The submitted code need only compile and we will not be testing the code as part of this test.