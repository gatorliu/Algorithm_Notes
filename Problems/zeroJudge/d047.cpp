// https://zerojudge.tw/ShowProblem?problemid=d047
// #include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

bool isLeap(string s) {
    int year = 0; // 最大5位數
    for (int j=0, i=s.size()-1; j < 5 && j <s.size() ; i--, j++ ) {
        year += (s[i] -'0') * pow(10, j);
    }
    if ( year % 4 == 0 ) {
            if ( year % 400 == 0 ) return true;
            else if ( year % 100 != 0)  return true;
    }
    return false;
}

bool Is3multiple(string s) {
    long long sum=0;
    for(int i=0; i<s.size();i++)
        sum += s[i]-'0';
    return (sum % 3 == 0);
}

bool Is5multiple(string s) {
    char c = s[s.size()-1];
    return (c=='0' || c == '5');
}

bool Is11multiple(string s) {
    long long sum_odd=0;
    long long sum_ever=0;
    for(int i=0; i<s.size();i+=2)
        sum_odd += s[i]-'0';
    for(int i=1; i<s.size();i+=2)
        sum_ever += s[i]-'0';

    return (max(sum_odd, sum_ever)- min(sum_odd, sum_ever)) % 11 == 0;
}

int main() {

    string s;
    int year;
    bool flag;
    while(cin >> s) {
        flag=false;
        
        bool isL = isLeap(s);    
        bool is3 = Is3multiple(s);
        bool is5 = Is5multiple(s);
        bool is11 = Is11multiple(s);

        if (isL) {
            cout << "This is leap year.\n";
            flag = true;
        }
        
        if (is3 && is5) {
            cout << "This is huluculu festival year.\n";
            flag = true;
        }
        if (isL && is5 && is11) {
            cout << "This is bulukulu festival year.\n";
            flag = true;
        }
        if ( !flag)
            cout << "This is an ordinary year.\n";
    }
}