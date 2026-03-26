<?php

    class Student{
        private $name;
        private $age;
        private $grade;
        public function __construct($name,$age,$grade){
            $this->name = $name;
            $this->age = $age;
            $this->grade = $grade;

        }

        public function introduce(){
            echo "Hi, I am ". $this->name. ". I am ". $this->age. " years old and I am in grade ". $this->grade;
        }
    }

    $Student = new Student("Bikash",21,"Bachelor");
    $Student->introduce();

?>