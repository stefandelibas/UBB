<?php

 $db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');

$hotel = '';
$category = '';
$type = '';

if (isset($_GET['rid1'])) {
    $rid1 = $_GET['rid1'];
}
if (isset($_GET['hotel'])) {
    $hotel = $_GET['hotel'];
}
if (isset($_GET['category'])) {
    $category = $_GET['category'];
}
if (isset($_GET['type'])) {
    $type = $_GET['type'];
}
//get all rooms
if($hotel !== '' && $category !== '' && $type !== ''){
    $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1  and h.HotelName='$hotel' and r.Type='$type' and r.Category='$category' ORDER BY r.RoomID DESC  LIMIT 4");
}
else {
    if ($hotel !== '' && $category !== '') {
        $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1  and h.HotelName='$hotel' and r.Category='$category' ORDER BY r.RoomID DESC  LIMIT 4");
    } else
        if ($hotel !== '' && $type !== '') {
            $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1  and h.HotelName='$hotel' and r.Type='$type' ORDER BY r.RoomID DESC  LIMIT 4");
        } else
            if ($category !== '' && $type !== '') {
                $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1  and r.Type='$type' and r.Category='$category' ORDER BY r.RoomID DESC  LIMIT 4");
            } else
                if ($hotel !== '') {
                    $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1  and h.HotelName='$hotel' ORDER BY r.RoomID DESC  LIMIT 4");
                } else
                    if ($category !== '') {
                        $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1  and r.Category='$category' ORDER BY r.RoomID DESC  LIMIT 4");
                    } else
                        if ($type !== '') {
                            $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1    and r.Type='$type'  ORDER BY r.RoomID DESC  LIMIT 4");
                        } else
                            if ($hotel === '' && $category === '' && $type === '') {
                                $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID<$rid1  ORDER BY r.RoomID DESC LIMIT 4");
                            }
}
  $rooms=array();
  while ($row = $query->fetch(PDO::FETCH_ASSOC)){
    array_push($rooms, array('id' => $row["RoomID"],'price' => $row["Price"],'type' => $row["Type"],'category' => $row["Category"],'hotel' => $row["HotelName"]));
  }
  $current_rooms=array();
  for($i=3;$i>=0;$i-=1)
  {
    array_push($current_rooms, $rooms[$i]);
  }

header('Content-Type: application/json');
echo json_encode($current_rooms);

?>

