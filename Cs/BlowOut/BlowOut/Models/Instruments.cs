using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace BlowOut.Models
{
    [Table("Instruments")]
    public class Instruments
    {
        [Key]
        public int instrumentID { get; set; }

        public string instName { get; set; }

        public string instType { get; set; }

        public decimal price { get; set; }

        public int? clientID { get; set; }

        public virtual Clients Clients { get; set; }
    }
}