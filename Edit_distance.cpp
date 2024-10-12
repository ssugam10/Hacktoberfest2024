#include <bits/stdc++.h>
using namespace std;

int editDistDP(const string &s1, const string &s2) {
  
    int m = s1.length();
    int n = s2.length();

    // Create a table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the known entries in dp[][]
    // If one string is empty, then answer 
    // is length of the other string
    for (int i = 0; i <= m; i++) 
        dp[i][0] = i;
    for (int j = 0; j <= n; j++) 
        dp[0][j] = j; 

    // Fill the rest of dp[][]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1],  
                                 dp[i - 1][j],   
                                 dp[i - 1][j - 1]});
        }
    }

    return dp[m][n];
}

// Driver code
int main() {
    string s1 = "GEEXSFRGEEKKS";
    string s2 = "GEEKSFORGEEKS";

    cout << editDistDP(s1, s2);

    return 0;
}
