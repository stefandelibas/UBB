//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace BloodDonation
{
    using System;
    using System.Collections.Generic;
    
    public partial class Request
    {
        public int idRequest { get; set; }
        public System.DateTime req_date { get; set; }
        public string status { get; set; }
        public string severity_level { get; set; }
        public int idPatient { get; set; }
        public string idDoctor { get; set; }
        public string idDonationCenter { get; set; }
    
        public virtual Doctor Doctor { get; set; }
        public virtual Donation_Center Donation_Centers { get; set; }
        public virtual Patient Patient { get; set; }
    }
}
