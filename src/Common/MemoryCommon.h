#pragma once

#include <cstddef>
#include <string>

#include "CommonTypes.h"

namespace Common
{
const u32 MEM1_SIZE = 0x1800000;
const u32 MEM1_START = 0x80000000;
const u32 MEM1_END = 0x81800000;

const u32 MEM2_SIZE = 0x4000000;
const u32 MEM2_START = 0x90000000;
const u32 MEM2_END = 0x94000000;

enum class MemType
{
  type_byte = 0,
  type_halfword = 1,
  type_word = 2,
  type_float = 3,
  type_double = 4,
  type_string = 5,
  type_byteArray = 6,
  type_num = 7
};

enum class MemBase
{
  base_decimal = 0,
  base_hexadecimal = 1,
  base_octal = 2,
  base_binary = 3,
  base_none = 4 // Placeholder when the base doesn't matter (ie. string)
};

enum class MemOperationReturnCode
{
  invalidInput = 0,
  operationFailed = 1,
  inputTooLong = 2,
  invalidPointer = 3,
  OK = 4
};

size_t getSizeForType(const MemType type, const size_t length);
bool shouldBeBSwappedForType(const MemType type);
int getNbrBytesAlignementForType(const MemType type);
char* formatStringToMemory(MemOperationReturnCode& returnCode, size_t& actualLength,
                           const std::string inputString, const MemBase base, const MemType type,
                           const size_t length);
std::string formatMemoryToString(const char* memory, const MemType type, const size_t length,
                                 const MemBase base, const bool isUnsigned,
                                 const bool withBSwap = false);
} // namespace Common
