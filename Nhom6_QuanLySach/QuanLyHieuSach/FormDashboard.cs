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
    public partial class FormDashboard : Form
    {

        private DataProvider dataProvider = new DataProvider();
        public FormDashboard()
        {
            InitializeComponent();
            load();
        }


        public void load()
        {
            DataTable dt2 = new DataTable();
            StringBuilder query2 = new StringBuilder("SELECT * FROM HoaDon");
            dt2 = dataProvider.execQuery(query2.ToString());
            dsHoaDon.DataSource = dt2;


            Dictionary<DateTime, int> ThongKe = new Dictionary<DateTime, int>();
            Dictionary<string, int> topUser = new Dictionary<string, int>();
            for (int i = 0; i < dsHoaDon.RowCount - 1; i++)
            {
                string temp = dsHoaDon.Rows[i].Cells["ThoiGian"].Value.ToString();
                DateTime datetime = DateTime.Parse(temp);
                DateTime date = datetime.Date;

                string temp1 = dsHoaDon.Rows[i].Cells["NguoiDung_UserName"].Value.ToString();


                int money = Convert.ToInt32(dsHoaDon.Rows[i].Cells["TongTien"].Value);
                if (!ThongKe.ContainsKey(date)) ThongKe.Add(date, 0);
                ThongKe[date] += money;

                if (!topUser.ContainsKey(temp1)) topUser.Add(temp1, 0);
                topUser[temp1] += money;

            }

            foreach (KeyValuePair<DateTime, int> product in ThongKe)
                doanhThuChart.Series["Series1"].Points.AddXY(product.Key, product.Value);

            foreach (KeyValuePair<string, int> product in topUser)
            {
                DataGridViewRow newRow = new DataGridViewRow();
                newRow.CreateCells(guna2DataGridView1);
                newRow.Cells[0].Value = product.Key;  // Điều chỉnh tên cột phù hợp
                newRow.Cells[1].Value = product.Value;
                guna2DataGridView1.Rows.Add(newRow);
            }

        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {

        }

        private void guna2Button2_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void guna2CircleProgressBar2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void guna2ProgressBar2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void guna2GradientPanel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void guna2GradientPanel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
