<?php
    function euclidGCD($m, $n){
        $temp = 0;
        
        while ($n != 0) {
            $temp = $m % $n;
            $m = $n;
            $n = $temp;
        }

        return $m;
    }
?>