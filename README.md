# Simple-C-UEFI-Library
A UEFI Library made for C (but can probably be used for C++) made for simplicity.
Libraries such as EDK2 have large development trees which can be hard to navigate.
The purpose of this Library is to simplify the process of UEFI development.

Documentation for UEFI can be found at https://uefi.org/specifications

HOW TO USE:

#include "EFI_SYSTEM_TABLE"

EFI_STATUS efi_main(ImageHandle Handle, EFI_SYSTEM_TABLE *SystemTable) {
  code here
}


OTHER INFORMATION:
More protocols will be added in the future
