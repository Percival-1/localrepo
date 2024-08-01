#include<iostream>
using namespace std;

long long int BinarySearch(int n){
        
    int start = 0;
    int end = n;
    long long int mid = start + (end - start)/2;
    
    long long int ans = 0;
    while(start <= end) 
    {
        long long int square = mid*mid;
        
        if(square == n)
            return mid;
        
        if(square < n )
        {
            ans = mid;
            start = mid+1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}    

long double Pre(int n , int precision , int temp ){

    double factor = 1;
    double ans = temp;
    for (int i = 0; i < precision; i++)
    {   
        factor = factor / 10;
        for (double j = ans; j*j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int result = BinarySearch(n);
    long double ans = Pre(n , 4 , result);
    cout << ans;
    return 0;
}