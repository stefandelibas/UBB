<?php
 $db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');
  if (isset($_GET['rid'])) {
        $rid = $_GET['rid'];
    }
  $query = $db->query("SELECT * FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID=$rid");
  
  $rooms=array();
  while ($row = $query->fetch(PDO::FETCH_ASSOC)){
    array_push($rooms, array('id' => $row["RoomID"],'price' => $row["Price"],'type' => $row["Type"],'category' => $row["Category"],'hotel' => $row["HotelName"]));
  }

header('Content-Type: application/json');
echo json_encode($rooms);

?>

