#include <iostream>
#include <algorithm>
#include <utility> // for pair

using namespace std;

#define x first
#define y second

pair<int, int> vertexs[1<<20]; 	// 存放輸入的頂點座標
pair<int, int> pick[1<<20];	// 存放篩選後，未被剔除的頂點
pair<int, int> res[1<<20];     	// 存放結果 
pair<int, int> *stash = vertexs; // stash point to vertexs[]，reuse vertexs 作為暫存區
int pick_count = 0;
int res_count = 0;	// 
int n = 0; 		// 頂點數

// x軸較小排前面，如果一樣y軸較小排前面
bool compare (pair<int, int> a, pair<int, int> b){
        if(a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    }

/*
 比較斜率,看看a,b 哪個斜，哪個平或是一樣
 因為用除法不好，所以交叉相乘後，再相減
 看看是否大於0
*/ 
long long cross(pair<int, int> o, pair<int, int> a, pair<int, int> b) 
{
    long long p1 = (a.x - o.x),
              p2 = (b.y - o.y),
              p3 = (a.y - o.y),
              p4 = (b.x - o.x);
    return p1*p2 - p3*p4;
}

void solve()
{
    sort(vertexs, vertexs+n, compare); // 依照compare規則排序

    for (int i=0; i<n ; ++i)  // 遍歷所有頂點。
    {
	// 刪除y 比前一個頂點小的。
        if(vertexs[i].y < vertexs[0].y || vertexs[i].y > vertexs[n-1].y)
        { 
            continue;
        }

        if(vertexs[i].y == vertexs[0].y)   // 如果y與起點的y 相等，則一定要經過，放入 res
            res[res_count++] = vertexs[i];
        else				   // 否則放到 pick
            pick[pick_count++] = vertexs[i];
    }
    

    // 找出 i 的起點 : 	pick 中比 res 最後一個的 x 座標還大的最小的 
    int i = 0;
    while (pick[i].x <= res[res_count-1].x && i < pick_count)
        i++;

    for (;i < pick_count ; ++i)  // 從i開始，遍歷 pick
    {
        int statsh_count = 0; 

        while (res_count >= 2)  // **注意** 當 res_count ==1 ，表示此點一定要選先放入結果 res
        {			// 否則 cross() 會出錯 res_count-2
            long long cres = cross(res[res_count-2], res[res_count-1], pick[i]);  // 判斷目前點b(pick[i])，是否比已選的點a(res[res_count-1])更優(斜率更小)
            if (cres > 0)    // 斜率較小(a > b)，把所有暫存放到結果中。
            {
                for (int p = statsh_count -1 ; p >= 0 ; --p)
                {
                    res[res_count++] = stash[p];
                }
                break;
            }
            else if(cres == 0)	// 斜率一樣，繼續往前比，(a 先存到暫存區)
            {
                stash[statsh_count++] = res[res_count-1];
                res_count --;
            }
            else 	       // 斜率較大( b > a)，繼續往前比。(刪除暫存）
            {
                res_count--;
                statsh_count = 0;
            }
        }
        res[res_count++] = pick[i]; // 選取該點
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i != n ; ++i)
        cin >> vertexs[i].x >> vertexs[i].y;
    solve();
    for(int i = 0; i != res_count ; ++i)
        cout << res[i].x << ' ' << res[i].y << '\n';
    return 0;
}
