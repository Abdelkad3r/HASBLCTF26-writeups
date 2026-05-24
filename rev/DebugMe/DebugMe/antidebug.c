#include "antidebug.h"

BOOL isThereAThread = FALSE;

BOOL strchecker(WCHAR* str) {
	BOOL ret = FALSE;
	if (str == NULL) {
		goto end;
	}
	if (!lstrcmpW(str,L"x64dbg.exe")) {
		goto end;
	}
	if (!lstrcmpW(str, L"ProcessHacker.exe")) {
		goto end;
	}
	if (!lstrcmpW(str, L"ida.exe")) {
		goto end;
	}
	if (!lstrcmpW(str, L"binaryninja.exe")) {
		goto end;
	}
	ret = TRUE;
end:
	return ret;
}

void stage2() {
	unsigned char flag[] = { 0x02,0x0b,0x19,0x08,0x06,0x31,0x33,0x7a,0x3f,0x15,0x2e,0x79,0x28,0x3f,0x2d,0x2d,0x79,0x2e,0x15,0x27,0x79,0x15,0x3a,0x38,0x79,0x7d,0x7d,0x33,0x15,0x2d,0x7a,0x7a,0x2e,0x37,0x00};
	//HASBL{y0u_d3bugg3d_m3_pr377y_g00d}
	while (1) {
		if (myIsDebuggerPresent()) {
			ExitProcess(1);
		}
		HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == INVALID_HANDLE_VALUE) {
			printf("process photo failed!\n");
			ExitProcess(2);
		}
		LPPROCESSENTRY32 pProcEntry = malloc(sizeof(PROCESSENTRY32));
		if (pProcEntry == NULL) {
			printf("malloc failed\n");
			ExitProcess(3);
		}
		pProcEntry->dwSize = sizeof(PROCESSENTRY32);
		if (!Process32FirstW(hProcessSnap, pProcEntry)) {
			printf("0x%x\n", GetLastError());
			ExitProcess(4);
		}
		if (!strchecker(pProcEntry->szExeFile)) {
			ExitProcess(5);
		}

		while (Process32NextW(hProcessSnap, pProcEntry)) {
			if (!strchecker(pProcEntry->szExeFile)) {
				ExitProcess(5);
			}
		}
		free(pProcEntry);
		pProcEntry = NULL;
		if (myIsDebuggerPresent()) {
			for (size_t i = 0; i < sizeof(flag)-1; i++) {
				flag[i] = flag[i] ^ 0x4a;
				
			}
			puts(flag);
		}
	}
	
}

BOOL DebugMe() {
	if (!myIsDebuggerPresent()) {
		printf("[-] Attach a debugger! Your goal is debugging me!\n");
		ExitProcess(1);
	}
	__try {
		crash();
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		HMODULE ntdll = GetModuleHandleA("ntdll.dll");
		NTSTATUS (*pNtCreateThreadEx)(PHANDLE,ACCESS_MASK,PVOID,HANDLE,PVOID,PVOID,ULONG,SIZE_T,SIZE_T,SIZE_T,PVOID) = GetProcAddress(ntdll, "NtCreateThreadEx");
		HANDLE hThread = NULL;
		NTSTATUS ret = pNtCreateThreadEx(&hThread, THREAD_ALL_ACCESS, NULL, (HANDLE)-1, stage2, NULL, 0x00000004, 0, 0, 0, NULL);
		if (ret != 0 || hThread == NULL) {
			printf("Thread failed!\n");
			ExitProcess(-1);
		}
		puts("checking if there's any debuggers...\n");
		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);
		return 1;
	}
}