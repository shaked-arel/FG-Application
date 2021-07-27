using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpCircleDll
{
    interface IDll
    {
        String getAnomaliesFile(string file_path, string checkCsv);
    }
}
