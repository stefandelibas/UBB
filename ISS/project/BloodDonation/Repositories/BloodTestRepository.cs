using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class BloodTestRepository : IRepository<Blood_Test>
    {
        public void Add(Blood_Test element)
        {
            /*
             * Adds a blood test into the DataBase in the "Blood Tests" table
             * Input: element = the blood test that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Blood_Tests.Add(element);
                context.SaveChanges();
            }
        }

        public void Delete(Blood_Test element)
        {
            /*
             * Deletes a blood test from the DataBase located in the "Blood Tests" table
             * Input: element = the blood test that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Blood_Tests.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Blood_Test> GetElements()
        {
            /*
             * Selects all blood tests from the DataBase located in the "Blood Tests" table
             * Input: none
             * Output: a list of blood tests
             */
            List<Blood_Test> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Blood_Tests.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Blood_Test element)
        {
            /*
             * Updates a blood test from the DataBase located in the "Blood Tests" table
             * Input: element = the blood test with the updated info that needs to replace the old blood test
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Blood_Test test = context.Blood_Tests.FirstOrDefault(t => t.id == element.id);
                this.Delete(test);
                this.Add(element);
            }
        }
    }
}
