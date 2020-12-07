#include <cmath> 
#include <iostream> 
#include <vector> 
#include <iomanip>      // std::setprecision

using namespace std; 
  
double power(double x, int n){
    if(n == 0)
        return 1;
    double res = power(x, n / 2);

    if(n % 2 != 0)
        return x * res * res;
    else
        return res * res;
}

double gp(double s, double t, int n){
    double r = t / s;
    double a = s / r;

    return a * power(r, n - 1);
}
  
// Driven program to test 
int main() 
{ 
    
    double a2=3, a3=9;
    int n=5;
    cout << fixed << setprecision(3) <<gp(a2,a3,n);
    // cout<<ans;
    return 0; 
} 