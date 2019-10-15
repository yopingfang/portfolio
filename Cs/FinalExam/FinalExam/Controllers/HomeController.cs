using FinalExam.DAL;
using FinalExam.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace FinalExam.Controllers
{
    public class HomeController : Controller
    {
        private TriviaCrackContext db = new TriviaCrackContext();
        public static string currentUser;
        public static int currentUserID;

        public ActionResult Index()
        {
            return View();
        }

        [HttpGet]
        public ActionResult Login()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Login(FormCollection form, bool rememberMe = false)
        {
            String user = form["UserName"].ToString();
            String password = form["Password"].ToString();
            currentUser = user;
            currentUserID = 1;
            FormsAuthentication.SetAuthCookie(user, rememberMe);

            return RedirectToAction("Index", "Home");
            //IEnumerable<Users> searchUsers = db.Users.ToList();

            //IEnumerable<Users> searchUsers = db.Database.SqlQuery<Users>(
            //    "SELECT * FROM Users WHERE UserName like '" + user + "'"
            //    );


            //foreach (var item in db.Users.ToList())
            //{
            //    if (item.UserName == user && item.UserPassword == password)
            //    {
            //        currentUser = user;
            //        currentUserID = item.UserID;
            //        FormsAuthentication.SetAuthCookie(user, rememberMe);

            //        return RedirectToAction("Index", "Home");
            //    }
            //}


            //Users newUser = new Users(user, password);
            //db.Users.Add(newUser);
            //db.SaveChanges();
            //currentUser = newUser.UserName;
            //currentUserID = newUser.UserID;
            //return RedirectToAction("Index", "Home");
        }

        [Authorize]
        public ActionResult Play()
        {
            IEnumerable<Question> searchQuest = db.Database.SqlQuery<Question>(
                "SELECT Q.QuestionID, C.CategoryDesc " +
                "FROM Question Q" +
                "INNER JOIN Category C" +
                "ON C.CategoryID = Q.CategoryID" +
                "INNER JOIN QuestionsAnswered QA" +
                "ON Q.QuestionID = QA.QuestionID" +
                "INNER JOIN Users U" +
                "ON QA.UserID = U.UserID" +
                "WHERE U.UserName like " + currentUser +
                "AND (QA.Answered is NULL OR QA.Answered is false)"
                );
            return View(searchQuest);
        }

        [HttpGet]
        public ActionResult Answer(int id)
        {
            ViewBag.User = currentUser;
            ViewBag.QID = id;
            Question userQuestion = db.Question.Find(id);
            return View(userQuestion);
        }

        [HttpPost]
        public ActionResult Answer(int id, int userAnswer)
        {
            Question currentQ = db.Question.Find(id);
            if (currentQ.CorrectAnswer == userAnswer)
            {
                Users currentU = db.Users.Find(currentUserID);
                currentU.UserScore += 10;
                db.Entry(currentU).State = EntityState.Modified;
                db.SaveChanges();
            }

            QuestionsAnswered currentQA = db.QuestionsAnswered.Find(currentUserID);
            currentQA.Answered = true;
            db.Entry(currentQA).State = EntityState.Modified;
            db.SaveChanges();

            return RedirectToAction("Play");
        }
    }
}