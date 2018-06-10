using System;
using System.Collections.Generic;
using System.Data.Entity.Validation;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class PersonRepository : IRepository<Person>
    {
        public void Add(Person element)
        {
            /*
             * Adds a person into the DataBase in the "Persons" table
             * Input: element = the person that needs to be added
             * Output: none
             */ 
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                try
                {
                    context.Persons.Add(element);
                    context.SaveChanges();
                }
                catch (DbEntityValidationException e)
                {
                    foreach (var eve in e.EntityValidationErrors)
                    {
                        Console.WriteLine("Entity of type \"{0}\" in state \"{1}\" has the following validation errors:",
                            eve.Entry.Entity.GetType().Name, eve.Entry.State);
                        foreach (var ve in eve.ValidationErrors)
                        {
                            Console.WriteLine("- Property: \"{0}\", Error: \"{1}\"",
                                ve.PropertyName, ve.ErrorMessage);
                        }
                    }
                    throw;
                }
            }
        }

        public void Delete(Person element)
        {
            /*
             * Deletes a person from the DataBase located in the "Persons" table
             * Input: element = the person that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Persons.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Person> GetElements()
        {
            /*
             * Selects all persons from the DataBase located in the "Persons" table
             * Input: none
             * Output: a list of persons
             */
            List<Person> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            { 
                list = context.Persons.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Person element)
        {
            /*
             * Updates a person from the DataBase located in the "Persons" table
             * Input: element = the person with the updated info that needs to replace the old person
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Person person = context.Persons.FirstOrDefault(p => p.email == element.email);
                this.Delete(person);
                this.Add(element);
            }
        }

        internal bool Find(String email)
        {

            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                var dataset = context.Persons
               .Where(x => x.email == email)
               .Select(x => x.email).ToList();

                if (dataset.Count > 0)
                    return true;
                return false;
            }

        }

    }
}
