#define MAX 100001
#include<iostream>

int arr[MAX];
int count(int arr[],int l,int r,int x){
    if(l == r)
        if(arr[l] == x)
            return 1;
        else return 0;
    else {
        int mid = (l+r)/2;
        return count(arr,l,mid,x) + count(arr,mid+1,r,x);
    }
}

int main(){
    int n;
    std::cin>>n;
    for(int i=0; i<n; i++){
        std::cin>>arr[i];
    }

    int x;
    std::cin>>x;

    std::cout<<count(arr,0,n-1,x);
}

// #define MAX 100001
// #include<iostream>

// int arr[MAX];
// int count(int arr[],int l,int r,int x){
//     if(l == r)
//         if(arr[l] == x)
//             return 1;
//         else return 0;
//     else {
//         int mid = (l+r)/2;
//         return count(arr,l,mid,x) + count(arr,mid+1,r,x);
//     }
// }

// int main(){
//     int n;
//     std::cin>>n;
//     for(int i=0; i<n; i++){
//         std::cin>>arr[i];
//     }

//     int x;
//     std::cin>>x;

//     std::cout<<count(arr,0,n-1,x);
// }