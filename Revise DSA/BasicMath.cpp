#include <bits/stdc++.h>
using namespace std;
int countDigit(int n)
{
    int count = 0;

    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

int countDigitoptimals(int n)
{
    return floor(log10(n) + 1);
}

int reverse(int n)
{
    int reverse = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        reverse = reverse * 10 + lastdigit;
        n = n / 10;
    }

    return reverse;
} 

void palindrome(int n)
{  int number = n;
    int reverse = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        reverse = reverse * 10 + lastdigit;
        n = n / 10;
    }  
    int palindrome = reverse;
  if(palindrome == number)
  {
      cout << "Palindrome";
  }
  else
  {
      cout << "Not Palindrome";
  }
    
}

int gcd(int n1, int n2) {
    
    while (n2 != 0) {
        int remainder = n1 % n2;  
        n1 = n2;                  
        n2 = remainder;           
    }
    return n1;  
}

void Aramstrong(int n){
    int Number = n;
    int digit = countDigit(n);
    int sum =0;

    while(n>0){
        int lastdigit = n%10;
        sum += pow(lastdigit, digit);
        n = n/10;
    }     if(sum == Number){
        cout<<"Aramstrong";
    }
    else{
        cout<<"Not Aramstrong";
    }
    


}  
int main()
{
    // cout << "Enter a number: ";
    // int n;
    // cin >> n;
    // cout << "Number of digits in " << n << " is: " << countDigit(n) << endl;
    // cout << "Number of digits in " << n << " is: " << countDigitoptimals(n) << endl;
   
    // cout<<"These number is Palindrome or not: ";
    // palindrome(n);
  //  int n1, n2;
  //  cout << "Enter two numbers to find GCD: ";
   // cin >> n1 >> n2;
   // cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd(n1, n2) << endl;

    int n;
    cout<<"Enter a number to check Aramstrong: ";
    cin>>n;
    Aramstrong(n);
}