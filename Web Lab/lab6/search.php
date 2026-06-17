<?php

    $searchQuery = $_GET['q'] ?? "";


    $connection = new mysqli("127.0.0.1","bikash","bikash123","ecommerce",3306);

    if($connection->connect_error){
        die("Connection Failed: " . $connection->connect_error);
    }


    $fetchProductsSql = "SELECT * FROM products WHERE name LIKE ? LIMIT 10";

    $stmt = $connection->prepare($fetchProductsSql);

    $searchCondtionValue = $searchQuery . "%";
    $stmt->bind_param("s", $searchCondtionValue);
    $stmt->execute();
    $result = $stmt->get_result();

    $products = $result->fetch_all(MYSQLI_ASSOC);
    // echo "<pre>";
    // print_r($products);
    // echo "</pre>";
    $jsonResponse = json_encode($products);

    echo $jsonResponse;


?>