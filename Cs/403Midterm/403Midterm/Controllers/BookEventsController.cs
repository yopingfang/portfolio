using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using _403Midterm.Models;

namespace _403Midterm.Controllers
{
    public class BookEventsController : Controller
    {
        //Holds customers
        public static List<Form> MyCustomers = new List<Form>();

        //Returns confirmation page
        public ActionResult Confirmation()
        {
            return View();
        }

        //Gets customer info
        [HttpGet]
        public ViewResult Index()
        {
            return View();
        }
        [HttpPost]
        public ViewResult Index(Form guestResponse)
        {
            if (ModelState.IsValid)
            {
                MyCustomers.Add(guestResponse);
                ViewBag.Name = guestResponse.FName + " " + guestResponse.LName;
                ViewBag.Catering = guestResponse.CaterPackage;
                ViewBag.Ent = guestResponse.EntPackage;
                ViewBag.Email = guestResponse.Email;
                return View("Confirmation", guestResponse);
            }
            else
            {
                //Validation Error
                return View();
            }
        }

        //Displays a table showing customer full name, email, and packages above the form
        public ActionResult DisplayCustomers()
        {
            ViewBag.Display = "<table>" +
                "<tr>" +
                "<th style=\"white-space:pre\">Name".PadRight(60, ' ') + "</th>" +
                    "<th style=\"white-space:pre\">Email".PadRight(50, ' ') + "</th>" +
                    "<th style=\"white-space:pre\">Catering Package".PadRight(50, ' ') + "</th>" +
                    "<th style=\"white-space:pre\">Entertainment Package".PadRight(50, ' ') + "</th>" +
                    "</tr>";
            foreach (Form listItem in MyCustomers)
            {
                ViewBag.Display += "<tr>";
                ViewBag.Display += "<td>" + listItem.FName + " " + listItem.LName + "</td>";
                ViewBag.Display += "<td>" + listItem.Email + "</td>";
                ViewBag.Display += "<td>" + listItem.CaterPackage + "</td>";
                ViewBag.Display += "<td>" + listItem.EntPackage + "</td></tr>";
            }

            ViewBag.Display += "</table>";

            return View("Index");
        }

        //Clears current list of customers and displays a blank table
        public ActionResult ClearCustomers()
        {
            MyCustomers = new List<Form>();
            return RedirectToAction("DisplayCustomers");
        }
    }
}