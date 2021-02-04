// https://zerojudge.tw/ShowProblem?problemid=f515
// Example program
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main()
{
   string s;
   getline(cin, s);
   stringstream sin;
   sin << s;

   while(sin >> s) {
      if ( (s[0] == 'F' || s[0] == 'f')&& s.length() == 3) {
         if ( (s[1] == 'O' || s[1] == 'o')
            && (s[2] == 'R' || s[2] == 'r')
         ) cout << '4';
         else cout << 'F';
      } 
      else if ( (s[0] == 'T' || s[0] == 't')&& s.length() == 2) {
         if ( (s[1] == 'O' || s[1] == 'o')
         ) cout << '2';
         else cout << 'T';

      } 
      else if ( (s[0] == 'A' || s[0] == 'a')&& s.length() == 3) {
         if ( (s[1] == 'N' || s[1] == 'n')
            && (s[2] == 'D' || s[2] == 'd')
         ) cout << 'n';
         else cout << 'A';

      } 
      else if ( (s[0] == 'Y' || s[0] == 'y')&& s.length() == 3) {
         if ( (s[1] == 'O' || s[1] == 'o')
            && (s[2] == 'U' || s[2] == 'u')
         ) cout << 'u';
         else cout << 'Y';
      } else 
      if (s[0] >= 'a' && s[0] <= 'z' ) 
            cout << (char)(s[0]-'a'+'A');
      else cout << s[0];
         
   }
   return 0;
}

