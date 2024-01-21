using Guna.UI2.WinForms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class FormChinh : Form
    {

        public User LoggedInUser { get; set; }
        public FormChinh()
        {
            InitializeComponent();
        }

        public FormChinh(User LoggedInUser)
        {
            InitializeComponent();

            label_val.Text = "Trang Chủ";
            guna2PictureBox_val.Image = Properties.Resources.house;
            container(new FormDashboard());
            label1.Text = LoggedInUser.Ten;
        }





        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void guna2Button1_CheckedChanged(object sender, EventArgs e)
        {
			
		}

		private void guna2Button2_Click(object sender, EventArgs e)
		{
			label_val.Text = "Danh Sách Hàng";
			guna2PictureBox_val.Image = Properties.Resources.shopping_bag;
            FormBanHang fbh = new FormBanHang();
			fbh.LoggedInUser = LoggedInUser;

            container(fbh);

		}

		private void panel2_Paint(object sender, PaintEventArgs e)
		{

		}


		
		private void guna2PictureBox1_Click(object sender, EventArgs e)
		{
            
            FormLogin f1 = new FormLogin();
            f1.Show();
			this.Hide();
        }

		// Tạo tab dashboard
		private void container(object _form)
        {
            if(guna2Panel_container.Controls.Count > 0) guna2Panel_container.Controls.Clear();

            Form fm = _form as Form;    
            fm.TopLevel = false;
            fm.FormBorderStyle = FormBorderStyle.None;
            fm.Dock = DockStyle.Fill;
            guna2Panel_container.Controls.Add(fm);
            guna2Panel_container.Tag = fm;
            fm.Show();
            
        }

		private void guna2Panel_container_Paint(object sender, PaintEventArgs e)
		{
			
		}

		private void guna2Button1_Click(object sender, EventArgs e)
		{
            label_val.Text = "Trang Chủ";
			guna2PictureBox_val.Image = Properties.Resources.house;
			container(new FormDashboard());
        }

		private void guna2ControlBox4_Click(object sender, EventArgs e)
		{

		}

		private void label1_Click(object sender, EventArgs e)
		{

		}

		private void guna2Button4_Click(object sender, EventArgs e)
		{
			label_val.Text = "Danh Sách Đã Bán";
			guna2PictureBox_val.Image = Properties.Resources.shopping_list;
			container(new FormDaBan());
		}

		private void guna2Panel1_Paint(object sender, PaintEventArgs e)
		{

		}

		private void guna2ControlBox1_Click(object sender, EventArgs e)
		{

		}

		private void guna2Button3_Click(object sender, EventArgs e)
		{
            label_val.Text = "Sản phẩm";
            guna2PictureBox_val.Image = Properties.Resources.bookshop;
            container(new FormSP());
        }

        private void doanhThuChart_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

		private void guna2PictureBox2_Click(object sender, EventArgs e)
		{

		}
	}
}
