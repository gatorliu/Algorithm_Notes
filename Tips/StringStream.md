---
Tags: Tips, INPUT OUTPUT
---
`重點整理:`
``` c++
1. #include <sstream> // include
2. getline(cin, str);  // 一次讀一行
3.  <<, >>             // Operators使用
4. ss.str(""); ss.clean(); // Reuse stringstream
```


# StringStream

`ioStream` 是將 input/output 當作 Stream 
`StringStream` 則是將 String 當作 Stream 

## Stream 
簡單來講，它就是一個流水線，你可以從任何地方放東西進去、然後再把裡面的東西拿出來到任何地方。[1]:


## StringStream 範例
### int to String( or string to int)
``` c++
#include <sstream>
using namespace std;
int main()
{
    stringstream ss;  // 設個 stringstream , 類似 iostream 的 cin/cout
    int num = 1234;
    string str ; 
    
    ss << num; // 相當於cout, 只是cout是將 snum 輸出到 console
               // 這裡是輸出到 ss 中
    
    ss >> str; // 相當於cin, 把 ss 中值，以stream方式輸入 str
    
    cout<< str << endl;//顯示output=1234;
}
```
*　為什麼可以這樣，想想 cin/cout 也可以自動判斷string/int 呀!!
* String to int 也可以

### 轉換輸入
除了可以把各種類型互相轉換外（有實作輸入或輸出方法的類型），還有像是有些題目的輸入格式比較討厭，一個檔案多筆測資、一筆測資占一行，但又不告訴你一筆測資有幾個數字，這個時候你就可以先用 getline 把整行讀到一個 string、然後再用 stringstream 做分割。[1]

``` c++
#include <iostream>
#include <sstream> // include stringstream
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str); // 輸入 1 2 3 4 5，一次讀一行
    
    stringstream sInOut; // 設個 stringstream , 類似 iostream 的 cin/cout 
    sInOut << str;       // 相當於cout, 只是cout是將 str 輸出到 console
                         // 這裡是輸出到 sInOut中    
    int val;
    int sum = 0;
    while(sInOut >> val) { // 相當於cin, 把 sInOut中值，以stream方式輸入 arr
        sum += val;
    }
    cout << sum << '\n'; // 輸出 6
}
```
### 針對stringstream類別的初始化
這邊要提到一點就是要重複使用一個stringstream的情況，因為宣告stringstream類別的時候其實蠻消耗CPU的時間，在解題目以及應用的時候不太建議重複宣告，而是使用完之後就初始化再次利用。[2]

``` c++
stringstream s1;
s1.str("");  
s1.clear();
```
PS：這兩行基本上缺一不可。細節請參考 [2](https://home.gamer.com.tw/creationDetail.php?sn=4114818


## References:
1. [StringStream](https://hackmd.io/@wiwiho/CPN-stringstream)
2. [stringstream用法整理](https://home.gamer.com.tw/creationDetail.php?sn=4114818)