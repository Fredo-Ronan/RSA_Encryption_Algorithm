
import java.math.BigInteger

fun main(args: Array<String>) {

    val p = PrimeNumberOp.getPrimeNumber(200,300)
    var q = PrimeNumberOp.getPrimeNumber(200,300)

    while(q==p){
        q = PrimeNumberOp.getPrimeNumber(200,300)
    }

//    println("P = $p")
//    println("Q = $q")

    val n = p * q
    val x_of_n = (p - 1) * (q - 1)
    val publicKey = PublicPrivateKey.generatePublicKey(BigInteger(x_of_n.toString()))
    var privateKey = PublicPrivateKey.generatePrivateKey(BigInteger(x_of_n.toString()), publicKey)

//    println("N = $n")
//    println("X_of_n = $x_of_n")
//    println("Public Key = $publicKey")
//    println("Private Key = $privateKey")

    val textData = "Hello"

    println("Text Data : $textData")

    val encrypted = EncryptDecrypt.encrypt(publicKey, BigInteger(n.toString()), textData)

    println("Encrypted data/text --> " + encrypted.joinToString("|"))

}