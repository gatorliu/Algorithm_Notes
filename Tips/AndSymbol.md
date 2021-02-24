---
Tags: Tips, 
---
`重點整理:`
``` c++
pair<int, string> *b = &a;
pair<int, string &b = a;
```


# & symbol in C++

C++ 的 **`&`** 有很多意義！！

* Bitwise operation
``` c++
 (3 & 2) == 2 // (0b11 & 0b10) == 0b10
```
*  Address-of Operator (在一個**變數**前)
```c++
int a =3;
cout << &a << endl;
int *b = &a; // b 是一個int型態的pointer，point to `a` 的地址(address of `a`)
```

* Reference （在**定義**變數的地方）
  a `aliase`
```c++
int a = 3;
int &b = a; // b 就是　a
int c = a; 
c= 4;   // a == 3
b = 5;  // a == 5
```

## 討論　Reference

* Case 1

```c++
    int arr[]={1,2,3,4};
    
    for (int i=0; i<4 ; i++) {
        int a = arr[i];
        a += 10;
    }                             // arr[] =  1 2 3 4
    
    for (int i=0; i<4 ; i++) {    
        int &a = arr[i];          // 重要!!  如果用一個需要改變Arr[i]的值，記得 `&`
        a += 10;
    }                             // arr[] = 11 12 13 14
    
    for (auto  a :arr ) a += 10;  // 11 12 13 14  
    for (auto &a :arr ) a += 10;  // 21 22 23 24  記得 `&`
```

* Case 2 

```c++
struct A {
  int val;
};

void F1(A b) {
    b.val= 10;
}
void F2(A &b) {
    b.val= 10;
}
int main()
{
    A a = {1}; 
    cout << a.val << endl;  // 1
    F1(a);
    cout << a.val << endl;  // 1
    F2(a);
    cout << a.val << endl;  // 2
}
```

### 應用
1. swap() 

```c++
void swap_not_work (pair<int,int> a, pair<int,int> b) {  // NO!! Call by Value
    pair<int,int> t = a;    a = b;    b = t;
}
void swap(pair<int,int> &a, pair<int,int> &b) { // with `&` call by reference
    pair<int,int> t = a;    a = b;    b = t;
}

int main() {
    pair<int,int> x = {1, 11};
    pair<int,int> y = {2, 22};
    swap(x, y);
    cout << x.second  << ", " << y.second << endl;
}
``` 
2. 輸入的好方法(先輸入有幾個數字(N), 接著輸入這N個數字)
```c++
int main()
{ 
    int N; cin >> N;

    // 一般做法
    vector<int> V; 
    int v;
    for (int i=0; i<N; i++) { 
        cin >> v;
        iV[i].push_back(v);
    }
    
    // 另一個較好作法
    // int V[N]
    vector<int> V(N);  // 事先確定了 vector大小  or 
    for (int i=0; i<3; i++) cin >> V[i]; // Yes
    for (auto v: V) cin >> v;            // No
    for (auto &v: V) cin >> v;           // Yes
}
```


* swap() 的 Pointer　作法 (補充)

```c++
/* 
NO!! Call by Value, here value is a address
So, this code just change address
*/
void swap(pair<int,int> *a, pair<int,int> *b) { 
    pair<int,int> *t = a;    a = b;    b = t;
}

// Yes! Call by Value, but change  the value of address
void swap(pair<int,int> *a, pair<int,int> *b) { 
    pair<int,int> t = *a;    *a = *b;    *b = t;
}

swap(&x, &y); // 加 `&`

```
