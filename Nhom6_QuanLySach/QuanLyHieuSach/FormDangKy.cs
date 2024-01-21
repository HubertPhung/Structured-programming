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
	public partial class FormDangKy : Form
	{
        private DataProvider dataProvider = new DataProvider();
        public FormDangKy()
		{
			InitializeComponent();
		}
        private void SignupBtn_Click(object sender, EventArgs e)
        {


            try
            {
                if (signup_name.Text == "") MessageBox.Show("You haven't written your name yet");
                else if (signup_username.Text == "") MessageBox.Show("You haven't written your username yet");
                else if (signup_password.Text == "") MessageBox.Show("You haven't written your password yet");
                else if (signup_repass.Text != signup_password.Text || signup_password.Text == "" && signup_password.Text == "")
                    MessageBox.Show("Re-type password does not match", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                else
                {
                    StringBuilder query = new StringBuilder("EXEC proc_dangki ");
                    query.Append("@Ten = N'" + signup_name.Text + "'");
                    query.Append(",@userName = '" + signup_username.Text + "'");
                    query.Append(",@pass = '" + signup_password.Text + "'");

                    int result = dataProvider.execNonQuery(query.ToString());

                    if (result > 0)
                    {
                        MessageBox.Show("Dang ki thanh cong!", "Thanh cong", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        FormLogin LogIn = new FormLogin();
                        LogIn.Show();
                        this.Hide();
                    }
                    else
                    {
                        MessageBox.Show("Dang ki khong thanh cong!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

                    }
                }
            }
            catch
            {
                MessageBox.Show("Already have this account", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void signup_loginBtn_Click(object sender, EventArgs e)
        {
            FormLogin LogIn = new FormLogin();
            LogIn.Show();
            this.Hide();
        }
    }
}
