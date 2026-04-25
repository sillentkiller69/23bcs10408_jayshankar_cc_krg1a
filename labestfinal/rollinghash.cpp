#include <bits/stdc++.h>
using namespace std;
#define int long long

 
int findHash(string &s) {
    int n = s.length();

    
    int p = 31, m = 1e9 + 7;

    int hash = 0;
    int Pow = 1;
    for (int i = 0; i < n; ++i) {
        hash = (hash + (s[i] - 'a' + 1) * Pow) % m;
        Pow = (Pow * p) % m;
    }
    return hash;
}

signed main() {
    string s2 = "polynomial";
     string s1= "geeksforgeeks";

    cout << findHash(s1)<<endl;
     cout << findHash(s2);
    return 0;
}