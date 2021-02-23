# LIS 最大遞增子序列

Longest Increasing Subsequence

Ex:
$$ S = \\{5, \color{red}{3}\color{black}{, } \color{red}{4}\color{black}, 9, \color{red}{6}\color{black}, 2, 1, \color{red}{8}\color{black}, 7, \color{red}{9}\color{black} \\} $$

$$ LIS(S) = \\{3. 4. 6, 8(or 7), 9 \\} $$
$$ Length(LIS(S)) = 5 $$

## 簡單的作法
* 可以找出*子序列*:
* 時間複雜度 = $$O(N^2)$$

建一個 length Array，針對每一個元素，若新加入一個數，則判斷並它可以接在那些前面的數後面

以 S = {5,3,4,9,6,2,1,8,7,9} 為例:
```
執行後 S 與 length Arr情況
        | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
        +---+---+---+---+---+---+---+---+---+---+---+---+
S:      | value | 5 | 3 | 4 | 9 | 6 | 2 | 1 | 8 | 7 | 9 |
        +---+---+---+---+---+---+---+---+---+---+---+---+
length: | length| 1 | 1 | 2 | 3 | 3 | 1 | 1 | 4 | 4 | 5 |
        +---+---+---+---+---+---+---+---+---+---+---+---+
```
說明:  
 * length[2] = 2 因為 S[2] = 4，可以接在 S[1]=3 後。 (自己本身是 length=1)
 * 如果需要明確列出，額外建立一條陣列，記錄銜接關係。
參考: [Longest Increasing Subsequence](http://web.ntnu.edu.tw/~algo/Subsequence.html)


## 更好做法
$$O(N log(N)) $$

### 說明：
* 用　vector L 紀錄，最遞增數列長度是 idx+1時的最小數值:
 1. 若L是空，則 push_back(至少LIS = 1)
 2. 若L不是空，
    1. 新數值v可以往後接(數字最大)， 則 push_back
    2. 新數值v不是最大，則修改L中數值大於v的，以v取代

PS: 用 upper_bound (找 > v) /lower_bound (找 >= v ) 找效果一樣 : O(logN)

* [LIS 最大遞增子序列](https://bear-1111.medium.com/longest-increasing-subsequence-lis-dp-1211fc7933f6)
*[APCS 20210109](https://hackmd.io/@gtcoding/BJwy6bPCP) 中 P4. 飛黃騰達 code

```c++
 int main()
{
  vector<int> S = {5,3,4,9,6,2,1,8,7,9};
  vector<int> L;
  
  for(auto v : S) {
      if (L.empty() || L.back() < v  /* 如果用 <= 則是不遞減 */ ) L.push_back(v);
      else *upper_bound(L.begin(), L.end(), v) = v;
  }
  cout << L.size() << endl;
  return 0;
}
```
PS :執行後 L= {1, 4, 6, 7, 9} 這*不是* LIS，是代表IS長度是idx+1時，最小值是多少
Ex: 
* L[0] = 1 => IS長度是1(0+1)的話，最小數字是　1
* L[2] = 6 => IS長度是3(2+1)的話，最小數字是　6 {3, 4,6}


### 若要找出LIS
[[筆記】DP：LIS 最長遞增子序列](https://yuihuang.com/dp-lis/)  
提示：　加一個Arr，紀錄每個數字，是L中的index(這樣就不用記錄整個LIS鍊了)
```c++
int main()
{
  vector<int> S = {5,3,4,9,6,2,1,8,7,9};
  vector<int> L;
  int dp[10]={0};           // 加這行，紀錄vector L 的　index (參考DP輸出結果)
  
  for(int i=0; i<10; i++) {
      int v=S[i];
      if (L.empty() || L.back() < v  /* 如果用 <= 則是不遞減 */ ) {
          L.push_back(v);
          dp[i] = L.size();　// 紀錄dp
      }
      else{
          auto it = upper_bound(L.begin(), L.end(), v);
          *it = v;
          dp[i] = (int)(it - L.begin()) +1; // 紀錄dp : 透過 it- L.begin() +　1　找出
      }
  }
  cout << L.size() << endl;
  
  cout << "Output dp: ";　　
  for ( auto v : dp) cout << v << ", "; 　
  cout << endl;
 
  //　輸出答案：　從　dp 最大數字往前找，
  vector<int> ans;
  int sz = L.size();
  for (int i=9; i>=0; i--){
    if (dp[i] ==sz ){
        ans.push_back(S[i]);
        sz--;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << "LIS: ";
  for (auto i: ans) cout << i << " ,";
}
```
OUTPUT:
```
5
Output dp: 1, 1, 2, 3, 3, 1, 1, 4, 4, 5, 　
LIS: 3 ,4 ,6 ,7 ,9 , 
```