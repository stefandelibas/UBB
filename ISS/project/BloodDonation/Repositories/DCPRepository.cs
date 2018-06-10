using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class DCPRepository : IRepository<Donation_Center>
    {
        /*Obs: Numele clasei se refera la personalul din interiorul centrului de donatii pe cand clasa modeleaza
         centrul propriu-zis
         Sugestie: Ar trebui schimbat numele clase in DCRepository*/

        public void Add(Donation_Center element)
        {
            /*
             * Adds a donation center into the DataBase in the "Donation Centers" table
             * Input: element = the donation center that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Donation_Centers.Add(element);
                context.SaveChanges();
            }
        }

        internal Donation_Center GetDonation_Center(string email)
        {
            //get the donation center whose email matches with the one give as a parameter
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {

                var dataset = context.Donation_Centers
               .Where(x => x.email == email)
               .Select(x => x).ToList();


                return dataset[0];
            }
        }

        public void Delete(Donation_Center element)
        {
            /*
             * Deletes a donation center from the DataBase located in the "Donation Centers" table
             * Input: element = the donation center that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Donation_Centers.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Donation_Center> GetElements()
        {
            /*
             * Selects all donation centers from the DataBase located in the "Donation Centers" table
             * Input: none
             * Output: a list of donation centers
             */
            List<Donation_Center> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Donation_Centers.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Donation_Center element)
        {
            /*
             * Updates a donation center from the DataBase located in the "Donation Centers" table
             * Input: element = the person with the donation center info that needs to replace the old donation center
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Donation_Center center = context.Donation_Centers.FirstOrDefault(d => d.email == element.email);
                this.Delete(center);
                this.Add(element);
            }
        }

        internal bool Find(string email, string password)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {

                var dataset = context.Donation_Centers
               .Where(x => x.email == email && x.password == password)
               .Select(x => new { x.email, x.password }).ToList();

                if (dataset.Count > 0)
                    return true;
                return false;
            }
        }
        internal bool Find(string email)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {

                var dataset = context.Donation_Centers
               .Where(x => x.email == email)
               .Select(x => new { x.email }).ToList();

                if (dataset.Count == 1)
                    return true;
                return false;
            }
        }
    }
}
