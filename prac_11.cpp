#include <iostream>
#include <string>
using namespace std;

// Encrypt using Vernam (one-time pad) stream cipher
string encryptVernam(const string& plaintext, const string& key) {
    if (plaintext.length() != key.length()) {
        cerr << "Error: Plaintext and key must have the same length." << endl;
        return "";
    }

    string ciphertext;
    for (size_t i = 0; i < plaintext.length(); i++) {
        char encryptedChar = plaintext[i] ^ key[i]; // XOR operation
        ciphertext += encryptedChar;
    }
    return ciphertext;
}

// Decrypt using Vernam (one-time pad) stream cipher
string decryptVernam(const string& ciphertext, const string& key) {
    return encryptVernam(ciphertext, key); // Decryption is the same as encryption
}

int main() {
    string plaintext = "HELLO";
    string key = "SECRET"; // Replace with your secret key (must be the same length as plaintext)

    string ciphertext = encryptVernam(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decryptVernam(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
