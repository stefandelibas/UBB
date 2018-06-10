using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BloodDonation.Controllers;
using BloodDonation.repositories;

namespace BloodDonation.controllers
{
    class DonorController : IController
    {
        Donor donor;
        MessageRepository messageRepository;
        BloodDonationRepository donationRepository;
        PersonRepository personRepository;

        //TO BE ADDED IF NEEDED. JUST ASK BEFORE

        public DonorController(Donor donor)
        {
            this.donor = donor;
            this.messageRepository = new MessageRepository();
            this.donationRepository = new BloodDonationRepository();
            this.personRepository = new PersonRepository();
        }


        public void SetPersonalData(String email, String name, String surname, String gender, String phone, DateTime dateOfBirth, String address, String actualAddress, String city, String actualCity)
        {
            List<int> idCitySet = null;
            List<int> idActualCitySet = null;

            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                idCitySet = context.Locations
                    .Where(x => x.city == city)
                    .Select(x => x.idCity).ToList();

                int idCity = idCitySet[0];

                idActualCitySet = context.Locations
                    .Where(x => x.city == actualCity)
                    .Select(x => x.idCity).ToList();

                int idActualCity = 0;
                if (idActualCitySet.Count > 0)
                {
                    idActualCity = idActualCitySet[0];
                }
                else
                {
                    throw new InvalidConstraintException("invalid city!");
                }
                


                List<Person> persons = context.Persons.Where(x => x.email == email).Select(x => x).ToList();
                Person person = persons[0];

                person.name = name;
                person.surname = surname;
                person.gender = gender;
                person.phoneNr = phone;
                person.birthdate = dateOfBirth;
                person.address = address;
                person.actualAddress = actualAddress;
                person.idCity = idCity;
                person.idActualCity = idActualCity;

                context.SaveChanges();
            }
        }

        /*
        * returns a list of tuples. each tuple represents the message and the donation center email
        * Input: none
        * Output: list of messages formed as tuples
        */
        public List<Tuple<String, String>> GetMessages()
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                List<Tuple<String, String>> messageTuple = context.Messages
                    .Where(x => x.idPerson == donor.idPerson)
                    .ToList()
                    .Select(x => new Tuple<String, String>(x.idDonationCenter, x.msg)).ToList();

                return messageTuple;
            }
        }

        /*
        * returns a list of tuples. each tuple represents the message and the donation center email
        * Input: none
        * Output: list of messages formed as tuples
        */
        public bool IsAvailableToDonate(Donor donor)
        {
            DateTime last_Donation = this.GetLastDonation(donor).donationDate;
            DateTime current_time = DateTime.Today;
            double totalDays = Math.Abs((last_Donation - current_time).TotalDays);
            int totalWeeks = (int)totalDays / 7;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                List<Blood_Donation> allDonations = context.Blood_Donations
                    .Where(x => donor.idPerson == x.idDonor && DbFunctions.DiffDays(DbFunctions.TruncateTime(x.donationDate), current_time) <= 365)
                    .Select(x => x)
                    .ToList();

                int age = (int)(current_time - donor.Person.birthdate).TotalDays / 365;
                if (donor.Person.gender == "female" && totalWeeks >= 6 && allDonations.Count < 3 && age >= 18 && age <= 60)
                {
                    return true;
                }
                else
                {
                    if (donor.Person.gender == "male" && totalWeeks >= 6 && allDonations.Count < 4 && age >= 18 && age <= 60)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }


        public Blood_Donation GetLastDonation(Donor donor)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {

                List<Blood_Donation> dataset = context.Blood_Donations
               .Where(x => x.idDonor == donor.idPerson)
               .OrderByDescending(x => x.donationDate)
               .Select(x => x)
               .ToList();
                Blood_Donation last_Donated = null;
                if (dataset.Count > 0)
                {
                    last_Donated = dataset[0];
                }
                else
                {
                    throw new InvalidConstraintException("You have no donation records so far!");
                }

                return last_Donated;
            }
        }


      
        public List<Blood_Donation> GetHistory()
        {
            List<Blood_Donation> donations;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                donations = context.Blood_Donations
                .Where(d => d.idDonor == donor.idPerson)
                .Select(x => x)
                .OrderBy(x => x.donationDate)
                .ToList();              
            }

            List<Blood_Donation> filteredDonations = new List<Blood_Donation>();
            for(int i = 0; i < donations.Count();i+=3)
            {
                filteredDonations.Add(donations[i]);
            }
            return filteredDonations;
        }
    }
}
