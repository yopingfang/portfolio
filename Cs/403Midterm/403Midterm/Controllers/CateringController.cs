using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace _403Midterm.Controllers
{
    public class CateringController : Controller
    {
        //Returns a page with catering options
        public ActionResult Index()
        {
            return View();
        }
    }
}