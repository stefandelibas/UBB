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
    public partial class DCPCenter : Form
    {
        Donation_Center donation_Center;
        DCPController ctrl;
        Request request = null;
        Blood_Donation bloodDonation = null;

        public DCPCenter()
        {
            InitializeComponent();
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                welcomeLabel.Text = "Welcome!";
            }
        }

        public DCPCenter(string email, IController c)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                this.donation_Center = context.Donation_Centers.Where(x => x.email == email).Select(x => x).ToList()[0];
            }
            ctrl = new DCPController(donation_Center);
            InitializeComponent();
            
           
        }
        public DCPCenter(string email)
        {
            InitializeComponent();
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                this.donation_Center = context.Donation_Centers.Where(x => x.email == email).Select(x => x).ToList()[0];
            }
            InitializeComponent();

        }

        private void SaveRequestButton2_Click(object sender, EventArgs e)
        {
            String message = MessageTextBox.Text;
            String bloodGroup = bloodGroupComboBox.Text + RhDComboBox.Text;
            List<Person> persons = ctrl.GetClosestDonor();
            List<Person> availableDonors = new List<Person>();
            foreach (Person person in persons)
            {
                if (person.bloodGroup == bloodGroup)
                {
                    availableDonors.Add(person);
                }
            }
            if (availableDonors.Count > 0)
            {
                ctrl.SendRequest(availableDonors[0], message);
            }
            else
            {
                MessageBox.Show("There are no available donors at this moment !", "Ups", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void richTextBox1_Click(object sender, EventArgs e)
        {
            MessageTextBox.Text = "";
        }

        private void SendRequestButton_Click(object sender, EventArgs e)
        {
            this.SendRequestMessageDGV.BringToFront();
            this.MessageTextBox.BringToFront();
            this.bloodGroupComboBox.BringToFront();
            this.RhDComboBox.BringToFront();
            this.SaveRequestButton2.BringToFront();
            this.HomeButton.BringToFront();
            this.LogOutButton.BringToFront();
            this.pictureBox2.BringToFront();
        }

        private void dataGridView3_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            int requestID = Int32.Parse(ManageRequestsContentDGV.Rows[e.RowIndex].Cells["ID"].Value as String);

            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                this.request = context.Requests
                    .Where(r => r.idRequest == requestID)
                    .Select(r => r)
                    .ToList()[0];
            }
           
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.ManageRequestsDGV.BringToFront();
            this.ManageRequestsContentDGV.BringToFront();
            this.ProccessRequestButton.BringToFront();
            //this.CompleteRequestButton.BringToFront();
            List<Request> reqList = ctrl.getReqRepo().GetElements();


            string[] dates = new string[100];
            string[] status = new string[100];
            string[] severity = new string[100];
            string[] patients = new string[100];
            string[] doctors = new string[100];
            string[] ids = new string[100];

            ManageRequestsContentDGV.Columns.Add("ID", "ID");
            int i = 0;
            foreach (Request req in reqList)
            {
                dates[i] = req.req_date.ToShortDateString();
                status[i] = req.status;
                int id = req.idRequest;
                ids[i] = i.ToString();
                severity[i] = req.severity_level;
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    string name = context.Patients.Where(p => p.idPatient == req.idPatient).Select(p => p.name).ToList()[0];
                    patients[i] = name;

                    doctors[i++] = context.Persons
                        .Where(x => x.email == req.idDoctor)
                        .Select(x => x.name + " " + x.surname)
                        .ToList()[0];
                }
            }


            for (i = 0; i < reqList.Count; i++)
            {
                ManageRequestsContentDGV.Rows.Add(new object[] { dates[i], status[i], severity[i], patients[i], doctors[i] , ids[i]});
            }
        }


        private void ProccessRequestButton_Click(object sender, EventArgs e)
        {
            if (request != null)
            {
                if (ctrl.ProcessRequest(request))
                {
                    this.CompleteRequestButton.BringToFront();
                }
                else
                {
                    string message = "The request you selected cannot be completed.";
                    string caption = "Attention!";
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

        private void CompleteRequestButton_Click(object sender, EventArgs e)
        {
            string patientGroup;
            int bloodNeeded;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                patientGroup = context.Patients
                    .Where(x => x.idPatient == this.request.idRequest)
                    .Select(x => x.name)
                    .ToList()[0];
                bloodNeeded = Int32.Parse(
                    context.Patients
                    .Where(x => x.idPatient == this.request.idRequest)
                    .Select(x => x.bloodNeeded)
                    .ToList()[0].ToString()
                );
            }
            if (PatientNameTextBox.Text == "")
            {
                ctrl.SendRecombination(bloodNeeded, patientGroup);
            }
            else
            {
                ctrl.SendRecombination(bloodNeeded, patientGroup, this.request.idPatient);
            }
            request.status = "Completed";
            ctrl.getReqRepo().Update(request);
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void SendToTestingButton_Click(object sender, EventArgs e)
        {
            ctrl.SendTesting(bloodDonation);
        }

        private void TestDonationsButton_Click(object sender, EventArgs e)
        {
            this.AnalysisDGV.BringToFront();
            this.BloodDonationsDGV.BringToFront();
            this.DiseasesTextBox.BringToFront();
            this.SendToTestingButton.BringToFront();
            this.SendResultsButton.BringToFront();


            List<Blood_Donation> bdList = ctrl.getBDRepo().GetElements();

            string[] ids = new string[100];
            string[] dates = new string[100];
            string[] status = new string[100];
            string[] isApproved = new string[100];
            string[] expDate = new string[100];
            string[] patients = new string[100];
            string[] component = new string[100];
            string[] quantity = new string[100];
            string[] bdGroup = new string[100];


            int i = 0;
            BloodDonationsDGV.Columns.Add("ID", "ID");
            foreach (Blood_Donation bd in bdList)
            {
                dates[i] = bd.donationDate.ToShortDateString();
                status[i] = bd.status;
                if (bd.isApproved)
                {
                    isApproved[i] = "Approved";

                }
                else
                {
                    isApproved[i] = "Not Approved";

                }
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    patients[i] = context.Patients
                        .Where(x => x.idPatient == bd.idPatient)
                        .Select(x => x.name)
                        .ToList()[0];
                }
                if (patients[i] == "Everyone")
                    patients[i] = "None";
                ids[i] = bd.idDonation.ToString();
                component[i] = bd.componentName;
                bdGroup[i] = bd.bloodGroup;
                quantity[i] = bd.quantity.ToString();
                expDate[i] = bd.expiratonDate.ToShortDateString();
                i++;
            }


            for (i = 0; i < bdList.Count; i++)
            {
                BloodDonationsDGV.Rows.Add(new object[] { dates[i], status[i], expDate[i], patients[i], isApproved[i], component[i], bdGroup[i], quantity[i], ids[i] });
            }
        }

        private void BloodDonationsDGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

            int bloodDonationID = Int32.Parse(BloodDonationsDGV.Rows[e.RowIndex].Cells["ID"].Value as String);

            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                this.bloodDonation = context.Blood_Donations
                    .Where(d => d.idDonation == bloodDonationID)
                    .Select(d => d)
                    .ToList()[0];
            }

        }

        private void SendResultsButton_Click(object sender, EventArgs e)
        {
            ctrl.AddTestResults(bloodDonation, DiseasesTextBox.Text, BloodBox.Text + RHBox.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String email = DonorEmailTextBox.Text;
            Donor donor = ctrl.getDonorRepo().GetDonor(email);
            String bloodG = "unk";
            DateTime currentDate = DateTime.Today;
            DateTime expDate = DateTime.Today.AddMonths(5);
            string DcpMail = donation_Center.email;
            string idDonor = donor.idPerson;
            bool Approved = false;
            Patient patient = null;

            if (PatientNameTextBox.Text != "")
            {
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    patient = context.Patients
                                    .Where(p => p.name == PatientNameTextBox.Text)
                                    .Select(p => p)
                                    .ToList()[0];
                }
            }
            else
            {
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    patient = context.Patients
                                    .Where(p => p.idPatient == 0)
                                    .Select(p => p)
                                    .ToList()[0];
                }
            }

            int lastID = 0;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                lastID = context.Blood_Donations
                                .Max(x => x.idDonation);
            }
            lastID += 1;
            Blood_Donation bd = new Blood_Donation()
            {
                bloodGroup = "unk",
                isApproved = Approved,
                donationDate = currentDate,
                expiratonDate = expDate,
                idDonationCenter = DcpMail,
                idDonor = idDonor,
                status = "harvested",
                idPatient = patient.idPatient,
                componentName = "Plasma",
                quantity = 275,
                idDonation = lastID
            };
            lastID += 1;
            ctrl.AddDonation(donor, bd, patient);
            bd.componentName = "Thrombocytes";
            bd.quantity = 5;
            bd.idDonation = lastID;
            bd.expiratonDate = DateTime.Today.AddDays(5);
            ctrl.AddDonation(donor, bd, patient);

            lastID += 1;
            bd.componentName = "RBC";
            bd.quantity = 220;
            bd.idDonation = lastID;
            bd.expiratonDate = DateTime.Today.AddDays(42);
            ctrl.AddDonation(donor, bd, patient);
        }

        private void DiseasesTextBox_Click(object sender, EventArgs e)
        {
            DiseasesTextBox.Text = "";
        }

        private void DonateButton_Click(object sender, EventArgs e)
        {
            this.DonateDGV.BringToFront();
            this.DonorEmailTextBox.BringToFront();
            this.PatientNameTextBox.BringToFront();
            this.ButtonDonate.BringToFront();
            this.HomeButton.BringToFront();
            this.LogOutButton.BringToFront();
            this.pictureBox2.BringToFront();
        }

        private void Component1TextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void HomeDFV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

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

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void DCPCenter_Load(object sender, EventArgs e)
        {

        }
    }
}
