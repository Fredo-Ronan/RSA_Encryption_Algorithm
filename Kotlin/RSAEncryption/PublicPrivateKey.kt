package RSAEncryption

import java.math.BigInteger

class PublicPrivateKey {

    companion object {
        fun generatePublicKey(x_of_n: BigInteger): BigInteger {
            var i: BigInteger = BigInteger("3")

            while(i.compareTo(x_of_n) == -1){
                if(i.gcd(x_of_n).compareTo(BigInteger("1")) == 0){
                    return i
                }

                i = i.add(BigInteger("1"))

            }

            return BigInteger("-1")
        }

        fun generatePrivateKey(x_of_n: BigInteger, publicKey: BigInteger): BigInteger{
            var pk = 3

            while(pk<=x_of_n.toInt()){
                if (
                        (
                            publicKey.multiply(BigInteger(pk.toString()))
                        )
                        .mod(x_of_n)
                        .compareTo(BigInteger("1")) == 0
                    ){
                    return BigInteger(pk.toString())
                }
                pk++
            }

            return BigInteger("-1")
        }
    }

}