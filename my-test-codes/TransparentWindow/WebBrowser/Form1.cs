using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WebBrowser
{
    public partial class Form1 : Form
    {
        private bool formMove = false;//窗体是否移动
        private Point formPoint = new Point();//记录窗体的位置

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // 任务栏不显示
            this.ShowInTaskbar = false;

            // 主窗口透明
            this.BackColor = Color.White;
            this.TransparencyKey = Color.White;

            // 默认位置右下角
            this.Left = Screen.PrimaryScreen.WorkingArea.Width - this.Width;
            this.Top = Screen.PrimaryScreen.WorkingArea.Height - this.Height;

            // 拖动事件
            this.pictureBox1.MouseDown += this.PictureBox1_MouseDown;
            this.pictureBox1.MouseMove += this.PictureBox1_MouseMove;
            this.pictureBox1.MouseUp += this.PictureBox1_MouseUp;

            // 右键菜单
            MenuItem menuItemAbout = new MenuItem("关于");
            menuItemAbout.Click += this.AboutItem_Click;
            MenuItem menuItemExit = new MenuItem("退出");
            menuItemExit.Click += this.ExitItem_Click;

            ContextMenu contextMenu = new ContextMenu();
            contextMenu.MenuItems.Add(menuItemAbout);
            contextMenu.MenuItems.Add(menuItemExit);
            this.pictureBox1.ContextMenu = contextMenu;

            // 托盘右键菜单
            ContextMenu trayContextMenu = new ContextMenu();
            trayContextMenu.MenuItems.Add(menuItemAbout);
            trayContextMenu.MenuItems.Add(menuItemExit);
            this.notifyIcon1.ContextMenu = trayContextMenu;
        }

        private void AboutItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("http://www.bgy.com.cn/china/index.aspx");
        }

        private void ExitItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void PictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                formPoint.X = -e.X - SystemInformation.FrameBorderSize.Width;
                formPoint.Y = -e.Y - SystemInformation.CaptionHeight - SystemInformation.FrameBorderSize.Height;
                formMove = true;//开始移动
            }
        }

        private void PictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (formMove == true)
            {
                Point mousePos = Control.MousePosition;
                mousePos.Offset(formPoint.X, formPoint.Y);
                Location = mousePos;
            }
        }

        private void PictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)//按下的是鼠标左键
            {
                formMove = false;//停止移动
            }
        }
    }
}
