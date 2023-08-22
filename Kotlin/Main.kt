
import RSAEncryption.RSA

fun main(args: Array<String>) {

    val rsa = RSA(200, 300)
    val text = "Hello this is a sample quite long text"

    val encrypted = rsa.encrypt(text)

    println("Encrypted: $encrypted")

    val decrypted = rsa.decrypt(encrypted)

    println("Decrypted: $decrypted")
}