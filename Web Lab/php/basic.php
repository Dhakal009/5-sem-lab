<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>First PHP Document</title>
</head>
<body>
    <h1>Hello, World!</h1>

    <?php
        // variable declaration
       $subject = "Web Tech";

       // constant declaration
       define("PI", 3.14);

       // constant declaration using const keyword
       const name = "PHP";

       // output the values
       echo $subject;

       echo "<br>";

       // output the constant values
       echo PI;
       echo "<br>";
       echo name;
       echo "<br>";


       //data types in php
        $integer = 42; // integer
        $float = 3.14; // float
        $string = "Hello, PHP!"; // string
        $boolean = true; // boolean
        $array = [1, 2, 3]; // array
        $nullValue = null; // null


        // array
        $fruits = ["Apple", "Banana", "Cherry"];


        //class and object
        class Car {
            public $make;
            public $model;
            public function __construct($make, $model) {
                $this->make = $make;
                $this->model = $model;
            }
        }
        $myCar = new Car("Toyota", "Corolla");


        //file
       // $file = fopen("example.txt", "r"); // resource


        //string concatenation
        $greeting = "Hello";
        $name = "Alice";
        $message = $greeting . " " . $name ; // string concatenation

        //string interpolation
        $message2 = "{$greeting} {$name}"; // string interpolation

        //string helper functions

        $length = strlen($message); // string length
        $upper = strtoupper($message); // convert to uppercase
        $lower = strtolower($message); // convert to lowercase
        $replaced = str_replace("Hello", "Hi", $message); // replace substring
        $contains = str_contains($message, "Alice"); // check if substring exists
        $substring = substr("Hello, World!", 0, 5); // get substring 
        $ends_with = str_ends_with("Hello, World!", "World!"); // check if string ends with a substring

        $split = explode(" ", $message); // split string into an array
        $implode = implode(" ", $split); // join array into a string


        // array
        $numbers = [1, 2, 3, 4, 5];
        $number = array(1, 2, 3, 4, 5); // array declaration using array() function

        // array helper functions
        $numbers = [10];
        $count = count($numbers); // count elements in array
        $push = array_push($numbers, 6); // add element to end of array
        $pop = array_pop($numbers); // remove last element from array
        $shift = array_shift($numbers); // remove first element from array
        $unshift = array_unshift($numbers, 0); // add element to beginning of array
        $slice = array_slice($numbers, 1, 3); // get a portion of the array
        $merge = array_merge($numbers, [7, 8, 9]); // merge two arrays
        $unique = array_unique([1, 2, 2, 3, 4, 4, 5]); // remove duplicate values


        // associative array(ket value array)(dictionary)(hash maps)

        $capitals = [
            "Nepal" => "Kathmandu",
            "India" => "New Delhi",
            "USA" => "Washington, D.C."
        ];

        echo $capitals["Nepal"];// access value using key
        echo "<br>"; 

        // looping
        for ($i = 0; $i < 5; $i++) {
            echo "Iteration: " . $i . "<br>";
        }

        foreach ($capitals as $country => $capital) {
            echo "The capital of " . $country . " is " . $capital . "<br>";
        }

        // array builtin functions
        array_keys($capitals); // get all keys from the array
        array_values($capitals); // get all values from the array
        array_merge(["a","b"], ["c", "d"]); // merge two arrays ["a", "b", "c", "d"]

        array_column($capitals, "capital"); // get values from a specific column in a multi-dimensional array

        array_map(function($capital) {
            return strtoupper($capital);
        }, $capitals); // apply a callback function to each element of the array

        array_filter($capitals,function($capital){
            return strtolower($capital);
        });


        //Functions

        function printHello(){
            echo "Hello";
        }

        printHello();

        function sum($a,$b){
            return $a + $b;
        }

        $result  = sum(3,6);


        //array functions

        $sum = fn($a,$b) => $a + $b


    ?>
    
</body>
</html>