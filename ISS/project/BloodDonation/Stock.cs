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
    
    public partial class Stock
    {
        public int idDonation { get; set; }
        public string idDonationCenter { get; set; }
        public string bloodGroup { get; set; }
        public System.DateTime donationDate { get; set; }
        public System.DateTime expirationDate { get; set; }
        public Nullable<int> idPatient { get; set; }
        public string componentName { get; set; }
        public int quantity { get; set; }
        public string status { get; set; }
    
        public virtual Donation_Center Donation_Centers { get; set; }
        public virtual Patient Patient { get; set; }
    }
}
