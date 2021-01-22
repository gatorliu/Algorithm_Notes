// https://zerojudge.tw/ShowProblem?problemid=f514
// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string src, target;
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> src >> target;


   bool init = true;   
   for(int i=0; i<target.length() ;i++) {
      for(int j=0; j<src.length() ;j++) {
         if (src[j] == target[i]) {
            if(!init) cout << ' ';
            cout << j+1;
            src[j] = ' ';
            init =  false;
            break;
         } else {
            if (j+1 == src.length()) {
               if(!init) cout << ' ';
               cout << "X";
               init =  false;
               break;
            }
         }
      }
   }
   cout << endl;
}

