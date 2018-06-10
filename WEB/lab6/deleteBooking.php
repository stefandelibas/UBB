<?php
 $db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');

 $bid='';

$bid = $_POST["bid"];

$query2 = $db->query("DELETE FROM `bookings` WHERE BookingID=$bid");
  

header('Content-Type: application/json');
$result = 'booking deleted';
echo json_encode($result);
?>

