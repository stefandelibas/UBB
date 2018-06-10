using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using BloodDonation.controllers;
using BloodDonation.repositories;
using BloodDonation.Utils;

namespace BloodDonation.Controllers
{
    class LoginController : IController
    {
        PersonRepository personRepository;
        DoctorRepository doctorRepository;
        DonorRepository donorRepository;
        DCPRepository dCPRepository;

        public LoginController()
        {
            personRepository = new PersonRepository();
            doctorRepository = new DoctorRepository();
            donorRepository = new DonorRepository();
            dCPRepository = new DCPRepository();
        }

        public IController InitializeEnviroment(string email)
        {
            if (doctorRepository.Find(email) == true)
            {
                Doctor doctor = doctorRepository.GetDoctor(email);
                return new DoctorController(doctor);
            }
            else if (dCPRepository.Find(email) == true)
            {
                Donation_Center donation_Center = dCPRepository.GetDonation_Center(email);
                return new DCPController(donation_Center);
            }
            else if(donorRepository.Find(email) == true)
            {
                Donor donor = donorRepository.GetDonor(email);
                return new DonorController(donor);
            }
            else
            {
                return new LoginController();

            }
        }

        internal bool CheckPassword(string email, string password)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                List<Person> person = context.Persons
                                            .Where(p => p.email == email).ToList();
                if ( person.Count() > 0)
                {   
                    if (person[0].password == password)
                        return true;
                    else
                        return false;

                }
                else
                {
                    List<Donation_Center> centers = context.Donation_Centers
                                                        .Where(d => d.email == email).ToList();
                    if (centers.Count() > 0)
                    {
                        if (centers[0].password == password)
                            return true;
                        else
                            return false;

                    }
                }
                return false;
            }

        }

        public void RegisterDoctor(string mail,string name, string surname, string gender, string phone, DateTime dateOfBirth, string address, string city, string actualAddress, string actualCity,string hospital)
        {
            List<int> hospitalID=null;

            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                hospitalID = context.Hospitals
                .Where(h => h.name == hospital)
                .Select(h => h.idHospital).ToList();
            }

            Doctor doctor = new Doctor()
            {
                id = mail,
                idHospital = hospitalID[0]
            };
        }
        public void RegisterDCP(string mail,string password)
        {
            string encryptedPassword = Cryptograph.Encrypt(password, mail);
            Donation_Center donation_Center = new Donation_Center()
            {
                email = mail,
                password = encryptedPassword
            };
            this.dCPRepository.Add(donation_Center);
            
        }

        internal object[] getCities()
        {
            object[] cities = null;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                cities = context.Locations.Select(x => x.city).ToList().ToArray<object>();
            }
            return cities;
        }

        public void Register(String email, String name, String surname, String gender, String phone, DateTime dateOfBirth, String password, String address, String actualAddress, String city, String actualCity)
        {

            List<int> idCitySet = null;
            List<int> idActualCitySet = null;

            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                idCitySet = context.Locations
                    .Where(x => x.city == city)
                    .Select(x => x.idCity).ToList();
            }

            int idCity = idCitySet[0];

            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                idActualCitySet = context.Locations
                    .Where(x => x.city == actualCity)
                    .Select(x => x.idCity).ToList();
            }

            int idActualCity = idActualCitySet[0];


            Person person = new Person()
            {
                email = email,
                bloodGroup = "UNK",
                name = name,
                surname = surname,
                gender = gender,
                phoneNr = phone,
                birthdate = dateOfBirth,
                password = password,
                idCity = idCity,
                address = address,
                actualAddress = actualAddress,
                idActualCity = idActualCity
            };


            personRepository.Add(person);

            string emailDC;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                try
                {
                    emailDC = context.Donation_Centers
                        .Where(x => x.IDlocation == idActualCity)
                        .Select(x => x.email).ToList()[0];
                }
                catch (Exception ex)
                {
                    emailDC = "ClujCenter@donation.ro";
                }
            }
            Donor donor = new Donor()
            {
                idPerson = email,
                idDonationCenter = emailDC
            };
            donorRepository.Add(donor);
        }


        public bool VerifyEmailExist(string email)
        {
            if (this.personRepository.Find(email) == true || this.dCPRepository.Find(email) == true)
                return false;
            return true;
        }

        public bool VerifyPassword(string pass1, string pass2)
        {
            if (pass1 == pass2)
                return true;
            return false;
        }

        public bool VerifyEmailRegex(string email)
        {
            Regex emailRegex = new Regex(@"^([\w\.\-]+)@([\w\-]+)((\.(\w){2,3})+)$");
            if (emailRegex.IsMatch(email))
            {
                return true;
            }
            return false;
        }

    }

}
