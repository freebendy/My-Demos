using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TransparentWindowWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            this.WindowStartupLocation = WindowStartupLocation.Manual;
            Left = SystemParameters.PrimaryScreenWidth - Width;
            Top = SystemParameters.PrimaryScreenHeight - Height - 20;

            this.MouseMove+=new MouseEventHandler(Login_MouseMove);
        }

        private void Login_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.LeftButton == MouseButtonState.Pressed)
            {
                this.DragMove();
            }
        }

        private void App_Exit(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void App_About(object sender, RoutedEventArgs e)
        {
            System.Diagnostics.Process.Start("http://www.bgy.com.cn/china/index.aspx");
        }
    }
}
