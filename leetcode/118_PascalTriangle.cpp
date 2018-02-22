#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<int> row(numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j >= 0; j--) {
            if (j == i || j == 0) row[j] = 1;
            else {
                row[j] = row[j - 1] + row[j];
            }
        }
        vector<int> row1(i + 1);
        for (int x = 0; x < i + 1; x++) row1[x] = row[x];
        ans.push_back(row1);
    }
    return ans;
}

vector<vector<int>> generate2(int numRows) {  //²Î¿¼
    vector<vector<int>> res;
    for (auto i = 0; i<numRows; ++i)
    {
        res.push_back(vector<int>(i + 1, 1));
        for (auto j = 1; j<i; ++j) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
    return res;
}
vector<vector<int> > generate1(int numRows) {  //²Î¿¼
    vector<vector<int>> r(numRows);

    for (int i = 0; i < numRows; i++) {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }

    return r;
}

int main()
{
    vector<vector<int> > ans = generate(5);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
    return 0;
}