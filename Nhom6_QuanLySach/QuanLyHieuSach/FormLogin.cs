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
    public partial class FormLogin : Form
    {
        private DataProvider dataProvider = new DataProvider();
        private User loggedInUser;
        public FormLogin()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

		private void guna2PictureBox1_Click(object sender, EventArgs e)
		{

		}

        private void loginBtn_Click(object sender, EventArgs e)
        {
            string query = "SELECT * FROM NguoiDung WHERE userName = '" + login_username.Text + "' AND pass = '" + login_password.Text + "'";
            SqlDataReader reader = dataProvider.execReader(query.ToString());

            if (reader.HasRows)
            {
                if (reader.Read())
                {

                    MessageBox.Show("Succedd login", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    loggedInUser = new User
                    {
                        Ten = reader["Ten"].ToString(),
                        userName = reader["userName"].ToString(),
                    };
                    FormChinh fm = new FormChinh(loggedInUser);
                    fm.Show();
                    fm.LoggedInUser = loggedInUser;
                    this.Hide();

                }
            }
            else
            {
                login_username.Text = "";
                login_password.Text = "";
                MessageBox.Show("Incorect username or password", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void guna2Button2_Click_1(object sender, EventArgs e)
        {
            FormDangKy regForm = new FormDangKy();

            regForm.Show();
            this.Hide();
        }

        private void login_showPass_CheckedChanged(object sender, EventArgs e)
        {
            login_password.PasswordChar = login_showPass.Checked ? '\0' : '●';
        }
    }
}
