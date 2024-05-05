#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to encrypt a message using the Rail Fence Cipher
string encryptRailFence(string message, int rails) {
  int n = message.length();
  int cycle = 2 * rails - 2;

  // Create a vector of strings to store the encrypted message in rows
  vector<string> encryptedRows(rails, "");

  // Loop through each character in the message
  for (int i = 0, row = 0, col = 1; i < n; i++) {
    encryptedRows[row] += message[i];

    // Change direction at the top and bottom of the rail fence
    if (col == 1 || col == cycle) {
      row = (row == rails - 1) ? row - 1 : row + 1;
    }
    
    // Move diagonally
    col++;
    if (col > cycle) {
      col = cycle - (col - cycle);
    }
  }

  // Concatenate the encrypted rows to form the final encrypted message
  string encryptedMessage;
  for (const string& row : encryptedRows) {
    encryptedMessage += row;
  }

  return encryptedMessage;
}

// Function to decrypt a message using the Rail Fence Cipher
string decryptRailFence(string ciphertext, int rails) {
  int n = ciphertext.length();
  int cycle = 2 * rails - 2;

  // Create a vector to store the order in which characters were encrypted
  vector<int> order(n);
  int row = 0, col = 1;
  for (int i = 0; i < n; i++) {
    order[i] = row * cycle + col - 1;

    if (col == 1 || col == cycle) {
      row = (row == rails - 1) ? row - 1 : row + 1;
    }
    
    col++;
    if (col > cycle) {
      col = cycle - (col - cycle);
    }
  }

  // Create a temporary vector to hold the decrypted message characters
  vector<char> decrypted(n, ' ');

  // Decrypt by placing characters in the correct order
  for (int i = 0; i < n; i++) {
    decrypted[order[i]] = ciphertext[i];
  }

  // Convert the decrypted vector to a string
  string decryptedMessage;
  for (char c : decrypted) {
    decryptedMessage += c;
  }

  return decryptedMessage;
}

int main() {
  string message;
  int rails;

  cout << "Enter message: ";
  getline(cin, message);

  cout << "Enter number of rails (2 or more): ";
  cin >> rails;

  if (rails < 2) {
    cout << "Invalid number of rails. Please enter 2 or more." << endl;
    return 1;
  }

  cout << "Encrypt (1) or Decrypt (2)? ";
  int choice;
  cin >> choice;

  string result;
  if (choice == 1) {
    result = encryptRailFence(message, rails);
  } else if (choice == 2) {
    result = decryptRailFence(message, rails);
  } else {
    cout << "Invalid choice. Please enter 1 or 2." << endl;
    return 1;
  }

  cout << (choice == 1 ? "Encrypted" : "Decrypted") << " message: " << result << endl;

  return 0;
}
