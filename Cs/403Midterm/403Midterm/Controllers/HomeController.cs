using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using _403Midterm.Models;

/*
 * Po Fang, Section 1
 * 
 * This is a website for a catering company called Bright Entertainment, which provides
 * Hawaiian catering and entertainment. The site includes information about the company, catering
 * and entertainment options, and allows customers to place orders
 * */
namespace _403Midterm.Controllers
{
    public class HomeController : Controller
    {
        //Displays landing/home page
        public ActionResult Index()
        {
            return View();
        }

        //Displays About Us page
        public ActionResult About()
        {
            return View();
        }

        
    }
}