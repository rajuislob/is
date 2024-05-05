#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Remove spaces from the input string
string removeSpaces(const string& input) {
    string modifiedText;
    for (char c : input) {
        if (!isspace(c)) {
            modifiedText += c;
        }
    }
    return modifiedText;
}

// Encrypt using row transposition
string encryptRowTransposition(const string& plaintext, const string& key) {
    string modifiedText = removeSpaces(plaintext);
    int numRows = key.length();
    int numCols = (modifiedText.length() + numRows - 1) / numRows; // Calculate columns

    char message[numRows][numCols];
    int place = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (place < modifiedText.length()) {
                message[i][j] = modifiedText[place++];
            } else {
                message[i][j] = 'x'; // Fill remaining spaces with 'x'
            }
        }
    }

    string ciphertext;
    for (int j = 0; j < numCols; j++) {
        for (int i = 0; i < numRows; i++) {
            ciphertext += message[i][j];
        }
    }

    return ciphertext;
}

// Decrypt using row transposition
string decryptRowTransposition(const string& ciphertext, const string& key) {
    int numRows = key.length();
    int numCols = ciphertext.length() / numRows;

    char message[numRows][numCols];
    int place = 0;

    for (int j = 0; j < numCols; j++) {
        for (int i = 0; i < numRows; i++) {
            message[i][j] = ciphertext[place++];
        }
    }

    string plaintext;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (message[i][j] != 'x') {
                plaintext += message[i][j];
            }
        }
    }

    return plaintext;
}

int main() {
    string plaintext = "HELLO WORLD";
    string key = "KEY"; // Replace with your desired key

    string ciphertext = encryptRowTransposition(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decryptRowTransposition(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
