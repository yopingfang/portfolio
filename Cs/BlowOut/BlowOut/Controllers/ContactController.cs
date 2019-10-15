using BlowOut.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BlowOut.Controllers
{
    public class ContactController : Controller
    {
        static public ToSend sendMe = new ToSend();
        // GET: Contact
        public string Index()
        {
            return "Please call Support at <b><u>801-555-1212</b></u>. Thank you!";
        }

        public string Email(string name, string email)
        {
            ToSend.emailToAddress = email; //sends an email to whatever address you enter - check the
            ToSend.SendEmail();            //model before you test it though and uncomment these lines
            return ("Thank you " + name + ". We will send an email to " + email);
        }

    }
}