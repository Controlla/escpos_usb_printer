#ifndef _9M_A338E9CB_F134_64D8_7DEB_975A23544BBA
#define _9M_A338E9CB_F134_64D8_7DEB_975A23544BBA

#pragma once
#include <Windows.h>

typedef BOOL(__stdcall* InitNetSevDef)();
typedef int(__stdcall* ConnectNetPortByIpDef)(char* ip, int port, int timeout);
typedef int(__stdcall* WriteToNetPortDef)(int handle,
                                          char* writeBuf,
                                          int writeBufSize);
typedef int(__stdcall* ReadFromNetPortDef)(int handle,
                                           char* readBuf,
                                           int readBufSize);
typedef BOOL(__stdcall* CloseNetPorDef)(int handle);

typedef BOOL(__stdcall* CloseNetServDef)();

typedef int(__stdcall* OpenUsbByVidPidDef)(int vid, int pid);
typedef int(__stdcall* OpenUsbDef)();
typedef int(__stdcall* WriteUsbDef)(int handle,
                                    char* writeBuf,
                                    int writeBufSize);
typedef int(__stdcall* ReadUsbDef)(int handle, char* readBuf, int readBufSize);
typedef BOOL(__stdcall* CloseUsbDef)(int handle);

typedef int(__stdcall* OpenLptWDef)(char* name);
typedef int(__stdcall* OpenLptADef)(char* name);
typedef int(__stdcall* WriteLptDef)(int handle,
                                    char* writeBuf,
                                    int writeBufSize);
typedef int(__stdcall* ReadLptDef)(int handle, char* readBuf, int readBufSize);
typedef BOOL(__stdcall* CloseLptDef)(int handle);
typedef int(__stdcall* OpenComADef)(char* name, int baudRate);
typedef int(__stdcall* ReadComDef)(int handle, char* readBuf, int writeBufSize);
typedef int(__stdcall* WriteComDef)(int handle,
                                    char* writeBuf,
                                    int writeBufSize);
typedef BOOL(__stdcall* CloseComDef)(int handle);

#endif /* _9M_A338E9CB_F134_64D8_7DEB_975A23544BBA */
