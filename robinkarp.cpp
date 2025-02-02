#include<bits/stdc++.h>
using namespace std;
long long calculateHash(const string& str, int d, long long q) {
    long long hash = 0;
    for (int i = 0; i < str.length(); i++) {
        hash = (d * hash + str[i]) % q;
    }
    return hash;
}

void rabinKarpMultiplePatterns(const string& text, const vector<string>& patterns, int d, long long q) {
    int n = text.length();
    vector<int> patlen;
    vector<long long> p_hash;
    vector<long long> t_hash(patterns.size(), 0);
    vector<bool> patternMatched(patterns.size(), false);

    for (int i = 0; i < patterns.size(); i++) {
        patlen.push_back(patterns[i].length());
        p_hash.push_back(calculateHash(patterns[i], d, q));
    }

    vector<long long> h(patterns.size(), 1);
    for (int i = 0; i < patterns.size(); i++) {
        for (int j = 0; j < patlen[i] - 1; j++) {
            h[i] = (h[i] * d) % q;
        }
    }

    for (int i = 0; i < patterns.size(); i++) {
        t_hash[i] = calculateHash(text.substr(0, patlen[i]), d, q);
    }

    for (int i = 0; i <= n - *min_element(patlen.begin(), patlen.end()); i++) {
        for (int p = 0; p < patterns.size(); p++) {
            if (i + patlen[p] <= n && t_hash[p] == p_hash[p]) {
                if (text.substr(i, patlen[p]) == patterns[p]) {
                    cout << patterns[p] << " pattern matched at " << i << endl;
                    patternMatched[p] = true;
                
                }
            }
            
            if (i + patlen[p] < n) {
                t_hash[p] = (d * (t_hash[p] - text[i] * h[p]) + text[i + patlen[p]]) % q;
                if (t_hash[p] < 0) t_hash[p] += q;
            }
            break;
        }
    }

    for (int p = 0; p < patterns.size(); p++) {
        if (!patternMatched[p]) {
            cout << patterns[p] << " pattern did not match" << endl;
        }
    }
}

int main() {
    string text;
    int patternCount;
    
    cin >> text;

    cin >> patternCount;

    vector<string> patterns(patternCount);

    for (int i = 0; i < patternCount; i++) {
        cin >> patterns[i];
    }

    int d = 256;            
    long long q = 101; 

    rabinKarpMultiplePatterns(text, patterns, d, q);

    return 0;
}