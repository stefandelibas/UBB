﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ASP_MVC.Models
{
    public class Booking
    {
        public int IDBooking { get; set; }
        public int IDRoom { get; set; }
        public int IDClient { get; set; }
        public string Hotel { get; set; }
        public int Price { get; set; }
        public string Type { get; set; }
        public string Category { get; set; }
        public DateTime startDate { get; set; }
        public DateTime endDate { get; set; }
    }
}