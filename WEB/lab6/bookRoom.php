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


    .spinner {
        background-color: #333;
        z-index: 100;
        position: absolute;
        top: 50%;
        left: 50%;
        width: 200px;
        height: 100px;
        margin-top: -150px;
        margin-left: -200px;


        margin: 100px auto;
        -webkit-animation: sk-rotateplane 1.2s infinite ease-in-out;
        animation: sk-rotateplane 1.2s infinite ease-in-out;

    }

    @-webkit-keyframes sk-rotateplane {
        0% { -webkit-transform: perspective(120px) }
        50% { -webkit-transform: perspective(120px) rotateY(180deg) }
        100% { -webkit-transform: perspective(120px) rotateY(180deg)  rotateX(180deg) }
    }

    @keyframes sk-rotateplane {
        0% {
            transform: perspective(120px) rotateX(0deg) rotateY(0deg);
            -webkit-transform: perspective(120px) rotateX(0deg) rotateY(0deg)
        } 50% {
              transform: perspective(120px) rotateX(-180.1deg) rotateY(0deg);
              -webkit-transform: perspective(120px) rotateX(-180.1deg) rotateY(0deg)
          } 100% {
                transform: perspective(120px) rotateX(-180deg) rotateY(-179.9deg);
                -webkit-transform: perspective(120px) rotateX(-180deg) rotateY(-179.9deg);
            }
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
        <li><a href="bookRoom.php">Home</a></li>
        <li><a href="bookRoom.php">Book a room</a></li>
        <li><a href="allBookings.html"><span class="glyphicon glyphicon-user"></span>Your Bookings</a></li>
        <li><a href="priceHotels.html">On your budget</a></li>
        <li><a href="Contact.html">Contact</a></li>
      </ul>

    </div>
  </div>
</nav>

  

<div class="container">  
 <div class="row">
  <div class="col-sm-6 filter">

  <?php
  session_start();

  //establish a connection to the database
  $db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');
  
  //populate the filtering options
  $query = $db->query("SELECT Name FROM categories"); 
  echo '<select class="categorySelect" name="category">';
  echo '<option value=""  selected>Select your option</option>';
  while ($row = $query->fetch(PDO::FETCH_ASSOC)) {
    echo '<option value="'.$row['Name'].'">'.$row['Name'].'</option>';
  }
  echo '</select>';
  
  $query = $db->query("SELECT HotelName FROM hotels"); 
  echo '<select class="hotelSelect" name="hotelChoice">';
  echo '<option value="" selected>Select your option</option>';
  while ($row = $query->fetch(PDO::FETCH_ASSOC)) {
    echo '<option value="'.$row['HotelName'].'">'.$row['HotelName'].'</option>';
  }
  echo '</select>';

  $query = $db->query("SELECT Type FROM types"); 
  echo '<select class="typeSelect" name="typeChoice">';
    echo '<option value=""  selected>Select your option</option>';
  while ($row = $query->fetch(PDO::FETCH_ASSOC)) {
    echo '<option value="'.$row['Type'].'">'.$row['Type'].'</option>';
  }
  echo '</select>';
  ?>

  </div>
     <div class="spinner"></div>
 </div>
  <div class="row">
    <div class="col-sm-6">
      <div class="panel panel-primary r1" >
        <div class="panel-heading r1"></div>
        <div class="panel-body">
            <img src="" class="r1" alt="Image">
            <div class="booking r1" style="display: none;">
                <p>Select your dates:</p>
                <input type="text" id="rid1" style="display: none;" name="rid" value='0'>
                Start Date:
                <input type="date" id="start1" name="startDate">
                End Date:
                <input type="date" id="end1" name="endDate">
                <button name="submit" type="submit" value="Submit">Book</button>
            </div>
        </div>
        <div class="panel-footer r1"></div>
      </div>
    </div>
    <div class="col-sm-6"> 
      <div class="panel panel-primary r2">
        <div class="panel-heading r2"></div>
              <div class="panel-body"><img src="" class="r2"  alt="Image"></div>
              <div class="panel-footer r2">
      </div>
    </div>
    
  </div>
</div><br>
   
  <div class="row">
    <div class="col-sm-6">
      <div class="panel panel-primary r3">
        <div class="panel-heading r3"></div>
          <div class="panel-body"><img src="" class="r3" alt="Image"></div>
          <div class="panel-footer r3">
      </div>
    </div>
  </div>
    <div class="col-sm-6"> 
      <div class="panel panel-primary r4">
        <div class="panel-heading r4"></div>
              <div class="panel-body"><img src="" class="r4"  alt="Image"></div>
              <div class="panel-footer r4"></div>
      </div>
  </div>
</div>
<button type="submit" class="back">Previous</button>
<button type="submit" class="next" >Next</button>
<br><br>
</div>
<footer class="container-fluid text-center">
  <p>made by &copy;Stefan Delibas </p>  
</footer>

<script type="text/javascript">

    $('.panel-primary.r1').mouseenter(function(){
        $('.booking.r1').show();
    });

    $('.panel-primary.r1').mouseleave(function(){
        $('.booking.r1').hide();
    });

  $(document).ready(function(){
      $('img').click(function(){
      window.open('/lab6/book.php/?id='+$(this).attr('id'));
    });

    $('.next').click(function(){
        $(".spinner").show();

        $.get(
            '/lab6/next.php',
            {
                rid4:$('.panel-primary.r4').attr('id'),
                category:$('.categorySelect').val(),
                hotel:$('.hotelSelect').val(),
                type:$('.typeSelect').val()
            },
            function (result) {
          populate(result);
          $(".spinner").hide();
        });
    });
    $('.back').click(function(){
        $(".spinner").show();
        $.get('/lab6/back.php',
            {   rid1    :$('.panel-primary.r1').attr('id'),
                category:$('.categorySelect').val(),
                hotel   :$('.hotelSelect').val(),
                type    :$('.typeSelect').val()
            },
            function (result) {
          populate(result);
          $(".spinner").hide();
        });
    });

    $('select').on('change', function() {
          $.get("/lab6/initParams.php",
          {
              category:$('.categorySelect').val(),
              hotel:$('.hotelSelect').val(),
              type:$('.typeSelect').val()
          },
          function(result)
          {
                if (result == undefined || result == null || result.length == 0){
                    alert("there is no result according to your filters");
                }
                  else {
                      populate(result);
                  }

            }
          );
    });

    $.get("/lab6/init.php", {}, function(result){
        $(".spinner").show();
      populate(result);
        $(".spinner").hide();
    });


    function populate(result) {

        var count = 0;
        while (result[count]) {
            count++;
        }

        $('.panel-heading.r1').html(result[0]['hotel']);
        for (i = 1; i <= 4; i++) {
            $(".panel-primary.r" + i).show();
        }


        var i;
        for (i = 0; i < count; i++) {
            var j = i + 1;
            var headingClass = '.panel-heading.r' + j;
            var primaryClass = '.panel-primary.r' + j;
            var footerClass = '.panel-footer.r' + j;
            var imgClass = '.r' + j + ' img';
            $(headingClass).html('Hotel ' + result[i]["hotel"] + ' - ' + result[i]["type"] + ' room ');
            $(imgClass).attr('id', result[i]["id"]);
            $(primaryClass).attr('id', result[i]["id"]);
            $(footerClass).html('Price:' + result[i]["price"] + ' ' +
                'Category:' + result[i]["category"]
            );
            $(imgClass).attr("src", "/lab6/"+result[i]["hotel"] + '.jpg');
        }
        while (i < 4) {
            var j = i + 1;
            $(".panel-primary.r" + j).hide();
            i++;
        }
    }
  });
</script>
</body>
</html>
