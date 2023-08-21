import java.math.BigInteger

class EncryptDecrypt {
    companion object{
        fun encrypt(publicKey: BigInteger, n: BigInteger, text: String): List<BigInteger>{
            val encrypted = mutableListOf<BigInteger>()
            var i = 0

            while(i<text.length){
                val charText = text[i]
                val charCode = text[i].toInt() // deprecated, change later with Char.code
                println("$charText : $charCode => " + BigInteger(charCode.toString()).pow(publicKey.toInt()).mod(n))
                encrypted.add(i, BigInteger(charCode.toString()).pow(publicKey.toInt()).mod(n))
                i++
            }

            return encrypted
        }


        private fun parseEncryptedData(encrypted: String){
            // coming soon TODO
        }

        fun decrypt(encrypted: String){
            // coming soon TODO
        }
    }
}