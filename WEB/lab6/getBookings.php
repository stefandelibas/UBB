<?php
 $db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');
  if (isset($_GET['rid'])) {
        $rid = $_GET['rid'];
    }

  $query2 = $db->query("SELECT * FROM bookings as b join rooms as r on r.RoomID=b.RoomID ");
  $rooms=array();
  while ($row1 = $query2->fetch(PDO::FETCH_ASSOC)){
  	$rid = $row1["RoomID"];
  	$bid = $row1["BookingID"];
  $query1 = $db->query("SELECT * from rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID and r.RoomID='$rid'");
  	while ($row = $query1->fetch(PDO::FETCH_ASSOC)){
    array_push($rooms, array('bid' => $row1["BookingID"],'rid' => $row["RoomID"],'price' => $row["Price"],'type' => $row["Type"],'category' => $row["Category"],'hotel' => $row["HotelName"], 'start' => $row1["startDate"], 'end' => $row1["endDate"]));
	}
  }

header('Content-Type: application/json');
echo json_encode($rooms);

?>

