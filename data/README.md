# About RSA Keys
## Create private key
```openssl genrsa -out private_key.pem 2048```

This ```private_key.pem``` can be used for the fastboot3DS signature.
## Create public key from private key
```openssl rsa -in .\private_key.pem -pubout -out public_key.pem```
## Create public key for OpenFirmInstaller
Open the public_key.pem with a text editor,copy the content and find a online tool to extract ```Exponent``` and ```Modulus``` from it.The ```Modulus``` is what we need,it has 256 bytes,save it as a binary file and replace the file ```fastboot3DS_pubkey.bin``` here. 
