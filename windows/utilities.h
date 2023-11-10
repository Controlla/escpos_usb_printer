#pragma once
#include <vector>
#include <string>

#define RAW_DATA(...) {__VA_ARGS__}
#define RAW_DATA_SIZE(var) _9V##var##_Size
#define RAW_DATA_DECL(var) extern const uint8_t var[]; extern const size_t RAW_DATA_SIZE(var);
#define RAW_DATA_IMPL(var, data) const uint8_t var[] = data; const size_t RAW_DATA_SIZE(var) = sizeof((var))/sizeof((var)[0]);

RAW_DATA_DECL(g_cmdClear);
RAW_DATA_DECL(g_cmdGetPrinterStatus);
RAW_DATA_DECL(g_cmdSetAlignment);


std::string printerStatusToText(uint8_t status);

std::vector<uint8_t> composeCmdSetAlignment(uint8_t alignment);
std::vector<uint8_t> composeCmdCut(uint8_t m);
std::vector<uint8_t> composeCmdFeedPaper(uint8_t n);
