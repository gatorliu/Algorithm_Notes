# Segment Tree 線段樹

處裡區間值的一種資料結構與演算法
* 不只可以處理極值，可以處理任何資料
* 資料變動時，可以立即更新 (稀疏表不行)
()

![](https://i.imgur.com/sC6SBjn.png)圖片來自外站(https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-segment-tree)

## 複雜度
### 空間
$$ Q(2N) $$

### 時間
* 建Tree  O(N)
* 單點修改 O(logN)
* 單點查詢 O(logN)

## Sample Code

### 建Tree 
* 就一直遞迴去把區間二等分填數字就好 ST root index = 1
```c++
const int N = 10;
int dt[N] = {0,1,2,3,4,5,6,7,8,9};
vector<int> STree(2*N+1, 0);

void build(int L, int R, int idx){
    if(L == R){
        STree[idx] = dt[L];
        return;
    }
    int M = (L + R) / 2;
    int li = 2*idx;  // left index  
    int ri = li + 1;
    //把區間二等分    build(L, M, 2*idx+1); // v的左子節點
    
    build(L, M, li );
    build(M + 1, R, ri);
    STree[idx] = max(STree[li], STree[ri]);
}

build(0, 9, 1); 
/*
idx    : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
STree  : 0 9 4 9 2 4 7 9 1 2  3  4  6  7  8  9  0  1  0  0  0 
*/
```
### 查詢
```c++

//查詢範圍是[l,r]，節點v的區間範圍是[L,R]
int query(int l, int r, int L, int R, int idx){
    if (l==L && r==R) return STree[idx];
    
    int M = (L + R) / 2;
    int li = 2*idx;
    int ri = li + 1;
    if(r <= M) //如果查詢區間都在左半部，就只查左半部
        return query(l, r, L, M, li);
    else if(l > M) //如果查詢區間都在右半部，就只查右半部
        return query(l, r, M+1, R, ri);
    else {
        //如果查詢區間跨越兩半部，那就也把查詢區間切半
        //這樣可以確保遞迴後[l,r]一定在[L,R]之內   
        int a = query(l, M, L, M, li);
        int b = query(M+1, r, M+1, R, ri);
        return max(a,b);
    }
}

cout <<  query(3, 8, 0, 9, 1) << endl; // 8
```

### 修改 
```c++
void modify(int pos, int v, int L, int R, int idx) {
    if (L == R) {
        STree[idx] = v;
        return;
    }
    int M = (L + R) / 2;
    int li = 2*idx;
    int ri = li + 1;
    if(pos <= M) { //pos在左半部
        modify(pos, v, L, M, li);
    } else if (pos <= R) {
        modify(pos, v, M+1, R, ri);
    }
    STree[idx] =  max(STree[li], STree[ri]);
}

modify( 4, 99, 0, 9, 1);
/*
idx    :  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
STree  :  0 99 99  9  2 99  7  9  1  2  3 99  6  7  8  9  0  1  0  0  0
*/  
cout <<  query(3, 8, 0, 9, 1) << endl; // 99
```





<未完成....>

[線段樹](https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-segment-tree) 
[108 師大附中校隊培訓簡報](https://hackmd.io/@wiwiho/S1wEdpwqr)