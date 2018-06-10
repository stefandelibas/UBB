using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using BloodDonation.controllers;
using BloodDonation.Controllers;
using BloodDonation.Utils;

namespace BloodDonation
{
    public partial class Form1 : Form
    {
        LoginController loginCtrl = new LoginController();
        IController controller;

        public Form1()
        {
            InitializeComponent();
          
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dataGridView1.BringToFront();
            UsernameLoginTextBox.BringToFront();
            PasswordLoginTextBox.BringToFront();
            LoginButton.BringToFront();
            this.LoginSwitchButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(96)))), ((int)(((byte)(85)))));
            this.RegisterSwitchButton.BackColor = System.Drawing.Color.DarkGray; 
        }

        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            String email = UsernameLoginTextBox.Text;
            String password = PasswordLoginTextBox.Text;

            try
            {
                this.CheckCredidentialsLogin(email, password);
            }

            catch (InvalidConstraintException ex)
            {
                string message = ex.Message;
                string caption = "Error!";
                MessageBoxButtons buttons = MessageBoxButtons.OK;
                DialogResult result;

                // Displays the MessageBox.

                result = MessageBox.Show(message, caption, buttons);

                if (result == System.Windows.Forms.DialogResult.OK)
                {
                    
                }
            }
            
        }

        private void CheckCredidentialsLogin(string email, string password)
        {
            if (this.loginCtrl.VerifyEmailExist(email) == false)
            {
                this.controller = this.loginCtrl.InitializeEnviroment(email);
                string encriptedPassword = Cryptograph.Encrypt(password, email);
                if (this.loginCtrl.CheckPassword(email, encriptedPassword) == true)
                {
                   
                    if (controller.GetType() == typeof(DonorController))
                    {
                        DonorUi donorUi = new DonorUi(email);
                        donorUi.Show();
                    }
                    else
                    if (controller.GetType() == typeof(DoctorController))
                    {
                        DoctorUi doctorUi = new DoctorUi(email,controller);
                        doctorUi.Show();
                    }
                    else
                    if (controller.GetType() == typeof(DCPController))
                    {
                        DCPCenter dcpCenterUi = new DCPCenter(email,controller);
                        dcpCenterUi.Show();
                    }
                    else
                    {
                        AdminUi adminUi = new AdminUi();
                        adminUi.Show();
                        this.Hide();
                    }
                    this.Hide();

                }
                else
                {
                    throw new InvalidConstraintException("Wrong password!");
                }
            }
            else
            {
                throw new InvalidConstraintException("Invalid email!");
            }

        }

        public void CheckCredidentials(String email, String password, String passwordVerification)
        {
            if (this.loginCtrl.VerifyEmailRegex(email) == true)
            {
                if (this.loginCtrl.VerifyEmailExist(email) == true)
                {
                    if (this.loginCtrl.VerifyPassword(password, passwordVerification) == true)
                    {
                        string encriptedPassword = Cryptograph.Encrypt(password, email);

                        PersonalData personalData = new PersonalData(email, encriptedPassword);
                        personalData.Show();
                        
                    }
                    else
                    {
                        throw new Exception("Passwords do not match!");
                    }

                }
                else
                {
                    throw new Exception("This email already exists!");
                }
            }
            else
            {
                throw new Exception("Please insert a valid email address!");
            }
        }

        private void RegisterButton_Click(object sender, EventArgs e)
        {
            dataGridView2.BringToFront();
            VerifyPassRegisterTextBox.BringToFront();
            RegisterUsernameTextBox.BringToFront();
            RegisterPassTextBox.BringToFront();
            RegisterButton.BringToFront();
            this.LoginSwitchButton.BackColor = System.Drawing.Color.DarkGray;
            this.RegisterSwitchButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(96)))), ((int)(((byte)(85))))); 


        }

        private void button3_Click(object sender, EventArgs e)
        {
            string user = RegisterUsernameTextBox.Text;
            string pass = RegisterPassTextBox.Text;
            string verifypass = VerifyPassRegisterTextBox.Text;
            this.CheckCredidentials(user, pass, verifypass);
            //this.Hide();
        }

        private void maskedTextBox1_Click(object sender, EventArgs e)
        {
            UsernameLoginTextBox.Text = "";
        }
        private void maskedTextBox2_Click(object sender, EventArgs e)
        {
            PasswordLoginTextBox.Text = "";
        }
        private void maskedTextBox3_Click(object sender, EventArgs e)
        {
            VerifyPassRegisterTextBox.Text = "";
        }
        private void maskedTextBox4_Click(object sender, EventArgs e)
        {
            RegisterUsernameTextBox.Text = "";
        }
        private void maskedTextBox5_Click(object sender, EventArgs e)
        {
            RegisterPassTextBox.Text = "";

        }
    }
}
