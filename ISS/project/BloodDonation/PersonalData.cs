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
    public partial class PersonalData : Form
    {
        private string email, password;
        Donor donor;
        LoginController controller;
        public PersonalData()
        {
            InitializeComponent();
        }

        public PersonalData(string email, string password)
        {
            this.email = email;
            this.password = password;
            controller = new LoginController();
            InitializeComponent();
        }
        public PersonalData(Donor d)
        {
            InitializeComponent();
            donor = d;
            FirstNameTextBox.Text = donor.Person.name;
            LastNameTextBox.Text = donor.Person.surname;
            phoneNumberTextBox.Text = donor.Person.phoneNr;
            DoBDatePicker.Text = donor.Person.birthdate.ToShortDateString();
            GenderComboBox.Text = donor.Person.gender;
            CityComboBox.Text = donor.Person.Location.city;
            AddressTextBox.Text = donor.Person.address;
            CurrentCityComboBox.Text = donor.Person.Location.city;
            CurrentAddressTextBox.Text = donor.Person.actualAddress;
        }


        private void SavePersonalButton_Click(object sender, EventArgs e)
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

            this.controller.Register(this.email, name, surname, gender, phone, birtDate, this.password, address, currentAddress, city, currentCity);

        }

        private void FirstNameTextBox_Click(object sender, EventArgs e)
        {
            FirstNameTextBox.Text = "";
        }

        private void LastNameTextBox_Click(object sender, EventArgs e)
        {
            LastNameTextBox.Text = "";
        }

        private void phoneNumberTextBox_Click(object sender, EventArgs e)
        {
            phoneNumberTextBox.Text = "";
        }

        private void AddressTextBox_Click(object sender, EventArgs e)
        {
            AddressTextBox.Text = "";
        }

        private void CurrentAddressTextBox_Click(object sender, EventArgs e)
        {
            CurrentAddressTextBox.Text = "";
        }

    }
}
