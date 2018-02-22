#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1, 1);
    for (int i = 2; i <= rowIndex; ++i) {
        for (int j = i - 1; j > 0; j--) {
            ans[j] = ans[j - 1] + ans[j];
        }
    }
    return ans;
}


int main()
{
    vector<int> ans = getRow(3);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
    cin.get();
    return 0;
}