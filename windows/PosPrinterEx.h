#ifndef _9M_356452E7_B134_6473_908A_CFC0FDBDBA25
#define _9M_356452E7_B134_6473_908A_CFC0FDBDBA25

#pragma once
#include "PosPrinter.h"
#include <stdint.h>

// PosPrinter (Abbr. : PP)

enum
{
    PP_INVALID_HANDLE = -1,
};

#ifdef __cplusplus

class PosPrinterStream
{
public:
    PosPrinterStream();
    virtual ~PosPrinterStream();

    virtual bool isOpen() = 0;
    virtual void close()  = 0;

    virtual int write(const char* writeBuf, int writeBufSize) = 0;
    virtual int read(char* readBuf, int readBufSize)          = 0;
};

class PosPrinterCom : public PosPrinterStream
{
public:
    PosPrinterCom();
    virtual ~PosPrinterCom();

    void open(const wchar_t* name,
              int baudRate,
              UINT8 parity   = 0,
              UINT8 byteSize = 8,
              UINT8 dtr      = 0,
              UINT8 stopBits = 1);

    void open(const char* name,
              int baudRate,
              UINT8 parity   = 0,
              UINT8 byteSize = 8,
              UINT8 dtr      = 0,
              UINT8 stopBits = 1);

    virtual bool isOpen() override;
    virtual void close() override;

    virtual int write(const char* writeBuf, int writeBufSize) override;
    virtual int read(char* readBuf, int readBufSize) override;

private:
    int handle_;
};

class PosPrinterNet : public PosPrinterStream
{
public:
    PosPrinterNet();
    virtual ~PosPrinterNet();

    void open(const char* host, uint16_t port = 9100, int timeout = 5000);

    virtual bool isOpen() override;
    virtual void close() override;

    virtual int write(const char* writeBuf, int writeBufSize) override;
    virtual int read(char* readBuf, int readBufSize) override;

private:
    int handle_;
};

class PosPrinterLpt : public PosPrinterStream
{
public:
    PosPrinterLpt();
    virtual ~PosPrinterLpt();

    void open(const wchar_t* name);
    void open(const char* name);

    virtual bool isOpen() override;
    virtual void close() override;

    virtual int write(const char* writeBuf, int writeBufSize) override;
    virtual int read(char* readBuf, int readBufSize) override;

private:
    int handle_;
};

class PosPrinterUsb : public PosPrinterStream
{
public:
    PosPrinterUsb();
    virtual ~PosPrinterUsb();

    void open(int vid, int pid);
    void open();
    virtual bool isOpen() override;
    virtual void close() override;

    virtual int write(const char* writeBuf, int writeBufSize) override;
    virtual int read(char* readBuf, int readBufSize) override;

private:
    int readHandle_;
    int writeHandle_;
};

typedef class PosPrinterStream* PpUsbPtr;
#else
typedef struct PosPrinterStream* PpUsbPtr;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Initialize PosPrinterEx by dynamic load raw apis from PosPrinter.dll
     *
     * @param libFileName The PosPrinter.dll path, could be NULL if it's under
     * program's director
     * @return int Return 1 if success, otherwise return 0
     */
    int PpApiInitA(const char* libFileName);

    /**
     * Initialize PosPrinterEx by dynamic load raw apis from PosPrinter.dll
     *
     * @param libFileName The PosPrinter.dll path, could be NULL if it's under
     * program's director
     * @return int Return 1 if success, otherwise return 0
     */
    int PpApiInitW(const wchar_t* libFileName);
    PpUsbPtr PpOpenUsb(void);
    PpUsbPtr PpOpenUsbById(uint16_t vid, uint16_t pid);
    PpUsbPtr PpOpenCom(const wchar_t* name, int baudRate);
    PpUsbPtr PpOpenCom2(const char* name, int baudRate);
    PpUsbPtr PpOpenLpt(const wchar_t* name);
    PpUsbPtr PpOpenLpt2(const char* name);
    PpUsbPtr PpOpenNet(const char* host);
    PpUsbPtr PpOpenNet2(const char* host, uint16_t port);
    PpUsbPtr PpOpenNet3(const char* host, uint16_t port, int timeout);
    int PpWrite(PpUsbPtr self, const uint8_t* buffer, int size);
    int PpRead(PpUsbPtr self, uint8_t* buffer, int size);
    void PpClose(PpUsbPtr self);

#ifdef __cplusplus
};
#endif

#endif /* _9M_356452E7_B134_6473_908A_CFC0FDBDBA25 */
