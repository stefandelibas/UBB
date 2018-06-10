<?php

$db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');


$min='';
$max='';

if (isset($_GET['rid4'])) {
    $rid4 = $_GET['rid4'];
}
if (isset($_GET['min'])) {
    $min = $_GET['min'];
}
if (isset($_GET['max'])) {
    $max = $_GET['max'];
}


if($min !== '' && $max !== '' ){
    $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID>'$rid4' and Price>='$min' and Price<='$max' ORDER BY r.RoomID LIMIT 4");
}
else
    if ($min === '' && $max !== '') {
        $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID>'$rid4' and  Price<='$max' ORDER BY r.RoomID LIMIT 4");
    } else
        if ($min !== '' && $max === '') {
            $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID>'$rid4' and Price>='$min'  ORDER BY r.RoomID LIMIT 4");
        } else
            if ($min === '' && $max === '') {
                $query = $db->query("SELECT RoomID,Price,HotelName,Type,Category FROM rooms as r JOIN hotels as h WHERE r.HotelID=h.HotelID AND r.RoomID>'$rid4' ORDER BY r.RoomID LIMIT 4");
            }


$rooms=array();
while ($row = $query->fetch(PDO::FETCH_ASSOC)){
    array_push($rooms, array(
        'id' => $row["RoomID"],
        'price' => $row["Price"],
        'type' => $row["Type"],
        'category' => $row["Category"],
        'hotel' => $row["HotelName"]));
}

$rooms=array();
while ($row = $query->fetch(PDO::FETCH_ASSOC)){
    array_push($rooms, array('id' => $row["RoomID"],'price' => $row["Price"],'type' => $row["Type"],'category' => $row["Category"],'hotel' => $row["HotelName"]));
}

header('Content-Type: application/json');
echo json_encode($rooms);

?>

