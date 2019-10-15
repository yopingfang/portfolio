using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace BlowOut.Models
{
    [Table("Clients")]
    public class Clients
    {
        [Key]
        public int clientID { get; set; }

        [DisplayName("First Name")]
        [Required(ErrorMessage = "Please enter your first name")]
        public string firstName { get; set; }

        [DisplayName("Last Name")]
        [Required(ErrorMessage = "Please enter your last name")]
        public string lastName { get; set; }

        [DisplayName("Mailing Address")]
        [Required(ErrorMessage = "Please enter your address")]
        public string address { get; set; }

        [DisplayName("City")]
        [Required(ErrorMessage = "Please enter the city you reside in")]
        public string city { get; set; }

        [DisplayName("State")]
        [Required(ErrorMessage = "Please enter the state you reside in")]
        public string state { get; set; }

        [DisplayName("Zip Code")]
        [Required(ErrorMessage = "Please enter your zip code")]
        [StringLength(5, MinimumLength = 5, ErrorMessage =("Zip code must be 5 digits"))]
        [RegularExpression("^[0-9]*$", ErrorMessage = "Zip code must be numeric")]
        public string zip { get; set; }

        [EmailAddress(ErrorMessage = "Please enter a valid email address")]
        [DisplayName("Email")]
        [Required(ErrorMessage = "Please enter your email address")]
        public string email { get; set; }

        [DisplayName("Phone Number")]
        [Required(ErrorMessage = "Please enter your phone number")]
        [RegularExpression(@"^\(\d{3}\) \d{3}-\d{4}$", ErrorMessage = "Please enter phone number in this format: (000) 000-0000")]
        public string phone { get; set; }

    }
}