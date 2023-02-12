//Built to UEFI 2.9 Specification
//Visit https://uefi.org/specifications for documentation

#ifndef UEFI_SYSTEM_TABLE
#define UEFI_SYSTEM_TABLE

typedef void *ImageHandle;

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                              DATA TYPES                               │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

// ╔═════════════════════════════════════╗
// ║                Types                ║
// ╚═════════════════════════════════════╝

#define BOOLEAN char
#define INTN long
#define UINTN unsigned long
#define INT8 char
#define UINT8 unsigned char
#define INT16 short
#define UINT16 unsigned short
#define INT32 int
#define UINT32 unsigned int
#define INT64 long
#define UINT64 unsigned long
#define CHAR8 char
#define CHAR16 unsigned short
#define VOID void
#define EFI_STATUS UINTN
#define EFI_HANDLE VOID*
#define EFI_EVENT VOID*
#define EFI_LBA UINT64
#define EFI_TPL UINTN

// ╔═════════════════════════════════════╗
// ║              Modifiers              ║
// ╚═════════════════════════════════════╝

#define IN
#define OUT
#define OPTIONAL
#define CONST
#define EFIAPI

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                              TABLE HEADER                             │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

typedef struct {
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                        SIMPLE TEXT INPUT PROTOCOL                     │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// ╔═════════════════════════════════════╗
// ║                Reset                ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_INPUT_RESET) (
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
    IN BOOLEAN ExtendedVerification
);

// ╔═════════════════════════════════════╗
// ║            ReadKeyStroke            ║
// ╚═════════════════════════════════════╝

//      Input Key
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    UINT16 ScanCode;
    CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_INPUT_READ_KEY) (
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
    OUT EFI_INPUT_KEY *Key
);

// ╔═════════════════════════════════════╗
// ║            SimpleTextInput          ║
// ╚═════════════════════════════════════╝

//        GUID
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID {0x387477c1,0x69c7,0x11d2,\{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

//      Structure
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_INPUT_RESET Reset;
    EFI_INPUT_READ_KEY ReadKeyStroke;
    EFI_EVENT WaitForKey;
};

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                        SIMPLE TEXT OUTPUT PROTOCOL                    │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// ╔═════════════════════════════════════╗
// ║                Reset                ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_TEXT_RESET) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN BOOLEAN ExtendedVerification
);

// ╔═════════════════════════════════════╗
// ║             OutputString            ║
// ╚═════════════════════════════════════╝

//  Drawing Characters
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define BOXDRAW_HORIZONTAL 0x2500
#define BOXDRAW_VERTICAL 0x2502
#define BOXDRAW_DOWN_RIGHT 0x250c
#define BOXDRAW_DOWN_LEFT 0x2510
#define BOXDRAW_UP_RIGHT 0x2514
#define BOXDRAW_UP_LEFT 0x2518
#define BOXDRAW_VERTICAL_RIGHT 0x251c
#define BOXDRAW_VERTICAL_LEFT 0x2524
#define BOXDRAW_DOWN_HORIZONTAL 0x252c
#define BOXDRAW_UP_HORIZONTAL 0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL 0x253c
#define BOXDRAW_DOUBLE_HORIZONTAL 0x2550
#define BOXDRAW_DOUBLE_VERTICAL 0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE 0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT 0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT 0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE 0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT 0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT 0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE 0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT 0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT 0x255a
#define BOXDRAW_UP_LEFT_DOUBLE 0x255b
#define BOXDRAW_UP_DOUBLE_LEFT 0x255c
#define BOXDRAW_DOUBLE_UP_LEFT 0x255d
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE 0x255e
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT 0x255f
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT 0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE 0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT 0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT 0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE 0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL 0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL 0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE 0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL 0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL 0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256a
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256b
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256c

//    Block Elements
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define BLOCKELEMENT_FULL_BLOCK 0x2588
#define BLOCKELEMENT_LIGHT_SHADE 0x2591

//    Block Elements
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼

//   Geometric Shapes
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define GEOMETRICSHAPE_UP_TRIANGLE 0x25b2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25ba
#define GEOMETRICSHAPE_DOWN_TRIANGLE 0x25bc
#define GEOMETRICSHAPE_LEFT_TRIANGLE 0x25c4

//     Arrow Shapes
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define ARROW_UP 0x2191
#define ARROW_DOWN 0x2193

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_TEXT_STRING) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN CHAR16 *String
);

// ╔═════════════════════════════════════╗
// ║              TestString             ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_TEXT_TEST_STRING) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN CHAR16 *String
);

// ╔═════════════════════════════════════╗
// ║              QueryMode              ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_TEXT_QUERY_MODE) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN ModeNumber,
    OUT UINTN *Columns,
    OUT UINTN *Rows
);

// ╔═════════════════════════════════════╗
// ║               SetMode               ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (* EFIAPI EFI_TEXT_SET_MODE) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN ModeNumber
);

// ╔═════════════════════════════════════╗
// ║             SetAttribute            ║
// ╚═════════════════════════════════════╝

//      Attributes
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x05
#define EFI_BROWN 0x06
#define EFI_LIGHTGRAY 0x07
#define EFI_BRIGHT 0x08
#define EFI_DARKGRAY (EFI_BLACK | EFI_BRIGHT) 0x08
#define EFI_LIGHTBLUE 0x09
#define EFI_LIGHTGREEN 0x0A
#define EFI_LIGHTCYAN 0x0B
#define EFI_LIGHTRED 0x0C
#define EFI_LIGHTMAGENTA 0x0D
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F
#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70

//        Macro
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_TEXT_ATTR(Foreground,Background) ((Foreground) | ((Background) << 4))

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_ATTRIBUTE) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN Attribute
);

// ╔═════════════════════════════════════╗
// ║             ClearScreen             ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_TEXT_CLEAR_SCREEN) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This
);

// ╔═════════════════════════════════════╗
// ║          SetCursorPosition          ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN Column,
    IN UINTN Row
);

// ╔═════════════════════════════════════╗
// ║             EnableCursor            ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_TEXT_ENABLE_CURSOR) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN BOOLEAN Visible
);

// ╔═════════════════════════════════════╗
// ║           SimpleTextOutput          ║
// ╚═════════════════════════════════════╝

//        GUID
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID {0x387477c2,0x69c7,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

//   Text Output Mode
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    INT32 MaxMode;
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumn;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

//      Structure
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
    EFI_TEXT_TEST_STRING TestString;
    EFI_TEXT_QUERY_MODE QueryMode;
    EFI_TEXT_SET_MODE SetMode;
    EFI_TEXT_SET_ATTRIBUTE SetAttribute;
    EFI_TEXT_CLEAR_SCREEN ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE *Mode; 
};

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                              BOOT SERVICES                            │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

typedef struct EFI_BOOT_SERVICES EFI_BOOT_SERVICES;

// ╔═════════════════════════════════════╗
// ║              RaiseTPL               ║
// ╚═════════════════════════════════════╝

// Task Priority Levels
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_TPL (EFIAPI *EFI_RAISE_TPL) (
    IN EFI_TPL NewTpl
);

// ╔═════════════════════════════════════╗
// ║             RestoreTPL              ║
// ╚═════════════════════════════════════╝

typedef VOID (EFIAPI *EFI_RESTORE_TPL) (
    IN EFI_TPL OldTpl
);

// ╔═════════════════════════════════════╗
// ║            AllocatePages            ║
// ╚═════════════════════════════════════╝

//     Allocate Type
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef enum {
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

//     Memory Type
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef enum {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

//   Physical Address
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef UINT64 EFI_PHYSICAL_ADDRESS;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_ALLOCATE_PAGES) (
    IN EFI_ALLOCATE_TYPE Type,
    IN EFI_MEMORY_TYPE MemoryType,
    IN UINTN Pages,
    IN OUT EFI_PHYSICAL_ADDRESS *Memory
);

// ╔═════════════════════════════════════╗
// ║              FreePages              ║
// ╚═════════════════════════════════════╝

// See AllocatePages for EFI_PHYSICAL_ADDRESS
typedef EFI_STATUS (EFIAPI *EFI_FREE_PAGES) (
    IN EFI_PHYSICAL_ADDRESS Memory,
    IN UINTN Pages
);

// ╔═════════════════════════════════════╗
// ║             GetMemoryMap            ║
// ╚═════════════════════════════════════╝

//   Virtual Address
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef UINT64 EFI_VIRTUAL_ADDRESS;

//   Memory Descriptor
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

//  Memory Attributes
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_MEMORY_UC 0x0000000000000001
#define EFI_MEMORY_WC 0x0000000000000002
#define EFI_MEMORY_WT 0x0000000000000004
#define EFI_MEMORY_WB 0x0000000000000008
#define EFI_MEMORY_UCE 0x0000000000000010
#define EFI_MEMORY_WP 0x0000000000001000
#define EFI_MEMORY_RP 0x0000000000002000
#define EFI_MEMORY_XP 0x0000000000004000
#define EFI_MEMORY_NV 0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 0x0000000000010000
#define EFI_MEMORY_RO 0x0000000000020000
#define EFI_MEMORY_SP 0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO 0x0000000000080000
#define EFI_MEMORY_RUNTIME 0x8000000000000000

//  Descriptor Version
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_MEMORY_DESCRIPTOR_VERSION 1

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_GET_MEMORY_MAP) (
    IN OUT UINTN *MemoryMapSize,
    OUT EFI_MEMORY_DESCRIPTOR *MemoryMap,
    OUT UINTN *MapKey,
    OUT UINTN *DescriptorSize,
    OUT UINT32 *DescriptorVersion
);

// ╔═════════════════════════════════════╗
// ║            AllocatePool             ║
// ╚═════════════════════════════════════╝

// See AllocatePages for EFI_MEMORY_TYPE
typedef EFI_STATUS (EFIAPI *EFI_ALLOCATE_POOL) (
    IN EFI_MEMORY_TYPE PoolType,
    IN UINTN Size,
    OUT VOID **Buffer
);

// ╔═════════════════════════════════════╗
// ║              FreePool               ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_FREE_POOL) (
    IN VOID *Buffer
);

// ╔═════════════════════════════════════╗
// ║             CreateEvent             ║
// ╚═════════════════════════════════════╝

//     Event Notify
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef VOID (EFIAPI *EFI_EVENT_NOTIFY) (
    IN EFI_EVENT Event,
    IN VOID *Context
);

//      Event Types
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EVT_TIMER 0x80000000
#define EVT_RUNTIME 0x40000000
#define EVT_NOTIFY_WAIT 0x00000100
#define EVT_NOTIFY_SIGNAL 0x00000200
#define EVT_SIGNAL_EXIT_BOOT_SERVICES 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT) (
    IN UINT32 Type,
    IN EFI_TPL NotifyTpl,
    IN EFI_EVENT_NOTIFY NotifyFunction, OPTIONAL
    IN VOID *NotifyContext, OPTIONAL
    OUT EFI_EVENT *Event
);

// ╔═════════════════════════════════════╗
// ║              SetTimer               ║
// ╚═════════════════════════════════════╝

//     Timer Delay
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef enum {
    TimerCancel,
    TimerPeriodic,
    TimerRelative
} EFI_TIMER_DELAY;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_SET_TIMER) (
    IN EFI_EVENT Event,
    IN EFI_TIMER_DELAY Type,
    IN UINT64 TriggerTime
);

// ╔═════════════════════════════════════╗
// ║            WaitForEvent             ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_WAIT_FOR_EVENT) (
    IN UINTN NumberOfEvents,
    IN EFI_EVENT *Event,
    OUT UINTN *Index
);

// ╔═════════════════════════════════════╗
// ║             SignalEvent             ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_SIGNAL_EVENT) (
    IN EFI_EVENT Event
);

// ╔═════════════════════════════════════╗
// ║             CloseEvent              ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_CLOSE_EVENT) (
    IN EFI_EVENT Event
);

// ╔═════════════════════════════════════╗
// ║             CheckEvent              ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_CHECK_EVENT) (
    IN EFI_EVENT Event
);

// ╔═════════════════════════════════════╗
// ║      InstallProtocolInterface       ║
// ╚═════════════════════════════════════╝

//    Interface Type
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef enum {
    EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

//      EFI Guid
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct EFI_GUID {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_GUID;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE) (
    IN OUT EFI_HANDLE *Handle,
    IN EFI_GUID *Protocol,
    IN EFI_INTERFACE_TYPE InterfaceType,
    IN VOID *Interface
);

// ╔═════════════════════════════════════╗
// ║      ReinstallProtocolInterface     ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    IN VOID *OldInterface,
    IN VOID *NewInterface
);

// ╔═════════════════════════════════════╗
// ║      UninstallProtocolInterface     ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    IN VOID *Interface
);

// ╔═════════════════════════════════════╗
// ║           HandleProtocol            ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_HANDLE_PROTOCOL) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    OUT VOID **Interface
);

// ╔═════════════════════════════════════╗
// ║       RegisterProtocolNotify        ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY) (
    IN EFI_GUID *Protocol,
    IN EFI_EVENT Event,
    OUT VOID **Registration
);

// ╔═════════════════════════════════════╗
// ║            LocateHandle             ║
// ╚═════════════════════════════════════╝

//     Search Type
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef enum {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_LOCATE_HANDLE) (
    IN EFI_LOCATE_SEARCH_TYPE SearchType,
    IN EFI_GUID *Protocol OPTIONAL,
    IN VOID *SearchKey OPTIONAL,
    IN OUT UINTN *BufferSize,
    OUT EFI_HANDLE *Buffer
);

// ╔═════════════════════════════════════╗
// ║          LocateDevicePath           ║
// ╚═════════════════════════════════════╝

// Device Path Protocol
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_DEVICE_PATH_PROTOCOL_GUID {0x09576e91,0x6d3f,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _EFI_DEVICE_PATH_PROTOCOL {
    UINT8 Type;
    UINT8 SubType;
    UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_LOCATE_DEVICE_PATH) (
    IN EFI_GUID *Protocol,
    IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePath,
    OUT EFI_HANDLE *Device
);

// ╔═════════════════════════════════════╗
// ║      InstallConfigurationTable      ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE) (
    IN EFI_GUID *Guid,
    IN VOID *Table
);

// ╔═════════════════════════════════════╗
// ║             LoadImage               ║
// ╚═════════════════════════════════════╝

//See LocateDevicePath for EFI_DEVICE_PATH_PROTOCOL
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_LOAD) (
    IN BOOLEAN BootPolicy,
    IN EFI_HANDLE ParentImageHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *DevicePath,
    IN VOID *SourceBuffer OPTIONAL,
    IN UINTN SourceSize,
    OUT EFI_HANDLE *ImageHandle
);

// ╔═════════════════════════════════════╗
// ║             StartImage              ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_IMAGE_START) (
    IN EFI_HANDLE ImageHandle,
    OUT UINTN *ExitDataSize,
    OUT CHAR16 **ExitData OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║                Exit                 ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_EXIT) (
    IN EFI_HANDLE ImageHandle,
    IN EFI_STATUS ExitStatus,
    IN UINTN ExitDataSize,
    IN CHAR16 *ExitData OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║             UnloadImage             ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_IMAGE_UNLOAD) (
    IN EFI_HANDLE ImageHandle
);

// ╔═════════════════════════════════════╗
// ║           ExitBootServices          ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_EXIT_BOOT_SERVICES) (
    IN EFI_HANDLE ImageHandle,
    IN UINTN MapKey
);

// ╔═════════════════════════════════════╗
// ║        GetNextMonotonicCount        ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT) (
    OUT UINT64 *Count
);

// ╔═════════════════════════════════════╗
// ║                Stall                ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_STALL) (
    IN UINTN Microseconds
);

// ╔═════════════════════════════════════╗
// ║           SetWatchdogTimer          ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_SET_WATCHDOG_TIMER) (
    IN UINTN Timeout,
    IN UINT64 WatchdogCode,
    IN UINTN DataSize,
    IN CHAR16 *WatchdogData OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║          ConnectController          ║
// ╚═════════════════════════════════════╝

//See LocateDevicePath for EFI_DEVICE_PATH_PROTOCOL
typedef EFI_STATUS (EFIAPI *EFI_CONNECT_CONTROLLER) (
    IN EFI_HANDLE ControllerHandle,
    IN EFI_HANDLE *DriverImageHandle OPTIONAL,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL,
    IN BOOLEAN Recursive
);

// ╔═════════════════════════════════════╗
// ║        DisconnectController         ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_DISCONNECT_CONTROLLER) (
    IN EFI_HANDLE ControllerHandle,
    IN EFI_HANDLE DriverImageHandle OPTIONAL,
    IN EFI_HANDLE ChildHandle OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║            OpenProtocol             ║
// ╚═════════════════════════════════════╝

//      Attributes
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL 0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL 0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL 0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER 0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE 0x00000020

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_OPEN_PROTOCOL) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    OUT VOID **Interface OPTIONAL,
    IN EFI_HANDLE AgentHandle,
    IN EFI_HANDLE ControllerHandle,
    IN UINT32 Attributes
);

// ╔═════════════════════════════════════╗
// ║            CloseProtocol            ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_CLOSE_PROTOCOL) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    IN EFI_HANDLE AgentHandle,
    IN EFI_HANDLE ControllerHandle
);

// ╔═════════════════════════════════════╗
// ║       OpenProtocolInformation       ║
// ╚═════════════════════════════════════╝

//     Entry Buffer
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID *Protocol,
    OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
    OUT UINTN *EntryCount
);

// ╔═════════════════════════════════════╗
// ║         ProtocolsPerHandle          ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_PROTOCOLS_PER_HANDLE) (
    IN EFI_HANDLE Handle,
    OUT EFI_GUID ***ProtocolBuffer,
    OUT UINTN *ProtocolBufferCount
);

// ╔═════════════════════════════════════╗
// ║         LocateHandleBuffer          ║
// ╚═════════════════════════════════════╝

// See LocateHandle for EFI_LOCATE_SEARCH_TYPE
// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_LOCATE_HANDLE_BUFFER) (
    IN EFI_LOCATE_SEARCH_TYPE SearchType,
    IN EFI_GUID *Protocol OPTIONAL,
    IN VOID *SearchKey OPTIONAL,
    OUT UINTN *NoHandles,
    OUT EFI_HANDLE **Buffer
);

// ╔═════════════════════════════════════╗
// ║           LocateProtocol            ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_LOCATE_PROTOCOL) (
    IN EFI_GUID *Protocol,
    IN VOID *Registration OPTIONAL,
    OUT VOID **Interface
);

// ╔═════════════════════════════════════╗
// ║  InstallMultipleProtocolInterfaces  ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
    IN OUT EFI_HANDLE *Handle,
    ...
);

// ╔═════════════════════════════════════╗
// ║ UninstallMultipleProtocolInterfaces ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
 IN EFI_HANDLE Handle,
 ...
);

// ╔═════════════════════════════════════╗
// ║          CalculateCrc32             ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_CALCULATE_CRC32) (
    IN VOID *Data,
    IN UINTN DataSize,
    OUT UINT32 *Crc32
);

// ╔═════════════════════════════════════╗
// ║              CopyMem                ║
// ╚═════════════════════════════════════╝

typedef VOID (EFIAPI *EFI_COPY_MEM) (
    IN VOID *Destination,
    IN VOID *Source,
    IN UINTN Length
);

// ╔═════════════════════════════════════╗
// ║               SetMem                ║
// ╚═════════════════════════════════════╝

typedef VOID (EFIAPI *EFI_SET_MEM) (
    IN VOID *Buffer,
    IN UINTN Size,
    IN UINT8 Value
);

// ╔═════════════════════════════════════╗
// ║            CreateEventEx            ║
// ╚═════════════════════════════════════╝

// See CreateEvent for EFI_EVENT_NOTIFY
// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT_EX) (
    IN UINT32 Type,
    IN EFI_TPL NotifyTpl,
    IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL,
    IN CONST VOID *NotifyContext OPTIONAL,
    IN CONST EFI_GUID *EventGroup OPTIONAL,
    OUT EFI_EVENT *Event
);

// ╔═════════════════════════════════════╗
// ║            Boot Services            ║
// ╚═════════════════════════════════════╝

//  Signature/Revision
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

//      Structure
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
struct EFI_BOOT_SERVICES {
    EFI_RAISE_TPL RaiseTPL;
    EFI_RESTORE_TPL RestoreTPL;
    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;
    EFI_CREATE_EVENT CreateEvent;
    EFI_SET_TIMER SetTimer;
    EFI_WAIT_FOR_EVENT WaitForEvent;
    EFI_SIGNAL_EVENT SignalEvent;
    EFI_CLOSE_EVENT CloseEvent;
    EFI_CHECK_EVENT CheckEvent;
    EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL HandleProtocol;
    VOID* Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
    EFI_LOCATE_HANDLE LocateHandle;
    EFI_LOCATE_DEVICE_PATH LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;
    EFI_IMAGE_LOAD LoadImage;
    EFI_IMAGE_START StartImage;
    EFI_EXIT Exit;
    EFI_IMAGE_UNLOAD UnloadImage;
    EFI_EXIT_BOOT_SERVICES ExitBootServices;
    EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
    EFI_STALL Stall;
    EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;
    EFI_CONNECT_CONTROLLER ConnectController;
    EFI_DISCONNECT_CONTROLLER DisconnectController;
    EFI_OPEN_PROTOCOL OpenProtocol;
    EFI_CLOSE_PROTOCOL CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;
    EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;
    EFI_CALCULATE_CRC32 CalculateCrc32;
    EFI_COPY_MEM CopyMem;
    EFI_SET_MEM SetMem;
    EFI_CREATE_EVENT_EX CreateEventEx;
};

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                            RUNTIME SERVICES                           │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

typedef struct EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

// ╔═════════════════════════════════════╗
// ║               GetTime               ║
// ╚═════════════════════════════════════╝

//       Daylight
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02

//       TimeZone
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

//        Time
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 Pad2;
} EFI_TIME;

//  Time Capabilities
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_GET_TIME) (
    OUT EFI_TIME *Time,
    OUT EFI_TIME_CAPABILITIES *Capabilities OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║               SetTime               ║
// ╚═════════════════════════════════════╝

// See GetTime for EFI_TIME
typedef EFI_STATUS (EFIAPI *EFI_SET_TIME) (
    IN EFI_TIME *Time
);

// ╔═════════════════════════════════════╗
// ║            GetWakeupTime            ║
// ╚═════════════════════════════════════╝

// See GetTime for EFI_TIME
typedef EFI_STATUS (EFIAPI *EFI_GET_WAKEUP_TIME) (
    OUT BOOLEAN *Enabled,
    OUT BOOLEAN *Pending,
    OUT EFI_TIME *Time
);

// ╔═════════════════════════════════════╗
// ║            SetWakeupTime            ║
// ╚═════════════════════════════════════╝

// See GetTime for EFI_TIME
typedef EFI_STATUS (EFIAPI *EFI_SET_WAKEUP_TIME) (
    IN BOOLEAN Enable,
    IN EFI_TIME *Time OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║        SetVirtualAddressMap         ║
// ╚═════════════════════════════════════╝

// See BOOT SERVICES GetMemoryMap for EFI_MEMORY_DESCRIPTOR
typedef EFI_STATUS (EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP) (
    IN UINTN MemoryMapSize,
    IN UINTN DescriptorSize,
    IN UINT32 DescriptorVersion,
    IN EFI_MEMORY_DESCRIPTOR *VirtualMap
);

// ╔═════════════════════════════════════╗
// ║           ConvertPointer            ║
// ╚═════════════════════════════════════╝

//   Debug Disposition
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_OPTIONAL_PTR 0x00000001

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef EFI_STATUS (EFIAPI *EFI_CONVERT_POINTER) (
    IN UINTN DebugDisposition,
    IN VOID **Address 
);

// ╔═════════════════════════════════════╗
// ║             GetVariable             ║
// ╚═════════════════════════════════════╝

//      Attributes
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_VARIABLE_NON_VOLATILE 0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS 0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD 0x00000008
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS 0x00000010
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 0x00000020
#define EFI_VARIABLE_APPEND_WRITE 0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS 0x00000080

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_GET_VARIABLE) (
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    OUT UINT32 *Attributes OPTIONAL,
    IN OUT UINTN *DataSize,
    OUT VOID *Data OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║           GetVariableName           ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_VARIABLE_NAME) (
    IN OUT UINTN *VariableNameSize,
    IN OUT CHAR16 *VariableName,
    IN OUT EFI_GUID *VendorGuid
);

// ╔═════════════════════════════════════╗
// ║             SetVariable             ║
// ╚═════════════════════════════════════╝

// See InstallProtocolInterface for EFI_GUID
// See GetVariable for Attributes
typedef EFI_STATUS (EFIAPI *EFI_SET_VARIABLE) (
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    IN UINT32 Attributes,
    IN UINTN DataSize,
    IN VOID *Data
);

// ╔═════════════════════════════════════╗
// ║      GetNextHighMonotonicCount      ║
// ╚═════════════════════════════════════╝

typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT) (
    OUT UINT32 *HighCount
);

// ╔═════════════════════════════════════╗
// ║             ResetSystem             ║
// ╚═════════════════════════════════════╝

//      Reset Type
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef VOID (EFIAPI *EFI_RESET_SYSTEM) (
    IN EFI_RESET_TYPE ResetType,
    IN EFI_STATUS ResetStatus,
    IN UINTN DataSize,
    IN VOID *ResetData OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║            UpdateCapsule            ║
// ╚═════════════════════════════════════╝

//    Capsule Flags
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

//    Capsule Header
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
// See InstallProtocolInterface for EFI_GUID
typedef struct {
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

//    Capsule Table
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    UINT32 CapsuleArrayNumber;
    VOID* CapsulePtr[1];
} EFI_CAPSULE_TABLE;

// Scatter Gather List
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
typedef struct {
    UINT64 Length;
    union {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    } Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

//       Function
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
// See BOOT SERVICES AllocatePages for EFI_PHYSICAL_ADDRESS
typedef EFI_STATUS (EFIAPI *EFI_UPDATE_CAPSULE) (
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL
);

// ╔═════════════════════════════════════╗
// ║       QueryCapsuleCapabilities      ║
// ╚═════════════════════════════════════╝

// See UpdateCapsule for EFI_CAPSULE_HEADER
// See ResetSystem for EFI_RESET_TYPE
typedef EFI_STATUS (EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES) (
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    OUT UINT64 *MaximumCapsuleSize,
    OUT EFI_RESET_TYPE *ResetType
);

// ╔═════════════════════════════════════╗
// ║          QueryVariableInfo          ║
// ╚═════════════════════════════════════╝

// See GetVariable for Attributes
typedef EFI_STATUS (EFIAPI *EFI_QUERY_VARIABLE_INFO) (
    IN UINT32 Attributes,
    OUT UINT64 *MaximumVariableStorageSize,
    OUT UINT64 *RemainingVariableStorageSize,
    OUT UINT64 *MaximumVariableSize
);

// ╔═════════════════════════════════════╗
// ║           Runtime Services          ║
// ╚═════════════════════════════════════╝

//  Signature/Revision
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

//      Structure
// ╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼╼
struct EFI_RUNTIME_SERVICES {
    EFI_TABLE_HEADER Hdr;
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;
    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;
    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
};

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                          CONFIGURATION TABLE                          │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

// See InstallProtocolInterface for EFI_GUID
typedef struct {
    EFI_GUID VendorGuid;
    VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                              SYSTEM TABLE                             │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249

typedef struct {
    EFI_TABLE_HEADER Hdr;
    CHAR16 *FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;

// ╔═════════════════════════════════════╗
// ║              Revisions              ║
// ╚═════════════════════════════════════╝

#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_90_SYSTEM_TABLE_REVISION

  //#####################################################################\\
//╭‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╮\\
//│                              STATUS CODES                             │\\
//╰_______________________________________________________________________╯\\
  //#####################################################################\\

// ╔═════════════════════════════════════╗
// ║             Code Ranges             ║
// ╚═════════════════════════════════════╝

#define MAX_BIT  0x8000000000000000ULL
#define ENCODE_ERROR(StatusCode) ((UINTN)(MAX_BIT | (StatusCode)))
#define ENCODE_WARNING(StatusCode) ((UINTN)(StatusCode))

// ╔═════════════════════════════════════╗
// ║            Success Codes            ║
// ╚═════════════════════════════════════╝

#define EFI_SUCCESS 0

// ╔═════════════════════════════════════╗
// ║            Warning Codes            ║
// ╚═════════════════════════════════════╝

#define EFI_WARN_UNKNOWN_GLYPH      ENCODE_WARNING (1)
#define EFI_WARN_DELETE_FAILURE     ENCODE_WARNING (2)
#define EFI_WARN_WRITE_FAILURE      ENCODE_WARNING (3)
#define EFI_WARN_BUFFER_TOO_SMALL   ENCODE_WARNING (4)
#define EFI_WARN_STALE_DATA         ENCODE_WARNING (5)
#define EFI_WARN_FILE_SYSTEM        ENCODE_WARNING (6)
#define EFI_WARN_RESET_REQUIRED     ENCODE_WARNING (7)

// ╔═════════════════════════════════════╗
// ║             Error Codes             ║
// ╚═════════════════════════════════════╝

#define EFI_LOAD_ERROR              ENCODE_ERROR (1)
#define EFI_INVALID_PARAMETER       ENCODE_ERROR (2)
#define EFI_UNSUPPORTED             ENCODE_ERROR (3)
#define EFI_BAD_BUFFER_SIZE         ENCODE_ERROR (4)
#define EFI_BUFFER_TOO_SMALL        ENCODE_ERROR (5)
#define EFI_NOT_READY               ENCODE_ERROR (6)
#define EFI_DEVICE_ERROR            ENCODE_ERROR (7)
#define EFI_WRITE_PROTECTED         ENCODE_ERROR (8)
#define EFI_OUT_OF_RESOURCES        ENCODE_ERROR (9)
#define EFI_VOLUME_CORRUPTED        ENCODE_ERROR (10)
#define EFI_VOLUME_FULL             ENCODE_ERROR (11)
#define EFI_NO_MEDIA                ENCODE_ERROR (12)
#define EFI_MEDIA_CHANGED           ENCODE_ERROR (13)
#define EFI_NOT_FOUND               ENCODE_ERROR (14)
#define EFI_ACCESS_DENIED           ENCODE_ERROR (15)
#define EFI_NO_RESPONSE             ENCODE_ERROR (16)
#define EFI_NO_MAPPING              ENCODE_ERROR (17)
#define EFI_TIMEOUT                 ENCODE_ERROR (18)
#define EFI_NOT_STARTED             ENCODE_ERROR (19)
#define EFI_ALREADY_STARTED         ENCODE_ERROR (20)
#define EFI_ABORTED                 ENCODE_ERROR (21)
#define EFI_ICMP_ERROR              ENCODE_ERROR (22)
#define EFI_TFTP_ERROR              ENCODE_ERROR (23)
#define EFI_PROTOCOL_ERROR          ENCODE_ERROR (24)
#define EFI_INCOMPATIBLE_VERSION    ENCODE_ERROR (25)
#define EFI_SECURITY_VIOLATION      ENCODE_ERROR (26)
#define EFI_CRC_ERROR               ENCODE_ERROR (27)
#define EFI_END_OF_MEDIA            ENCODE_ERROR (28)
#define EFI_END_OF_FILE             ENCODE_ERROR (31)
#define EFI_INVALID_LANGUAGE        ENCODE_ERROR (32)
#define EFI_COMPROMISED_DATA        ENCODE_ERROR (33)
#define EFI_IP_ADDRESS_CONFLICT     ENCODE_ERROR (34)
#define EFI_HTTP_ERROR              ENCODE_ERROR (35)

#endif //UEFI_SYSTEM_TABLE