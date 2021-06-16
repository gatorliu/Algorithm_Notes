// https://codeforces.com/problemset/problem/706/D
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <bitset>
#include <stack>

using namespace std;
typedef unsigned int ui;

/****  MLE  ****/
const int Depth = 31;
const ui Base = ( 1 << (Depth-1)); // 0b100......
const ui MAXn = Base*2 + 5 ; //2147483650;

//vector<bool> trie(MAXn, false);
bitset<MAXn> trie(0);


void insert(int num) {
    ui index = 1;
    for(int i = 1; i <= Depth; i++) {
        if ((num & Base) > 0)
            index = index*2-1;
        else
            index = index*2;
        trie[index] = true;
        num <<= 1;
    }
    //for(int i = 0; i < 10; i++) cout << trie[i] << " ";
}
void del(int num) {
    stack<ui> st;
    ui index = 1;
    st.push(index);
    for(int i = 1; i <= Depth; i++) {
        if ((num & Base) > 0)
            index = index*2-1;
        else
            index = index*2;
        st.push(index);
        num <<= 1;
    }
    index = st.top(); st.pop();
    trie[index] = false;
    while (!st.empty()) {
        index = st.top(); st.pop();
        if ( (trie[index*2-1] == false)  && (trie[index*2] == false) )
            trie[index] = false;
        else break;
    }
    //for(int i = 0; i < 10 ; i++) cout << trie[i] << " ";
}
int query(int num) {
    int ret = 1;
    ui index = 1;
    for(int i = 1; i <= Depth; i++) {
        if ((num & Base) > 0) {
            index = index*2-1;
        } else {
            index = index*2;
        }
        //cout << index << ":" <<  trie[index] << " ";
        if (!trie[index]) return 0;
        num <<= 1;
    }
    return ret;
}

int maxxor(int num) {
    int ret=0;
    ui index = 1;
    for(int i = 1; i <= Depth; i++) {
        // XOR 所以index剛好相反
        if ((num & Base) > 0) {
            index = index*2;
            if (trie[index] == false) index -= 1;
        } else {
            index = index*2-1;
            if (trie[index] == false) index += 1;
        }
        ret <<= 1;
        if ((index & 1) == 1) ret |= 1 ;
        
        num <<= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int q, num;
    string s;
    cin >> q ;
    while(q--){
        cin >> s >> num;
        if (s[0] == '+') {
            insert(num);
        } else if (s[0] == '-') {
            del(num);
        } else if (s[0] == '?') {
            //cout << query(num) << '\n';
            cout << (maxxor(num) ^ num)<< '\n';
        }
    } 
    return 0;
}