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
    public class QuestionsController : Controller
    {
        private TriviaCrackContext db = new TriviaCrackContext();

        // GET: Questions
        [Authorize]
        public ActionResult Index()
        {
            var question = db.Question.Include(q => q.Category);

            Users cUser = db.Users.Find(HomeController.currentUserID);
            if (cUser.UserRole == "A")
            {
                return View(question.ToList());
            }

            return RedirectToAction("Index", "Home");

            
        }

        // GET: Questions/Details/5
        
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Question question = db.Question.Find(id);
            if (question == null)
            {
                return HttpNotFound();
            }
            return View(question);
        }

        // GET: Questions/Create
        //[Authorize]
        public ActionResult Create()
        {
            ViewBag.Category = db.Category.ToList();
            ViewBag.CategoryID = new SelectList(db.Category, "CategoryID", "CategoryDesc");
            return View();
        }

        // POST: Questions/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "QuestionID,CategoryID,QuestionText,Answer1,Answer2,Answer3,Answer4,CorrectAnswer")] Question question)
        {
            if (ModelState.IsValid)
            {
                db.Question.Add(question);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.CategoryID = new SelectList(db.Category, "CategoryID", "CategoryDesc", question.CategoryID);
            return View(question);
        }

        // GET: Questions/Edit/5
        
        public ActionResult Edit(int? id)
        {
            ViewBag.Category = db.Category.ToList();
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Question question = db.Question.Find(id);
            if (question == null)
            {
                return HttpNotFound();
            }
            ViewBag.CategoryID = new SelectList(db.Category, "CategoryID", "CategoryDesc", question.CategoryID);
            return View(question);
        }

        // POST: Questions/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "QuestionID,CategoryID,QuestionText,Answer1,Answer2,Answer3,Answer4,CorrectAnswer")] Question question)
        {
            if (ModelState.IsValid)
            {
                db.Entry(question).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.CategoryID = new SelectList(db.Category, "CategoryID", "CategryDesc", question.CategoryID);
            return View(question);
        }

        // GET: Questions/Delete/5
        
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Question question = db.Question.Find(id);
            if (question == null)
            {
                return HttpNotFound();
            }
            return View(question);
        }

        // POST: Questions/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Question question = db.Question.Find(id);
            db.Question.Remove(question);
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
