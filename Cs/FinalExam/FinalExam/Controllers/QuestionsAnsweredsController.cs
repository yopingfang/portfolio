using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using FinalExam.DAL;
using FinalExam.Models;

namespace FinalExam.Controllers
{
    public class QuestionsAnsweredsController : Controller
    {
        private TriviaCrackContext db = new TriviaCrackContext();

        // GET: QuestionsAnswereds
        [Authorize]
        public ActionResult Index()
        {
            var questionsAnswered = db.QuestionsAnswered.Include(q => q.Question).Include(q => q.Users);

            Users cUser = db.Users.Find(HomeController.currentUserID);
            if (cUser.UserRole == "A")
            {
                return View(questionsAnswered.ToList());
            }

            return RedirectToAction("Index", "Home");
        }

        // GET: QuestionsAnswereds/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            QuestionsAnswered questionsAnswered = db.QuestionsAnswered.Find(id);
            if (questionsAnswered == null)
            {
                return HttpNotFound();
            }
            return View(questionsAnswered);
        }

        // GET: QuestionsAnswereds/Create
        public ActionResult Create()
        {
            ViewBag.QuestionID = new SelectList(db.Question, "QuestionID", "QuestionText");
            ViewBag.UserID = new SelectList(db.Users, "UserID", "UserName");
            return View();
        }

        // POST: QuestionsAnswereds/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "UserID,QuestionID,Answered")] QuestionsAnswered questionsAnswered)
        {
            if (ModelState.IsValid)
            {
                db.QuestionsAnswered.Add(questionsAnswered);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.QuestionID = new SelectList(db.Question, "QuestionID", "QuestionText", questionsAnswered.QuestionID);
            ViewBag.UserID = new SelectList(db.Users, "UserID", "UserName", questionsAnswered.UserID);
            return View(questionsAnswered);
        }

        // GET: QuestionsAnswereds/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            QuestionsAnswered questionsAnswered = db.QuestionsAnswered.Find(id);
            if (questionsAnswered == null)
            {
                return HttpNotFound();
            }
            ViewBag.QuestionID = new SelectList(db.Question, "QuestionID", "QuestionText", questionsAnswered.QuestionID);
            ViewBag.UserID = new SelectList(db.Users, "UserID", "UserName", questionsAnswered.UserID);
            return View(questionsAnswered);
        }

        // POST: QuestionsAnswereds/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "UserID,QuestionID,Answered")] QuestionsAnswered questionsAnswered)
        {
            if (ModelState.IsValid)
            {
                db.Entry(questionsAnswered).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.QuestionID = new SelectList(db.Question, "QuestionID", "QuestionText", questionsAnswered.QuestionID);
            ViewBag.UserID = new SelectList(db.Users, "UserID", "UserName", questionsAnswered.UserID);
            return View(questionsAnswered);
        }

        // GET: QuestionsAnswereds/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            QuestionsAnswered questionsAnswered = db.QuestionsAnswered.Find(id);
            if (questionsAnswered == null)
            {
                return HttpNotFound();
            }
            return View(questionsAnswered);
        }

        // POST: QuestionsAnswereds/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            QuestionsAnswered questionsAnswered = db.QuestionsAnswered.Find(id);
            db.QuestionsAnswered.Remove(questionsAnswered);
            db.SaveChanges();
            return RedirectToAction("Index");
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
