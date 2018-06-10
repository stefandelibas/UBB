using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class MessageRepository : IRepository<Message>
    {
        public void Add(Message element)
        {
            /*
             * Adds a message into the DataBase in the "Messages" table
             * Input: element = the message that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Messages.Add(element);
                context.SaveChanges();
            }
        }

        public void Delete(Message element)
        {
            /*
             * Deletes a message from the DataBase located in the "Messages" table
             * Input: element = the message that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Messages.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Message> GetElements()
        {
            /*
             * Selects all messages from the DataBase located in the "Messages" table
             * Input: none
             * Output: a list of messages
             */
            List<Message> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Messages.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Message element)
        {
            /*
             * Updates a person from the DataBase located in the "Messages" table
             * Input: element = the message with the updated info that needs to replace the old message
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Message message = context.Messages.FirstOrDefault(m => m.idMessage == element.idMessage);
                this.Delete(message);
                this.Add(element);
            }
        }

        internal int getNextID()
        {
            int nextId = 0;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                string nextId_str;
                nextId_str = context.Messages
                    .Max(x => x.idMessage)
                    .ToString();
                if (nextId_str != null)
                {
                    nextId = Int32.Parse(nextId_str);
                    nextId++;
                }
            }
            return nextId;
        }
    }
}
