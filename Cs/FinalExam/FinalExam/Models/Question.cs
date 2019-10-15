using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace FinalExam.Models
{
    [Table("Question")]
    public class Question
    {
        [Key]
        [Display(Name = "Question ID")]
        public int QuestionID { get; set; }

        [Display(Name = "Category ID")]
        [StringLength(1)]
        public string CategoryID { get; set; }

        [Display(Name = "Question")]
        public string QuestionText { get; set; }

        [Display(Name = "Answer 1")]
        public string Answer1 { get; set; }

        [Display(Name = "Answer 2")]
        public string Answer2 { get; set; }

        [Display(Name = "Answer 3")]
        public string Answer3 { get; set; }

        [Display(Name = "Answer 4")]
        public string Answer4 { get; set; }

        [Display(Name = "Correct Answer")]
        public int CorrectAnswer { get; set; }

        virtual public Category Category { get; set; }
    }
}