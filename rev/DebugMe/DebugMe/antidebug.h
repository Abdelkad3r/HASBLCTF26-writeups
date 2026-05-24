#include <Windows.h>
#include <stdio.h>
#include <tlhelp32.h>

extern void crash();
extern BOOL myIsDebuggerPresent();

BOOL DebugMe();

void stage2();