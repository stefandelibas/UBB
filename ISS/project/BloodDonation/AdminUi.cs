using BloodDonation.Controllers;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BloodDonation
{
    public partial class AdminUi : Form
    {
        LoginController controller;
        public AdminUi()
        {
            InitializeComponent();
            controller = new LoginController();
        }

        private void MenuRegisterDoctorButton_Click(object sender, EventArgs e)
        {
            this.RegisterDoctorDGV.BringToFront();
            this.FirstNameTextBox.BringToFront();
            this.LastNameTextBox.BringToFront();
            this.DoBDatePicker.BringToFront();
            this.CityComboBox.BringToFront();
            this.CurrentAddressTextBox.BringToFront();
            this.CurrentCityComboBox.BringToFront();
            this.AddressTextBox.BringToFront();
            this.phoneNumberTextBox.BringToFront();
            this.GenderComboBox.BringToFront();
            this.RegisterDoctorButton.BringToFront();


        }

        private void MenuRegisterDcpButton_Click(object sender, EventArgs e)
        {
            this.RegisterDcpDGV.BringToFront();
            this.RegisterDcpButton.BringToFront();
            this.EmailDcpTextBox.BringToFront();
            this.PasswordDCPTextBox.BringToFront();
            this.ConfirmPassDcpTextBox.BringToFront();
        }

        private void RegisterDoctorButton_Click(object sender, EventArgs e)
        {
            string name = FirstNameTextBox.Text;
            string surname = LastNameTextBox.Text;
            string phone = phoneNumberTextBox.Text;
            DateTime birtDate = this.DoBDatePicker.Value.Date;
            string gender = this.GenderComboBox.Text;
            string city = this.CityComboBox.Text;
            string currentCity = this.CurrentCityComboBox.Text;
            string address = this.AddressTextBox.Text;
            string currentAddress = this.CurrentAddressTextBox.Text;
            if (this.DoctorConfirmPassTextBox != this.DoctorPassTextBox)
            {
                string message = "Passwords do not match!";
                string caption = "Error!";
                MessageBoxButtons buttons = MessageBoxButtons.OK;
                DialogResult result;

                // Displays the MessageBox.

                result = MessageBox.Show(message, caption, buttons);

                if (result == System.Windows.Forms.DialogResult.OK)
                {

                }
            }
            else
            {
                this.controller.RegisterDoctor(this.DoctorMailTextBox.Text, name, surname, gender, phone, birtDate, this.DoctorPassTextBox.Text, address, currentAddress, city, currentCity);

            }

        }

        private void RegisterDcpButton_Click(object sender, EventArgs e)
        {
            if (this.ConfirmPassDcpTextBox != this.PasswordDCPTextBox)
            {
                string message = "Passwords do not match!";
                string caption = "Error!";
                MessageBoxButtons buttons = MessageBoxButtons.OK;
                DialogResult result;

                // Displays the MessageBox.

                result = MessageBox.Show(message, caption, buttons);

                if (result == System.Windows.Forms.DialogResult.OK)
                {

                }
            }
            else
            {
                this.controller.RegisterDCP(this.EmailDcpTextBox.Text, this.PasswordDCPTextBox.Text);

            }
        }
    }
}
