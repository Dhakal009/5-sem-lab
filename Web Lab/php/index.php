<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bank-Account</title>
</head>
<body>
    <?php
        // $customers = [
        //     "Alice" => 1000,
        //     "Bob" => 500,
        //     "Charlie" => 0
        // ];
        
        // function deposit(&$customers, $name, $amount){
        //     $customers[$name] += $amount;
        //     return $customers;
        // }
        // function withdraw(&$customers, $name, $amount){
        //     if ($customers[$name] >= $amount) {
        //         $customers[$name] -= $amount;
        //     } else {
        //         echo "Insufficient funds for $name.<br>";
        //     }
        //     return $customers;
        // }
        // function transfer(&$customers, $from, $to, $amount){
        //     if ($customers[$from] >= $amount) {
        //         $customers[$from] -= $amount;
        //         $customers[$to] += $amount;
        //     } else {
        //         echo "Insufficient funds for transfer from $from to $to.<br>";
        //     }
        //     return $customers;
        // }

        // deposit($customers, "Alice", 200);
        // withdraw($customers, "Bob", 100);
        // withdraw($customers, "Charlie", 200);
        // transfer($customers, "Alice", "Charlie", 300);

        // echo "Account Summary:<br>";

        // foreach ($customers as $name => $balance) {
        //     echo "$name: $balance<br>";
        // }

        interface Depositable {
            public function deposit($amount);
        }

        class BankAccount implements Depositable{
            private $name;
            protected $balance;
            protected $rate = 5;

            public function __construct($name, $balance = 0){
                $this->name = $name;
                $this->balance = $balance;  
            }

            public function deposit($amount){
                $this->balance += $amount;
            }
            public function withdraw($amount){
                if ($this->balance >= $amount) {
                    $this->balance -= $amount;
                } else {
                    echo "Insufficient funds for withdrawal from {$this->name}.<br>";
                    return;
                }
            }
            public function printStatement(){
                echo "Account Statement for {$this->name}:<br>";
                echo "Balance: {$this->balance}<br>";
            }
            public function transfer($toAccount, $amount){
                if ($this->balance >= $amount) {
                    $this->balance -= $amount;
                    $toAccount->deposit($amount);
                } else {
                    echo "Insufficient funds for transfer.<br>";
                }
            }

            public function calculateInterest($time){
                return $this->balance * ($time * $this->rate) / 100;
            }
            
        }

        class FixedDepositAccount extends BankAccount{
            public function __construct($name,$amount){
                parent::__construct($name, $amount);
                $this->rate = 7;
            }

            public function withdraw($amount){
                throw new Exception("Withdrawals are not allowed from a Fixed Deposit Account.<br>");
            }

            public function deposit($amount){
                $this->balance += $amount +10;
            }

        }

        $aliceAccount = new BankAccount("Alice", 1000);
        $bobAccount = new FixedDepositAccount("Bob", 500);
        $charlieAccount = new BankAccount("Charlie", 0);

        $aliceAccount -> printStatement();
        $bobAccount -> printStatement();
        $charlieAccount -> printStatement();
        echo "<br>";

        $aliceAccount -> deposit(200);
        try {
            $bobAccount -> withdraw(100);
        } catch (Exception $e) {
            echo $e->getMessage();
        }
        $charlieAccount -> withdraw(200);
        $aliceAccount -> transfer($charlieAccount, 300);
        echo "<p> Interest for Alice's account after 1 year: " . $aliceAccount -> calculateInterest(1) . "</p>";
        echo "<br>";


        //update 500 in all account:

        $amountToDeposit = 500;
        $accounts = [$aliceAccount, $bobAccount, $charlieAccount];
        foreach ($accounts as $account) {
            $account -> deposit($amountToDeposit);
        }   

        echo "Updated Account Summary:<br>";
        $aliceAccount -> printStatement();
        $bobAccount -> printStatement();
        $charlieAccount -> printStatement();

    ?>    


</body>
</html>