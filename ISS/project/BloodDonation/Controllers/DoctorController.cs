using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BloodDonation.repositories;
using BloodDonation;
using BloodDonation.Controllers;
using System.Data;

namespace BloodDonation.controllers
{
    class DoctorController : IController
    {
        Doctor doctor;
        RequestRepository requestRepository;
        PatientRepository patientRepository;
        //TO BE ADDED IF NEEDED. JUST ASK BEFORE    

        
        public DoctorController(Doctor doctor)
        {
            this.doctor = doctor;
            requestRepository = new RequestRepository();
            patientRepository = new PatientRepository();
        }
        /*
        * add a new request in the databes
        * Input: patient name, how much blood he/she needs, the bloodgroup, the severity level
        * Output: the added request
        * Result: the message is inserted into the DB
        */
        public Request FillRequest(string patientName, int bloodNeeded, string bloodGroup, string severity, string donationCenterMail)
        {
            int nextPatientID;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                string nextPatientIDString;
                nextPatientIDString = context.Patients
                    .Max(x => x.idPatient)
                    .ToString();

                nextPatientID = Int32.Parse(nextPatientIDString);
                nextPatientID++;
            }

            int nextRequestID;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                string nextRequestIDString;
                nextRequestIDString = context.Requests
                    .Max(x => x.idRequest)
                    .ToString();

                nextRequestID = Int32.Parse(nextRequestIDString);
                nextRequestID++;
            }

            Patient patient = new Patient()
            {
                idPatient = nextPatientID,
                idDoctor = this.doctor.id,
                name = patientName,
                bloodGroup = bloodGroup,
                bloodNeeded = bloodNeeded
            };

            Request request = new Request()
            {
                idRequest = nextRequestID,
                idDoctor = this.doctor.id,
                status = "requested",
                severity_level = severity,
                idPatient = nextPatientID,
                idDonationCenter = donationCenterMail,
                req_date = DateTime.UtcNow
            };

            try
            {
                this.patientRepository.Add(patient);
                this.requestRepository.Add(request);
            }
            catch (Exception ex)
            {
                throw new ArgumentException(ex.Message);
            }
            return request;
        }

        /*
        * returns a request according to the name of the patient
        * Input: patient name
        * Output: the request containing the patient name
        */
        public Request TrackRequest(string patientName)
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                List<Patient> patients = context.Patients
                    .Where(x => x.name == patientName)
                    .Select(x => x).ToList();

                int patientId;
                if (patients.Count > 0)
                {
                    patientId = patients[0].idPatient;
                }
                else
                {
                    throw new InvalidConstraintException("Invalid patient name !");
                }

                List<Request> requests = context.Requests
                    .Where(x => x.idDoctor == doctor.id && x.idPatient == patientId)
                    .Select(x => x).ToList();

                if (requests.Count > 0)
                {
                    Request request = requests[0];
                    return request;
                }
                else
                {
                    throw new InvalidConstraintException("Invalid patient name !");
                }

            }
        }

        /*
        * returns a list of patients
        * Input: none
        * Output: list of patients of the current logged doctor
        */
        public List<Patient> GetPatients()
        {
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                List<Patient> patients = context.Patients
                    .Where(x => x.idDoctor == this.doctor.id)
                    .Select(x => x).ToList();
                return patients;
            }
        }
    }
}
