using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class DonorRepository : IRepository<Donor>
    {
        public void Add(Donor element)
        {
            /*
             * Adds a donor into the DataBase in the "Donors" table
             * Input: element = the donor that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Donors.Add(element);
                context.SaveChanges();
            }
        }

        public void Delete(Donor element)
        {
            /*
             * Deletes a donor from the DataBase located in the "Donors" table
             * Input: element = the donor that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Donors.Remove(element);
                context.SaveChanges();
            }
        }

        internal Donor GetDonor(string email)
        {
            //get the donor whose email matches with the one give as a parameter
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {

                var dataset = context.Donors
               .Where(x => x.idPerson == email)
               .Select(x => x).ToList();


                return dataset[0];
            }
        }

        internal bool Find(string email)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {

                var dataset = context.Donors
               .Where(x => x.idPerson == email)
               .Select(x => x).ToList();

                if (dataset.Count == 1)
                    return true;
                return false;
            }
        }

        public List<Donor> GetElements()
        {
            /*
             * Selects all donors from the DataBase located in the "Donors" table
             * Input: none
             * Output: a list of donors
             */
            List<Donor> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Donors.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Donor element)
        {
            /*
             * Updates a donor from the DataBase located in the "Donors" table
             * Input: element = the donor with the updated info that needs to replace the old donor
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Donor donor = context.Donors.FirstOrDefault(d => d.idPerson == element.idPerson);
                this.Delete(donor);
                this.Add(element);
            }
        }
    }
}
