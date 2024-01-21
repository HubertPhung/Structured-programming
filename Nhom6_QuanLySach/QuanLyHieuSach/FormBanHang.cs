using System;
using System.Collections;
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
	public partial class FormBanHang : Form
	{
        private DataProvider dataProvider = new DataProvider();

        public User LoggedInUser { get; set; }
        public FormBanHang()
		{
			InitializeComponent();
            load();
		}

        private int id;

        public void load()
        {
            DataTable dt1 = new DataTable();
            StringBuilder query1 = new StringBuilder("SELECT ID, Ten, Gia, SoLuong FROM Sach");
            dt1 = dataProvider.execQuery(query1.ToString());
            dsTimKiem.DataSource = dt1;

        }

        private void dsTimKiem_CellClick(object sender, DataGridViewCellEventArgs e)
		{
            int rowId = e.RowIndex;
            if (rowId < 0) rowId = 0;
            if (rowId == dsTimKiem.RowCount - 1) rowId = rowId - 1;

            DataGridViewRow row = dsTimKiem.Rows[rowId];
            id = (int)row.Cells[0].Value;
            bookID.Text = id.ToString();
            bookName.Text = row.Cells[1].Value.ToString();

            stock = Convert.ToInt32(row.Cells[3].Value);
            bookPrice.Text = row.Cells[2].Value.ToString();
        }

		
		
		
		

		private void btnHuy_Click_1(object sender, EventArgs e)
		{
            int indexOfRow = dsChon.CurrentCell.RowIndex;
            dsChon.Rows.RemoveAt(indexOfRow);
            int tongSoTien = getTotalHD();
            txtTongTien.Text = tongSoTien.ToString();
        }

		private void panel3_Paint(object sender, PaintEventArgs e)
		{

		}
        int stock;

        private void btnChon_Click_1(object sender, EventArgs e)
        {
            int n = 0;
            if (bookNumber.Value == 0 || Convert.ToInt32(bookNumber.Value) > stock)
            {
                MessageBox.Show("Kho con hang ton", "Canh bao", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                int total = Convert.ToInt32(bookNumber.Value) * Convert.ToInt32(bookPrice.Text);
                int newQty = stock - Convert.ToInt32(bookNumber.Value);

                string query = "update Sach set SoLuong = " + newQty + " where ID = " + id;

                int dt = dataProvider.execNonQuery(query);



                load();

                DataGridViewRow newRow = new DataGridViewRow();

                newRow.CreateCells(dsChon);
                newRow.Cells[0].Value = id;
                newRow.Cells[1].Value = bookName.Text;
                newRow.Cells[2].Value = bookPrice.Text;
                newRow.Cells[3].Value = bookNumber.Value;

                newRow.Cells[4].Value = total;
                dsChon.Rows.Add(newRow);
                int tongSoTien = getTotalHD();
                txtTongTien.Text = tongSoTien.ToString();
            }
        }

        private void btnSearch_Click_2(object sender, EventArgs e)
        {
            DataTable dt = new DataTable();
            StringBuilder query = new StringBuilder("SELECT ID, Ten, Gia, SoLuong FROM Sach WHERE Ten = '" + search.Text + "'");

            dt = dataProvider.execQuery(query.ToString());
            dsTimKiem.DataSource = dt;
        }

        public int getTotalHD()
        {
            int total = 0;
            for (int i = 0; i < dsChon.RowCount; i++)
            {
                total += Convert.ToInt32(dsChon.Rows[i].Cells["Column5"].Value);
            }
            return total;
        }

        private void btnMua_Click_1(object sender, EventArgs e)
        {
            DateTime now = DateTime.Now;

            StringBuilder query = new StringBuilder("EXEC proc_hoa_don ");
            query.Append("@NguoiDung_UserName = '" + LoggedInUser.userName + "'");
            query.Append(",@ThoiGian = '" + now.ToString("yyyy-MM-dd HH:mm:ss") + "'");
            query.Append(",@TongTien = " + txtTongTien.Text + "");

            int result = Convert.ToInt32(dataProvider.execScaler(query.ToString()));



            StringBuilder query1 = new StringBuilder("INSERT INTO ChiTietHoaDon (DonHangID, SachID, SoLuong, TongTien) VALUES ");
            for (int i = 0; i < dsChon.RowCount; i++)
            {

                query1.Append($"({result}, {dsChon.Rows[i].Cells["Column1"].Value}, {dsChon.Rows[i].Cells["Column4"].Value}, {dsChon.Rows[i].Cells["Column5"].Value})");
                if (i < dsChon.RowCount - 1) query1.Append(", ");
            }



            int result1 = dataProvider.execNonQuery(query1.ToString());

            if (result > 0)
            {
                load();
                MessageBox.Show("Ban thanh cong!", "Thanh cong", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);

            }
            else
            {
                MessageBox.Show("Ban khong thanh cong!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            DataTable dt = new DataTable();
            StringBuilder query = new StringBuilder("SELECT ID, Ten, Gia, SoLuong FROM Sach WHERE Ten = '" + search.Text + "'");

            dt = dataProvider.execQuery(query.ToString());
            dsTimKiem.DataSource = dt;
        }
    }
}
