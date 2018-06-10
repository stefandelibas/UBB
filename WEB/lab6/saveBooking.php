<?php
 $db = new PDO('mysql:host=localhost;dbname=hotelchain', 'root', '');
 	
 	if (isset($_GET['rid'])) {
        $rid = $_GET['rid'];
    }
  	if (isset($_GET['startDate'])) {
        $start = $_GET['startDate'];
    }
	if (isset($_GET['endDate'])) {
	    $end = $_GET['endDate'];
	}


	//start date is between other booking dates
	$check1=$db->query("SELECT COUNT(*) from bookings as b WHERE b.RoomID='$rid' and b.ClientID='1' and b.startDate > '$start' and b.endDate<'$start' ");
	$result = $check1->fetch();
	$count1 = $result[0];
	if($count1 != 0)
	{
		$result=array();
		array_push($result, array('error' => 'error','message' =>'start date between other booking dates! room not available'));
		echo json_encode($result);
		exit();
	}	
	//end date is between other booking dates
	$check2 = $db->query("SELECT COUNT(*) from bookings as b WHERE b.RoomID='$rid' and b.ClientID='1' and b.startDate>'$end' and b.endDate<'$end'");
	$result = $check2->fetch();
	$count2 = $result[0];
	if($count2 != 0)
	{
		$result=array();
		array_push($result, array('error' => 'error','message' =>'end date between other booking dates! room not available'));
		echo json_encode($result);
		exit();
	}
	//end date is between other booking dates
	$check3 = $db->query("SELECT COUNT(*) from bookings as b WHERE b.RoomID='$rid' and b.ClientID='1' and b.startDate>'$start' and b.endDate<'$end' ");
	$result = $check3->fetch();
	$count3 = $result[0];
	if($count3 != 0)
	{
		$result=array();
		array_push($result, array('error' => 'error','message' =>'room not available!'));
		echo json_encode($result);
		exit();
	}




	$start = date('Y-m-d', strtotime(str_replace('-', '/', $start)));
	$end = date('Y-m-d', strtotime(str_replace('-', '/', $end)));

	$query = $db->query("SELECT BookingID from bookings ORDER BY BookingID DESC LIMIT 1");
	$last=array();
	  while ($row = $query->fetch(PDO::FETCH_ASSOC)){
	    array_push($last, $row["BookingID"]);
	  }
	$last[0] += 1;

	
$query=$db->query("INSERT INTO `bookings` (`BookingID`, `RoomID`, `ClientID`, `startDate`, `endDate`) VALUES ($last[0], $rid, '1', '$start', '$end')");

header('Content-Type: application/json');
$result=array();
array_push($result, array('error' => 'no error','message' =>'the booking was succesfully placed!'));
echo json_encode($result);
?>

