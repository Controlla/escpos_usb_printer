#pragma once
#include "utilities.h"
#include <algorithm>

#define ARRAY_LEN(var) (sizeof((var))/sizeof((var)[0]))

RAW_DATA_IMPL(g_cmdClear, RAW_DATA(0x1B, 0x40));
RAW_DATA_IMPL(g_cmdGetPrinterStatus, RAW_DATA(0x10, 0x04, 0x02));

std::string printerStatusToText(uint8_t status)
{
    std::string text;

    if (0x12 == status)
    {
        text = "Ready";
    }
    else if (0x16 == status)
    {
        text = "Cover opened";
    }
    else if (0x32 == status)
    {
        text = "Paper end";
    }
    else if (0x36 == status)
    {
        text = "Cover opened & Paper end";
    }
    else
    {
        text = "Error";
    }

    return text;
}

std::vector<uint8_t> composeCmdSetAlignment(uint8_t alignment)
{
    std::vector<uint8_t> cmd = { 0x1B, 0x61, alignment };

    return cmd;
}

std::vector<uint8_t> composeCmdCut(uint8_t m)
{
    std::vector<uint8_t> cmd = { 0x1D, 0x56, m };

    return cmd;

}

std::vector<uint8_t> composeCmdFeedPaper(uint8_t n)
{
    std::vector<uint8_t> cmd;

    while (n-- > 0)
    {
        cmd.push_back('\n');
    }

    return cmd;

}