using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class RequestRepository : IRepository<Request>
    {
        public void Add(Request element)
        {
            /*
             * Adds a request into the DataBase in the "Requests" table
             * Input: element = the request that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Requests.Add(element);
                context.SaveChanges();
            }
        }

        public void Delete(Request element)
        {
            /*
              * Deletes a request from the DataBase located in the "Requests" table
              * Input: element = the request that needs to be deleted
              * Output: none
              */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Request request = context.Requests.Where(r => r.idRequest == element.idRequest).Select(r => r).ToList()[0];
                context.Requests.Remove(request);
                context.SaveChanges();
            }
        }

        public List<Request> GetElements()
        {
            /*
             * Selects all requests from the DataBase located in the "Requests" table
             * Input: none
             * Output: a list of requests
             */
            List<Request> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Requests.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Request element)
        {
            /*
             * Updates a request from the DataBase located in the "Requests" table
             * Input: element = the request with the updated info that needs to replace the old request
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Request request = context.Requests.FirstOrDefault(r => r.idRequest == element.idRequest);
                this.Delete(request);
                this.Add(element);
            }
        }
    }
}
