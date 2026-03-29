<?php

    require_once "connection.php";

    $selectSQL="SELECT * FROM users";
    $result=$connection->query($selectSQL);
    if($result===false){
        die("Error selecting records: ");
    }
    

    while($row=$result->fetch_assoc()){
        echo"<pre>";
        print_r($row);
        echo"</pre>";
    }
?>