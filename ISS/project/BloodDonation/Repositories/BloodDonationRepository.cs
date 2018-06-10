using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BloodDonation;

namespace BloodDonation.repositories
{
    class BloodDonationRepository : IRepository<Blood_Donation>
    {
        public void Add(Blood_Donation element)
        {
            /*
             * Adds a donation into the DataBase in the "Blood Donations" table
             * Input: element = the donation that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Blood_Donation bd = new Blood_Donation();
                bd.idDonation = element.idDonation;
                bd.bloodGroup = element.bloodGroup;
                bd.isApproved = element.isApproved;
                bd.donationDate = element.donationDate;
                bd.expiratonDate = element.expiratonDate;
                bd.idDonationCenter = element.idDonationCenter;
                bd.idDonor = element.idDonor;
                bd.idPatient = element.idPatient;
                bd.componentName = element.componentName;
                bd.quantity = element.quantity;
                bd.status = element.status;
                context.Blood_Donations.Add(bd);
                context.SaveChanges();
            }
        }
        public void Delete(Blood_Donation element)
        {
            /*
             * Deletes a donation from the DataBase located in the "Blood Donations" table
             * Input: element = the donation that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Blood_Donation bd = context.Blood_Donations
                    .Where(d => d.idDonation == element.idDonation)
                    .Select(d => d)
                    .ToList()[0];
                context.Blood_Donations.Remove(bd);
                context.SaveChanges();
            }
        }

        public List<Blood_Donation> GetElements()
        {
            /*
             * Selects all donations from the DataBase located in the "Blood Donations" table
             * Input: none
             * Output: a list of blood donations
             */
            List<Blood_Donation> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Blood_Donations.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Blood_Donation element)
        {
            /*
             * Updates a donation from the DataBase located in the "Blood Donations" table
             * Input: element = the blood donation with the updated info that needs to replace the old donation
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Blood_Donation donation = context.Blood_Donations.FirstOrDefault(d => d.idDonation == element.idDonation);
                this.Delete(donation);
                this.Add(element);
            }
        }
    }
}
