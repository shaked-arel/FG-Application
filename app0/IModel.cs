using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using static app0.Model;
using OxyPlot;

namespace app0
{
    interface IModel : INotifyPropertyChanged
    {
        
        string File_path { set; get; }

        float Aileron { set; get; }
        float Elevator { set; get; }
        float Rudder { set; get; }
        float Throttle { set; get; }

        float Altimeter { set; get; }
        float AirSpeed { set; get; }
        float Pitch { set; get; }
        float Roll { set; get; }
        float Yaw { set; get; }
        float Heading { set; get; }
        Boolean Stop { set; get; }
        int Sleep { set; get; }
        int Current_line { set; get; }
        int Num_of_lines { set; get; }

        string TimePassed { set; get; }
        List<String> XmlNames { get; set; }
       
        List<DataPoint> GraphList { get; set; }

        List<DataPoint> Corre_points { get; set; }
        List<DataPoint> Corre_list { get; set; }
        string Correlated_att { get; set; }
        float A { get; set; }
        string DllString { get; set; }

        float B { get; set; }

        String Selection { get; set; }

        String AnomalyCsv { get; set; }
        String DetectType { get; set; }
        List<String> DetectNames { get; set; }

        Boolean StartDll { get; set; }

        List<String> Anomalies { get; set; }

       }
}
