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
	public partial class FormDaBan : Form
	{
        private DataProvider dataProvider = new DataProvider();
        public FormDaBan()
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
        }

		private void guna2PictureBox1_Click(object sender, EventArgs e)
		{

		}

		private void guna2PictureBox4_Click(object sender, EventArgs e)
		{

		}

        private void dsHoaDon_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        int idHoaDon;
        string nameNB;
        private void dsHoaDon_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int rowId = e.RowIndex;
            if (rowId < 0) rowId = 0;
            if (rowId == dsHoaDon.RowCount - 1) rowId = rowId - 1;

            DataGridViewRow row = dsHoaDon.Rows[rowId];
            idHoaDon = (int)row.Cells[0].Value;
            nameNB = row.Cells[1].Value.ToString();
            idHD.Text = row.Cells[0].Value.ToString();
            nameStaff.Text = row.Cells[1].Value.ToString();
            dateTime.Text = row.Cells[2].Value.ToString();
            totalHD.Text = row.Cells[3].Value.ToString();
        }

        private void chiTietHD_Click(object sender, EventArgs e)
        {

            ChiTietHoaDon chiTietHoaDon = new ChiTietHoaDon(idHoaDon, nameNB);
            chiTietHoaDon.Show();
        }
    }
}
