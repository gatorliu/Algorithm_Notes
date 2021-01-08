# Algorithm_Notes

這是我有關演算法的筆記。採用 markdown語法紀錄，並透過我的另一個專案([pyMDPublish](https://github.com/gatorliu/pyMDPublish) ) 

Please visit : [https://gatorliu.github.io/Algorithm_Notes](https://gatorliu.github.io/Algorithm_Notes)



###  注意事項

由於 Github pages `Jekyll` 會檢查 md語法，所以 2個方式解決:

#### 1. 注意MD語法:

　　* 開頭不能用 hackmd 加入參數的方式: `---` ...mulit-lines ... `---`  
改用 `\<!--` ...mulit-lines ... `-->`


　　* `code block` 中的程式碼，不能是連續的`}}` (應該是 Jekyll的 bug吧!)  
估計應該整個文件都不允許 `} }`

　　*　：ㄊ`code block` 結束後要多空一行 (應該是 Jekyll的 bug吧!)
  

#### 2. Disable Jekyll

  * 在 `gh-pages` breach 下加一個  .nojekyll 的空白文件

