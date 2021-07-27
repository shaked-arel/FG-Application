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
    /// Interaction logic for detectOption.xaml
    /// </summary>
    public partial class detectOption : UserControl
    {
        ViewModel vm;
        Boolean csv,dll;
        public detectOption(ViewModel v)
        {
            vm = v;
            csv = false;
            InitializeComponent();
            DataContext = vm;
        }
        private void GetFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                String path = System.IO.Path.GetFullPath(openFileDialog.FileName);
                vm.VM_AnomalyCsv = path;
                detectLable.Content = path;
                csv = true;

            }
        }
        private void GetDll_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                String path = System.IO.Path.GetFullPath(openFileDialog.FileName);
                vm.VM_DllString = path;
             dllLable.Content = path;
                dll = true;

            }
        }

        private void start_Detect(object sender, RoutedEventArgs e)
        {
            if (csv &&dll)
            {
                
                vm.VM_StartDll = true;
            }

        }

    }
}
