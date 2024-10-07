#include <bits/stdc++.h>
using namespace std;

int lcs(string &S1, string &S2, int m, int n) {
    // Base case: If either string is empty, the length of LCS is 0
    if (m == 0 || n == 0)
        return 0;

    // If the last characters of both substrings match
    if (S1[m - 1] == S2[n - 1])
        // Include this character in LCS and recur for remaining substrings
        return 1 + lcs(S1, S2, m - 1, n - 1);
    else {
        // If the last characters do not match
        // Recur for two cases:
        // 1. Exclude the last character of S1 
        // 2. Exclude the last character of S2 
        // Take the maximum of these two recursive calls
        return max(lcs(S1, S2, m, n - 1), lcs(S1, S2, m - 1, n));
    }
}

int main() {
    string S1, S2;
    
    // Input for both strings
    cout << "Enter the first string: ";
    cin >> S1;
    cout << "Enter the second string: ";
    cin >> S2;

    int m = S1.size();
    int n = S2.size();

    // Output the length of LCS
    cout << "Length of LCS is " << lcs(S1, S2, m, n) << endl;

    return 0;
}
