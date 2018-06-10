<%@ page import="java.util.List" %>
<%@ page import="repo.Repository" %><%--
  Created by IntelliJ IDEA.
  User: Stefan-PC
  Date: 5/25/2018
  Time: 1:34 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<body><!DOCTYPE html>
<html lang="en">
<head>
    <title>Stefan Hotels</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href='http://fonts.googleapis.com/css?family=Pacifico' rel='stylesheet' type='text/css'>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <link href='http://fonts.googleapis.com/css?family=Pacifico' rel='stylesheet' type='text/css'>

    <style type="text/css">

        body{
            background-color: #E6D72A;
        }

        .flex-container{
            background-color: #E6D72A;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;

        }
        #current{
            background-color: #5BC8AC;
            padding: 3px;
        }


        button {
            margin: 5px;
            background-color: #5BC8AC;
            color:#E6D72A;
            border-radius: 20px;
            border: 3px solid #E6D72A;
            font-size: 25;
        }
        .content
        {
            height: 100%;
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .insertLoc
        {
            font: 400 16px/1.5 'Pacifico', Helvetica, sans-serif;
        }
        h1
        {
            font: 400 32px/1.5 'Pacifico', Helvetica, sans-serif;
        }
    </style>
</head>
<body>
<div class="content">
    <div class="flex-container">
        <div>
            <h1>Welcome to Stefan Bus-line</h1>
        </div>
        <div class="insertLoc">
            Please insert your location:
        </div>
        <div>
            <%
                Repository repository = (Repository)session.getAttribute("repository");
                List<String> cities;
                cities = repository.getAll();
                out.print("<div class=\"styled-select blue semi-square\">");
                out.print("<select id=\"cities\" name=\"cities\">");
                for(int i=0;i<cities.size();i++) {
                    out.print("<option value=\"" + cities.get(i) + "\">" + cities.get(i)  + "</option>");
                }
                out.print("</select></div>");
            %>
            <a class="go" href="" ><button> Let's go!</button></a>
        </div>
    </div>

</div>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jsPlumb/2.5.8/js/jsplumb.min.js"></script>

<script type="text/javascript">

    var ref = "/servlets/set?city=" + $("#cities").find(":selected").text();
    $(".go").attr("href",ref);

    $(document).ready(function() {
        $('select').on('change', function () {
            var ref = "/servlets/set?city=" + $("#cities").find(":selected").text();
            $(".go").attr("href",ref);
        });
    });
</script>
</body>
</html>

