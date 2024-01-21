using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp3
{
    internal class DataProvider
    {
        private string connectString = @"Data Source=DESKTOP-ODC3GVJ\SQLEXPRESS;Initial Catalog=QuanLiSach;Integrated Security=True";

        public DataTable execQuery (string query)
        {
            DataTable data = new DataTable();
            using (SqlConnection con = new SqlConnection(connectString))
            {
                con.Open();
                SqlCommand cmd = new SqlCommand(query, con);
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                adapter.Fill(data);
                con.Close();
            }
            return data;
        }

        public int execNonQuery (string query)
        {
            int data = 0;
            using (SqlConnection con = new SqlConnection(connectString))
            {
                con.Open();
                SqlCommand cmd = new SqlCommand(query, con);
                data = cmd.ExecuteNonQuery();
                con.Close();
            }
            return data;
        }


        public object execScaler(string query)
        {
            object data = 0;
            using (SqlConnection con = new SqlConnection(connectString))
            {
                con.Open();
                SqlCommand cmd = new SqlCommand(query, con);    
                data = cmd.ExecuteScalar();
                con.Close();
            }
            return (data);
        }

        public SqlDataReader execReader(string query)
        {
            SqlConnection con = new SqlConnection(connectString);
            con.Open();
            try
            {
                SqlCommand cmd = new SqlCommand(query, con);
                SqlDataReader data = cmd.ExecuteReader(CommandBehavior.CloseConnection);
                return data;
            }
            catch
            {
                con.Close(); // Đảm bảo kết nối được đóng trong trường hợp xảy ra ngoại lệ
                throw; // Ném lại ngoại lệ để thông báo về lỗi
            }
        }
       /* public DataTable readData(string query)
        {


            DataTable data = new DataTable();
            SqlConnection con = new SqlConnection(connectString);


                if (con.State == ConnectionState.Closed)
                {
                    con.Open();
                }
                try
                {
                    SqlCommand cmd = new SqlCommand(query, con);
                    SqlDataAdapter da = new SqlDataAdapter(cmd);
                    da.Fill(data);
                }
                catch (Exception)
                {
                    data = null;
                }
                if(con.State == ConnectionState.Open)
                {
                    con.Close();
                }
            
            
            return data;
        }*/
    }
}
