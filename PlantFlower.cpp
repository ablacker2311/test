#define MAX 100001
#include<iostream>

void quicksort(int l,int r,int arr[]){
    int i = l;
    int j = r;
    int pivot = arr[(l+r)/2];
    while (i < j){
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        
        if(i<=j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

        if(i<r)
            quicksort(i,r,arr);
        

        if(j>l)
            quicksort(l,j,arr);
        
    }
}
int arr[MAX];
int main(){
int n;
	std::cin >> n;
	for (int i = 0; i < n; i++){
		std::cin >> arr[i];
	};
	
    quicksort(0, n-1,arr);
    int k = 1;
    int max = 0;
    for(int i = n-1 ;i >= 0; i--){
        if(arr[i]+k > max){
            max = arr[i] + k;
        }
        k++;
    }

    std::cout<<max;
}