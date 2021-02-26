# 臨時筆記

## 離散法
常用

## 矩陣快速冪 

$$ F(n) = a * F(n-1) + b * F(n-2) $$
$$ X_n= a * X_{n-1} + b * X_{n-2} $$
$$ X_0= 0, X_1=1, X_2=1, X_3=2, ...  $$

$$
\left[\begin{matrix}
X_{n+1} \\\\
X_{n} \\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
a & b \\\\
1 & 0 \\\\
\end{matrix}
\right]^n
\\\\
\dot
\\\\
\left[\begin{matrix}
X_1 \\\\
X_0 \\\\
\end{matrix}
\right]
\\\\
$$ 


$$ 
Q^2 \\\\
= 
\left[\begin{matrix}
a & b \\\\
1 & 0 \\\\
\end{matrix}
\right]^2
\\\\
=
\left[\begin{matrix}
a & b \\\\
1 & 0 \\\\
\end{matrix}
\right]
\\\\
\dot
\\\\
\left[\begin{matrix}
a & b \\\\
1 & 0 \\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
(a\*a + b\*1)  & (a\*b + b\*0) \\\\
(1\*a + 0\*1) & (1\*b + 0\*0) \\\\
\end{matrix}
\right]
$$

### 三維
$$
\left[\begin{matrix}
X_{n+2} \\\\
X_{n+1} \\\\
X_{n} \\\\
\end{matrix}
\right]
\\\\
=
\\\\
\left[\begin{matrix}
a & b & c \\\\
1 & 0 & 0 \\\\
0 & 1 & 0 \\\\
\end{matrix}
\right]^{n}
\\\\
\dot
\\\\
\left[\begin{matrix}
X_2 \\\\
X_1 \\\\
X_0 \\\\
\end{matrix}
\right]
$$


## 逆序對

**逆序對**(數字排列未按照順序)數目比較普遍的方法是利用歸併排序做到$$\displaystyle{ O(n\log n)}$$的時間複雜度。

就是計算要交換的次數。  
[merge_sort.cpp](source/merge_sort.cpp)  
[merge_sort_vector.cpp](source/merge_sort_vector.cpp)


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


