#include<bits/stdc++.h>
using namespace std;

void fibrecursive(int a,int b,int rem){
    if(rem<=0) return;
    cout<<a;
    if(rem>1) cout<<" ";
    return fibrecursive(b,a+b,rem-1);
}
void fibonacciiterative(int n){
    if(n==1){
        cout<<0;
        return;
    }
    if(n<=0) return;
    int a=0,b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<n;i++){
        int c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

int main(){
    int n;
    if(!(cin >> n)) return 0;

    // Print the first n Fibonacci numbers (iterative)
    cout << "Iterative (first " << n << ") : ";
    fibonacciiterative(n);
    cout << '\n';

    // Print the first n Fibonacci numbers (recursive)
    cout << "Recursive (first " << n << ") : ";
    if(n > 0) fibrecursive(0, 1, n);
    cout << '\n';

    return 0;
}