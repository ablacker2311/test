
#include<iostream>


int arr[100001];
int l[100001];

int main(){
    int n;
    std::cin>>n;

    for(int i = 0; i < n; i++){
        std::cin>>arr[i];
    }
    int x;
    std::cin>>x;

    for(int i=0;i<=x;i++){
        l[i] = INT_MAX;
    }

    l[0] = 0;
    for(int i = 1; i <= x; i++)
        for(int j = 0; j < n; j++){
            if(i >= arr[j])
                l[i] = std::min(l[i],l[i-arr[j]]+1);
        }

    if(l[x] >0)
        std::cout<<l[x];
    else std::cout<<0;

    
}