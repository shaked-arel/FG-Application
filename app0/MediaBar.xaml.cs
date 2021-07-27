using System;
using System.Collections.Generic;
using System.Globalization;
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
using System.Windows.Threading;

namespace app0
{
    /// <summary>
    /// Interaction logic for UserControl1.xaml
    /// </summary>
    public partial class MediaBar : UserControl
    {
        DispatcherTimer d;
        ViewModel vm;

        public MediaBar(ViewModel v)
        {
            InitializeComponent();
            this.vm = v;
            Slider2.Value = 1.0;
            this.DataContext = vm;
        }


        private void Slider1_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {

        }

        private void Slider2_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if ((int)(100 / Slider2.Value) > 0)
            {
                if (vm.VM_Stop == true)
                {
                    vm.VM_Stop = false;
                }
                vm.VM_Sleep = (int)(100 / Slider2.Value);
            }
            else
            {
                vm.VM_Stop = true;
            }
            speed.Text = Slider2.Value.ToString();
        }

        private void Play_Click(object sender, RoutedEventArgs e)
        {
            vm.VM_Stop = false;
        }

        private void Stop_Click(object sender, RoutedEventArgs e)
        {
            vm.VM_Stop = true;
        }

        private void Go_Click(object sender, RoutedEventArgs e)
        {
            if ((vm.VM_Num_of_lines - vm.VM_Current_line) >= 50)
            {
                vm.VM_Current_line += 50;
            }
            else
            {
                vm.VM_Current_line = vm.VM_Num_of_lines;
            }
        }

        private void Back_Click(object sender, RoutedEventArgs e)
        {
            if ((vm.VM_Current_line - 50) >= 0)
            {
                vm.VM_Current_line -= 50;
            }
            else
            {
                vm.VM_Current_line = 0;
            }
        }

        private void PlaySpeed_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Speed_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Clock_changed(object sender, TextChangedEventArgs e)
        {
            
        }

        private void End_Click(object sender, RoutedEventArgs e)
        {
            vm.VM_Current_line = vm.VM_Num_of_lines;
            double t = (vm.VM_Num_of_lines / 10);
            vm.VM_TimePassed = TimeSpan.FromSeconds(t).ToString();
        }

        private void Restart_Click(object sender, RoutedEventArgs e)
        {
            vm.VM_Current_line = 0;
            vm.VM_TimePassed = TimeSpan.FromSeconds(0).ToString();
        }
    }
}