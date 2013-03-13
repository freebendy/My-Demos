using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace _2._0TransparentWindow
{
    class WinAPI
    {
        [DllImport("user32.dll")]
        public extern static IntPtr GetDesktopWindow();

        [DllImport("user32.dll")]
        public extern static bool SetLayeredWindowAttributes(IntPtr hwnd, uint crKey, byte bAlpha, uint dwFlags);
        public static uint LWA_COLORKEY = 0x00000001;
        public static uint LWA_ALPHA = 0x00000002;

        [DllImport("user32.dll")]
        public extern static uint SetWindowLong(IntPtr hwnd, int nIndex, uint dwNewLong);
        [DllImport("user32.dll")]
        public extern static uint GetWindowLong(IntPtr hwnd, int nIndex);

        public enum WindowStyle : int
        {
            GWL_EXSTYLE = -20
        }

        public enum ExWindowStyle : uint
        {
            WS_EX_LAYERED = 0x00080000
        } 
    }
}
