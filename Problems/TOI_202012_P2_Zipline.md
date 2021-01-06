<!--
Tags: 動態規劃, DAG有向無環圖, TOI,
-->
# 空中鋼索 (Zipline)  

``TOI 202012 練習賽 潛力組 第二題``

## 題目(pdf)  
* [TOI 提供](https://toi-reg.csie.ntnu.edu.tw/question/202012/Zipline.pdf)  
* [TOI備份](source\Zipline.pdf)  

## 解說

### 有向無環圖（DAG Directed Acyclic Graph）
* 有向：纜車從高往低走，所以兩點的連線有方向性
* 無環: 纜車從高往低走，不可能往回走。無法構成一個`環`。

### DFS & 動態規劃
* DAG **不**可以看成一個`Tree`，因為有可能一個`node(節點)`會有2個以上的`parent(父節點)`。(反之`(有向)Tree`可以視為 DAG)
* 但 DAG 有**一路算下去(不會回頭)**的特性，仍可以使用*DFS*，因為終究會算到**Leaf(葉)**。
只是用到某些*節點*(就是那些有多個*父節點*的節點)，會重複計算下面的subtree。
* 所以採用*動態規劃*減少計算量時，要**額外紀錄** 已經算過subtree的`node`,下次遇到該`node`時，就不用在計算了。
* O(N+M)  N:基地數 M:鋼索數

### 資料結構  
* int h[N]: 儲存每一個基地的高度 (為了確認每個edge的方向(高->低)

``` console
      0   1   2   3   4   ......
    +---+---+---+---+---+ 
 h  | \ | 9 | 6 | 5 | 2 | ......
    +---+---+---+---+---+
```

* vector<int> g[N]: 儲存每一個基地可以透過纜線到哪些其他基地

``` console
+---+
| g |
+---+
| 0 | 
| 1 | -> { 2, 3 , 4 }
| 2 | -> { 4 }
| 3 | -> { 4 }
| 4 | -> { }
+---+

```

### 參考文件 (.odp)：
* [TOI提供](https://toi-reg.csie.ntnu.edu.tw/question/202012/Zipline.odp)  
* [TOI備份](source\Zipline.odp)  


## 實作

### 無動態規劃版本(Partial)

``` c++
int cnt = 0;  // 紀錄最長路徑總數
int curr_steps = 0; // 目前走了幾步(當前路徑步數)
int max_steps = 0;  // 走到終點(n)的步數(最長路徑)
void dfs(int u)
{
    if ( u == n ) { // 走到終點(n)
        if (curr_steps > max_steps) { // 如果發現新的最長路徑
            max_steps = curr_steps;
            cnt = 1;            
        } else if (curr_steps == max_steps) { // 如果當前路徑步數 == 最長路徑
            ++cnt;
        } 
        return;
    } 
	for (auto v : g[u] ) {
        curr_steps++; // 當前路徑步數 +1
        dfs(v);
        curr_steps--; // 當前路徑步數 -1
    }
}

int main()
{
	// 輸入略過 .....
	dfs(1);
	cout << cnt << endl;
	return 0;
}

```
### 動態規劃
考慮加入動態規劃時，架構要做些許調整。  

* 紀錄每一個節點的**最長路徑**
* 由上一個條資訊，才可以**算出**，並**紀錄**每一個節點的**最長路徑總數**
* 紀錄已經算過subtree的`node`(因為DAG關係)

實作細節參考 Source Code

### Source Code:
* [TOI官網提供](https://toi-reg.csie.ntnu.edu.tw/question/202012/Zipline.cpp)
* [TOI備份(加入註解)](source\Zipline_toi.cpp)
* [DFS無動態規劃版本(TLE)](source\Zipline.cpp)
