<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Demo.aspx.cs" Inherits="WebApplication4.Demo" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Please work</h1>

            <asp:RadioButtonList ID="rblMaritalStatus" runat="server">
                <asp:ListItem>Married</asp:ListItem>
                <asp:ListItem>Single</asp:ListItem>
            </asp:RadioButtonList>
            <asp:LinkButton ID="lbSubmit" runat="server" OnClick="lbSubmit_Click">Predict</asp:LinkButton> <br /><br />
            <asp:Label ID="lblResults" runat="server" Text=""></asp:Label>
        </div>
        
    </form>
    
</body>
</html>
