#define MAX 100001
#include<iostream>
#include<algorithm>
using namespace std;

void QuickSort(int arr[],int l,int r){
    int i = l, j = r;
    int pivot = arr[(l+r)/2];

    while(i<j)
    {
        while(arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if(i<=j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

        if(i < r)
            QuickSort(arr,i,r);
        if(j > l)
            QuickSort(arr,l,j);
    }

}


int solve(int arr[],int n){

    int k = 1;
    int stiffness = arr[n-1];
    for(int i=n-2 ;i >= 0; i--){
        k=k+1;
        stiffness = stiffness - 1;
        if(stiffness > arr[i]){
            stiffness = arr[i];
        }
        if (stiffness == 0) return k;
    }
    return n;
}


int arr[MAX];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
    QuickSort(arr,0,n-1);
	cout << solve(arr, n);
	return 0;
}