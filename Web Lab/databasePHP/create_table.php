<?php

    require_once "connection.php";

    $tableSql="CREATE TABLE IF NOT EXISTS users (
        id INT PRIMARY KEY AUTO_INCREMENT,
        name VARCHAR(255) NOT NULL,
        email VARCHAR(255) NOT NULL UNIQUE,
        password VARCHAR(255) NOT NULL,
        verified_at DATETIME,
        CREATED_AT TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    )";

    $result=$connection->query($tableSql);
    if($result===false){
        die("Error creating table: ");
    } else {
        echo "Table created successfully";
    }