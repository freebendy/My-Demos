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

namespace GIFDecoder
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            //Uri uri = new Uri("/gif.gif", UriKind.Relative);
            //GifBitmapDecoder gifDecoder = new GifBitmapDecoder(uri, BitmapCreateOptions.None, BitmapCacheOption.Default);
            //lbx.ItemsSource = gifDecoder.Frames;
        }
    }
}
