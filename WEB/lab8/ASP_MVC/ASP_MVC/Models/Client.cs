using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ASP_MVC.Models
{
    public class Client
    {
        public int IDClient { get; set; }
        public string ClientName { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }
    }
}