#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty())
        return;
    int rows = matrix.size(), cols = matrix[0].size();
    //int i = 0, j = rows - 1;
    //while (i < j){
    //	swap(matrix[i++], matrix[j--]);
    //}
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> solution = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
    rotate(solution);
    for (int i = 0; i < solution.size(); i++) {
        vector<int> temp = solution[i];
        for (int j = 0; j < temp.size(); j++) {
            cout << solution[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
    return 0;
}


