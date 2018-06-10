<%@ page import="repo.Repository" %>
<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: Stefan-PC
  Date: 5/29/2018
  Time: 1:32 PM
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
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jsPlumb/2.5.8/js/jsplumb.min.js"></script>

    <style type="text/css">
        .container {
            margin-top: 100px;
            background-color: #E6D72A;
        }
        .col-sm-4 {
            background-color: #5BC8AC;
            height: 66%;
        }
        .flex-container{
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;

        }
        #current{
            background-color: #E6D72A;
            color: #5BC8AC;
            padding: 10px;
            font-size: 20px;
            border-radius: 5px;
        }

        .item{
            background-color: #5BC8AC;
            width: 100%;
            padding: 10px;
            font-size: 20px;
            color: #E6D72A;
            min-width: 250px;
            margin: 3px;
        }
        button {
            margin: 5px;
            background-color: #E6D72A;
            color:#5BC8AC;
            border-radius: 20px;
            border: 3px solid #5BC8AC;
            font-size: 20px;
        }
        .route
        {
            color:#5BC8AC;
            font-size: 32px;

        }




    </style>
</head>
<body>

<div class="container">
    <div class="row">
        <div class="route">
            Your final route is:
            <%
                Repository repository = (Repository)session.getAttribute("repository");
                ArrayList<String> citiesOnRoute = repository.getCitiesOnRoute();
                for(int i=0;i<citiesOnRoute.size();i++) {
                    out.print(citiesOnRoute.get(i));
                    if(i!=citiesOnRoute.size()-1)
                        out.print(" -> ");
                }
            %>
        </div>
    </div>
</div>

</body>
</html>
