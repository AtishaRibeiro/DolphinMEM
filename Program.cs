using System;
using System.Text;

namespace DolphinMEM
{
    class Program
    {
        static void Main(string[] args)
        {
            MemoryAccessor.hook(new string[0]);
            DolphinStatus status = (DolphinStatus)MemoryAccessor.getStatus();
            string region = "INVALID";
            if (status == DolphinStatus.hooked)
            {
                byte[] buffer = new byte[6];
                MemoryAccessor.readFromRAM(0, buffer, 6, false);
                region = Encoding.Default.GetString(buffer);
            }
            Console.WriteLine(region);
        }
    }
}
