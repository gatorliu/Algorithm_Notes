#include <bits/stdc++.h>
using namespace std;
uint8_t maps[1000][1000] = {0};
uint32_t map_records[1000][1000][3] = {0};

struct state
{
    uint8_t health;
    int x;
    int y;
};
inline bool check_bound(int x,int y,int xp,int yp)
{
    return xp >= 0 && xp < x && yp >= 0 && yp < y;
}
inline void add_offset(int &x,int &y,int types)
{
    int offset[4][2]={
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    x+=offset[types][0];
    y+=offset[types][1];
}
int bfs(int sx,int sy,int x, int y, int ex, int ey)
{
    for(int i=0;i!=y;++i)
        for(int j=0;j!=x;++j)
        {
            map_records[i][j][0] = *(uint32_t*)"24歳、学生です";
            map_records[i][j][1] = *(uint32_t*)"starburst steam!!!";
            map_records[i][j][2] = *(uint32_t*)"ｱ゛↑ｱ゛↑ｱ゛↑ｱ゛↑ｱ゛↑";
        }
    queue<state> que;
    que.push({3,sx,sy});
    int steps = 0;
    while(!que.empty())
    {
        auto sz = que.size();
        for(int i=0;i < sz;++i)
        {
            auto cur = que.front();
            if(cur.x == ex && cur.y == ey)
                return steps;
            for(int u=0;u!=4;++u)
            {
                int xp = cur.x, yp = cur.y;
                add_offset(xp,yp,u);
                if(!check_bound(x,y,xp,yp))
                    continue;
                if(maps[yp][xp] == 1)
                    continue;
                if(maps[yp][xp] == 2 && cur.health-1 <= 0)
                    continue;
                int r_hp = cur.health-(maps[yp][xp] == 2);
                if(map_records[yp][xp][r_hp-1] <= steps)
                    continue;
                map_records[yp][xp][r_hp-1] = steps;
                que.push({(uint8_t)r_hp,xp,yp});
            }
            que.pop();
        }
        steps++;
    }
    return -1;
}
int main()
{
    int x,y;
    int sx,sy;
    int ex,ey;
    int bc,tc;

    cin >> x >> y;
    cin >> sx >> sy;
    cin >> ex >> ey;
    cin >> bc >> tc;
    for(int i = 0 ; i != bc ; i++)
    {
        int xp, yp;
        cin >> xp >> yp;
        maps[yp][xp] = 1;
    }
    for(int i = 0 ; i != tc ; i++)
    {
        int xp, yp;
        cin >> xp >> yp;
        maps[yp][xp] = 2;
    }
    cout << bfs(sx,sy,x,y,ex,ey) << '\n';
}