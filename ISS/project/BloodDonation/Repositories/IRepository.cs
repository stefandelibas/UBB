using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    interface IRepository<Element>
    {
        void Add(Element element);
        void Update(Element element);
        void Delete(Element element);
        List<Element> GetElements();
    }
}
