#include<iostream>
using namespace std;

double myPow(double x, int n) {  //³¬Ê±
    if (n < 0) {
        if (n == INT_MIN)
            return 1.0 / (myPow(x, INT_MAX)*x);
        else
            return 1.0 / myPow(x, -n);
    }
    double res = 1.0;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (n < 0) {
        if (n == INT_MIN)
            return 1.0 / (myPow(x, INT_MAX)*x);
        else
            return 1.0 / myPow(x, -n);
    }
    double temp = myPow(x, n >> 1);
    if (n & 1 == 1)	return x*temp*temp;
    else return temp*temp;
}

int main()
{
    cout << myPow(2, 11) << endl;
    cin.get();
    return 0;
}