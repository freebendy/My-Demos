using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace _2._0TransparentWindow
{
    public partial class Form1 : Form
    {
        private Image m_img = null;//首先定义私有变量
        private EventHandler evtHandler = null;

        public Form1()
        {
            InitializeComponent();

            //this.Load += Form1_Load;
            this.Load += gifFrm_Load;
        }

        //重载当前winform的OnPaint方法，当界面被重绘时去显示当前gif显示的某一帧
        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            if (m_img != null)
            {

                //获得当前gif动画下一步要渲染的帧。
                UpdateImage();

                //将获得的当前gif动画需要渲染的帧显示在界面上的某个位置。
                e.Graphics.DrawImage(m_img, new Rectangle(145, 140, m_img.Width, m_img.Height));
            }
        }
        //实现Load方法

        private void gifFrm_Load(object sender, EventArgs e)
        {
            evtHandler = new EventHandler(OnImageAnimate);//为委托关联一个处理方法
            string fileName = Application.StartupPath + "\\1.gif";//获取要加载的gif动画文件
            if (System.IO.File.Exists(fileName) == true)
            {
                m_img = Image.FromFile(fileName);

                BeginAnimate();//调用开始动画方法
            }
        }

        private void BeginAnimate()//开始动画方法
        {
            if (m_img != null)
            {
                //当gif动画每隔一定时间后，都会变换一帧那么就会触发一事件，该方法就是将当前image每变换一帧时，都会调用当前这个委托所关联的方法。
                ImageAnimator.Animate(m_img, evtHandler);
            }
        }

        private void OnImageAnimate(Object sender, EventArgs e)//委托所关联的方法
        {
            this.Invalidate();//该方法中，只是使得当前这个winform重绘，然后去调用该winform的OnPaint（）方法进行重绘)
        }

        private void UpdateImage()
        {//获得当前gif动画的下一步需要渲染的帧，当下一步任何对当前gif动画的操作都是对该帧进行操作
            ImageAnimator.UpdateFrames(m_img);
        }

        private void StopAnimate()
        {//关闭显示动画，该方法可以在winform关闭时，或者某个按钮的触发事件中进行调用，以停止渲染当前gif动画。
            m_img = null;
            ImageAnimator.StopAnimate(m_img, evtHandler);
        }

        //关闭动画

        private void gifFrm_FormClosing(object sender, FormClosingEventArgs e)
        {
            StopAnimate();
        }

        /***                                                ***/
        private void Form1_Load(object sender, EventArgs e)
        {
            this.SetWindowTransparent(100);
        }

        private void SetWindowTransparent(byte bAlpha)
        {
            try
            {
                WinAPI.SetWindowLong(this.Handle, (int)WinAPI.WindowStyle.GWL_EXSTYLE,
                    WinAPI.GetWindowLong(this.Handle, (int)WinAPI.WindowStyle.GWL_EXSTYLE) | (uint)WinAPI.ExWindowStyle.WS_EX_LAYERED);

                WinAPI.SetLayeredWindowAttributes(this.Handle, 0, bAlpha, WinAPI.LWA_COLORKEY | WinAPI.LWA_ALPHA);
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams cp = base.CreateParams;

                cp.Parent = WinAPI.GetDesktopWindow();
                cp.ExStyle = 0x00000080 | 0x00000008;//WS_EX_TOOLWINDOW | WS_EX_TOPMOST

                return cp;
            }
        }
        /***                                                ***/
    }
}
