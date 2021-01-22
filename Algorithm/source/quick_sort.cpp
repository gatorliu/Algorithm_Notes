#include <iostream>
#include <algorithm>
using namespace std;


int partition(int *arr, int start, int end){
    int pivot = arr[end];
    int i = start;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            if (i <= j ) // 這行可以省略
                swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}
void quick_sort_recursive(int *arr, int start, int end){
    if (start < end) {
        int pivot_index = partition(arr, start, end);
        quick_sort_recursive(arr, start, pivot_index - 1);
        quick_sort_recursive(arr, pivot_index + 1, end);
    }
}

void quick_sort_iterative(int *arr, int len){
    int stack[len];
    int top = -1;
    int start;
    int end;
    int pivot_index;
    stack[++top] = 0;  // start 
    stack[++top] = len-1; // End

    while(top > 0) {
        end   = stack[top--];
        start = stack[top--];

        pivot_index = partition(arr, start, end);
        if (start < pivot_index-1) {
            stack[++top] = start;
            stack[++top] = pivot_index -1;
        }
        if(end > pivot_index+1) {
            stack[++top] = pivot_index +1;
            stack[++top] = end;
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
    quick_sort_recursive(N, 0, len-1);
    cout << " after : " ;print_out(N, len);


    int N2[len]= { 1,34, 10, 23, 9 ,4, 34, 3, 8, 1 };
    cout << "Iterative:" << endl;
    cout << " before: " ;print_out(N2, len);
    quick_sort_iterative(N2, len);
    cout << " after : " ;print_out(N2, len);
    

}