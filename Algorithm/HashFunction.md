# Hash function處理字串

給定底數 b 跟質數 p，我們可以計算字串 S 的 hash：
$$ 
(S_0 \cdot b^{|S| - 1} + S_1 \cdot b^{|S| - 2} + \dots + S_{|S| - 1} \cdot b^0) \bmod p
$$

b = 128 (因為ASCII 0-127)  
(TODO ....)
