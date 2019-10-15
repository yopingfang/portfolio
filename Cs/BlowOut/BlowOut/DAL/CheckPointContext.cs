using BlowOut.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace BlowOut.DAL
{
    public class CheckPointContext : DbContext
    {
        public CheckPointContext() : base("CheckPointContext") { }

        public DbSet<Clients> Clients { get; set; }
        public DbSet<Instruments> Instruments { get; set; }

    }
}