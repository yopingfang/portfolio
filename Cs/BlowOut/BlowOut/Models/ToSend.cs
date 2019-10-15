using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Mail;
using System.Web;

namespace BlowOut.Models
{
    public class ToSend //I tested this thing out and it worked but you can try it too if you want to
    {                   //I took out my email and password (because duh) so just put your own in; don't worry
        static string smtpAddress = "smtp.gmail.com";      //about the emailToAddress, that's in the controller
        static int portNumber = 587;
        static bool enableSSL = true;
        static string emailFromAddress = "yopingfang@gmail.com"; //Sender Email Address  
        static string password = "l7pcjqo6nf76790l"; //Sender Password  
        static public string emailToAddress { get; set; } //Receiver Email Address  
        static string subject = "Hello";
        static string body = "Hello, This is Email sending test using gmail.";
        static void Main(string[] args)
        {
            SendEmail();
        }
        public static void SendEmail()
        {
            using (MailMessage mail = new MailMessage())
            {
                mail.From = new MailAddress(emailFromAddress);
                mail.To.Add(emailToAddress);
                mail.Subject = subject;
                mail.Body = body;
                mail.IsBodyHtml = true;
                //mail.Attachments.Add(new Attachment("D:\\TestFile.txt"));//--Uncomment this to send any attachment  
                using (SmtpClient smtp = new SmtpClient(smtpAddress, portNumber))
                {
                    smtp.Credentials = new NetworkCredential(emailFromAddress, password);
                    smtp.EnableSsl = enableSSL;
                    smtp.Send(mail);
                }
            }
        }
    }
}