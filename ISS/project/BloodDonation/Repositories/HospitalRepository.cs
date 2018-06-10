using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class HospitalRepository : IRepository<Hospital>
    {
        public void Add(Hospital element)
        {
            /*
             * Adds a hospital into the DataBase in the "Hospitals" table
             * Input: element = the hospital that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Hospitals.Add(element);
                context.SaveChanges();
            }
        }

        public void Delete(Hospital element)
        {
            /*
             * Deletes a hospital from the DataBase located in the "Hospitals" table
             * Input: element = the hospital that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Hospitals.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Hospital> GetElements()
        {
            /*
             * Selects all hospitals from the DataBase located in the "Hospitalss" table
             * Input: none
             * Output: a list of hospitals
             */
            List<Hospital> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Hospitals.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Hospital element)
        {
            /*
             * Updates a hospital from the DataBase located in the "Hospitals" table
             * Input: element = the hospital with the updated info that needs to replace the old hospital
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                //Note: Neavand un ID am folosit "email" ca identificator unic !
                Hospital hospital = context.Hospitals.FirstOrDefault(h => h.idHospital == element.idHospital);
                this.Delete(hospital);
                this.Add(element);
            }
        }
    }
}
