#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Encryption using columnar transposition
string encryptColumnarTransposition(const string& plaintext, const string& key) {
    string modifiedText = plaintext;
    // Remove spaces and convert to uppercase
    modifiedText.erase(remove_if(modifiedText.begin(), modifiedText.end(), ::isspace), modifiedText.end());
    transform(modifiedText.begin(), modifiedText.end(), modifiedText.begin(), ::toupper);

    int numCols = key.length();
    int numRows = (modifiedText.length() + numCols - 1) / numCols;

    char message[numRows][numCols];
    int place = 0;

    for (int j = 0; j < numCols; j++) {
        for (int i = 0; i < numRows; i++) {
            if (place < modifiedText.length()) {
                message[i][j] = modifiedText[place++];
            } else {
                message[i][j] = 'X'; // Fill remaining spaces with 'X'
            }
        }
    }

    string ciphertext;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            ciphertext += message[i][j];
        }
    }

    return ciphertext;
}

int main() {
    string plaintext = "HELLO WORLD";
    string key = "KEY"; // Replace with your desired key

    string ciphertext = encryptColumnarTransposition(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
