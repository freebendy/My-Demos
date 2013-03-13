using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TransparentWindow
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.White;
            this.TransparencyKey = Color.White;
            this.FormBorderStyle = FormBorderStyle.None;

            //this.Location = new System.Drawing.Point(100, 100);
            //this.Cursor = System.Windows.Forms.Cursors.Hand;
            //// 定义在窗体上，光标显示为手形  
            //this.Text = "透明的WinForm窗体！";
            //// 定义窗体的标题名称  
            //this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            //// 定义窗体的开始显示位置是屏幕的中间  
            //this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            //// 窗体的边界是Fixed3D类型  
            //this.ForeColor = System.Drawing.SystemColors.Desktop;
            ////以桌面的前景色作为窗体的前景色  
            //this.Font = new System.Drawing.Font("宋体", 9);
            //// 定义字体类型，大小  
            //this.BackColor = System.Drawing.Color.Blue;
            //// 定义背景色为蓝色  
            //this.ClientSize = new System.Drawing.Size(440, 170);
            //// 设置窗体的大小  
            //// Opacity属性设立窗体的透明程度，只对于视窗2000有效  
            //this.Opacity = 0.60;  
        }
    }
}
