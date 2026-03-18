# Lab Report: Implementation of Classical Ciphers

## Discussion

We have implemented three classical ciphers: Caesar cipher, Vernam cipher, and Hill cipher. In Caesar cipher, we used a fixed key to shift characters for encryption and decryption. For Vernam cipher, we implemented a key-based encryption where the plaintext length matches the key length, and the cipher repeats the key to match plaintext length. In Hill cipher, we implemented matrix-based encryption using a 2x2 or 3x3 key matrix with modular arithmetic and matrix inversion for decryption. All implementations successfully handle padding, modular operations, and character conversion between plaintext and ciphertext. We also handled edge cases like spaces and calculated modular inverses for decryption.

## Conclusion

We have successfully implemented and tested three classical cipher algorithms with proper encryption and decryption functionality. The implementations demonstrate the working mechanism of classical cryptography and the use of modular arithmetic and matrix operations in cryptographic systems. This lab provided practical understanding of cipher design and the core concepts used in cryptographic applications.
