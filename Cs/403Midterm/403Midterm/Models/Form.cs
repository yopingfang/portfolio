using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace _403Midterm.Models
{
    public class Form
    {
        //Customer first name, required field, 30 max characters
        [DisplayName("First Name")]
        [Required(ErrorMessage = "Please enter your first name")]
        [MaxLength(30, ErrorMessage = "Name cannot be more than 30 characters")]
        public string FName { get; set; }

        //Customer last name, required field, 50 max characters
        [DisplayName("Last Name")]
        [Required(ErrorMessage = "Please enter your last name")]
        [MaxLength(50, ErrorMessage = "Name cannot be more than 50 characters")]
        public string LName { get; set; }

        //Customer email, required field, must be in email address format
        [DisplayName("Email")]
        [Required(ErrorMessage = "Please enter your email")]
        [EmailAddress(ErrorMessage = "Please enter a valid email address")]
        public string Email { get; set; }

        //Email confirmation, required field, must be in email address format, must match previous email
        [DisplayName("Confirm Email")]
        [Required(ErrorMessage = "Emails do not match")]
        [EmailAddress(ErrorMessage = "Please enter a valid email address")]
        [Compare("Email", ErrorMessage = "Emails do not match")]
        public string CEmail { get; set; }

        //Catering options, takes package number as string, required field
        [DisplayName("Catering")]
        [Required(ErrorMessage = "Please choose a package")]
        public string CaterPackage { get; set; }

        //Entertainment options, takes package number as string, required field
        [DisplayName("Entertainment")]
        [Required(ErrorMessage = "Please choose a package")]
        public string EntPackage { get; set; }
    }
}