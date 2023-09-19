<?php
    include("./math/euclidGCD.php");


    /*

        Function to generate public key
        accept parameter the result of x_of_n calculated before in order to make the public key

        return integer
        Error code flag -1
    */

    function generatePublicKey($x_of_n){
        for ($i = 3; $i < $x_of_n; $i++) { 
            if(euclidGCD($i, $x_of_n)){
                return $i;
            }
        }

        return -1;
    }

    /*

        Function to generate private key
        accept parameter the result of x_of_n calculated before and public key generated before in order to make the private key

        return integer
        Error code flag -1
    */

    function generatePrivateKey($x_of_n, $public_key){
        for ($privK = 3; $privK <= $x_of_n; $privK++) { 
            if(($public_key * $privK) % $x_of_n === 1){
                return $privK;
            }
        }

        return -1;
    }


    /*
        Function to calculate x_of_n
    */
    function find_x_of_n($p, $q){
        return ($p - 1) * ($q -1);
    }
?>