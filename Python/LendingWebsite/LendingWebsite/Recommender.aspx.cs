using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using Newtonsoft.Json.Linq;
using RestSharp;

namespace LendingWebsite
{
    public partial class Recommender : System.Web.UI.Page
    {
        static SqlConnection cn = new SqlConnection("Server=Tcp:is415.database.windows.net,1433;Initial Catalog = is415;Persist Security Info=False;User ID=is415;Password=Temporary415;MultipleActiveResultSets=False;Encrypt=True;TrustServerCertificate=False;Connection Timeout=400;");
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Convert.ToBoolean(Session["LoggedIn"]))
            {
                PanelLogged.Visible = true;
                PanelLogin.Visible = false;
            }
            else
            {
                PanelLogged.Visible = false;
                PanelLogin.Visible = true;
            }
            
            SqlCommand cmd;
            SqlDataReader dr;
            ListItem li;

            cn.Open();

            cmd = new SqlCommand("SELECT DISTINCT TOP(100) asin, productName FROM am_Products;", cn);

            dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                li = new ListItem((string)dr["productName"], (string)dr["asin"]);
                ddlItem.Items.Add(li);
                ddlItem2.Items.Add(li);
                //ddlItem3.Items.Add(li);
            }
            dr.Close();

            cmd = new SqlCommand("SELECT DISTINCT TOP(100) reviewerID, reviewerName FROM am_Products;", cn);

            dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                li = new ListItem((string)dr["reviewerName"], (string)dr["reviewerID"]);
                ddlUser.Items.Add(li);
                //ddlUser2.Items.Add(li);
                ddlUser3.Items.Add(li);
            }
            dr.Close();

            DataBind();
            cn.Close();

        }

        protected void btnRecc_Click(object sender, EventArgs e)
        {
            var client = new RestClient("https://ussouthcentral.services.azureml.net/workspaces/b55b28a7fd264c668bfd94ada007237a/services/c0b39f879d24476681e5db2345004308/execute?api-version=2.0&details=true");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Postman-Token", "fc5c730d-da73-4206-8999-8c5ecf843059");
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("Content-Type", "application/json");
            request.AddHeader("Authorization", "Bearer NUOOKqCVd39ukLi6uJ24iNwu/fZnIXyzjVHw1ZrNctlv9FnvNuVUvPqLG39UxSzkKgHAOFVhBRgCDBMdHo3J8g==");
            request.AddParameter("undefined", "{\r\n  \"Inputs\": {\r\n    \"input1\": {\r\n      \"ColumnNames\": [\r\n        \"reviewerID\",\r\n        \"asin\"\r\n      ],\r\n      \"Values\": [\r\n        [\r\n          \"" + ddlUser.SelectedItem.Text + "\",\r\n          \"" + ddlItem.SelectedItem.Text + "\"\r\n        ]\r\n      ]\r\n    }\r\n  },\r\n  \"GlobalParameters\": {}\r\n}", ParameterType.RequestBody);
            IRestResponse response = client.Execute(request);

            lblResult.Text = response.Content.ToString();

            SqlCommand cmd;
            SqlDataReader dr;
            //ListItem li;


            string prediction = "";

            var results = JObject.Parse(response.Content);
            try
            {
                prediction = results["Results"]["output1"]["value"]["Values"].ToString();
            }
            catch
            {
                lblResult.Text = "Item hasn't been rated by user.";
                return;
            }

            prediction = prediction.Replace("[", "").Replace("]", "").Replace("\"", "").Replace("\r\n", "");
            prediction.Trim();
            string[] allResults = prediction.Split(',');
            //for (int i = 0; i < allResults.Length; i++)
            //{
            //    allResults[i] = allResults[i].Trim();
            //}
            List<string> trimmed = new List<string> { };
            foreach (string x in allResults)
            {
                trimmed.Add(x.Trim());
            }
            string finalText = "Recommended Items: <ul>";

            cn.Open();

            foreach (string x in trimmed)
            {
                cmd = new SqlCommand("SELECT DISTINCT productName FROM am_Products WHERE asin like '" + x + "';", cn);
                dr = cmd.ExecuteReader();
                while (dr.Read())
                {
                    finalText += "<li>" + (string)dr["productName"] + "</li>";
                }
                dr.Close();

            }
            finalText += "</ul>";

            cn.Close();
            lblResult.Text = finalText;
        }

        protected void btnRecc2_Click(object sender, EventArgs e)
        {
            var client = new RestClient("https://ussouthcentral.services.azureml.net/workspaces/b55b28a7fd264c668bfd94ada007237a/services/086165d7c7574ec0a91de8df908fd8af/execute?api-version=2.0&details=true");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Postman-Token", "f3c36994-9d42-41fd-90b8-01dc368b0ed0");
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("Content-Type", "application/json");
            request.AddHeader("Authorization", "Bearer C+cDDzb/Lwrc3CXKRt7KRoa7eOns+x/53cA4+rtiA6/o2Eyw9nr25+4cJ3QEyeAWLGgB1QSVVzDQt2chczD5IA==");
            request.AddParameter("undefined", "{\r\n  \"Inputs\": {\r\n    \"input1\": {\r\n      \"ColumnNames\": [\r\n        \"reviewerID\",\r\n        \"asin\"\r\n      ],\r\n      \"Values\": [\r\n        [\r\n          \"A15T9G38F589KM\",\r\n          \"" + ddlItem2.SelectedItem.Text + "\"\r\n        ]\r\n      ]\r\n    }\r\n  },\r\n  \"GlobalParameters\": {}\r\n}", ParameterType.RequestBody);
            IRestResponse response = client.Execute(request);

            lblResult2.Text = response.Content.ToString();

            SqlCommand cmd;
            SqlDataReader dr;
            //ListItem li;

            string prediction = "";

            var results = JObject.Parse(response.Content);
            try
            {
                prediction = results["Results"]["output1"]["value"]["Values"].ToString();
            }
            catch
            {
                lblResult2.Text = "Sorry, we had an error! Please select a item.";
                return;
            }

            prediction = prediction.Replace("[", "").Replace("]", "").Replace("\"", "").Replace("\r\n", "");
            prediction.Trim();
            string[] allResults = prediction.Split(',');
            //for (int i = 0; i < allResults.Length; i++)
            //{
            //    allResults[i] = allResults[i].Trim();
            //}
            List<string> trimmed = new List<string> { };
            foreach (string x in allResults)
            {
                trimmed.Add(x.Trim());
            }
            string finalText = "Recommended Items: <ul>";

            cn.Open();

            foreach (string x in trimmed)
            {
                cmd = new SqlCommand("SELECT DISTINCT productName FROM am_Products WHERE asin like '" + x + "';", cn);
                dr = cmd.ExecuteReader();
                while (dr.Read())
                {
                    finalText += "<li>" + (string)dr["productName"] + "</li>";
                }
                dr.Close();

            }
            finalText += "</ul>";

            cn.Close();
            lblResult2.Text = finalText;
        }

        protected void btnRecc3_Click(object sender, EventArgs e)
        {
            var client = new RestClient("https://ussouthcentral.services.azureml.net/workspaces/b55b28a7fd264c668bfd94ada007237a/services/608466baf0e143538d99844132820ad0/execute?api-version=2.0&details=true%0A%0A");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Postman-Token", "ef6671b7-337f-4a7f-82a1-d2d445edf0a2");
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("Content-Type", "application/json");
            request.AddHeader("Authorization", "Bearer ptPQ+VUI3ozp0cKpDC+PEQg7flrh6txYKZMglN3R31mg+nOt3Q05UMDCCzyu+Gldqq49bj293PJZW5s5WRYREA==");
            request.AddParameter("undefined", "{\r\n  \"Inputs\": {\r\n    \"input1\": {\r\n      \"ColumnNames\": [\r\n        \"reviewerID\",\r\n        \"asin\"\r\n      ],\r\n      \"Values\": [\r\n        [\r\n          \"" + ddlUser3.SelectedItem.Text + "\",\r\n          \"B000WEOQV8\"\r\n        ]\r\n      ]\r\n    }\r\n  },\r\n  \"GlobalParameters\": {}\r\n}", ParameterType.RequestBody);
            IRestResponse response = client.Execute(request);

            lblResult3.Text = response.Content.ToString();

            SqlCommand cmd;
            SqlDataReader dr;
            //ListItem li;

            string prediction = "";

            var results = JObject.Parse(response.Content);
            try
            {
                prediction = results["Results"]["output1"]["value"]["Values"].ToString();
            }
            catch
            {
                lblResult3.Text = "Sorry, we had an error! Please select a different user.";
                return;
            }
            
            prediction = prediction.Replace("[", "").Replace("]", "").Replace("\"", "").Replace("\r\n", "");
            prediction.Trim();
            string[] allResults = prediction.Split(',');
            //for (int i = 0; i < allResults.Length; i++)
            //{
            //    allResults[i] = allResults[i].Trim();
            //}
            List<string> trimmed = new List<string> { };
            foreach (string x in allResults)
            {
                trimmed.Add(x.Trim());
            }
            string finalText = "Recommended Users: <ul>";

            cn.Open();

            foreach (string x in trimmed)
            {
                cmd = new SqlCommand("SELECT DISTINCT reviewerName FROM am_Products WHERE reviewerID like '" + x + "';", cn);
                dr = cmd.ExecuteReader();
                while (dr.Read())
                {
                    finalText += "<li>" + (string)dr["reviewerName"] + "</li>";
                }
                dr.Close();

            }
            finalText += "</ul>";

            cn.Close();
            lblResult3.Text = finalText;
        }

        protected void btnLogin_Click(object sender, EventArgs e)
        {
            if (userName.Text == "415Grader" && pass.Text == "Here2Grade")
            {
                Session["LoggedIn"] = true;
                PanelLogged.Visible = true;
                PanelLogin.Visible = false;
            }
            else
            {
                Session["LoggedIn"] = false;
                lblLogin.Text = "Login Failed.";
            }
        }
    }
}