<!--
Tags: 前綴和, 離散化, Segment Tree,TOI,
-->
# 著色 (Coloting)

``TOI 202010 練習賽 潛力組 第三題``

## 題目(pdf)  
* [TOI提供](https://toi-reg.csie.ntnu.edu.tw/question/202010/Coloring.pdf)  
* [TOI備份](source/Coloring.pdf)  

## 解題重點
* 使用前綴和的技巧將時間優化成O(M)
  * 首先先開一個長度為M+1的陣列tag
  * 如果X~Y區間要加1，只需要在tag[X]加上1，表示位置X（含）之後的前綴和數值都會加上1，tag[Y+1]遞減1，表示位置Y+1（含）之後的數值不會加上1
  * 最後新的tag[pos]為原本tag[1]~tag[pos]的加總，解答就出來了

* 離散化
  * 離散化就是將無限空間上有限的個體映射到有限空間上
  * 雖然M可高達10億，但實際上不會出現那麼多個座標
    例如：(1000, 10000)可以將1000映射到1，10000映射到2
      可以省去許多不必要的運算
  * 在這邊的做法是：將X到Y的區間著色我們只需要X、Y和Y+1這3個數值先預處理離散化，之後使用前綴和做完之後在轉換回來
  * 使用 **STL的map** 處理映射(mapping)

### 參考文件 (.odp)：
* [TOI提供](https://toi-reg.csie.ntnu.edu.tw/question/202010/Coloring.odp)  
* [TOI備份](source\Coloring.odp)  



## 實作
(略)

### Source Code:
* [TOI官網提供](https://toi-reg.csie.ntnu.edu.tw/question/202010/Coloring.cpp)
* [TOI備份](source\Coloring_toi.cpp)
