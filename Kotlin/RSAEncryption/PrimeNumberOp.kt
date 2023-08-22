package RSAEncryption

class PrimeNumberOp{

    companion object {
        private fun isPrime(number: Int): Boolean{
            if(number < 2){
                return false
            }

            for(i in 2..(number/2)+1){
                if(number % i == 0){
                    return false
                }
            }

            return true
        }

        private fun generatePrimeNumber(min: Int, max: Int): Int{
            var number = (min..max).random()

            while(!isPrime(number)){
                number = (min..max).random()
            }

            return number
        }

        fun getPrimeNumber(min: Int, max: Int): Int{
            return generatePrimeNumber(min, max)
        }
    }

}