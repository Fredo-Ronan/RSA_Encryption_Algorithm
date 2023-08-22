package RSAEncryption

import java.math.BigInteger

class RSA constructor(
    private val min: Int,
    private val max: Int
) {

    private var p: Int = 0
    private var q: Int = 0
    private var n: Int = 0
    private var xOfn: Int = 0
    private var privateKey: BigInteger = BigInteger("0")
    private var publicKey: BigInteger = BigInteger("0")

    init {
        this.p = PrimeNumberOp.getPrimeNumber(this.min, this.max)
        this.q = PrimeNumberOp.getPrimeNumber(this.min, this.max)

        while(this.q==this.p){
            this.q = PrimeNumberOp.getPrimeNumber(this.min, this.max)
        }

        this.n = this.calculateN()
        this.xOfn = this.calculateXofN()
        this.publicKey = PublicPrivateKey.generatePublicKey(BigInteger(this.xOfn.toString()))
        this.privateKey = PublicPrivateKey.generatePrivateKey(BigInteger(this.xOfn.toString()), BigInteger(this.publicKey.toString()))
    }


    // Public function
    fun getN(): Int{
        return this.n
    }

    fun getPublicKey(): Int{
        return this.publicKey.toInt()
    }

    fun encrypt(textData: String): String{
        val encrypted = EncryptDecrypt.encrypt(this.publicKey, BigInteger(this.n.toString()), textData)
        return encrypted.joinToString("|") + "|"
    }

    fun decrypt(encryptedData: String): String{
        val decrypted = EncryptDecrypt.decrypt(encryptedData, this.privateKey, BigInteger(this.n.toString()))
        return decrypted.joinToString("")
    }

    // Private function
    private fun calculateN(): Int {
        return (this.p * this.q)
    }

    private fun calculateXofN(): Int {
        return (this.p - 1) * (this.q - 1)
    }

}