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
using System.Net.Sockets;
using System.Threading;
using Microsoft.Win32;


namespace app0
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public String filePath;
        public String fileXml;
        private Boolean xml;
        private Boolean csv;

 
        public MainWindow()
        {
            InitializeComponent();
            xml = false;
            csv = false;
        }
        private void OpenFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                filePath = System.IO.Path.GetFullPath(openFileDialog.FileName);
                showCsv.Content = filePath;
                csv = true;

            }
        }
        private void OpenXML_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                fileXml = System.IO.Path.GetFullPath(openFileDialog.FileName);
                showXml.Content = fileXml;
                xml = true;
            }
        }
        private void start_Click(object sender, RoutedEventArgs e)
        {
            if (csv && xml)
            {
                this.Hide();

                View view = new View(filePath, fileXml);
                view.ShowDialog();
                this.Show();

            }

        }
    }
}