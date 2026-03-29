<?php

    class Database {
        public $connection;
        public function __construct($host, $username, $password, $dbname) {
            $this->host = $host;
            $this->username = $username;
            $this->password = $password;
            $this->dbname = $dbname;
        }


        public function connect() {
            $this->connection = new mysqli($this->host, $this->username, $this->password, $this->dbname);

            if ($this->connection->connect_error) {
                die("Connection failed: " . $this->connection->connect_error);
            }

            echo "Connected successfully";
        }

        public function insert($table, array $data) {
            $columns = implode(", ", array_keys($data));
            $placeholders = implode(", ",array_map(function($data){
                return "?";
            }, $data));

            $insertSQL = "INSERT INTO $table ($columns) VALUES ($placeholders)";
            $preparedstmt = $this->connection->prepare($insertSQL);
            $preparedstmt->bind_param($types, ...array_values($data));
            return $preparedstmt->execute();

        }


        public function all($table) {
            $sql = "SELECT * FROM $table";
            $result = $this->connection->query($sql);

            return $result->fetch_all(MYSQLI_ASSOC);
        }
    }




?>