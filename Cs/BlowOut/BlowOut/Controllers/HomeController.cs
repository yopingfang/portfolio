using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using BlowOut.DAL;
using BlowOut.Models;

namespace BlowOut.Controllers
{
    public class HomeController : Controller
    {
        //static public Instruments custInst = new Instruments();
        private CheckPointContext db = new CheckPointContext();
        static public int custInstID;

        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public ActionResult Rentals(string instrument = "default")
        {
            ViewBag.Instrument = instrument;
            
            if (instrument == "trumpet")
            {
                
                ViewBag.Name = "Trumpet";

            }

            else if (instrument == "trombone")
            {
                ViewBag.Name = "Trombone";
            }

            else if (instrument == "tuba")
            {
                ViewBag.Name = "Tuba";
            }

            else if (instrument == "flute")
            {
                ViewBag.Name = "Flute";
            }

            else if (instrument == "clarinet")
            {
                ViewBag.Name = "Clarinet";
            }

            else if (instrument == "saxophone")
            {
                ViewBag.Name = "Saxophone";
            }

            else
            {
                return View();
            }

            return View(db.Instruments.ToList());
        }

        public ActionResult Summary(Clients client)
        {
            Instruments instrument = db.Instruments.Find(custInstID);
            instrument.clientID = client.clientID;
            db.SaveChanges();

            ViewBag.Name = instrument.instName;
            ViewBag.Total = instrument.price * 18;
            ViewBag.Client = client.clientID;
            ViewBag.ClientName = client.firstName;

            return View(db.Instruments.ToList());
        }

        public ActionResult Create(int ID)
        {
            custInstID = ID;
            return View();
        }

        // POST: Clients/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "clientID,firstName,lastName,address,city,state,zip,email,phone")] Clients clients)
        {
            if (ModelState.IsValid)
            {
                db.Clients.Add(clients);

                db.SaveChanges();
                return RedirectToAction("Summary", clients);
            }

            return View(clients);
        }

        [HttpGet]
        public ActionResult UpdateData()
        {
            ViewBag.CanAccess = "false";
            return View();
        }

        [HttpPost]
        public ActionResult UpdateData(string name, string pass)
        {
            ViewBag.CanAccess = "false";
            if (name == "Missouri" && pass == "ShowMe")
            {
                ViewBag.CanAccess = "true";
            }
            return View(db.Instruments.ToList());
        }

        public ActionResult Clear()
        {
            IEnumerable<Clients> allClients = db.Clients.SqlQuery("SELECT * FROM Clients;");
            db.Clients.RemoveRange(allClients);
            db.SaveChanges();

            //Sets the variable allInst equal to the Instrument table
            IEnumerable<Instruments> allInst = db.Instruments.SqlQuery("SELECT * FROM Instruments;");
            //Sifts through all the entries
            foreach (Instruments inst in allInst)
            {
                //Finds entries with a clientID in it (probably change this)
                if (inst.clientID != null)
                {
                    //Changes the ID to null
                    inst.clientID = null;
                }
            }
            //Always save!
            db.SaveChanges();

            return View("Index");
        }

        // GET: Clients/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Clients clients = db.Clients.Find(id);
            if (clients == null)
            {
                return HttpNotFound();
            }
            return View(clients);
        }

        // POST: Clients/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "clientID,firstName,lastName,address,city,state,zip,email,phone")] Clients clients)
        {
            if (ModelState.IsValid)
            {
                db.Entry(clients).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("UpdateData", new { name = "Missouri", pass = "ShowMe" });
            }
            return View(clients);
        }

        // GET: Clients/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Clients clients = db.Clients.Find(id);
            if (clients == null)
            {
                return HttpNotFound();
            }
            return View(clients);
        }

        // POST: Clients/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Clients clients = db.Clients.Find(id);
            db.Clients.Remove(clients);

            

            IEnumerable<Instruments> allInst = db.Instruments.SqlQuery("SELECT * FROM Instruments;");
            //Sifts through all the entries
            foreach (Instruments inst in allInst)
            {
                //Finds entries with a clientID in it (probably change this)
                if (inst.clientID == id)
                {
                    //Changes the ID to null
                    inst.clientID = null;
                    break;
                }
            }

            db.SaveChanges();
            return RedirectToAction("UpdateData", new { name = "Missouri", pass = "ShowMe" });
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}