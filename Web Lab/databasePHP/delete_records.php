<?php

    require_once "connection.php";

    $deleteSQL="DELETE FROM users WHERE id > ?";
    $preparedstmt=$connection->prepare($deleteSQL);
    $id=3;
    $preparedstmt->bind_param("i", $id);
    $result=$preparedstmt->execute();

    if($result===false){
        die("Error deleting records: " . $preparedstmt->error);
    } else {
        echo "Records deleted successfully";
    }



?>