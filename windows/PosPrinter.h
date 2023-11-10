#ifndef _9M_8BCD9770_F134_6472_DB03_A2100A57A22B
#define _9M_8BCD9770_F134_6472_DB03_A2100A57A22B
#pragma once
#include <Windows.h>

#if defined(__cplusplus)
extern "C"
{
#endif

#ifdef POSPRINTER_EXPORTS
#    define POSPRINTER_API __declspec(dllexport)

    /**
     * Start the printer socket service
     */
    POSPRINTER_API BOOL __stdcall InitNetSev();

    /**
     * Connect printer by network
     *
     * It's not a good network connect method, you have better to implement you
     * custom network access method.
     *
     * @param ip
     * @param port
     * @param timeout Timeout value, seems not much helps, if it failed, you
     * must at least wait 21s.
     * @return When return value < -1 (might -5, -x ...), than means an error
     * code, positive value indicated a handle value.
     */
    POSPRINTER_API int __stdcall ConnectNetPortByIp(char* ip,
                                                    int port    = 9100,
                                                    int timeout = 5000);
    POSPRINTER_API int __stdcall WriteToNetPort(int handle,
                                                char* writeBuf,
                                                int writeBufSize);
    POSPRINTER_API int __stdcall ReadFromNetPort(int handle,
                                                 char* readBuf,
                                                 int readBufSize);
    POSPRINTER_API BOOL __stdcall CloseNetPor(int handle);

    /**
     */
    POSPRINTER_API BOOL __stdcall CloseNetServ();

    /**
     * Open printer by it's vid & pid
     *
     * You must read() & write() with different printer handle, they won't works
     * together! So you have to open twice if you want to read & write in the same
     * time.
     *
     * @param vid
     * @param pid
     * @return The printer handle which opened
     */
    POSPRINTER_API int __stdcall OpenUsbByVidPid(int vid, int pid);
    POSPRINTER_API int __stdcall OpenUsb();
    POSPRINTER_API int __stdcall WriteUsb(int handle,
                                          char* writeBuf,
                                          int writeBufSize);
    POSPRINTER_API int __stdcall ReadUsb(int handle,
                                         char* readBuf,
                                         int readBufSize);
    POSPRINTER_API BOOL __stdcall CloseUsb(int handle);

    POSPRINTER_API int __stdcall OpenLptW(char* name);
    POSPRINTER_API int __stdcall OpenLptA(char* name);
    POSPRINTER_API int __stdcall WriteLpt(int handle,
                                          char* writeBuf,
                                          int writeBufSize);
    POSPRINTER_API int __stdcall ReadLpt(int handle,
                                         char* readBuf,
                                         int readBufSize);
    POSPRINTER_API BOOL __stdcall CloseLpt(int handle);

    /// OpenComW() not working as expected, use OpenComA() instead!
    // POSPRINTER_API int __stdcall OpenComW(char* Com,
    //                                       int baudRate,
    //                                       UINT8 Parity,
    //                                       UINT8 ByteSize,
    //                                       UINT8 fDtrControl,
    //                                       UINT8 StopBits);

    POSPRINTER_API int __stdcall OpenComA(char* name, int baudRate);
    POSPRINTER_API int __stdcall ReadCom(int handle,
                                         char* readBuf,
                                         int writeBufSize);
    POSPRINTER_API int __stdcall WriteCom(int handle,
                                          char* writeBuf,
                                          int writeBufSize);
    POSPRINTER_API BOOL __stdcall CloseCom(int handle);
#else
#    define POSPRINTER_API __declspec(dllimport)
#endif

// You must load all functions by runtime, because we don't have the permission
// to get the source code of the raw PosPrinter.dll, and the lib.exe generate
// wrong PosPrinter.lib in x86 mode (It's assume lib are declared as stdcall).
//
// See http://wyw.dcweb.cn/stdcall.htm .
//
// So we have to load those dll function in both X86 and X64 mode
#include "PosPrinterDynFuncDefs.h"

#if defined(__cplusplus)
}
#endif

#endif /* _9M_8BCD9770_F134_6472_DB03_A2100A57A22B */
