#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n==0 || n==1)
    {
        return false;
    }
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cout<<"Enter a number: ";
    int num;
    cin>>num;
    if(isPrime(num))
    {
        cout<<"Prime Number";
    }
    else{
        cout<<"Not a Prime Number";
    }
}
