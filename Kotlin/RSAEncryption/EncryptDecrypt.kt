package RSAEncryption

import java.math.BigInteger

class EncryptDecrypt {
    companion object{
        fun encrypt(publicKey: BigInteger, n: BigInteger, text: String): List<BigInteger>{
            val encrypted = mutableListOf<BigInteger>()
            var i = 0

            while(i<text.length){
                val charText = text[i]
                val charCode = text[i].code
                encrypted.add(i, BigInteger(charCode.toString()).pow(publicKey.toInt()).mod(n))
                i++
            }

            return encrypted
        }


        private fun parseEncryptedData(encrypted: String): List<BigInteger> {
            val encryptedData = mutableListOf<BigInteger>()
            val buffer = mutableListOf<Char>()
            var i = 0
            var indexBuffer = 0
            var indexEncryptedData = 0

            while(i<encrypted.length){
                if(encrypted[i] != '|'){
                    buffer.add(indexBuffer, encrypted[i])
                    indexBuffer++
                } else {
                    val value = BigInteger(buffer.joinToString(""))
                    encryptedData.add(indexEncryptedData, value)

                    buffer.clear()
                    indexBuffer = 0
                    indexEncryptedData++
                }

                i++
            }

            return encryptedData
        }

        fun decrypt(encrypted: String, privateKey: BigInteger, n: BigInteger): List<Char> {
            // coming soon TODO
            val parsedEncryptedData = parseEncryptedData(encrypted)
            val decryptedData = mutableListOf<Char>()
            var indexDecrypted = 0

            for(data in parsedEncryptedData){
                val resultDecrypted = data.pow(privateKey.toInt()).mod(n)

                decryptedData.add(indexDecrypted, Char(resultDecrypted.toInt()))
            }

            decryptedData.reverse()

            return decryptedData
        }
    }
}