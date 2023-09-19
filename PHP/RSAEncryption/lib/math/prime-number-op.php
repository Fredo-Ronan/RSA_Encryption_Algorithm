/*
    HANDLE Prime Number Operation
*/

<?php 

    /*
        Function to check if the number given in the parameter is a prime number or not
        Return boolean
    */
    function isPrime($number){
        if($number < 2){
            return false;
        }

        for($i = 0; $i < ($number/2) + 1; $i++){
            if($number % $i === 0){
                return false;
            }
        }

        return true;
    }

    /*
        Function to generate random prime number by the range given in the min and max parameter
        Return integer
    */
    function generatePrime($min, $max){
        $primeNumber = rand($min, $max);

        while(!isPrime($primeNumber)){
            $primeNumber = rand($min, $max);
        }

        return $primeNumber;
    }

?>