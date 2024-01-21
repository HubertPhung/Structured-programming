using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class ChiTietHoaDon : Form
    {
        DataProvider dataProvider = new DataProvider();
        public ChiTietHoaDon()
        {
            InitializeComponent();
        }

        public ChiTietHoaDon(int idHoaDon, string userName)
        {
            InitializeComponent();
            DataTable dt = new DataTable();
            StringBuilder query = new StringBuilder("SELECT * FROM ChiTietHoaDon WHERE DonHangID = " + idHoaDon);
            dt = dataProvider.execQuery(query.ToString());
            dsMua.DataSource = dt;


            StringBuilder query1 = new StringBuilder("SELECT * FROM NguoiDung WHERE userName = '" + userName + "'");
            SqlDataReader dt1 = dataProvider.execReader(query1.ToString());


            if (dt1.Read())
            {
                textBox1.Text = dt1["Ten"].ToString();

            }


            textBox2.Text = getTotalHD().ToString();

        }

        public int getTotalHD()
        {
            int total = 0;
            for (int i = 0; i < dsMua.RowCount - 1; i++)
            {
                total += Convert.ToInt32(dsMua.Rows[i].Cells["TongTien"].Value);
            }
            return total;
        }

        private void dsMua_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
