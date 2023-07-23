#define MAX 100001
#include<iostream>
/* Cho arr[] gồm n số nguyên. 
Tìm dãy con dài nhất không giảm trong arr[] ?
(nếu có nhiều dãy con dài nhất thì chọn lần xuất hiện đầu tiên.)*/
//   i   0 1 2 3 4 5 6
//arr[i] 1 2 1 3 5 6 4
// l[i]: 1 2 1 2 3 4 1 
// Hướng giải quyết: 
// gọi mảng phụ l[], l[i] lưu trữ độ dài của dãy con dài nhất kết thúc tại vị trí thứ i của mảng arr[],

int l[MAX];         
int arr[MAX];       

void printArray(int arr[],int l,int r){
    for(int i = l;i<=r;i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    std::cin>>n;
    for(int i = 0; i < n; i++){
        std::cin>>arr[i];
    }
    int maxEle = 1;
    int posEnd = 0;

    l[0] = 1;
    for(int i = 1; i < n; ++i){
        if(arr[i] >= arr[i-1]){
            l[i] = l[i-1] + 1;
        }
        else l[i] = 1;
    }

    for(int i=0;i<n;i++){
        if(l[i] > maxEle){
            maxEle = l[i];
            posEnd = i;
        }
    }

    int posStart = posEnd - maxEle + 1; /*vì posEnd sẽ là phần tử cuối của dãy con thỏa yc bài toán, l[posEnd] sẽ lưu trữ số lượng
phần tử của dãy con, nên posStart = posEnd - l[posEnd] + 1; (rút ra từ công thức đếm số lượng phần tử trong dãy: slpt = cuối - đầu + 1)*/    
       printArray(arr,posStart,posEnd);
}
