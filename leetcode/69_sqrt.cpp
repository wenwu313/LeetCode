#include<iostream>
using namespace std;

int mySqrt(int x) {
    if (x <= 1) return -1;
    int left = 0, right = (x / 2) + 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if ((x / mid >= mid) && ((mid + 1) > x / (mid + 1))) return mid;
        else if (x / mid < mid) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main()
{
    int n = 3;
    cout << mySqrt(n) << endl;
    cin.get();
    return 0;
}