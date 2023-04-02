#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

long long calHash(string s, int n) {
    const int p = 31;
    const ll m = 1e9 + 9;
    ll hashvalue = 0;
    ll x = 1;
    for(int i = 0; i < n; i++) {
        hashvalue = (hashvalue + ((s[i] - 'a' + 1) * x) % m) % m;
        x = (x * p) % m;
    }
    return hashvalue;
}

vector<ll> calHashArray(string s, int n) {
    vector<ll> hashtable(n + 1, 0);
    const int p = 31;
    const ll m = 1e9 + 9;
    ll x = 1;
    for(int i = 0; i < n; i++) {
        hashtable[i + 1] = (hashtable[i] + ((s[i] - 'a' + 1) * x) % m) % m;
        x = (x * p) % m;
    }
    return hashtable;
}
bool Check(string txt, int n, string pat, int m, vector<long long int> &hash) {
    long long patHash = calHash(pat, m);
    const ll d = 1e9 + 9;
    const int p = 31;
    ll x = 1;
   
    for(int i = 0; i < n; i++) {
        long long subHash = (hash[i + m] - hash[i] + d) % d;
        if(subHash == (patHash * x) % d) {
            return true;
        }
        x = (x * p) % d;
    }
    return false;
}



int main() {
    string txt;
    string pat;
    cin >> txt >> pat;
    int n = txt.size();
    int m = pat.size();
    vector<long long int> hash = calHashArray(txt, n);
    bool cond = Check(txt, n, pat, m, hash);
    if(cond) {
        cout << "Pattern Exists";
    }
    else {
        cout << "Pattern does not exist in the text";
    }
    return 0;
}
