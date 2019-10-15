using RestSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication4
{
    public partial class Demo : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void lbSubmit_Click(object sender, EventArgs e)
        {
            var client = new RestClient("https://ussouthcentral.services.azureml.net/workspaces/b55b28a7fd264c668bfd94ada007237a/services/165c845feba64b2fa9359b9f67b10f46/execute?api-version=2.0&details=true");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Postman-Token", "d2edb6ab-99dc-442a-b81b-f6ed1fa847c3");
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("Content-Type", "application/json");
            request.AddHeader("Authorization", "Bearer bcRyPjyTyMirwqKXUMWJ0/0bC5XF6n//cGK3+T0iPbEFQeuVihntra3h4BWCgIugOwfEFcAokJ36Pta0JzBcOA==");
            request.AddParameter("undefined", "{\r\n  \"Inputs\": {\r\n    \"input1\": {\r\n      \"ColumnNames\": [\r\n        \"Marital Status\",\r\n        \"Gender\",\r\n        \"Income\",\r\n        \"Children\",\r\n        \"Cars\",\r\n        \"Age\",\r\n        \"Education\",\r\n        \"Occupation\",\r\n        \"Home Owner\",\r\n        \"Commute Distance\",\r\n        \"Region\"\r\n      ],\r\n      \"Values\": [\r\n        [\r\n          \"" + rblMaritalStatus.SelectedItem + "\",\r\n          \"Male\",\r\n          \"60000\",\r\n          \"0\",\r\n          \"0\",\r\n          \"24\",\r\n          \"Bachelors\",\r\n          \"Professional\",\r\n          \"No\",\r\n          \"0-1 Miles\",\r\n          \"North America\"\r\n        ]\r\n      ]\r\n    }\r\n  },\r\n  \"GlobalParameters\": {}\r\n}", ParameterType.RequestBody);
            IRestResponse response = client.Execute(request);

            lblResults.Text = response.Content.ToString();
        }
    }
}