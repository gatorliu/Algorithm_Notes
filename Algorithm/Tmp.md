# 臨時筆記

[TOI (初選) 歷屆考題](https://yuihuang.com/toi-pre/)

## GCD 最大公因數

``` c++
int gcd (int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}
```

## O(1)空間 O(N)時間 找 ROOT 
ZJ b967 可以不TLE REF: https://zerojudge.tw/ShowThread?postid=25613&reply=0

假設：　有Ｎ個nodes （0 ~ N-1)，　一行行輸入　a(child)  b(parent) 兩個值

* 方法一：
    ``` c++
    long long root = N(N-1)/2;     // (編號 0加到N-1)  :: logn long
    for (int i=1; i<N; i++) { 
        cin >> a >> b;　
        .....
        root -= b ;
    }
    ```
* 方法二： 改良自方法一 
    ``` c++
    long root = N-1;            
    for (int i=0; i<N-1; i++) {  // N-1 個連接，　i 從0開始
        cin >> a >> b;
        .....
        root += i - b;          // i (0 加到　N-2)  減去出現的 b ,　所以  root = N-1開始
    }
    ```

* 方法三：   原理來自方法二　與XOR
    ``` c++
    int root = N-1;           // root = N-1    int即可
    for (int i=0; i<N-1; i++) {  // N-1 個連接，　i 從0開始
        cin >> a >> b;
        .....
        root ^= i ^ b;      // 有點像方法二　 a^b^c == abs( a - abs(b-c)) Why work??
                            // 但過程中 root值不一樣，最終root 是對的
    }
    ```


## 離散法
常用

## 矩陣快速冪 

$$ F(n) = a * F(n-1) + b * F(n-2) $$
$$ X_n= a * X_{n-1} + b * X_{n-2} $$
$$ X_0= 0, X_1=1, X_2=1, X_3=2, ...  $$

$$
\left[\begin{matrix}
X_{n} \\\\
X_{n+1} \\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
0 & 1 \\\\
a & b \\\\
\end{matrix}
\right]^n
\\\\
\dot
\\\\
\left[\begin{matrix}
X_0 \\\\
X_1 \\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
0 & 1 \\\\
a & b \\\\
\end{matrix}
\right]^{n-1}
\\\\
\dot
\\\\
\left[\begin{matrix}
X_1 \\\\
X_2 \\\\
\end{matrix}
\right]
\\\\
$$


$$
\left[\begin{matrix}
X_{n}  & 0 \\\\
X_{n+1} & 0\\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
0 & 1 \\\\
a & b \\\\
\end{matrix}
\right]^{n-1}
\\\\
\dot
\\\\
\left[\begin{matrix}
X_1  & 0 \\\\
X_2  & 0 \\\\
\end{matrix}
\right]
\\\\
$$

----------------------------------------------------------------

$$ 
Q^2 \\\\
= 
\left[\begin{matrix}
0 & 1 \\\\
2 & 3 \\\\
\end{matrix}
\right]^2
\\\\
=
\left[\begin{matrix}
0 & 1 \\\\
1 & 3 \\\\
\end{matrix}
\right]
\\\\
\dot
\\\\
\left[\begin{matrix}
0 & 1 \\\\
2 & 3 \\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
(0\*0 + 1\*2)  & (0\*1 + 1\*3) \\\\
(2\*0 + 3\*2) & (2\*1 + 3\*3) \\\\
\end{matrix}
\right]
$$

```c++
  struct mat{
    int a[2][2];
  };
  
  mat Q1 = {{{00, 01},{10, 11}}}; 
  mat Q2 = {{{00, 01},{10, 11}}}; 

  mat mat_dot(mat Q2, mat Q1) {
    mat ret; 

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                ret.a[i][j] =  Q1.a[i][k] * Q2.a[k][j];
            }
        }
    }
    return ret;
 } 
```

### 三維
$$
\left[\begin{matrix}
X_{n} \\\\
X_{n+1} \\\\
X_{n+2} \\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
0 & 0 & 1 \\\\
0 & 1 & 0 \\\\
a & b & c \\\\
\end{matrix}
\right]^{n}
\\\\
\dot
\\\\
\left[\begin{matrix}
X_0 \\\\
X_1 \\\\
X_2 \\\\
\end{matrix}
\right]
$$

### 快速冪

$$ X = Q^n * X $$

```c++
mat pow(mat Q, int n, mat X) {
  while(n) {
    if (n & 1)  // n % 2 == 1
      X = P * X

    P  = P * P;
    n >>=1 ; // n = n / 2
  }
  return X; 
}
```

## 逆序對

**逆序對**(數字排列未按照順序)數目比較普遍的方法是利用歸併排序做到$$\displaystyle{ O(n\log n)}$$的時間複雜度。

就是計算要交換的次數。  
[merge_sort.cpp](source/merge_sort.cpp)  
[merge_sort_vector.cpp](source/merge_sort_vector.cpp)

``` c++
int count_inversion(int a[], int n)  //bubble sort O(N^2)
{
    int count = 0;
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(a[i] > a[j]) {
              count += 1;
              // swap here
            }
    return count;
}
```

 1. 2020年10月APCS 4. 低地距離

```
Q:
3 1 2 1 3 2
Ans: 4

3 1 2 3 1 2
3 1 3 2 1 2
3 3 1 2 1 2
3 3 1 2 2 1 四次
```

  2. TOI2010 第五題：餐廳評鑑 

```
Q1:
3 7 5 5 8
4 6 7 5 8
Ans: 1
轉化問題成逆序對數
以第一行排序，然後以第二行merge sort
1: 3 5 5 7 8
2: 4 5 7 6 8
--------------
 : 4 5 6 7 8  一次

Q2:
3 7 5 5 8
4 6 7 7 7
Ans: 2 

1: 3 5 5 7 8
2: 4 7 7 6 7
--------------
 : 4 7 6 7 7
 : 4 6 7 7 7  二次
```
