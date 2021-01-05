#include "API.h"
#include "DolphinProcess/DolphinAccessor.h"
#include "Common/CommonUtils.h"

// DolphinAccessor Functions

void initDA() {
    DolphinComm::DolphinAccessor::init();
}

void freeDA() {
    DolphinComm::DolphinAccessor::free();
}

void hook(std::string dolphin_names[]) {
    std::vector<std::string> names_vector(dolphin_names, dolphin_names + sizeof dolphin_names / sizeof dolphin_names[0]);
    DolphinComm::DolphinAccessor::hook(names_vector);
}

void unHook() {
    DolphinComm::DolphinAccessor::unHook();
}

bool readFromRAM(const u32 offset, char* buffer, const size_t size, const bool withBSwap) {
    return DolphinComm::DolphinAccessor::readFromRAM(offset, buffer, size, withBSwap);
}

bool writeToRAM(const u32 offset, const char* buffer, const size_t size, const bool withBSwap) {
    return DolphinComm::DolphinAccessor::writeToRAM(offset, buffer, size, withBSwap);
}

int getPID() {
    return DolphinComm::DolphinAccessor::getPID();
}

u64 getEmuRAMAddressStart() {
    return DolphinComm::DolphinAccessor::getEmuRAMAddressStart();
}

int getStatus() {
    return (int) DolphinComm::DolphinAccessor::getStatus();
}

bool isMEM2Present() {
    return DolphinComm::DolphinAccessor::isMEM2Present();
}

int updateRAMCache() {
    return (int) DolphinComm::DolphinAccessor::updateRAMCache();
}   

std::string getFormattedValueFromCache(const u32 ramIndex, int memType, size_t memSize, int memBase, bool memIsUnsigned) {
    return DolphinComm::DolphinAccessor::getFormattedValueFromCache(ramIndex, static_cast<Common::MemType>(memType), memSize, static_cast<Common::MemBase>(memBase), memIsUnsigned);
}

void copyRawMemoryFromCache(char* dest, const u32 consoleAddress, const size_t byteCount) {
    return DolphinComm::DolphinAccessor::copyRawMemoryFromCache(dest, consoleAddress, byteCount);
}

bool isValidConsoleAddress(const u32 address) {
    return DolphinComm::DolphinAccessor::isValidConsoleAddress(address);
}

// CommonUtils Functions

u32 dolphinAddrToOffset(u32 addr)
{
    return Common::dolphinAddrToOffset(addr);
}

u32 offsetToDolphinAddr(u32 offset)
{
    return Common::offsetToDolphinAddr(offset);
}