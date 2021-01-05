#include <iostream>
#include <algorithm>

using namespace std;

struct Vertex{
    int x;
    int y;
    bool operator < (const Vertex& vet) const
    {
        if(x == vet.x)
            return y < vet.y;
        return x < vet.x;
    }
};
Vertex vertexs[1<<20], pick[1<<20], res[1<<20];
Vertex *stash = vertexs;
int pick_count = 0;
int res_count = 0;
int vertex_count = 0;

long long cross(Vertex o, Vertex a, Vertex b)
{
    long long p1 = (a.x - o.x),
              p2 = (b.y - o.y),
              p3 = (a.y - o.y),
              p4 = (b.x - o.x);
    return p1*p2 - p3*p4;
}

void solve()
{
    sort(vertexs, vertexs+vertex_count);

    for (int i=0; i<vertex_count ; ++i)
    {
        if(vertexs[i].y < vertexs[0].y || vertexs[i].y > vertexs[vertex_count-1].y)
        {
            continue;
        }

        if(vertexs[i].y == vertexs[0].y)
            res[res_count++] = vertexs[i];
        else
            pick[pick_count++] = vertexs[i];
    }

    int i = 0;
    while (pick[i].x <= res[res_count-1].x && i < pick_count)
        i++;
    for (;i < pick_count ; ++i)
    {
        int statsh_count = 0;

        while (res_count >= 2)
        {
            long long cres = cross(res[res_count-2], res[res_count-1], pick[i]);
            if (cres > 0)
            {
                for (int p = statsh_count -1 ; p >= 0 ; --p)
                {
                    res[res_count++] = stash[p];
                }
                break;
            }
            else if(cres == 0)
            {
                stash[statsh_count++] = res[res_count-1];
                res_count --;
            }
            else
            {
                res_count--;
                statsh_count = 0;
            }
        }
        res[res_count++] = pick[i];
    }
}
int main()
{
    cin >> vertex_count;
    for(int i = 0; i != vertex_count ; ++i)
        cin >> vertexs[i].x >> vertexs[i].y;
    solve();
    for(int i = 0; i != res_count ; ++i)
        cout << res[i].x << ' ' << res[i].y << '\n';
    return 0;
}
