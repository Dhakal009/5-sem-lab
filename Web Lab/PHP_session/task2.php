<?php
        session_start();

        if (!isset($_SESSION['count'])) {
                $_SESSION['count'] = 0;
        }

        $_SESSION['count']++;
        $count = $_SESSION['count'];


        echo "You have visited this page ".$count." times";



?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <br>
    <a href="./task2_reset.php"><h2>RESET</h2></a>
</body>
</html>


