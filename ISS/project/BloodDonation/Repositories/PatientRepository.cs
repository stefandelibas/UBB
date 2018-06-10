using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class PatientRepository : IRepository<Patient>
    {
        public void Add(Patient element)
        {
            /*
             * Adds a patient into the DataBase in the "Patients" table
             * Input: element = the patient that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Patients.Add(element);
                context.SaveChanges();
            }
            
        }

        public void Delete(Patient element)
        {
            /*
             * Deletes a patient from the DataBase located in the "Patients" table
             * Input: element = the patient that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Patients.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Patient> GetElements()
        {
            /*
             * Selects all petients from the DataBase located in the "Patients" table
             * Input: none
             * Output: a list of patients
             */
            List<Patient> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Patients.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Patient element)
        {
            /*
             * Updates a patient from the DataBase located in the "Patients" table
             * Input: element = the patient with the updated info that needs to replace the old patient
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Patient patient = context.Patients.FirstOrDefault(p => p.idPatient == element.idPatient);
                this.Delete(patient);
                this.Add(element);
            }
        }

        public List<Patient> GetPatientsByName(string Name)
        {
            /*
             * Selects all patients from the DataBase located in the "Patients" table with a certain name
             * Input: a name
             * Output: a list of patients
             */
            List<Patient> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Patients.Where(patient => (patient.name == Name)).ToList();
            }

            return list;
        }
    }
}
