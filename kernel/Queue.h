/*++

Module Name:

    queue.h

Abstract:

    This file contains the queue definitions.

Environment:

    Kernel-mode Driver Framework

--*/
#include <ntddk.h>
#include <wdf.h>

#define NTSTRSAFE_LIB
#include <ntstrsafe.h>
#include <wdmsec.h> // for SDDLs
#include "public.h" // contains IOCTL definitions
#include "Trace.h" // contains macros for WPP tracing
#include "ntdef.h"

EXTERN_C_START

//
// This is the context that can be placed per queue
// and would contain per queue information.
//

// https://www.osronline.com/article.cfm%5Earticle=499.htm
typedef struct _CUSTOM_LIST_ENTRY
{
    struct _LIST_ENTRY* Flink;
    struct _LIST_ENTRY* Blink;
} CUSTOM_LIST_ENTRY, *PCUSTOM_LIST_ENTRY;

typedef struct _QUEUE_CONTEXT {
    CUSTOM_LIST_ENTRY ListEntry;
    ULONG PrivateDeviceData;  // just a placeholder
} QUEUE_CONTEXT, *PQUEUE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(QUEUE_CONTEXT, QueueGetContext)

NTSTATUS
KmtQueueInitialize(
    _In_ WDFDEVICE Device
    );

//
// Events from the IoQueue object
//
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL KmtEvtIoDeviceControl;
EVT_WDF_IO_QUEUE_IO_STOP KmtEvtIoStop;

EXTERN_C_END
