<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Recommender.aspx.cs" Inherits="LendingWebsite.Recommender" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <asp:Panel ID="PanelLogin" runat="server">
            <table>
                <tr>
                    <td>User:</td>
                    <td>
                        <asp:TextBox ID="userName" runat="server"></asp:TextBox></td>
                </tr>
                <tr>
                    <td>Password:</td>
                    <td>
                        <asp:TextBox ID="pass" runat="server" TextMode="Password"></asp:TextBox></td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <asp:Button ID="btnLogin" runat="server" Text="Login" OnClick="btnLogin_Click" /></td>
                </tr>
                <tr>
                    <td>
                        <asp:Label ID="lblLogin" runat="server" Text=""></asp:Label>
                    </td>
                </tr>
            </table>
            <%--Put text boxes here and link to users table
            do a page load function and check session variable for login  Session["LoggedIn"] 
                then do PanelLogin.Visible = false etc
                make a button for login and check login and password then do Session["LoggedIn"] = true--%>
        </asp:Panel>
        <asp:Panel ID="PanelLogged" runat="server">
        <div>
            <fieldset>
                <legend>Amazon Recommender: Item Recommendation</legend>
                Pick a User: <asp:DropDownList ID="ddlUser" runat="server"></asp:DropDownList> <br />
                Pick an Item: <asp:DropDownList ID="ddlItem" runat="server"></asp:DropDownList> <br />
                <asp:Button ID="btnRecc" runat="server" Text="Recommend" OnClick="btnRecc_Click" /> <br /><br />
                <asp:Label ID="lblResult" runat="server" Text=""></asp:Label> <br />
                Want to try my error handler? Select User "921" and Item "Gardeneer by Dalen..."
            </fieldset>
            <fieldset>
                <legend>Amazon Recommender: Related Item Recommendation</legend>
                <%--<asp:DropDownList ID="ddlUser2" runat="server"></asp:DropDownList> <br />--%>
                Pick an Item:<asp:DropDownList ID="ddlItem2" runat="server"></asp:DropDownList> <br />
                <asp:Button ID="btnRecc2" runat="server" Text="Recommend" OnClick="btnRecc2_Click" /> <br />
                <asp:Label ID="lblResult2" runat="server" Text=""></asp:Label>
            </fieldset>
            <fieldset>
                <legend>Amazon Recommender: Related User Recommendation</legend>
                Pick a User:<asp:DropDownList ID="ddlUser3" runat="server"></asp:DropDownList> <br />
                <%--<asp:DropDownList ID="ddlItem3" runat="server"></asp:DropDownList> <br />--%>
                <asp:Button ID="btnRecc3" runat="server" Text="Recommend" OnClick="btnRecc3_Click" /> <br />
                <asp:Label ID="lblResult3" runat="server" Text=""></asp:Label>
            </fieldset>
        </div>
        </asp:Panel>
    </form>
</body>
</html>
