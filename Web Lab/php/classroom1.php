<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
    echo "1 ans: " ;
    echo "Hello, World!";

    echo"<br";
    echo "2 ans:";
    $name = "Manjila";
    $age = 18;
    $gpa = 3.14;
    $isEnrolled = true;
    $graduated = null;

    echo "Name: " . $name . "<br>";
    echo "Age: " . $age . "<br>";
    echo "GPA: " . $gpa . "<br>";
    echo "Is Enrolled: " . ($isEnrolled ? "Yes" : "No") . "<br>";
    echo "Graduated: " . ($graduated === null ? "Not Graduated" : "Graduated") . "<br>";

    echo "3 ans: ";
    $firstName = "Ada";
    $lasteName = "Lovelace";
    $fullName = $firstName . " " . $lasteName;
    echo " $fullName Programmer " . "<br>";


    echo "4 ans: ";
    $fullName = "$lasteName, $firstName";
    echo "$fullName Programmer " . "<br>";


    echo "5 ans: ";
    $csv = "Alice,85,Maths;Bob,90,Science;Carol,78,English";
    $students = explode(";", $csv);
    foreach ($students as $student) {
        list($name, $score, $subject) = explode(",", $student);
        echo "Name: $name, Score: $score, Subject: $subject<br>";
    }

    echo "6 ans: ";
    $queue = ["Task1", "Task2", "Task3"];
    array_push($queue, "Task4");
    array_unshift($queue, "Task0");
    array_pop($queue);
    array_shift($queue);
    foreach ($queue as $task) {
        echo "$task<br>";
    }


    echo "7 ans: ";
    function factorial($n){
        if ($n == 0 || $n == 1) {
            return 1;
        } else {
            return $n * factorial($n - 1);
        }
    }
    echo "Factorial of 0 is: " . factorial(0) . "<br>";
    echo "Factorial of 5 is: " . factorial(5) . "<br>";
    echo "Factorial of 10 is: " . factorial(10) . "<br>";





    ?>

</body>
</html>