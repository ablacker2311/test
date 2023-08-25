#include<iostream>

void quicksort(int arr[],int l,int r){
    int i = l;
    int j = r;
    int pivot = arr[(l+r)/2];

    while(i<j){
        while(arr[i]<pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i<=j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

        if(i < r){
            quicksort(arr,i,r);
        }

        if(l < j){
            quicksort(arr,l,j);
        }
    }
}

int main(){
    int arr[5] = {2,1,3,5,4};

     for(int i = 0;i<=4;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<'\n';

    quicksort(arr,0,4);

    for(int i = 0;i<=4;i++){
        std::cout<<arr[i]<<" ";
    }
}