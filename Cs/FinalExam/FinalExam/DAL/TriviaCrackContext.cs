using FinalExam.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace FinalExam.DAL
{
    public class TriviaCrackContext : DbContext
    {
        public TriviaCrackContext() : base("TriviaCrack") {}

        public DbSet<Category> Category { get; set; }
        public DbSet<Question> Question { get; set; }
        public DbSet<QuestionsAnswered> QuestionsAnswered { get; set; }
        public DbSet<Users> Users { get; set; }
    }
}