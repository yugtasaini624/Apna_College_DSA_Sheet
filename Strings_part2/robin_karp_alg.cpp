#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> rabinKarp(const string& text, const string& pattern) {

    int n = text.length();
    int m = pattern.length();

    vector<int> matches;

    if (m == 0 || n < m) {
        return matches;
    }

    // Constants for hashing
    const int d = 256;
    const int q = 101;

    long long patternHash = 0;
    long long textHash = 0;
    long long h = 1;

    // h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate initial hashes
    for (int i = 0; i < m; i++) {

        patternHash =
            (d * patternHash + pattern[i]) % q;

        textHash =
            (d * textHash + text[i]) % q;
    }

    // Slide the window
    for (int i = 0; i <= n - m; i++) {

        // If hash values match
        if (patternHash == textHash) {

            bool matchFound = true;

            // Check characters to avoid hash collision
            for (int j = 0; j < m; j++) {

                if (text[i + j] != pattern[j]) {
                    matchFound = false;
                    break;
                }
            }

            if (matchFound) {
                matches.push_back(i);
            }
        }

        // Move the window
        if (i < n - m) {

            // Remove old character
            // Add new character
            textHash =
                (d * (textHash - text[i] * h)
                + text[i + m]) % q;

            // Make hash positive
            if (textHash < 0) {
                textHash += q;
            }
        }
    }

    return matches;
}

int main() {

    string text = "ABCCDDAEFGBCBCA";
    string pattern = "BC";

    vector<int> result = rabinKarp(text, pattern);

    cout << "Pattern found at indices: ";

    for (int idx : result) {
        cout << idx << " ";
    }

    cout << endl;

    return 0;
}