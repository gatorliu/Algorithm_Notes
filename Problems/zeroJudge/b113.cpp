// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <list>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vector<ll> > vvll;
#define f first
#define s second

struct Mat {
    int N;
    vvll Matrix;
    Mat(int n): N(n) {
        this->Matrix = vvll(N, vll(N+1));
    }
    ll gcd(ll a, ll b) {
        if (b == 0 )  return a;        
        else return gcd(b, a%b);
    }
    void debug(string s = ""){
        // output Matrix 
        cout<< s << ":\n"; for (auto row : Matrix) {    for(auto &col : row)  cout << col << " "; cout << endl;    }    cout << endl;   
    }
    
    // 為確保最後完成時，　Matrix[i][i] != 0 
    // 所以每次做Elimination前，需要檢查（與swap)
    // 確保下個row 的　Matrix[i][i] != 0 
    bool sort_mat(int row_no) {
        //debug("before sort row_no = " + to_string(row_no));
        for (int i=row_no; i<N; i++) {
            if (Matrix[i][row_no] != 0) {
                if (i != row_no)
                    swap(Matrix[i], Matrix[row_no]);
                //debug("after sort row_no = " + to_string(row_no));
                return true;
            }
        }
        return false;
    }
  
    void Reduction() {  // 減化
        for ( auto &row : Matrix) {    
            ll g = gcd( row[0], row[1]);
            for (int i=2; i<=N; i++) g = gcd(g, row[i]);
            if (g != 0 ) {
                g= abs(g);
                for (int i=0; i<=N; i++) row[i] /= g;
            }
        }
        // output Matrix 
        // cout<< "Matrix:\n"; for (auto row : Matrix) {    for(auto &col : row)  cout << col << " "; cout << endl;    }    cout << endl;
    }

    void Elimination(int pos, vll orig, vll &target) { // 消去一個
        //cout << "start -------- : "  << pos ;
        ll t = target[pos];
        ll o = orig[pos];
        for (int c=0; c<=N; c++) {
            target[c] = orig[c] * t - target[c] *o ;
        }
        //cout << "      ------------- end "  << endl;
    }
    char check_by_row(vll target) {
        for (int c=0; c<N; c++) {
            if (target[c] != 0) return '1'; // 
        }
        if (target[N] == 0)  return 'N'; // 無線多解
        return '0' ; //無解
    }
    char check_mat() {
        for (int c=0; c<N; c++) {
            if (Matrix[c][c] != 0) continue;
            else if (Matrix[c][N] == 0)  return 'N' ; // 無限多解
            else  return '0' ; //無解　
        }
        return '1'; 
    }
    void print() {
        for (int i=0; i< N; i++) {
            int a = abs(Matrix[i][N]);
            int b = abs(Matrix[i][i]);
            int g =  gcd(a,b);
            string val =  (Matrix[i][i] * Matrix[i][N] < 0) ? "-" : "";
            if (g == b) val+= to_string(a/g);
            else val += to_string(a/g) + "/" +  to_string(b/g);

            cout << 'x' << (i+1) << " = " << val << '\n';
        }
    } 
    char solve() {
        Reduction();
        for(int i=0; i<N; i++) {
            if ( sort_mat(i) ) {
                for ( int j=0; j<N; j++ ) {
                    if (i != j ) Elimination (i, Matrix[i], Matrix[j]);
                    //int check = check_by _row(Matrix[j]);
                    //if (check != 1 ) return check;
                }
                Reduction();
            } else continue; // 此處不可以break,  考慮 test case 1
        }       
        return check_mat();
    }

};


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    // inpput
    int n; 
    cin >> n;
    Mat M(n);
    for (auto &row : M.Matrix) for(auto &col : row) cin >> col;

    char ret = M.solve();       
    // M.debug("\nFinal Matrix");
    cout << ret << '\n';
    if (ret == '1'){
        M.print();
    }

    return 0;
}

/*
test case 1:
5
1 2 3 5 25 2
0 0 0 -8 -16 -56
0 0 0 35 70 245
0 0 0 1 2 7
0 0 0 1 2 7
*/