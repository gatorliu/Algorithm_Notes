// https://zerojudge.tw/ShowProblem?problemid=f605
// Example program
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
 int n, d;
 int a, b, c;
 int tot=0, sum=0;
 cin >> n >> d;
 while( n--) {
     cin >> a >> b >> c ;
     // int mx = (a>b) ? (c>a ? c:a ) : (c>b ? c:b );
     // int mn = (a<b) ? (c<a ? c:a ) : (c<b ? c:b );
     int mx = max({a,b,c}); // #include <algorithm> max/min 傳入array
     int mn = min({a,b,c});
     if (mx -mn >= d ) {
         tot +=1;
         sum += (a+b+c)/3;
     }
 }
 cout << tot << ' ' << sum << endl;
}