#pragma once

#include "framework.h"
#include "Common/CommonTypes.h"
#include <string>
#include <vector>

#ifdef MEMORYACCESSOR_EXPORTS
#define  MEMORYACCESSOR_API __declspec(dllexport)
#else
#define  MEMORYACCESSOR_API __declspec(dllimport)
#endif

extern "C" {

    // DolphinAccessor functions
    MEMORYACCESSOR_API void initDA();
    MEMORYACCESSOR_API void freeDA();
    MEMORYACCESSOR_API void hook(std::string dolphin_names[]);
    MEMORYACCESSOR_API void unHook();
    MEMORYACCESSOR_API bool readFromRAM(const u32 offset, char* buffer, const size_t size, const bool withBSwap);
    MEMORYACCESSOR_API bool writeToRAM(const u32 offset, const char* buffer, const size_t size, const bool withBSwap);
    MEMORYACCESSOR_API int getPID();
    MEMORYACCESSOR_API u64 getEmuRAMAddressStart();
    MEMORYACCESSOR_API int getStatus();
    MEMORYACCESSOR_API bool isMEM2Present();
    MEMORYACCESSOR_API int updateRAMCache();
    MEMORYACCESSOR_API std::string getFormattedValueFromCache(const u32 ramIndex, int memType, size_t memSize, int memBase, bool memIsUnsigned);
    MEMORYACCESSOR_API void copyRawMemoryFromCache(char* dest, const u32 consoleAddress, const size_t byteCount);
    MEMORYACCESSOR_API bool isValidConsoleAddress(const u32 address);

    // CommonUtils functions
    MEMORYACCESSOR_API u32 dolphinAddrToOffset(u32 addr);
    MEMORYACCESSOR_API u32 offsetToDolphinAddr(u32 offset);
}