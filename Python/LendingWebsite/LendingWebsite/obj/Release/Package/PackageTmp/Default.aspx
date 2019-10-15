<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="LendingWebsite.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <script src="jquery-3.3.1.min.js"></script>
</head>
<body>
    <form id="form1" runat="server">
       <%-- <asp:Panel ID="PanelLogin" runat="server">
            <%--Put text boxes here and link to users table--%>
            <%--do a page load function and check session variable for login  Session["LoggedIn"] 
                then do PanelLogin.Visible = false etc
                make a button for login and check login and password then do Session["LoggedIn"] = true
        </asp:Panel>
        <asp:Panel ID="PanelLogged" runat="server">--%>
            <div>
                <h1>Lending Club Predictor</h1>
                <table>
                    <%--<tr>
                        <td>Home Owner Status*:</td>
                        <td>
                            <asp:RadioButtonList ID="rblHomeOwn" runat="server">
                            <asp:ListItem Value="OWN">Own</asp:ListItem>
                            <asp:ListItem Value="RENT">Rent</asp:ListItem>
                            <asp:ListItem Value="MORTGAGE">Mortgage</asp:ListItem>
                            </asp:RadioButtonList>
                            <asp:RadioButtonList ID="RadioButtonList1" runat="server"></asp:RadioButtonList>
                        </td>
                        <td>
                            <asp:RequiredFieldValidator 
                                ID="ValidHO" runat="server" 
                                ControlToValidate="rblHomeOwn"
                                Display="Dynamic" 
                                ErrorMessage="Required"></asp:RequiredFieldValidator>
                        </td>
                    </tr>
                    <tr>
                        <td>Income Verification Status*:</td>
                        <td>
                            <asp:RadioButtonList ID="rblVerify" runat="server">
                                <asp:ListItem>Verified</asp:ListItem>
                                <asp:ListItem>Source Verified</asp:ListItem>
                                <asp:ListItem>Not Verified</asp:ListItem>
                            </asp:RadioButtonList>
                        </td>
                        <td>
                            <asp:RequiredFieldValidator 
                                ID="ValidV" runat="server" 
                                ControlToValidate="rblVerify"
                                Display="Dynamic" 
                                ErrorMessage="Required"></asp:RequiredFieldValidator>
                        
                        </td>
                    </tr>--%>
                    <%--<tr>
                        <td>Loan Purpose:</td>
                        <td>
                            <asp:DropDownList ID="ddlPurpose" runat="server">
                                <asp:ListItem>Other</asp:ListItem>
                                <asp:ListItem>Debt consolidation</asp:ListItem>
                                <asp:ListItem>Credit card refinancing</asp:ListItem>
                                <asp:ListItem>Major purchase</asp:ListItem>
                                <asp:ListItem>Business</asp:ListItem>
                                <asp:ListItem>Moving and relocation</asp:ListItem>
                                <asp:ListItem>Home improvement</asp:ListItem>
                                <asp:ListItem>Car financing</asp:ListItem>
                                <asp:ListItem>Green loan</asp:ListItem>
                                <asp:ListItem>Home buying</asp:ListItem>
                                <asp:ListItem>Medical expenses</asp:ListItem>
                                <asp:ListItem>Vacation</asp:ListItem>
                            </asp:DropDownList>
                        
                        </td>
                    </tr>--%>
                    <tr>
                        <td>Years Employed:</td>
                        <td>
                            <asp:DropDownList ID="ddlEmployYears" runat="server">
                                <asp:ListItem>&lt; 1 year</asp:ListItem>
                                <asp:ListItem>1 year</asp:ListItem>
                                <asp:ListItem>2 years</asp:ListItem>
                                <asp:ListItem>3 years</asp:ListItem>
                                <asp:ListItem>4 years</asp:ListItem>
                                <asp:ListItem>5 years</asp:ListItem>
                                <asp:ListItem>6 years</asp:ListItem>
                                <asp:ListItem>7 years</asp:ListItem>
                                <asp:ListItem>8 years</asp:ListItem>
                                <asp:ListItem>9 years</asp:ListItem>
                                <asp:ListItem>10+ years</asp:ListItem>
                            </asp:DropDownList>
                        </td>
                    </tr>
                    <%--<tr>
                        <td>Annual Income*:</td>
                        <td>
                            <asp:TextBox ID="txtIncome" runat="server"></asp:TextBox>
                            <asp:RequiredFieldValidator 
                                ID="ValidI" runat="server" 
                                ControlToValidate="txtIncome"
                                Display="Dynamic" 
                                ErrorMessage="Required"></asp:RequiredFieldValidator>
                            <asp:RangeValidator 
                                ID="RangeIncome" runat="server"
                                ControlToValidate="txtIncome"
                                MaximumValue="999999999"
                                MinimumValue="0"
                                ErrorMessage="Must be greater than zero."></asp:RangeValidator></td>
                    </tr>
                    <tr>
                        <td>DTI*:</td>
                        <td>
                            <asp:TextBox ID="txtDTI" runat="server"></asp:TextBox>
                            <asp:RequiredFieldValidator 
                                ID="ValidDTI" runat="server" 
                                ControlToValidate="txtDTI"
                                Display="Dynamic" 
                                ErrorMessage="Required"></asp:RequiredFieldValidator>
                            <asp:RangeValidator 
                                ID="RangeDTI" runat="server"
                                ControlToValidate="txtDTI"
                                MaximumValue="999999999"
                                MinimumValue="0"
                                ErrorMessage="Must be greater than zero."></asp:RangeValidator>
                        </td>
                    </tr>
                    <tr>
                        <td>Delinquencies in the Past 2 Years*:</td>
                        <td>
                            <asp:TextBox ID="txtDelinq2y" runat="server"></asp:TextBox>
                            <asp:RequiredFieldValidator 
                                ID="ValidD2Y" runat="server" 
                                ControlToValidate="txtDelinq2y"
                                Display="Dynamic" 
                                ErrorMessage="Required"></asp:RequiredFieldValidator>
                            <asp:RangeValidator 
                                ID="RangeD2Y" runat="server"
                                ControlToValidate="txtDelinq2y"
                                MaximumValue="999999999"
                                MinimumValue="0"
                                ErrorMessage="Must be greater than zero."></asp:RangeValidator>
                        </td>
                    </tr>--%>
                    <%--<tr>
                        <td>Days Since Earliest Credit Line Opened*:</td>
                        <td>
                            <asp:TextBox ID="txtEarly" runat="server"></asp:TextBox>
                            <asp:RequiredFieldValidator 
                                ID="ValidE" runat="server" 
                                ControlToValidate="txtEarly"
                                Display="Dynamic" 
                                ErrorMessage="Required"></asp:RequiredFieldValidator>
                            <asp:RangeValidator 
                                ID="RangeE" runat="server"
                                ControlToValidate="txtEarly"
                                MaximumValue="999999999"
                                MinimumValue="0"
                                ErrorMessage="Must be greater than zero."></asp:RangeValidator>
                        </td>
                    </tr>
                    <tr>
                        <td>FICO Range Lower Bound:</td>
                        <td><asp:TextBox ID="txtFico" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Inquiries in the Past 6 Months:</td>
                        <td><asp:TextBox ID="txtInq6m" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Months Since Last Delinquency:</td>
                        <td><asp:TextBox ID="txtDelinqM" runat="server"></asp:TextBox></td>
                    </tr>--%>
                    <tr>
                        <td>Number of Open Credit Lines:</td>
                        <td><asp:TextBox ID="txtOpenCredLine" runat="server"></asp:TextBox></td>
                    </tr>
                    <%--<tr>
                        <td>Number of Derogatory Public Records:</td>
                        <td><asp:TextBox ID="txtDerag" runat="server"></asp:TextBox></td>
                    </tr>--%>
                    <%--<tr>
                        <td>Total Credit Revolving Balance:</td>
                        <td><asp:TextBox ID="txtRevolve" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Revolving Line Utilization Rate:</td>
                        <td><asp:TextBox ID="txtUtilRate" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Total Number of Credit Lines:</td>
                        <td><asp:TextBox ID="txtNumCL" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Number of Collections in 12 Months:</td>
                        <td><asp:TextBox ID="txtCol12m" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Accounts Now Delinquent:</td>
                        <td><asp:TextBox ID="txtAccDelinq" runat="server"></asp:TextBox></td>
                    </tr>--%>
                   <%-- <tr>
                        <td>Total Current Balance:</td>
                        <td><asp:TextBox ID="txtTotCurBal" runat="server"></asp:TextBox></td>
                    </tr>--%>
                    <tr>
                        <td>Number of Revovling Trades Opened in Past 24 Months:</td>
                        <td><asp:TextBox ID="txtRevol24m" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Balance to Credit Limit on All Trades:</td>
                        <td><asp:TextBox ID="txtCLTrade" runat="server"></asp:TextBox></td>
                    </tr>
                    <%--<tr>
                        <td>Inquiries in the Past 12 Months:</td>
                        <td><asp:TextBox ID="txtInq12m" runat="server"></asp:TextBox></td>
                    </tr>--%>
                    <tr>
                        <td>Number of Accounts Opened in the Past 24 Months:</td>
                        <td><asp:TextBox ID="txtAccOp12m" runat="server"></asp:TextBox></td>
                    </tr>
                    <%--<tr>
                        <td>Number of Chargeoffs Within 12 Months:</td>
                        <td><asp:TextBox ID="txtCharge12m" runat="server"></asp:TextBox></td>
                    </tr>--%>
                    <%--<tr>
                        <td>Deliquency Amounts Due:</td>
                        <td><asp:TextBox ID="txtDelinqAmt" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Number of Mortgage Accounts:</td>
                        <td><asp:TextBox ID="txtMortNum" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Public Record Bankruptcies:</td>
                        <td><asp:TextBox ID="txtBankrupt" runat="server"></asp:TextBox></td>
                    </tr>
                    <tr>
                        <td>Number of Tax Liens:</td>
                        <td><asp:TextBox ID="txtTaxLien" runat="server"></asp:TextBox></td>
                    </tr>--%>
                    <tr>
                        <td></td>
                        <td>
                            <asp:Button ID="btnPredict" runat="server" Text="Predict" OnClick="btnPredict_Click" />
                        </td>
                    </tr>
                </table>
            
                <h2>Results:</h2>
                <asp:Label ID="lblResults" runat="server" Text=""></asp:Label>
                <%--Key:
                <table>
                    <tr>
                        <td>1</td>
                        <td>Charged Off</td>
                    </tr>
                    <tr>
                        <td>2</td>
                        <td>Default</td>
                    </tr>
                    <tr>
                        <td>3</td>
                        <td>Late (31-120 days)</td>
                    </tr>
                    <tr>
                        <td>4</td>
                        <td>Late (16-30 days)</td>
                    </tr>
                
                    <tr>
                        <td>5</td>
                        <td>In Grace Period</td>
                    </tr>
                    <tr>
                        <td>6</td>
                        <td>Current</td>
                    </tr>
                    <tr>
                        <td>7</td>
                        <td>Fully Paid</td>
                    </tr>
                </table>--%>
            </div>
        <%--</asp:Panel>--%>
    </form>
</body>
</html>
