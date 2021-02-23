# 單調隊列 Monotoen Queue

## 意義
 * 又稱為`有序隊列`
 * 在整個 Queue中，元素的大小是有序的(單調)
 * 其實不是一個 Queue (FIFO)

## 可以解決的問題 
 * RMQ問題: Sliding Window( or subarray)的極值(最大/小值) (也可使用线段树或稀疏表，但MonoQ更快)
 * 可以優化一些要一直取最大/小值的問題(參看例題2)

上述問題，是找最大/小值，一般來說用Sort時間複雜度是O(logN)，如果需要找N次時間複雜度會是O(NlogN)。  
如果能利用`單調隊列`技巧，可以降到 **O(N)** (很重要哦! NlogN -> N )

## 演算法說明

為保持隊列單調性(假設是大到小)，
* 入隊: 每次放到Queue中的值，必須先和`隊尾`比較，如果大於`隊尾`，就把**隊尾踢出**，直到符合條件。 (所以不是FIFO)
* 出隊: 將最前面的元素 pop ( Like a Queue)
* 隊首即是解答

### MonoQ的操作範例
arr=[7 6 3 5 1 3 2] 如果保持MonoQ size < 3
``` python
[7]         # 7 入隊
[7, 6]      # 6 入隊
[7, 6, 3]   # 3 入隊
[6, 5]      # 5 入隊,  3 被踢出 Queue 
[6, 5, 1]   # .....
[6, 5, 3]   # .....
[5, 3, 2]   # 2 入隊,  6 出隊
```

### 以找區間最大值為例
假設arr=[7 6 3 5 1 3 2] , 要找長度(`Sliding Window`/`subarray`) = 3 的每個區間最大值
tips: 
   1. 紀錄index 
   2. index 與目前入隊的idx 差3 就要出隊

``` python
[0]         # 7(idx = 0) 入隊 (此時得到區間最大值max([0:1]) = 7(i=0) )
[0, 1]      # 6(idx = 1) 入隊 (此時得到區間最大值max([0:2]) = 7(i=0) )
[0, 1, 2]   # 3(idx = 2) 入隊 (此時得到區間最大值max([0:3]) = 7(i=0) )
[1, 3]      # 5(idx = 3) 入隊, 3 被踢出 Queue, 7 出隊(因為 subarray= 3) (此時得到區間最大值max([1:4]) = 6(i=1) )
[3, 4]      # 1(idx = 4) 入隊, 6 出隊(因為 subarray= 3), (此時得到區間最大值max([2:5]) = 5 )
[3, 5]      # 3(idx = 5) 入隊, 1 被踢出 Queue, (此時得到區間最大值max([3:6]) = 5 )
[5, 6]      # 2(idx = 6) 入隊, 5出隊(因為 subarray= 3) (此時得到區間最大值max([3:6]) = 5 )
```

### 實作
 * STL : list / deque (Double End Queue)
 * Array: 自己操作 MonoQ 的 front/end 的index


 ```C++
 /* Using DEQUE */
#include <iostream>
#include <deque> 
using namespace std;

const int len = 7;
int arr[len] = {7, 6, 3, 5, 1, 3, 2};
int wlen = 3;  // window

int main()
{
  cout << "arr = {";  for (int i=0; i<len; i++) { cout << arr[i] << " ";  }  cout << "}" << endl << endl; // output arr
  
deque<int> MQ; // 此處 MQ存index ，不是存值比較容易處理
  
  for (int i=0; i < len; i++) {
      //入隊
      while(!MQ.empty() && arr[MQ.back()] < arr[i]) MQ.pop_back(); // 如果值比較小，踢出去!!
      MQ.push_back(i);
  
      //出隊
      while ( i- MQ.front() >= wlen) MQ.pop_front(); // 超出Window, POP out
      
      // output( 解答)
      int start = i - wlen +1;
      if ( start>=0 )
        cout << " max(arr["<< start << ":" << i<<"]) = " << arr[MQ.front()] << endl;
  }
}
```
output
``` 
arr = {7 6 3 5 1 3 2 }
 max(arr[0:2]) = 7
 max(arr[1:3]) = 6
 max(arr[2:4]) = 5
 max(arr[3:5]) = 5
 max(arr[4:6]) = 3
```

## 例題:
* [f174: m6a2-蛋糕(Cake)](https://zerojudge.tw/ShowProblem?problemid=f174)
    * TOI練習賽2020年6月潛力組 
    * O(NlogN)只能 85%
    * 找`前綴和`的`區間最小值`
    * [Source code](../Problems/zeroJudge/f174.cpp)

* [b151: NOIP2004 2.合并果子](https://zerojudge.tw/ShowProblem?problemid=b151)
    * NOIP2004提高組
    * 還有其他解法。不一定要用單調隊列(其實新堆必定單調，所以可以直接用Queue)。

## 參考：
* [单调队列及其应用](https://www.cnblogs.com/neverforget/archive/2011/10/13/ll.html)
* [单调队列](https://baike.baidu.com/item/%E5%8D%95%E8%B0%83%E9%98%9F%E5%88%97)



