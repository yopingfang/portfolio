using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace FinalExam.Models
{
    [Table("Users")]
    public class Users
    {
        public Users(string name, string pass)
        {
            UserName = name;
            UserPassword = pass;
            UserScore = 0;
            UserRole = "U";
        }
        [Key]
        [Display(Name = "User ID")]
        public int UserID { get; set; }

        [Display(Name = "User Name")]
        [Required(ErrorMessage = "Please enter your user name")]
        public string UserName { get; set; }

        [Display(Name = "User Password")]
        [Required(ErrorMessage = "Please enter your password")]
        public string UserPassword { get; set; }

        [Display(Name = "User Score")]
        public int UserScore { get; set; }

        [Display(Name = "User Role")]
        [StringLength(1)]
        public string UserRole { get; set; }

        virtual public ICollection<QuestionsAnswered> QuestionsAnswered { get; set; }

    }
}