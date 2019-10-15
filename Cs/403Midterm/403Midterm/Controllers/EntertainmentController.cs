using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace _403Midterm.Controllers
{
    public class EntertainmentController : Controller
    {
        //Returns a page with entertainment options
        public ActionResult Index()
        {
            return View();
        }
    }
}