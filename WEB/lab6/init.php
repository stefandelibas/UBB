<?php

 $db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');

  //get all rooms
  $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID ORDER BY r.RoomID LIMIT 4");
  
  $rooms=array();
  while ($row = $query->fetch(PDO::FETCH_ASSOC)){
    array_push($rooms, array('id' => $row["RoomID"],'price' => $row["Price"],'type' => $row["Type"],'category' => $row["Category"],'hotel' => $row["HotelName"]));
  }

  //$rooms_ids = array_column($rooms, 'id');
  $current_rooms=array();
  for($i=0;$i<4;$i+=1)
  {
    array_push($current_rooms, $rooms[$i]);
  }

header('Content-Type: application/json');
echo json_encode($current_rooms);

?>