using OxyPlot;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace app0
{
    /// <summary>
    /// Interaction logic for ViewModel.xaml
    /// </summary>
    public partial class ViewModel : INotifyPropertyChanged
    {
        private IModel model;

        public ViewModel(Model m)
        {
            this.model = m;
            InitializeComponent();
            model.PropertyChanged += delegate (Object sender, PropertyChangedEventArgs e)
            {
                NotifyPropertyChanged("VM_" + e.PropertyName);
            };
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void NotifyPropertyChanged(string propName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propName));
        }
        public List<DataPoint> VM_GraphList 
        {
            get
            {
                return model.GraphList;
            }
            set
            {
                model.GraphList = value;
            }
        }
        public String VM_Selection
        {
            get
            {
                return model.Selection;
            }
            set
            {
                model.Selection = value;
            }
        }
        public String VM_DetectType
        {
            get
            {
                return model.DetectType;
            }
            set
            {
                model.DetectType = value;
            }
        }
        public String VM_AnomalyCsv
        {
            get
            {
                return model.AnomalyCsv;
            }
            set
            {
                model.AnomalyCsv = value;
            }
        }

        public float VM_Throttle
        {
            get
            {
                return model.Throttle;
            }
            set
            {
                model.Throttle = value;
            }
        }

        public float VM_Rudder
        {
            get
            {
                return model.Rudder;
            }
            set
            {
                model.Rudder = value;
            }
        }

        public float VM_Elevator
        {
            get
            {
                return model.Elevator;
            }
            set
            {
                model.Elevator = value;
            }
        }

        public float VM_Aileron
        {
            get
            {
                return model.Aileron;
            }
            set
            {
                model.Aileron = value;
            }
        }


        public int VM_Current_line
        {
            get
            {
                return model.Current_line;
            }
            set
            {
                model.Current_line = value;
            }
        }

        public int VM_Num_of_lines
        {
            get
            {
                return model.Num_of_lines;
            }
            set
            {
                model.Num_of_lines = value;
            }
        }

        public int VM_Sleep
        {
            get
            {
                return model.Sleep;
            }
            set
            {
                model.Sleep = value;
            }
        }

        public Boolean VM_Stop
        {
            get
            {
                return model.Stop;
            }
            set
            {
                model.Stop = value;
            }
        }

        public List<String> VM_XmlNames
        {
            get
            {
                return model.XmlNames;
            }
        }
        public List<String> VM_DetectNames
        {
            get
            {
                return model.DetectNames;
            }
        }
        public List<String> VM_Anomalies
        {
            get
            {
                return model.Anomalies;
            }
            set
            {
                model.Anomalies = value;
            }
        }
        public Boolean VM_StartDll
        {
            get
            {
                return model.StartDll;
            }
            set
            {
                model.StartDll = value;
            }
        }

        public float VM_Altimeter
        {
            get
            {
                return model.Altimeter;
            }
        }
        public float VM_AirSpeed
        {
            get
            {
                return model.AirSpeed;
            }
        }
        public float VM_Pitch
        {
            get
            {
                return model.Pitch;
            }
        }
        public float VM_Roll
        {
            get
            {
                return model.Roll;
            }
        }
        public float VM_Yaw
        {
            get
            {
                return model.Yaw;
            }
        }
        public float VM_Heading
        {
            get
            {
                return model.Heading;
            }
        }

        public string VM_TimePassed
        {
            get
            {
                return model.TimePassed;
            }
            set
            {
                model.TimePassed = value;
            }
        }

        public string VM_Correlated_att
        {
            get
            {
                return model.Correlated_att;
            }
            set
            {
                model.Correlated_att = value;
            }
        }

        public List<DataPoint> VM_Corre_points
        {
            get
            {
                return model.Corre_points;
            }
            set
            {
                model.Corre_points = value;
            }
        }


        public List<DataPoint> VM_Corre_list
        {
            get
            {
                return model.Corre_list;
            }
            set
            {
                model.Corre_list = value;
            }
        }

        public float VM_A
        {
            get
            {
                return model.A;
            }
            set
            {
                model.A = value;
            }
        }
        public String VM_DllString
        {
            get
            {
                return model.DllString;
            }
            set
            {
                model.DllString = value;
            }
        }

        public float VM_B
        {
            get
            {
                return model.B;
            }
            set
            {
                model.B = value;
            }
        }

        public string VM_File_path { get; internal set; }
    }
}
    

