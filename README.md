
# DolphinMEM

A very simple Dolphin memory interface library based on Aldelaro's **[Dolphin-memory-engine](https://github.com/aldelaro5/Dolphin-memory-engine)**
The original included both Windows and Linux code but only the Windows files were ported to this library.

## Building and using the .dll
When building the .dll, make sure to build a 64-bit version, 32-bit does not work.
The functions that can be called are all located in `API.h`, some of these are explained here. This is just something I wrote down quickly and is by no means a thorough explanation.

 - `hook(std::string dolphin_names[])`
	 - This function will try to find a running version of Dolphin. By default it will look for running programs that have on of the following names: `Dolphin.exe`, `DolphinQt2.exe` or `DolphinWx.exe`.  The `dolphin_names` parameter let's you add more possible names to this list, in case that is necessary. In case you don't need it, simply pass an empty array.
 - `getStatus()`
	 - Returns an enum that represents the current hook status. The possible values are `hooked = 0, notRunning = 1,
    noEmu = 2,
    unHooked = 3`
  -  `writeToRAM(const u32 offset, const char* buffer, const size_t size, const bool withBSwap)`
	  -  `offset`: The offset in memory. To get the right offset simply use the `dolphinAddrToOffset` function.
	  - `buffer`: The bytes that need to be written to memory.
	  - `size`: The size of the buffer (amount of bytes).
	  - `withBSwap`: I don't remember what this does. (swap the bytes around?) Just set to false if you don't know what this does.
  - `readFromRAM(const u32 offset, char* buffer, const size_t size, const bool withBSwap)`
	  - Same as `writeToRAM` but the other way around.
  - `dolphinAddrToOffset(u32 address)`
	  - Given the Dolphin (Wii) address, returns the corresponding offset in memory.

## C# Interface

A C# interface is included that communicates with the dll. Not all functions are implemented here but adding functions shouldn't be too hard. Just look at `API.h` and copy (with C# types) the signature of the function you want to include.

A small test program is included to verify that the library is working properly. When run it will try to hook to a running Dolphin instance and print out the game version in console if it succeeds.
