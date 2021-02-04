// https://zerojudge.tw/ShowProblem?problemid=b190
// The Tower of Hanoi   奇數號的環移到b柱上，偶數號的環移到c柱上
#include <iostream>
using namespace std;

int step = 0;

int curr = 0;
void move(int n , char start, char end, char tmp ){
		cout << curr << endl;
        if (n == 1) {
            step++;
		if (curr==1) {
			if (start != 'b')
        	    		cout << "ring " << n << " : " << start << " -> " << 'b' << endl; // 把最大一個從 Start 搬到 End
		}
		else
        	    cout << "ring " << n << " : " << start << " -> " << end << endl; // 把最大一個從 Start 搬到 End
	}
	else if(curr==2){
		cout << "XXXXXX";
        } else {
	
	    if (((n&1)==1 && start == 'b') && curr == n )
	    {
		curr--;
            	move(n-1, start, end, tmp );
            	//move(n-1, tmp, end, start );
	    } else if (((n&1)!=1 && start =='c') && curr == n )
	    {
		curr--;
            	//move(n-1, tmp, start, end );
            	move(n-1, start, end, tmp );
	    } else
	    {
            	move(n-1, start, tmp, end );
	    	step++;
            	cout << "ring " << n << " : " << start << " -> " << end <<  " -- \n"; // 把最大一個從 Start 搬到 End
	
		//cout <<"---"<< n << endl;
		if (n == curr) curr--;

	    	if ((n&1)==1 && start == 'b')
            		move(n-1, tmp, start, end );
		else
            		move(n-1, tmp, end, start );
	    }
        }
}

int main() {
    int n;
    while(cin >> n) {
        step = 0;
	curr = n;
        if ((n & 1) == 1)
            move(n, 'a', 'b', 'c');
        else
            move(n, 'a', 'c', 'b');
        cout << "total move "<< step << " steps.\n";
    }
        
}
