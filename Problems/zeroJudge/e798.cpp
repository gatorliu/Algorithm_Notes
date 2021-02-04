// https://zerojudge.tw/ShowProblem?problemid=e798
// Example program
#include <iostream>
#include <algorithm>

using namespace std;

int IMG[20][20];
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;

   for (int i=0; i<n; i++ )for (int j=0; j<n; j++ ) cin >> IMG[i][j];
   // solve
   for (int i=0; i<n; i +=2  ) {
      for (int j=0; j<n; j+=2 ) {
         cout << max({IMG[i][j], IMG[i+1][j], IMG[i][j+1], IMG[i+1][j+1]});
         if (j+2 !=  n) cout << " ";
      }  
      cout << endl;
   }
   return 0;
}

