#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to perform Caesar Cipher (monoalphabetic)
string caesarCipher(string message, int shift, bool encrypt) {
  string result;
  for (char c : message) {
    if (isalpha(c)) {
      int newChar = c + (encrypt ? shift : -shift);
      // Handle wrap-around for uppercase and lowercase letters
      if (isupper(c)) {
        newChar = (newChar - 'A' + 26) % 26 + 'A';
      } else {
        newChar = (newChar - 'a' + 26) % 26 + 'a';
      }
      result += char(newChar);
    } else {
      result += c; // Keep non-alphabetic characters unchanged
    }
  }
  return result;
}

// Function to perform Vigenere Cipher (polyalphabetic)
string vigenereCipher(string message, string key, bool encrypt) {
  int keyLen = key.length();
  string result;
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    if (isalpha(c)) {
      int shift = (key[i % keyLen] - (isupper(key[i % keyLen]) ? 'A' : 'a') + 26) % 26;
      result += caesarCipher(string(1, c), shift, encrypt);
    } else {
      result += c; // Keep non-alphabetic characters unchanged
    }
  }
  return result;
}

int main() {
  string message, key;
  int shift;
  bool encrypt;

  cout << "Enter message: ";
  getline(cin, message);

  while (true) {
    cout << "Choose operation (1: Monoalphabetic (Caesar Cipher), 2: Polyalphabetic (Vigenere Cipher)): ";
    cin >> shift;
    if (shift == 1 || shift == 2) {
      break;
    } else {
      cout << "Invalid choice. Please enter 1 or 2.\n";
    }
  }

  cout << "Enter key (for Vigenere Cipher only, leave blank otherwise): ";
  if (shift == 2) {
    getline(cin, key);
  } else {
    getline(cin, key); // Consume newline character for monoalphabetic case
    key.clear(); // Clear key for monoalphabetic case
  }

  while (true) {
    cout << "Encrypt (1) or Decrypt (2)? ";
    cin >> shift;
    if (shift == 1 || shift == 2) {
      encrypt = (shift == 1);
      break;
    } else {
      cout << "Invalid choice. Please enter 1 or 2.\n";
    }
  }

  string result;
  if (shift == 1) {
    result = caesarCipher(message, shift, encrypt);
  } else {
    result = vigenereCipher(message, key, encrypt);
  }

  cout << (encrypt ? "Encrypted" : "Decrypted") << " message: " << result << endl;

  return 0;
}
