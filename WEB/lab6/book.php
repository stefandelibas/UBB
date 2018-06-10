<!DOCTYPE html>
<html lang="en">
<head>
  <title>Stefan Hotels</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href='http://fonts.googleapis.com/css?family=Pacifico' rel='stylesheet' type='text/css'>
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  
  <style>
    /* Remove the navbar's default rounded borders and increase the bottom margin */ 
    .navbar {
      margin-bottom: 50px;
      border-radius: 0;
      background-color: #0f1626;

    }
    
    /* Remove the jumbotron's default bottom margin */ 
     .jumbotron {
      margin-bottom: 0;
      background-color: #ff533d;
    }
   
    /* Add a gray background color and some padding to the footer */
    footer {
      background-color: #0f1626;
      color:white;
      padding: 25px;
    }

    #logo {
	  color:#ff533d;
	  font: 400 16px/1.5 'Pacifico', Helvetica, sans-serif;
	}
  h1  {
    color:#ff533d;
    font: 400 16px/1.5 'Pacifico', Helvetica, sans-serif;
  }
  .filter{
    margin-bottom: 5px;
  }

  img
  {
    width: 500px;
    height: 300px;
    margin-left: 10px;
  }

	  </style>
</head>
<body>

<div class="jumbotron">
  <div class="container text-center">
    <h1>Stefan Hotels</h1>      
    <p>Live is Luxury</p>
  </div>
</div>

<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>                        
      </button>
      <a class="navbar-brand" id="logo" href="#">Stefan Hotels</a>
    </div>
    <div class="collapse navbar-collapse" id="myNavbar">
      <ul class="nav navbar-nav">
        <li class="active"><a href="#">Home</a></li>
        <li><a href="#">Book a room</a></li>
        <li><a href="#">Your Bookings</a></li>
        <li><a href="#">Hotels</a></li>
        <li><a href="#">Contact</a></li>
      </ul>
      <ul class="nav navbar-nav navbar-right">
        <li><a href="#"><span class="glyphicon glyphicon-user"></span> Your Account</a></li>
      </ul>
    </div>
  </div>
</nav>

  

<div class="container">  
 <div class="row">
  <div class="col-sm-6 filter">

  </div>
 </div>  
  <div class="row">
    <div class="col-sm-8">
      <div class="panel panel-primary r1" >
        <div class="panel-heading r1"></div>
        <div class="panel-body r1"></div>
        <div class="panel-footer r1">
            <div>
          <p>Select your dates:</p>
          <input type="text" id="rid" name="rid" value='0'>
          Start Date:
          <input type="date" id="start" name="startDate">
          End Date:
          <input type="date" id="end" name="endDate">
         <button name="submit" type="submit" value="Submit">Book</button>
        </div>
        </div>
      </div>
    </div>
  </div>
</div><br>

<footer class="container-fluid text-center">
  <p>made by &copy;Stefan Delibas </p>  
</footer>


<script type="text/javascript">
  $(document).ready(function(){

    var urlParams = new URLSearchParams(window.location.search);
    $.get("/lab6/getRoom.php", {rid : urlParams.get('id') }, function(result){
    
    $(".panel-heading.r1").html('Hotel '+result[0]["hotel"]+ ' - ' +result[0]["type"]+' room ');
    $(".panel-primary.r1").attr('id', result[0]["id"]);
    $(".panel-body.r1").html('Price:'+result[0]["price"]+' '+
                                'Category:'+result[0]["category"]
                              ); 
    });
    $('.myButton').hide();
    $('#end').blur(function () {
      if($('#end').not(":empty")){
        if ($('#start').not(":empty")) {
         $('.myButton').show();
       }
     }
    });
    $('#rid').hide();
    $('#rid').attr('value',urlParams.get('id'));

    

    
      $('button').on('click', function (event) {
        var data = {rid:urlParams.get('id'),startDate: $('#start').val(),endDate:$('#end').val()};
        $.get("/lab6//saveBooking.php", data, function(result){
          alert(result[0]);
        });

      });

    });
</script>
</body>
</html>
