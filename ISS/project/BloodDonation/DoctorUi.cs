using BloodDonation.controllers;
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
    public partial class DoctorUi : Form
    {
        private Doctor doctor;
        private DoctorController ctrl ;
        public DoctorUi()
        {
            InitializeComponent();
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                welcomeLabel.Text = "Welcome, " + doctor.Person.name + " " + doctor.Person.surname + "!";
            }

        }
        public DoctorUi(string email, IController c)
        {
            InitializeComponent();
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                this.doctor = context.Doctors.Where(x => x.id == email).Select(x => x).ToList()[0];
                welcomeLabel.Text = "Welcome, " + doctor.Person.name + " " + doctor.Person.surname + "!";
            }
            ctrl = new DoctorController(this.doctor);

        }

        private void RequestBloodButton_Click(object sender, EventArgs e)
        {
            string patientName = this.patientNameTextBox.Text;
            int bloodNeeded = Convert.ToInt32(this.BloodNeededTextBox.Text);
            string rh = this.RhDComboBox.Text;
            string bloodGroup = this.BloodGroupComboBox.Text + rh[rh.Length-1];
            string severity = this.SeverityComboBox.Text;
            string dcpmail = this.donationCenterMail.Text;
            ctrl.FillRequest(patientName, bloodNeeded, bloodGroup, severity, dcpmail);
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void MenuReqBloodButton_Click(object sender, EventArgs e)
        {
            this.RequestBloodDGV.BringToFront();
            this.BloodNeededTextBox.BringToFront();
            this.patientNameTextBox.BringToFront();
            this.BloodGroupComboBox.BringToFront();
            this.RhDComboBox.BringToFront();
            this.SeverityComboBox.BringToFront();
            this.donationCenterMail.BringToFront();
            this.RequestBloodButton.BringToFront();
            this.label1.BringToFront();
            this.label2.BringToFront();
            this.label3.BringToFront();
            this.label4.BringToFront();
            this.label5.BringToFront();
            this.label6.BringToFront();
            this.pictureBox2.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();

        }

        private void MenuViewPacientButton_Click(object sender, EventArgs e)
        {
            this.PacientInfoDGV.BringToFront();
            this.pacientNameInfoTextBox.BringToFront();
            this.SeverityInfoTextBox.BringToFront();
            this.RequestStatusInfoTextBox.BringToFront();
            this.ViewPacientInfoButton.BringToFront();
            this.label7.BringToFront();
            this.label9.BringToFront();
            this.label10.BringToFront();
            this.label12.BringToFront();
            this.label13.BringToFront();
            this.BloodGroupInfoTextBox.BringToFront();
            this.BloodNeededInfoTextBox.BringToFront();
            this.pictureBox2.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();

        }

        private void ViewPacientInfoButton_Click(object sender, EventArgs e)
        {

            Request request = null;
            try
            {
                request = ctrl.TrackRequest(this.pacientNameInfoTextBox.Text);
                this.RequestStatusInfoTextBox.Text = request.status;
                this.SeverityInfoTextBox.Text = request.severity_level;
                this.BloodNeededInfoTextBox.Text = request.Patient.bloodNeeded.ToString();
                this.BloodGroupInfoTextBox.Text = request.Patient.bloodGroup;
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

        private void HomeButton_Click(object sender, EventArgs e)
        {
            HomeDFV.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();
            welcomeLabel.BringToFront();
            bigMascotPictureBox.BringToFront();
        }

        private void LogOutButton_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 logout = new Form1();
            logout.Show();
        }

        private void HomeDFV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void bigMascotPictureBox_Click(object sender, EventArgs e)
        {

        }

        private void LogOutButton_Click_1(object sender, EventArgs e)
        {

        }

        private void ViewAllPacientsButton_Click(object sender, EventArgs e)
        {
            ViewAllPacientsDGV.BringToFront();
            ViewAllPacientsContentDGV.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();
            pictureBox2.BringToFront();
            


            List<Patient> patientsList = ctrl.GetPatients();
            string[] patients = new string[patientsList.Count];
            int i = 0;
            foreach (Patient patient in patientsList)
            {
                patients[i] = patient.name;
                i++;
            }

            ViewAllPacientsContentDGV.Rows.Clear();
            ViewAllPacientsContentDGV.Refresh();

            for (i = 0; i < patientsList.Count; i++)
            {
                ViewAllPacientsContentDGV.Rows.Add(new object[] { patients[i] });
            }

            this.ViewAllPacientsContentDGV.CellContentClick += (sender2, e2) => ViewAllPacientsContentDGV_CellContentClick(sender2, e2, patients[e2.RowIndex]);

        }

        private void ViewAllPacientsContentDGV_CellContentClick(object sender, DataGridViewCellEventArgs e, string patientName)
        {
            this.PacientInfoDGV.BringToFront();
            this.pacientNameInfoTextBox.BringToFront();
            this.SeverityInfoTextBox.BringToFront();
            this.RequestStatusInfoTextBox.BringToFront();
            this.ViewPacientInfoButton.BringToFront();
            this.label7.BringToFront();
            this.label9.BringToFront();
            this.label10.BringToFront();
            this.label12.BringToFront();
            this.label13.BringToFront();
            this.BloodGroupInfoTextBox.BringToFront();
            this.BloodNeededInfoTextBox.BringToFront();
            this.pictureBox2.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();

            pacientNameInfoTextBox.Text = patientName;

            Request request = null;
            try
            {
                request = ctrl.TrackRequest(this.pacientNameInfoTextBox.Text);
                this.RequestStatusInfoTextBox.Text = request.status;
                this.SeverityInfoTextBox.Text = request.severity_level;
                this.BloodNeededInfoTextBox.Text = request.Patient.bloodNeeded.ToString();
                this.BloodGroupInfoTextBox.Text = request.Patient.bloodGroup;
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

        
    }
}
