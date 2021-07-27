using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace regCDll
{
    public class regDll:IDll
    {
        [DllImport("plugins\\DllRe\\Debug\\DllRe.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr Create(string name);
        [DllImport("plugins\\DllRe\\Debug\\DllRe.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void FindDetect(IntPtr p, string csvPath, string filePath, StringBuilder result);

        public String getAnomaliesFile(string file_path, string checkCsv)
        {
            IntPtr p = Create(file_path);
            StringBuilder res = new StringBuilder(100000);
            FindDetect(p, checkCsv, file_path, res);
            return res.ToString();
        }
    }
}
