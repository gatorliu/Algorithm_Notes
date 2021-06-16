// https://codeforces.com/problemset/problem/706/D
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
struct Node {
    int one, zero, cnt;
};
// #define Node pair<int,int> 
#define node first
#define preNodeBit second

const int Depth = 31;
const ui Base = ( 1 << (Depth-1) ); // 0b0100......
//coutconst int MAXn = (200000 +5) *2; 
int nodeCnt=1;

//vector<Node > trie(MAXn, {0,0,0}); 
vector<Node > trie(2, {0,0,0}); 

int genNode(int index, bool isBitOne) { 

    if (isBitOne) {
        if(trie[index].one == 0 ) {
            nodeCnt++; 
            trie.push_back({0,0,0});
            trie[index].one =nodeCnt;
        }
        return trie[index].one;
    } else {
        if(trie[index].zero == 0 ) {
            nodeCnt++;
            trie.push_back({0,0,0});
            trie[index].zero = nodeCnt;
        }
        return trie[index].zero;
    }
} 

void insert(int num) {
    int index = 1;
    bool isOne;
    for(int i = 1; i <= Depth; i++) {
        trie[index].cnt++;
        index = genNode(index, ((num & Base) > 0));
        num <<= 1;
    }
    trie[index].cnt++;
    //for(int i = 1; i <= 31 ; i++) cout << trie[i].zero <<  "," << trie[i].one << ":" << trie[i].cnt << " ";
}
void del(int num) {
    int index = 1;
    for(int i = 1; i <= Depth; i++) {
        trie[index].cnt--;
        if ( (num & Base) > 0) {
            index = trie[index].one;
        } else {
            index = trie[index].zero;
        } 
        num <<= 1;
    }
    trie[index].cnt--;
}

bool query(int num) {
    int index = 1;
    for(int i = 1; i <= Depth; i++) {
        if (trie[index].cnt==0 ) return 0;
        if ((num & Base) > 0) {
            index = trie[index].one;
        } else {
            index = trie[index].zero;
        }
        num <<= 1;
    }
    
    if(trie[index].cnt == 0) return 0;
    return 1;
}

int findMaxXor(int num) {
    int ret=0;
    int index = 1;
    int nextIdx;
    bool isBitOne;
    if (trie[index].cnt==0 ) return (0 ^ num);

    for(int i = 1; i <= Depth; i++) {
        ret <<= 1;
        isBitOne = ((num & Base) == 0); // XOR 所以index剛好相反
        if (isBitOne) {
            nextIdx = trie[index].one;
            if ( trie[nextIdx].cnt > 0 ) {
                ret |= 1;
            } else {
                nextIdx = trie[index].zero;
            }
        } else {
            nextIdx = trie[index].zero;
            if ( trie[nextIdx].cnt > 0) {
                ret |= 1;
            } else {
                nextIdx = trie[index].one;
            }
        }
        index = nextIdx;        
        num <<= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int q, num;
    string s;
    cin >> q ;
    insert(0);
    while(q--){
        cin >> s >> num;
        if (s[0] == '+') {
            insert(num);
        } else if (s[0] == '-') {
            del(num);
        } else if (s[0] == '?') {
            //cout << query(num) << " : ";
            cout << findMaxXor(num) << '\n';
        }
    } 
    return 0;
}