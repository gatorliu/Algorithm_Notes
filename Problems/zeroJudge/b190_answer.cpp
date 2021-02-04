// https://zerojudge.tw/ShowProblem?problemid=a190
// The Tower of Hanoi   奇數號的環移到b柱上，偶數號的環移到c柱上

// 
// 來自　https://naukri7707.github.io/%E7%B7%9A%E4%B8%8A%E8%A7%A3%E9%A1%8C/ZeroJudge/b190/
#include <iostream>
using namespace std;

int n, cnt;
char list[100];

void dfs(int lv, char to)
{
    for (int i = lv; i; i--)
    {
        if (lv == n)
            to = i & 1 ? 'b' : 'c'; //　單數移到b 雙數移到c
        if (list[i] != to)
        {
            dfs(i - 1, 294 - list[i] - to);  // 294 = 'a' + 'b' + 'c' ASCII
            //printf("ring %d : %c -> %c\n", i, list[i], to);
            cout << "ring " << i << " : " << list[i] << " -> " << to << endl;
            list[i] = to;
            cnt++;
        }
    }
}

int main()
{
    while (cin >> n)
    {
        cnt = 0;
        for (int i = 1; i <= n; i++)
            list[i] = 'a';
        dfs(n, '?');
        cout << "共移動了 "<< cnt << " 步\n";
    }
    return 0;
}
