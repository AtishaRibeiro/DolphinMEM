using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace DolphinMEM
{
    class MemoryAccessor
    {
        [DllImport("MemoryAccessor.dll")]
        public static extern int getStatus();

        [DllImport("MemoryAccessor.dll")]
        public static extern int hook(string[] dolphin_names);

        [DllImport("MemoryAccessor.dll")]
        public static extern bool readFromRAM(UInt32 offset, byte[] buffer, int size, bool withBSwap);

        [DllImport("MemoryAccessor.dll")]
        public static extern bool writeToRAM(UInt32 offset, byte[] buffer, int size, bool withBSwap);

        [DllImport("MemoryAccessor.dll")]
        public static extern bool isValidConsoleAddress(UInt32 address);

        [DllImport("MemoryAccessor.dll")]
        public static extern UInt32 dolphinAddrToOffset(UInt32 addr);
    }

    public enum DolphinStatus
    {
        hooked = 0,
        notRunning = 1,
        noEmu = 2,
        unHooked = 3
    }

    class Util
    {
        public static byte[] get_ptr_at_addr(UInt32 address)
        {
            byte[] buffer = new byte[4];
            MemoryAccessor.readFromRAM(MemoryAccessor.dolphinAddrToOffset(address), buffer, 4, false);
            return buffer;
        }

        public static byte[] int_to_byte_array(UInt32 address)
        {
            byte[] byte_address = BitConverter.GetBytes(address);
            Array.Reverse(byte_address);
            return byte_address;
        }

        public static UInt32 byte_array_to_int(byte[] address)
        {
            // reverse buffer so the endianness is correct
            Array.Reverse(address);
            return BitConverter.ToUInt32(address, 0);
        }

        public static byte[] int_list_byte_array(List<UInt32> int_list)
        {
            List<byte> result = new List<byte>();
            foreach (UInt32 hex_int in int_list)
            {
                List<byte> temp = int_to_byte_array(hex_int).ToList<byte>();
                result = result.Concat(temp).ToList();
            }
            return result.ToArray();
        }
    }
}
