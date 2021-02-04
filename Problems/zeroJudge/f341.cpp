// https://zerojudge.tw/ShowProblem?problemid=f341

#include <iostream>
using namespace std;

int findstring(const string s1, const string s2 ) {
    for (int i = 0; i< s1.length(); i++) {
        if (s1[i] == s2[0]) {
            bool notmatch = false ;
            for (int j = 1; j<s2.length(); j++) {
                if (i+j==s1.length()) return -1;
                if (s1[i+j] != s2[j]) {
                    notmatch = true;
                    break;
                }
            }
            if (notmatch == false) return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int l = findstring(s1,s2);
    
    // output
    if (l ==-1) {
        for(int i= s1.length(); i>=0; i--) cout << s1[i];
    } else {
        int r = l+ s2.length() -1;
        //cout << l << ", r=" << r<< endl;
        for(int i= s1.length(); i> r; i--) cout << s1[i];
        cout << s2;
        for(int i= l-1; i>=0; i--) cout << s1[i];
    }
    cout << endl;
    return 0;

}