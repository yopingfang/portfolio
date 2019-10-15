using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace FinalExam.Models
{
    [Table("QuestionsAnswered")]
    public class QuestionsAnswered
    {
        [Key, Column(Order = 1)]
        [Display(Name = "User ID")]
        public int UserID { get; set; }

        [Key, Column(Order = 2)]
        [Display(Name = "Question ID")]
        public int QuestionID { get; set; }

        [Display(Name = "Answered")]
        public bool? Answered { get; set; }

        virtual public Users Users { get; set; }
        virtual public Question Question { get; set; }
    }
}