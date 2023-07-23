#include<iostream>


// int findMin(int arr[],int n){
//     int min = arr[0];
//     for(int i = 1; i < n; ++i){
//         if(arr[i] < max)
//             min = arr[i];
//     }
//     return min;
// }
int Factorial(int n){
    if (n == 1)
    return 1;
    return n*Factorial(n-1);
}
double calSum(int n){
    double sum = 0;
    for(int i = 1;i <= n;i++){
        sum = sum + 1.0/Factorial(i);
    }
    return sum;
}

int main(){
    int n;
    std::cout<<"nhap n:";
    std::cin>>n;

    std::cout<<calSum(n)*1.0;
    
    // for(int i = 0;i<n;++i){
    //     std::cout<<"arr["<<i<<"]:";
    //     std::cin>>arr[i];
    // }

}