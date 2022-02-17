/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID(
    GUID_DEVINTERFACE_Kmt,
    0x79241679,
    0x85eb,
    0x43e4,
    0x82,
    0xdb,
    0xb0,
    0x1f,
    0xf3,
    0x56,
    0x9c,
    0x74);
// {79241679-85eb-43e4-82db-b01ff3569c74}

// Structure that describes a file that you to track along with the trackining encryption key. NOTE
// - This structure is passed with NEITHER_IO.
typedef struct _TRACK_FILE
{
    ULONG Magic;                // Should be 0xBAADFOOD.
    USHORT Version;             // Only versions 1 and 2 are valid.
    UCHAR Key[32];              // Encryption key for later use.
    WCHAR PathBuffer[260];      // Buffer that contains the path to a file.
    PWSTR FilePath;             // Points to the full file path.
    PWSTR FileName;             // Points the file name.
    PWSTR DirectoryAndFileName; // Points to the directory + filename.
} TRACK_FILE, *PTRACK_FILE;
