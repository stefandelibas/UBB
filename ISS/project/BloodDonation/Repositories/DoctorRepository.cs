using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class DoctorRepository : IRepository<Doctor>
    {
        public void Add(Doctor element)
        {
            /*
             * Adds a doctor into the DataBase in the "Doctors" table
             * Input: element = the doctor that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Doctors.Add(element);
                context.SaveChanges();
            }
        }

        internal Doctor GetDoctor(string email)
        {   //get the doctow whose email matches with the one give as a parameter
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {

                var dataset = context.Doctors
               .Where(x => x.id == email)
               .Select(x => x).ToList();


                return dataset[0];
            }


        }

        internal bool Find(string email)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                var dataset = context.Doctors
               .Where(x => x.id == email)
               .Select(x => new { x.id }).ToList();

                if (dataset.Count == 1)
                    return true;
                return false;
            }
        }

        public void Delete(Doctor element)
        {
            /*
             * Deletes a doctor from the DataBase located in the "Doctors" table
             * Input: element = the doctor that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Doctors.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Doctor> GetElements()
        {
            /*
             * Selects all doctors from the DataBase located in the "Doctors" table
             * Input: none
             * Output: a list of doctors
             */
            List<Doctor> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Doctors.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Doctor element)
        {
            /*
             * Updates a doctor from the DataBase located in the "Doctors" table
             * Input: element = the doctor with the updated info that needs to replace the old doctor
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                //Note: Neavand un ID am folosit "email" ca identificator unic !
                Doctor doctor = context.Doctors.FirstOrDefault(d => d.id == element.id);
                this.Delete(doctor);
                this.Add(element);
            }
        }
    }
}
