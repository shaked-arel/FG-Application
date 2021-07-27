using System;
using System.Collections.Generic;
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
using Microsoft.Win32;


namespace app0
{
    /// <summary>
    /// Interaction logic for View.xaml
    /// </summary>
    public partial class View : Window
    {
        private ViewModel vm;
        private String filePath;
        private String xmlFile;


        public View(String csv, String xml)
        {
            InitializeComponent();
            filePath = csv;
            xmlFile = xml;
            ViewModel vm = new ViewModel(new Model(csv, xml));
            MediaBar media = new MediaBar(vm);
            Joystick joy = new Joystick(vm);
            measurments meas = new measurments(vm);
            Graph g = new Graph(vm);
            Graph_Ilustraion i = new Graph_Ilustraion(vm);
            detectOption d = new detectOption(vm);
            grd_panel.Children.Add(media);
            joystick_panel.Children.Add(joy);
            measurments_panel.Children.Add(meas);
            graphs.Children.Add(i);
            graph_panel.Children.Add(g);
            anomalies.Children.Add(d);
            DataContext = vm;
        }

        private void OpenFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                this.filePath = System.IO.Path.GetFullPath(openFileDialog.FileName);

                vm = new ViewModel(new Model(filePath,xmlFile));
                vm.VM_File_path = filePath;
                DataContext = vm;

            }
        }
     
        public string Filepath
        {
            get { return filePath; }
        }
    }
}
