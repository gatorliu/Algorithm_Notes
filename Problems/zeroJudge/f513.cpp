// https://zerojudge.tw/ShowProblem?problemid=f513
// Example program
#include <iostream>
#include <vector>
using namespace std;

/*----------------------------------------------------------------
計算周圍8個位置與中間都不同的數目
--*/



int out(vector< vector<int> >M, int x, int y) {
   for (int i=-1; i<=1 ;i++ ) {
      for (int j=-1; j<=1; j++ ){
         if (i==0 && j==0) continue;
         if ( M[x][y] == M[x+i][y+j]) return 0;
      }
   }
   return 1;
}

int main()
{
   int r, c;
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> r>> c;
   vector< vector<int> >M(r+2, vector<int>(c+2,0) );

   for(int i=1; i<=r;i++) for(int j=1; j<=c;j++) cin >> M[i][j]; 
   /* 
   for(int i=0; i<=r+1;i++) {
      for(int j=0; j<=c+1;j++) cout <<  M[i][j] << " "; 
    cout <<endl;
   }
   */
   int cnt=0;
   for(int i=1; i<=r;i++)
      for(int j=1; j<=c;j++)
         cnt += out(M, i, j);
   cout << cnt << endl;

}

