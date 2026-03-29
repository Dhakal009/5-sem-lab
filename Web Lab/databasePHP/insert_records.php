<?php
    require_once "connection.php";

    $users = [
        ["Manjil Smith", "manjil@gmail.com", "manjil123"],
        ["Aarav Shah", "aarav@gmail.com", "aarav123"],
        ["Nina Roy", "nina@gmail.com", "nina123"],
        ["Riya Das", "riya@gmail.com", "riya123"],
        ["Sohan Khan", "sohan@gmail.com", "sohan123"],
    ];

    $insertSQL="INSERT INTO users (name, email, password) 
    VALUES (?, ?, ?)";

    $preparedstmt=$connection->prepare($insertSQL);

    if ($preparedstmt === false) {
        die("Error preparing statement");
    }

    foreach ($users as $user) {
        $name = $user[0];
        $email = $user[1];
        $password = $user[2];

        $preparedstmt->bind_param("sss", $name, $email, $password);
        $result=$preparedstmt->execute();

        if($result===false){
            die("Error inserting record: " . $preparedstmt->error);
        }
    }

    echo "<br/>" . count($users) . " records inserted successfully";
?>