#include <iostream>
#include <algorithm>
using namespace std;


void merge(int *arr, int l, int m, int r) {
    int l_len=m-l+1;
    int r_len = r-m;
    int l_arr[l_len]; 
    int r_arr[r_len]; 
    int l_idx=0, r_idx=0;

    for(int i=0; i<l_len ; i++) l_arr[i] = arr[i+l];
    for(int i=0; i<r_len ; i++) r_arr[i] = arr[i+m+1];

    int idx = l;
    while( l_idx < l_len && r_idx < r_len) {
        if ( l_arr[l_idx] < r_arr[r_idx]) {
            arr[idx++] = l_arr[l_idx++];
        } else {
            arr[idx++] = r_arr[r_idx++];
        }
    }

    while(l_idx < l_len) {
        arr[idx++] = l_arr[l_idx++];
    }
    while(r_idx < r_len) {
        arr[idx++] = r_arr[r_idx++];
    }
}

void merge_sort_recursive(int *arr, int l, int r){
    int idx;
    if (l < r) { // divide
        int mid = (l+r)/2;
        merge_sort_recursive(arr, l, mid);
        merge_sort_recursive(arr, mid + 1, r);

        // merge/conquer
        merge(arr, l, mid, r);
    }
}

void merge_sort_iterative(int *arr, int len){
    int l, mid, r;
    for ( int curr_len=1; curr_len<len; curr_len *= 2) { // 從最小的開始(buttom up)
        for (int l=0; l<len-1; l = r+1) {           // next left =  righrt +1    
            mid = min(l+curr_len-1, len -1);        // 需判斷是否超出範圍
            r = min(l+2*curr_len-1, len-1);
            merge(arr, l, mid, r);
        }
    }
    
    
}

void print_out(int *arr, int len) {
    for (int i=0; i< len; i++ ) cout <<arr[i] << " ";
    cout << endl;
}

int main() {
    const int len = 10;

    int N[len]= { 1,34, 10, 23, 9 ,4, 34, 3, 8, 1 };
    cout << "Recursive:" << endl;
    cout << " before: " ;print_out(N, len);
    merge_sort_recursive(N, 0, len-1);
    cout << " after : " ;print_out(N, len);

    int N2[len]= { 1,34, 10, 23, 9 ,4, 34, 3, 8, 1 };
    cout << "Iterative:" << endl;
    cout << " before: " ;print_out(N2, len);
    merge_sort_iterative(N2, len);
    cout << " after : " ;print_out(N2, len);

}