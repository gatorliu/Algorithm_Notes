<!--
Tags: DFS, Disjoint Set並查集, TOI,




-->

# 同學 (Classmates)

``TOI 202011 練習賽 潛力組 第一題``

## 題目(pdf)  
* [TOI提供](https://toi-reg.csie.ntnu.edu.tw/question/202011/Classmates.pdf)  
* [TOI備份](source\Classmates.pdf)  

## 解題重點
* 連通分量（Connected Component）: 簡單的說就是點連接在一起，也就是成為一組
  * 可以用 Disjoint SET, DFS  BFS 都可以。

* 判斷連通分量是否有環，有兩種解法:
  1. 本題使用關於「樹（tree）」的特性判斷，因為無向圖為樹若且唯若它不存在環。而且，一棵樹除了自己的父節點之外，不會再碰到其他已經走訪過的節點。所以如果碰到了表示存在環。
  2.我們也可以記錄下連通分量的節點數和邊樹。樹有一個簡單的小定理：點數=邊數-1，如果不成立表示存在環。


### 資料結構  
* vector<int> g[N]: 儲存每一同學的朋友，因為互為朋友，要兩邊都計

``` console
+---+
| g |
+---+
| 0 | -> { 1 }
| 1 | -> { 0, 2 }
| 2 | -> { 1 }
| 3 | -> { 4, 7 }
| 4 | -> { 3, 5, 6 }
| 5 | -> { 4, 7 }
| 6 | -> { 4 }
| 7 | -> { 3, 5}
+---+
```

### 參考文件 (.odp)：
* [TOI提供](https://toi-reg.csie.ntnu.edu.tw/question/202011/Classmates.odp)  
* [TOI備份](source\Classmates.odp)  


## 實作
### DFS，只處理連通分量(Group)

``` c++
void dfs_group_only(int u) //只計算有幾組
{
	used[u] = true;
	for(int v : g[u])
	{
		if(used[v]) continue;
		dfs_group_only(v);
	}
}

int main (){
  ......
  for(int i=0; i<n; ++i)
	{
		if(used[i]) continue;
		dfs_group_only(i);
		++tot;
	}

}
```

### 加入Ring判斷

``` c++
bool dfs(int u, int p) // p = 前面的朋友(parent)
{
	bool has_ring =  false;
	used[u] = true;
	for(int v : g[u])
	{
		if (v==p) continue; // 不可省略， 否則 has_ring == true
		if (used[v] || dfs(v, u)) has_ring = true; 
		//  只要碰到used[v] == true，一定　has_ring 
		// 	因為不同群，一定不可能在 g[u]，所以為不存在之前找過，卻在不同群的問題
	}
	return has_ring;
}

int main (){
  for(int i=0; i<n; ++i)
    {
      if(used[i]) continue;
      if( dfs(i, -1) ) ring++ ;
      ++tot;
    }
｝
```

### Source Code:
* [TOI官網提供解答1](https://toi-reg.csie.ntnu.edu.tw/question/202011/Classmates_100_1.cpp)
* [TOI官網提供解答2](https://toi-reg.csie.ntnu.edu.tw/question/202011/Classmates_100_2.cpp)
* [TOI備份解答1](source\Classmates_100_1_toi.cpp)
* [TOI備份解答2](source\Classmates_100_2_toi.cpp)

* [改寫版(TOI解答1加入註解)](source\Classmates_100_1.cpp)
