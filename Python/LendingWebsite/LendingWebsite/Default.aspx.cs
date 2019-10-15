using Newtonsoft.Json.Linq;
using RestSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace LendingWebsite
{
    public partial class Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //SqlConnection con = new SqlConnection("Server=tcp:is41518.database.windows.net,1433;Initial Catalog=is415;Persist Security Info=False;User ID=is41518@is41518;Password=WeAreGroup8;MultipleActiveResultSets=False;Encrypt=True;TrustServerCertificate=False;Connection Timeout=30;");
            //SqlCommand cmd = new SqlCommand("SELECT Status FROM LendingHO", con);
            //SqlDataReader dr;
            //ListItem li;

            //con.Open();
            //dr = cmd.ExecuteReader();
            //while (dr.Read()) {
            //    li = new ListItem((string)dr["Status"]);
            //    RadioButtonList1.Items.Add(li);
            //}
            //dr.Close();

            //RadioButtonList1.DataBind();
            //con.Close();
        }



        protected void btnPredict_Click(object sender, EventArgs e)
        {
            //if (Page.IsValid) {
            //var client = new RestClient("https://ussouthcentral.services.azureml.net/workspaces/b55b28a7fd264c668bfd94ada007237a/services/cabe5d00a3514ba5b30762c2d4b41960/execute?api-version=2.0&details=true");
            //var request = new RestRequest(Method.POST);
            //request.AddHeader("Postman-Token", "fe639fa5-9b48-4b9f-87c3-e7f36804ea6b");
            //request.AddHeader("cache-control", "no-cache");
            //request.AddHeader("Content-Type", "application/json");
            //request.AddHeader("Authorization", "Bearer YXmJ6QeExCBtQoV5Iska414ACBHoylhlVMbEy1mzR+8NRGh9TTQpqWmQ0C84K0MaJhpJZ3sBgxBsixZiXOSjTg==");
            //request.AddParameter("undefined", "{\r\n  \"Inputs\": {\r\n    \"input1\": {\r\n      \"ColumnNames\": [\r\n        \"loan_title\",\r\n        \"emp_length\",\r\n        \"home_ownership\",\r\n        \"annual_inc\",\r\n        \"income_verification\",\r\n        \"dti\",\r\n        \"delinq_2yrs\",\r\n        \"earliest_cr_line_days\",\r\n        \"fico_range_low\",\r\n        \"inq_last_6mths\",\r\n        \"mths_since_last_delinq\",\r\n        \"open_acc\",\r\n        \"pub_rec\",\r\n        \"revol_bal\",\r\n        \"revol_util\",\r\n        \"total_acc\",\r\n        \"collections_12_mths_ex_med\",\r\n        \"acc_now_delinq\",\r\n        \"tot_cur_bal\",\r\n        \"open_rv_24m\",\r\n        \"all_util\",\r\n        \"inq_last_12m\",\r\n        \"acc_open_past_24mths\",\r\n        \"chargeoff_within_12_mths\",\r\n        \"delinq_amnt\",\r\n        \"mort_acc\",\r\n        \"pub_rec_bankruptcies\",\r\n        \"tax_liens\"\r\n      ],\r\n      \"Values\": [\r\n        [\r\n          \""+ ddlPurpose.SelectedItem.Text +"\",\r\n          \"" + ddlEmployYears.SelectedItem.Text + "\",\r\n          \"" + rblHomeOwn.SelectedValue + "\",\r\n          \"" + txtIncome.Text + "\",\r\n          \"" + rblVerify.SelectedItem.Text + "\",\r\n          \"" + txtDTI.Text + "\",\r\n          \"" + txtDelinq2y.Text + "\",\r\n          \"" + txtEarly.Text + "\",\r\n          \"" + txtFico.Text + "\",\r\n          \"" + txtInq6m.Text + "\",\r\n          \"" + txtDelinqM.Text + "\",\r\n          \"" + txtOpenCredLine.Text + "\",\r\n          \"" + txtDerag.Text + "\",\r\n          \"" + txtRevolve.Text + "\",\r\n          \"" + txtUtilRate.Text + "\",\r\n          \"" + txtNumCL.Text + "\",\r\n          \"" + txtCol12m.Text + "\",\r\n          \"" + txtAccDelinq.Text + "\",\r\n          \"" + txtTotCurBal.Text + "\",\r\n          \"" + txtRevol24m.Text + "\",\r\n          \"" + txtCLTrade.Text + "\",\r\n          \"" + txtInq12m.Text + "\",\r\n          \"" + txtAccOp12m.Text + "\",\r\n          \"" + txtCharge12m.Text + "\",\r\n          \"" + txtDelinqAmt.Text + "\",\r\n          \"" + txtMortNum.Text + "\",\r\n          \"" + txtBankrupt.Text + "\",\r\n          \"" + txtTaxLien.Text + "\"\r\n        ]\r\n      ]\r\n    }\r\n  },\r\n  \"GlobalParameters\": {}\r\n}", ParameterType.RequestBody);
            //IRestResponse response = client.Execute(request);
            var client = new RestClient("https://ussouthcentral.services.azureml.net/workspaces/b55b28a7fd264c668bfd94ada007237a/services/26e6a3fee8914a1f9df75500946ba501/execute?api-version=2.0&details=true");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Postman-Token", "fe259614-4a84-4e11-a3de-77d41abc181a");
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("Content-type", "application/json");
            request.AddHeader("Authorization", "Bearer v7DLs3latguGdKiQeW59GUHa+qF7fRWDEEpKQfaob1qXcXVPgwjD7UQWfuUpOK+z4yro8cy+VEV5+i2Mqse4XA==");
            request.AddParameter("undefined", "{\r\n  \"Inputs\": {\r\n    \"input1\": {\r\n      \"ColumnNames\": [\r\n        \"emp_length\",\r\n        \"open_acc\",\r\n        \"open_rv_24m\",\r\n        \"all_util\",\r\n        \"acc_open_past_24mths\"\r\n      ],\r\n      \"Values\": [\r\n        [\r\n          \"" + ddlEmployYears.SelectedItem.Text + "\",\r\n          \"" + txtOpenCredLine.Text + "\",\r\n          \"" + txtRevol24m.Text + "\",\r\n          \"" + txtCLTrade.Text + "\",\r\n          \"" + txtAccOp12m.Text + "\"\r\n        ]\r\n      ]\r\n    }\r\n  },\r\n  \"GlobalParameters\": {}\r\n}", ParameterType.RequestBody);
            IRestResponse response = client.Execute(request);
            //lblResults.Text = response.Content.ToString();

            var results = JObject.Parse(response.Content);
                string prediction = results["Results"]["output1"]["value"]["Values"].ToString();
                prediction = prediction.Replace("[", "").Replace("]", "").Replace("\"", "");
                lblResults.Text = prediction;
            //}
        }
    }
}