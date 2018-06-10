using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BloodDonation;
using BloodDonation.Controllers;
using BloodDonation.repositories;

namespace BloodDonation.controllers
{
    class DCPController : IController
    {
        Donation_Center donation_Center;
        RequestRepository requestRepository;
        MessageRepository messageRepository;
        BloodDonationRepository donationRepository;
        StockRepository stockRepository;
        DonorRepository donorRepository;
        PatientRepository patientRepository;
        //TO BE ADDED IF NEEDED. JUST ASK BEFORE

        public DCPController(Donation_Center donation_Center)
        {
            this.donation_Center = donation_Center;
            this.requestRepository = new RequestRepository();
            this.messageRepository = new MessageRepository();
            this.donationRepository = new BloodDonationRepository();
            this.stockRepository = new StockRepository();
            this.donorRepository = new DonorRepository();
            this.patientRepository = new PatientRepository();
        }

        public bool ProcessRequest(Request request)
        {
            //refresh stock
            stockRepository.Refresh();

            int patientId = request.idPatient;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Patient patient = context.Patients.Find(patientId);
                if (patient == null)
                    throw new Exception("Invalid patient ID. Patient doesn't exist.");

                if (IsAvailable(patient.bloodNeeded, patient.bloodGroup))
                    return true;
                else//check all other blood groups he's compatible with
                {
                    List<string> compatibleBloodGroups = GetCompatibleGroupsToReceive(patient.bloodGroup);
                    if (compatibleBloodGroups != null)
                    {
                        foreach (string cbg in compatibleBloodGroups)
                        {
                            if (IsAvailable(patient.bloodNeeded, cbg))
                                return true;
                        }

                    }
                }
                return false;
            }

        }

        private List<string> GetCompatibleGroupsToGive(string bloodGruop)
        /*Returns a list for compatible groups for a given bloodGroup to donate to
         * Input: bloodGroup
         * Output: a list of bloodGroups or null
         */
        {
            List<string> compatibleBloodGroups = new List<string>();

            switch (bloodGruop)
            {
                case "O-":
                    {
                        compatibleBloodGroups.Add("AB+");
                        compatibleBloodGroups.Add("AB-");
                        compatibleBloodGroups.Add("A+");
                        compatibleBloodGroups.Add("A-");
                        compatibleBloodGroups.Add("B+");
                        compatibleBloodGroups.Add("B-");
                        compatibleBloodGroups.Add("O+");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "O+":
                    {
                        compatibleBloodGroups.Add("O+");
                        compatibleBloodGroups.Add("B+");
                        compatibleBloodGroups.Add("A+");
                        compatibleBloodGroups.Add("AB+");
                        break;
                    }
                case "B-":
                    {
                        compatibleBloodGroups.Add("B-");
                        compatibleBloodGroups.Add("B+");
                        compatibleBloodGroups.Add("AB-");
                        compatibleBloodGroups.Add("AB+");
                        break;
                    }
                case "B+":
                    {
                        compatibleBloodGroups.Add("B+");
                        compatibleBloodGroups.Add("AB+");
                        break;
                    }
                case "A-":
                    {
                        compatibleBloodGroups.Add("A-");
                        compatibleBloodGroups.Add("A+");
                        compatibleBloodGroups.Add("AB-");
                        compatibleBloodGroups.Add("AB+");
                        break;
                    }
                case "A+":
                    {
                        compatibleBloodGroups.Add("A+");
                        compatibleBloodGroups.Add("AB+");
                        break;
                    }
                case "AB-":
                    {
                        compatibleBloodGroups.Add("AB-");
                        compatibleBloodGroups.Add("AB+");
                        break;
                    }
                case "AB+":
                    {
                        compatibleBloodGroups.Add("AB+");
                        break;
                    }
            }
            if (compatibleBloodGroups.Count != 0)
                return compatibleBloodGroups;
            return null;
        }

        internal RequestRepository getReqRepo()
        {
            return this.requestRepository;
        }

        private List<string> GetCompatibleGroupsToReceive(string bloodGruop)
        /*Returns a list for compatible groups for a given bloodGroup to receive from
         * Input: bloodGroup
         * Output: a list of bloodGroups or null
         */
        {
            List<string> compatibleBloodGroups = new List<string>();

            switch (bloodGruop)
            {
                case "AB+":
                    {
                        compatibleBloodGroups.Add("AB+");
                        compatibleBloodGroups.Add("AB-");
                        compatibleBloodGroups.Add("A+");
                        compatibleBloodGroups.Add("A-");
                        compatibleBloodGroups.Add("B+");
                        compatibleBloodGroups.Add("B-");
                        compatibleBloodGroups.Add("O+");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "AB-":
                    {
                        compatibleBloodGroups.Add("AB-");
                        compatibleBloodGroups.Add("A-");
                        compatibleBloodGroups.Add("B-");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "A+":
                    {
                        compatibleBloodGroups.Add("A+");
                        compatibleBloodGroups.Add("A-");
                        compatibleBloodGroups.Add("O+");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "A-":
                    {
                        compatibleBloodGroups.Add("A-");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "B+":
                    {
                        compatibleBloodGroups.Add("B+");
                        compatibleBloodGroups.Add("B-");
                        compatibleBloodGroups.Add("O+");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "B-":
                    {
                        compatibleBloodGroups.Add("B-");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "O+":
                    {
                        compatibleBloodGroups.Add("O+");
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
                case "O-":
                    {
                        compatibleBloodGroups.Add("O-");
                        break;
                    }
            }
            if (compatibleBloodGroups.Count != 0)
                return compatibleBloodGroups;
            return null;
        }

        internal BloodDonationRepository getBDRepo()
        {
            return this.donationRepository;
        }

        private bool IsAvailable(int bloodNeeded, string bloodGroup)
        /*Verifies if there is enough blood in the stocks for a bloodGroup
         *
         * Input: blood quantity and bloodGroup
         * Output: true if blood is available, false otherwise
         * 
         * Note: should be in the StockRepository
         */
        {
            int totalPlasmaQuantity = 0;//the quantity of Plasma in stock for a blood group
            int totalRBCQuantity = 0;//the quantity of Red Blood Cells in stock for a blood group
            int totalThrombocytesQuantity = 0;//the quantity of Thrombocytes in stock for a blood group
            stockRepository.GetElements()
                //find all stocks with the blood group and component name = Plasma
                .FindAll(stock => (stock.bloodGroup == bloodGroup) && (stock.componentName == "Plasma"))
                //and add the quantities together to see if they are more than blood needed
                .ForEach(stock => totalPlasmaQuantity += stock.quantity);

            stockRepository.GetElements()
                //find all stocks with the blood group and component name = RBC
                .FindAll(stock => (stock.bloodGroup == bloodGroup) && (stock.componentName == "RBC"))
                //and add the quantities together to see if they are more than blood needed
                .ForEach(stock => totalPlasmaQuantity += stock.quantity);

            stockRepository.GetElements()
                //find all stocks with the blood group and component name = Thrombocytes
                .FindAll(stock => (stock.bloodGroup == bloodGroup) && (stock.componentName == "Thrombocytes"))
                //and add the quantities together to see if they are more than blood needed
                .ForEach(stock => totalPlasmaQuantity += stock.quantity);

            if ((totalPlasmaQuantity >= bloodNeeded * (55.0 / 100)) //plasma = 55% of blood
                && (totalThrombocytesQuantity >= bloodNeeded * (1.0 / 100)) //thrombocytes = 1% of blood
                && (totalRBCQuantity >= bloodNeeded * (44.0 / 100))) //red blood cells = 44% of blood
            {
                return true;//is available
            }
            return false;//there isn't enough blood
        }

        internal DonorRepository getDonorRepo()
        {
            return this.donorRepository;
        }

        public void AddDonation(Donor donor, Blood_Donation blood_Donation)
        /*Adds a new donation to the BloodDonationRepository and to the StockRepository
         * Input: A new donor and a new Blood_Donation
         * Output: none
         */
        {
            if (blood_Donation.idDonor != donor.idPerson)
                //just making sure the blood_donation.idDonor won't be null or other than our Donor's id
                blood_Donation.idDonor = donor.idPerson;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                if (context.Donors.Where(d => d.idPerson == donor.idPerson).Select(d => d).ToList().Count == 0)
                    throw new Exception("Cannot add donation. Donor doesn't exist.");
            }
            blood_Donation.status = "harvested";//set the status to harvested, which is the first step

            //verify it doesn't already exist
            if (donationRepository.GetElements().Find(bd => bd.idDonation == blood_Donation.idDonation) != null)
                throw new Exception("Cannot add donation. Already exists in BloodDonationRepositor.");
            if (stockRepository.GetElements().Find(stk => stk.idDonation == blood_Donation.idDonation) != null)
                throw new Exception("Cannot add donation. Already exists in StockRepository.");

            donationRepository.Add(blood_Donation);//add to DB
            Stock stock = new Stock //create a stock out of that blood_donation
            {
                idDonation = blood_Donation.idDonation,
                idDonationCenter = blood_Donation.idDonationCenter,
                donationDate = blood_Donation.donationDate,
                componentName = blood_Donation.componentName,
                quantity = blood_Donation.quantity,
                bloodGroup = blood_Donation.bloodGroup,
                expirationDate = blood_Donation.expiratonDate,
                status = blood_Donation.status
                //set patient id to a default id
            };
            stockRepository.Add(stock);//add the stock to DB

        }

        internal PatientRepository getPatientRepo()
        {
            return this.patientRepository;
        }

        public void AddDonation(Donor donor, Blood_Donation blood_Donation, Patient patient)
        /*Adds a new donation for a specific patient to the BloodDonationRepository and to the StockRepository
         * Input: A new donor and a new Blood_Donation and a patient
         * Output: none
         */
        {
            if (blood_Donation.idDonor != donor.idPerson)
                //just making sure the blood_donation.idDonor won't be null or other than our Donor's id
                blood_Donation.idDonor = donor.idPerson;
            if (blood_Donation.idPatient != patient.idPatient)
                //just making sure the blood_donation.idPatient won't be null or other than our Patient's id
                blood_Donation.idPatient = patient.idPatient;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                if (context.Donors.Where(d => d.idPerson == donor.idPerson).Select(d => d).ToList().Count == 0)
                    throw new Exception("Cannot add donation. Donor doesn't exist.");
                if (context.Patients.Where(p => p.idPatient == patient.idPatient).Select(p => p).ToList().Count == 0)
                    throw new Exception("Cannot add donation. Patient doesn't exist.");
            }

            blood_Donation.status = "harvested";//set the status to harvested, which is the first step

            //verify it doesn't already exist
            if (donationRepository.GetElements().Find(bd => bd.idDonation == blood_Donation.idDonation) != null)
                throw new Exception("Cannot add donation. Already exists in BloodDonationRepositor.");
            if (stockRepository.GetElements().Find(stk => stk.idDonation == blood_Donation.idDonation) != null)
                throw new Exception("Cannot add donation. Already exists in StockRepository.");

            donationRepository.Add(blood_Donation);//add to DB
            //Stock stock = new Stock //create a stock out of that blood_donation
            //{
            //    idDonation = blood_Donation.idDonation,
            //    idDonationCenter = blood_Donation.idDonationCenter,
            //    donationDate = blood_Donation.donationDate,
            //    componentName = blood_Donation.componentName,
            //    quantity = blood_Donation.quantity,
            //    bloodGroup = blood_Donation.bloodGroup,
            //    expirationDate = blood_Donation.expiratonDate,
            //    status = blood_Donation.status,

            //    idPatient = blood_Donation.idPatient

            //};
            //stockRepository.Add(stock);//add the stock to DB
        }

        
        public void SendRecombination(int blood, string bloodGroup)
        /*
         * Extracts from the stock a given amount of blood for a given blood group
         * Input: how much blood we need to extract and from which blood group
         * Output: none
         */
        {
            stockRepository.Refresh();//clear out expired stocks or empty
            
            bool isAvailable = IsAvailable(blood, bloodGroup);//verify if there is enough blood
            if (!isAvailable)
            {
                //check compatible bloodGroups
                List<string> compatibleBloodGroups = GetCompatibleGroupsToReceive(bloodGroup);
                if (compatibleBloodGroups == null)
                    return;
                else
                {
                    foreach (string cbg in compatibleBloodGroups)
                    {
                        isAvailable = IsAvailable(blood, cbg);//verify if there is enough blood
                        if (isAvailable)
                        {
                            bloodGroup = cbg;
                            break;
                        }
                    }
                }
            }
            if (!isAvailable)//if there is not one compatible group avaliable then we return
                return;

            //separate the blood into the three components

            int plasma = Convert.ToInt32(Math.Ceiling(blood * 55.0 / 100));
            int thrombocytes = Convert.ToInt32(Math.Ceiling(blood * 1.0 / 100));
            int rbc = Convert.ToInt32(Math.Ceiling(blood * 44.0 / 100));


            stockRepository.GetElements()
                //find all stocks with the blood group and component name = Plasma
                .FindAll(stock => (stock.bloodGroup == bloodGroup) && (stock.componentName == "Plasma"))
                //and take from the stocks until we have the quantity of plasma we need
                .ForEach(stock => {
                    if (stock.quantity > plasma) { stock.quantity -= plasma; plasma = 0; }
                    else { plasma -= stock.quantity; stock.quantity = 0; }
                });

            stockRepository.GetElements()
                //find all stocks with the blood group and component name = RBC
                .FindAll(stock => (stock.bloodGroup == bloodGroup) && (stock.componentName == "RBC"))
                //and take the first stocks until we have enough to cover the quantity of rbc we need
                .ForEach(stock => {
                    if (stock.quantity > rbc) { stock.quantity -= rbc; rbc = 0; }
                    else { rbc -= stock.quantity; stock.quantity = 0; }
                });

            stockRepository.GetElements()
                //find all stocks with the blood group and component name = RBC
                .FindAll(stock => (stock.bloodGroup == bloodGroup) && (stock.componentName == "Thrombocytes"))
                //and take the first stocks until we have enough to cover the quantity of rbc we need
                .ForEach(stock => {
                    if (stock.quantity > thrombocytes) { stock.quantity -= thrombocytes; thrombocytes = 0; }
                    else { thrombocytes -= stock.quantity; stock.quantity = 0; }
                });

            stockRepository.Refresh();//clear out expired stocks or empty
        }

        public void SendRecombination(int blood, string bloodGroup, int idPatient)
        /*
         * Extracts from the stock a given amount of blood for a given blood group 
                 and searches first for stocks a Patient with the given name
         * Input: how much blood we need to extract and from which blood group and a patient name
         * Output: none
         */
        {
            stockRepository.Refresh();//clear out expired stocks or empty

            int patientID = idPatient;


            bool isAvailable = IsAvailable(blood, bloodGroup);//verify if there is enough blood
            if (!isAvailable)
            {
                //check compatible bloodGroups
                List<string> compatibleBloodGroups = GetCompatibleGroupsToReceive(bloodGroup);
                if (compatibleBloodGroups == null)
                    return;
                else
                {
                    foreach (string cbg in compatibleBloodGroups)
                    {
                        isAvailable = IsAvailable(blood, cbg);//verify if there is enough blood
                        if (isAvailable)
                        {
                            bloodGroup = cbg;
                            break;
                        }
                    }
                }
            }
            if (!isAvailable)//if there is not one compatible group avaliable then we return
                return;

            //separate the blood into the three components

            int plasma = Convert.ToInt32(Math.Ceiling(blood * 55.0 / 100));
            int thrombocytes = Convert.ToInt32(Math.Ceiling(blood * 1.0 / 100));
            int rbc = Convert.ToInt32(Math.Ceiling(blood * 44.0 / 100));


            //first we take from the stocks the blood donated specifically for that Patient
            if (patientID != 0)
            {
                stockRepository.GetElements()
               //find all stocks with the blood group and component name = Plasma
               .FindAll(stock =>
                        (stock.idPatient == patientID) &&
                       (stock.bloodGroup == bloodGroup) &&
                       (stock.componentName == "Plasma"))
               //and take from the stocks until we have the quantity of plasma we need
               .ForEach(stock => {
                   if (stock.quantity > plasma) { stock.quantity -= plasma; plasma = 0; }
                   else { plasma -= stock.quantity; stock.quantity = 0; }
               });

                stockRepository.GetElements()
                //find all stocks with the blood group and component name = RBC
                .FindAll(stock =>
                        (stock.idPatient == patientID) &&
                        (stock.bloodGroup == bloodGroup) &&
                        (stock.componentName == "RBC"))
                //and take the first stocks until we have enough to cover the quantity of rbc we need
                .ForEach(stock => {
                    if (stock.quantity > rbc) { stock.quantity -= rbc; rbc = 0; }
                    else { rbc -= stock.quantity; stock.quantity = 0; }
                });

                stockRepository.GetElements()
                    //find all stocks with the blood group and component name = RBC
                    .FindAll(stock =>
                            (stock.idPatient == patientID) &&
                            (stock.bloodGroup == bloodGroup) &&
                            (stock.componentName == "Thrombocytes"))
                    //and take the first stocks until we have enough to cover the quantity of rbc we need
                    .ForEach(stock => {
                        if (stock.quantity > thrombocytes) { stock.quantity -= thrombocytes; thrombocytes = 0; }
                        else { thrombocytes -= stock.quantity; stock.quantity = 0; }
                    });
            }

            // if we still need blood, we take from others as well
            if (plasma != 0)
            {
                stockRepository.GetElements()
                    //find all stocks with the blood group and component name = Plasma
                    .FindAll(stock =>
                            (stock.bloodGroup == bloodGroup) &&
                            (stock.componentName == "Plasma"))
                    //and take from the stocks until we have the quantity of plasma we need
                    .ForEach(stock =>
                    {
                        if (stock.quantity > plasma) { stock.quantity -= plasma; plasma = 0; }
                        else { plasma -= stock.quantity; stock.quantity = 0; }
                    });
            }
            if (rbc != 0)
            {
                stockRepository.GetElements()
                //find all stocks with the blood group and component name = RBC
                .FindAll(stock =>
                        (stock.bloodGroup == bloodGroup) &&
                        (stock.componentName == "RBC"))
                //and take the first stocks until we have enough to cover the quantity of rbc we need
                .ForEach(stock =>
                {
                    if (stock.quantity > rbc) { stock.quantity -= rbc; rbc = 0; }
                    else { rbc -= stock.quantity; stock.quantity = 0; }
                });
            }
            if (thrombocytes != 0)
            {
                stockRepository.GetElements()
                //find all stocks with the blood group and component name = RBC
                .FindAll(stock =>
                        (stock.bloodGroup == bloodGroup) &&
                        (stock.componentName == "Thrombocytes"))
                //and take the first stocks until we have enough to cover the quantity of rbc we need
                .ForEach(stock =>
                {
                    if (stock.quantity > thrombocytes) { stock.quantity -= thrombocytes; thrombocytes = 0; }
                    else { thrombocytes -= stock.quantity; stock.quantity = 0; }
                });
            }
            stockRepository.Refresh();//clear out expired stocks or empty
        }




        /*
         * Informs the donor about his test results
         * Input: blood_Donation = the donation which was tested
         *        diseases = a string that can be either null, in case the results are fine, or contains 
         *                   all the diseases found while testing the blood
         * Output: none
         */
        public void AddTestResults(Blood_Donation blood_Donation, String diseases, String bloodGroup)
        {
            //If the results are clean
            if (diseases == null)
            {
                //Blood Donations table update
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    /*Retrieve the Blood Donation from "Blood Donations" table matching our parameter 
                    and save it into a list with 1 element*/
                    List<Blood_Donation> bd = context.Blood_Donations
                        .Where(x => x.idDonation == blood_Donation.idDonation)
                        .Select(x => x)
                        .ToList();
                    //Change the "status" of that Blood Donation
                    bd[0].status = "Approved";
                    //Set the "isApproved" field
                    bd[0].isApproved = true;
                    //Call the Update method from Repository
                    this.donationRepository.Update(bd[0]);
                }
                //Stocks table update
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    /*Retrieve the Blood Donation from "Stocks" table matching our parameter 
                    and save it into a list with 1 element*/
                    List<Stock> bd = context.Stocks
                        .Where(x => x.idDonation == blood_Donation.idDonation)
                        .Select(x => x)
                        .ToList();
                    //Change the "status" of that Blood Donation
                    bd[0].status = "Approved";
                    //update the blood group
                    bd[0].bloodGroup = bloodGroup;

                    //Call the Update method from Repository
                    this.stockRepository.Update(bd[0]);
                }
            }
            //Else if the results are not ok
            else
            {
                //Blood Donations table update
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    /*Retrieve the Blood Donation from "Blood Donations" table matching our parameter 
                    and save it into a list with 1 element*/
                    List<Blood_Donation> bd = context.Blood_Donations
                        .Where(x => x.idDonation == blood_Donation.idDonation)
                        .Select(x => x)
                        .ToList();
                    //Change the "status" of that Blood Donation
                    bd[0].status = "Rejected";
                    //Set the "isApproved" field
                    bd[0].isApproved = false;
                    bd[0].bloodGroup = bloodGroup;
                    //Call the Update method from Repository
                    this.donationRepository.Update(bd[0]);
                }
                //Stocks table update
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    /*Retrieve the Blood Donation from "Stocks" table matching our parameter 
                    and save it into a list with 1 element*/
                    List<Stock> bd = context.Stocks
                        .Where(x => x.idDonation == blood_Donation.idDonation)
                        .Select(x => x)
                        .ToList();
                    //Call the Delete method from Repository
                    this.stockRepository.Delete(bd[0]);
                    //Refresh the stock
                    this.stockRepository.Refresh();
                }
                //Notify the donor

                //Create the message that will be sent to the donor
                String textMessage = "The tests found the following diseases: " + diseases;

                /* Retrieve the Person from "Persons" table who donated the blood
                 * and save it into a list with 1 element
                */
                List<Person> person = null;
                using (Blood_DonationEntities context = new Blood_DonationEntities())
                {
                    person = context.Persons
                        .Where(x => x.email == blood_Donation.idDonor)
                        .Select(x => x)
                        .ToList();
                }

                //Call the SendRequest method to notify the person
                this.SendRequest(person[0], textMessage);
            }
        }
        /*
        * sends a request(a message) to a donor
        * Input: a person
        * Output: none
        * Result: the message is inserted into the DB
        */
        public void SendRequest(Person person, string textMessage)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Message message = new Message()
                {
                    msg = textMessage,
                    idDonationCenter = this.donation_Center.email,
                    idPerson = person.email,
                    idMessage = this.messageRepository.getNextID()
                };
                this.messageRepository.Add(message);
                
            }
        }
        /*
        * sends a request(a message) to some donors
        * Input: a list of persons
        * Output: none
        * Result: messages are inserted into the DB
        */
        public void SendTesting(Blood_Donation blood_Donation)
        {
            //Blood Donations table update
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                /*Retrieve the Blood Donation from "Blood Donations" table matching our parameter 
                and save it into a list with 1 element*/
                List<Blood_Donation> bd = context.Blood_Donations
                    .Where(x => x.idDonation == blood_Donation.idDonation)
                    .Select(x => x)
                    .ToList();
                //Change the status of that Blood Donation
                bd[0].status = "in testing";
                //Call the Update method from Repository
                this.donationRepository.Update(bd[0]);
            }
            //Stocks table update
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                /*Retrieve the Blood Donation from "Stocks" table matching our parameter 
                and save it into a list with 1 element*/
                List<Stock> bd = context.Stocks
                    .Where(x => x.idDonation == blood_Donation.idDonation)
                    .Select(x => x)
                    .ToList();

                if (bd.Count > 0)
                {
                    //Change the status of that Blood Donation
                    bd[0].status = "in testing";
                    //Call the Update method from Repository
                    this.stockRepository.Update(bd[0]);
                }
            }
        }
        /*
        * Selects all donors that are closest to the current donation center
        * Input: none
        * Output: a list of people
        */
        public List<Person> GetClosestDonor()
        {
            List<Distance> distances;
            List<Person> people = null;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                distances = context.Distances
                    .Where(x => x.idLocation1 == this.donation_Center.IDlocation)
                    .Select(x => x)
                    .OrderBy(x => x.distance1)
                    .ToList();

                people = context.Persons
                        .Join(context.Donors, a => a.email, b => b.idPerson, (a, b) => a)
                        .Where(x => x.idActualCity == distances[0].idLocation1)
                        .Select(x => x)
                        .ToList();
                if (people == null)
                {
                    foreach (var d in distances)
                    {
                        people = context.Persons
                            .Join(context.Donors, a => a.email, b => b.idPerson, (a, b) => a)
                            .Where(x => x.idActualCity == d.idLocation2)
                            .Select(x => x)
                            .ToList();
                        if (people == null)
                            continue;
                        else
                            break;
                        
                    }
                }

            }
            return people;
        }
    }
}
