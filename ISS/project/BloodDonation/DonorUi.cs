using BloodDonation.controllers;
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
    public partial class DonorUi : Form
    {
        Donor donor;
        DonorController ctrl;


        public DonorUi()
        {
            InitializeComponent();
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                welcomeLabel.Text = "Welcome, " + donor.Person.name + " " + donor.Person.surname + "!";
            }
        }

        public DonorUi(string email)
        {
            InitializeComponent();
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                this.donor = context.Donors.Where(x => x.idPerson == email).Select(x => x).ToList()[0];
                welcomeLabel.Text = "Welcome, " + donor.Person.name + " " + donor.Person.surname + "!";
            }

            ctrl = new DonorController(donor);
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void fontDialog1_Apply(object sender, EventArgs e)
        {

        }

        private void DHistoryButton_Click(object sender, EventArgs e)
        {

            DonationHistoryDGV.BringToFront();
            BDonationHistoryContentDGV.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();
            smallMascotPictureBox.BringToFront();
            //dummy test - nu este nimic in baza de date si trebuia sa testam cumva
            //string[] dates = new string[100];
            //for (int i = 0; i < 49; i++)
            //{
            //    dates[i] = DateTime.Today.ToShortDateString();
            //}
            
  
            //for(int i = 0; i < 49; i++)
            //{
            //    BDonationHistoryContentDGV.Rows.Add(new object[] { dates[i] });
            //}
            
            
            List<Blood_Donation> dontationsList = ctrl.GetHistory();
            string[] dates = new string[dontationsList.Count];
            int i = 0;
            foreach (Blood_Donation donation in dontationsList)
            {
                dates[i] = donation.donationDate.ToShortDateString();
                i++;
            }

            BDonationHistoryContentDGV.Rows.Clear();
            BDonationHistoryContentDGV.Refresh();

            for (i = 0; i < dontationsList.Count; i++)
            {
                BDonationHistoryContentDGV.Rows.Add(new object[] { dates[i] });
            }
        }

        private void DonateButton_Click(object sender, EventArgs e)
        {
            //check availability 
            DonateDGV.BringToFront();
            bigMascotPictureBox.BringToFront();
            //ok = ctrl.IsAvailableToDonate(donor);
            try
            {
                bool ok = this.ctrl.IsAvailableToDonate(this.donor);
                if (ok)
                {
                    BifaPictureBox.BringToFront();
                    approveLabel.BringToFront();
                }
                else
                {
                    declinePictureBox.BringToFront();
                    declineLabel.BringToFront();
                }
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

        private void LastDButton_Click(object sender, EventArgs e)
        {
            LastDonationDGV.BringToFront();
            DateTextBox.BringToFront();
            ExpirationDateTextBox.BringToFront();
            BloodGroupInfoTextBox.BringToFront();
            IsApproved.BringToFront();
            StatusTextBox.BringToFront();
            //ComponentTextBox.BringToFront();
            //label1.BringToFront();
            label9.BringToFront();
            label10.BringToFront();
            label12.BringToFront();
            label13.BringToFront();
            label3.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();
            smallMascotPictureBox.BringToFront();

            DateTextBox.Text = "";
            ExpirationDateTextBox.Text = "";
            BloodGroupInfoTextBox.Text = "";
            IsApproved.Text = "";
            StatusTextBox.Text = "";
            //ComponentTextBox.Text = "";

            try
            {
                Blood_Donation dontation = ctrl.GetLastDonation(donor);
                DateTextBox.Text = dontation.donationDate.ToShortDateString();
                ExpirationDateTextBox.Text = dontation.expiratonDate.ToShortDateString();
                BloodGroupInfoTextBox.Text = dontation.bloodGroup;
                if (dontation.isApproved)
                {
                    IsApproved.Text = "Yes";
                }
                else
                {
                    IsApproved.Text = "No";
                }
                StatusTextBox.Text = dontation.status;
                //ComponentTextBox.Text = dontation.componentName;
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

        private void MessagesButton_Click(object sender, EventArgs e)
        {
            MessagesDGV.BringToFront();
            MessagesContentDGV.BringToFront();
            messageContentLabel.BringToFront();
            HomeButton.BringToFront();
            LogOutButton.BringToFront();
            smallMascotPictureBox.BringToFront();
            try
            {
                List<Tuple<String, String>> messageList = ctrl.GetMessages();
                string[] dcpMail = new string[100];
                string[] titles = new string[100];

                int i = 0;
                foreach (Tuple<String, String> message in messageList)
                {
                    dcpMail[i] = message.Item1;
                    titles[i] = message.Item2;
                    i++;
                }

                MessagesContentDGV.Rows.Clear();
                MessagesContentDGV.Refresh();

                for (i = 0; i < messageList.Count; i++)
                {
                    MessagesContentDGV.Rows.Add(new object[] { dcpMail[i], titles[i].Substring(0, 9) });
                }
               
                this.MessagesContentDGV.CellContentClick += (sender2, e2) => MessagesContentDGV_CellContentClick(sender2, e2, titles[e2.RowIndex]);

            }
            catch (InvalidConstraintException ex)
            {
                string message = ex.Message;
                string caption = "Error!";
                MessageBoxButtons buttons = MessageBoxButtons.OK;
                DialogResult result;
                

                result = MessageBox.Show(message, caption, buttons);

                if (result == System.Windows.Forms.DialogResult.OK)
                {

                }
            }


        }

        

        private void PDataButton_Click(object sender, EventArgs e)
        {
            //PersonalData pd = new PersonalData(donor);
            PersonalData pd = new PersonalData(this.donor.Person.email, this.donor.Person.password);
            pd.Show();
        }

       

        private void BDonationHistoryContentDGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void MessagesContentDGV_CellContentClick(object sender, DataGridViewCellEventArgs e, string msg)
        {
            messageContentLabel.Text = msg;
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

        

        private void bigMascotPictureBox_Click(object sender, EventArgs e)
        {

        }

        private void HomeDFV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
