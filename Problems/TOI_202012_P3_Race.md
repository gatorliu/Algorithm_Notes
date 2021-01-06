<!--
Tags: 動態規劃, Sparse table, Segment Tree, TOI,
-->
# 賽車 (Race)

``TOI 202012 練習賽 潛力組 第三題``

## 題目(pdf)  
* [TOI 提供](https://toi-reg.csie.ntnu.edu.tw/question/202012/Race.pdf)  
* [TOI備份](source\Race.pdf)  

## 解題重點
* 用Pair或自訂struct儲存 x,y
* 注意避免用除法（利用交叉相乘，後相減）取代斜率計算
  $$ (x_a - x_o)  * (y_b - y_o) - (x_b - x_o)  * (y_a - y_o) $$
* 參考解答：
  * sort 排序後，找出起點，終點
  * 迴圈排除不可能的點。
  * 看似動態規劃（forloop版），不是太確定??


* 我的想法：（未經驗證）
  * 動態規劃（遞迴版)
  * Sparse table 稀疏表: 用於計算不會變動的區間極值。
    1. 起點到終點的間min 斜率的點。
    2. 然後再將該點當作起點，重複步驟1
    3. 直到找到終點為止
  * 可以用稀疏表，就可以用segment Tree

### 參考文件 (.odp)：
無


## 實作
* TOI提供解答，利用struct與 Operator overloadding (為了sort()，改寫`<`)
* 改寫版，改用 pair。並採用 callback function傳入sort()

### Source Code:
* [TOI官網提供](https://toi-reg.csie.ntnu.edu.tw/question/202012/Race.cpp)
* [TOI備份](source\Race_toi.cpp)
* [改寫版(TOI備份加入註解與採用pair)](source\Race.cpp)
