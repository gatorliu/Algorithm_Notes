// https://zerojudge.tw/ShowProblem?problemid=a019
#include <iostream>
#include <set>
using namespace std;


multiset<int> L;



void op_insert(int v) {
    L.insert(v);
}
void op_max() {
    if (L.size()==0) return;
    auto it = L.end(); --it;
    cout << *it << '\n';
    L.erase(it);
}
void op_min() {
    if (L.size()==0) return;
    auto it = L.begin();
    cout << *it << '\n';
    L.erase(it);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int op;
    while(cin >> op) {
        if (op == 1) {
            int v; cin >> v;
            op_insert(v);

        } else if (op==2) {
            op_max();
        } else { // op=3
            op_min();
        }
    }
}
