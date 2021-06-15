// https://tioj.ck.tp.edu.tw/problems/2188
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;

    string tmp="";
    int c = 1;
    for(int i=0; i<s.size(); i++) {
        if (s[i] >='a' && s[i] <='z') {
            if (tmp.size()==0) c=1;
            else {
                c= stoi(tmp);
                tmp=""; tmp.clear();
            }
            while(c>0) {
                cout << s[i];
                c--;
            }
        } else {
            tmp.push_back(s[i]);
        }
    }

    return 0;
}