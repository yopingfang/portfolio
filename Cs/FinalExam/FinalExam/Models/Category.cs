using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace FinalExam.Models
{
    [Table("Category")]
    public class Category
    {                
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.None)]        
        [Display(Name = "Category ID")]
        [StringLength(1)]
        public string CategoryID { get; set; }

        [Display(Name = "Category Description")]
        public string CategoryDesc { get; set; }

        virtual public ICollection<Question> Question { get; set; }
    }
}