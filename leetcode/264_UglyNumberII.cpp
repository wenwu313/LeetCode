class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> res(n, 0);
		res[0] = 1;
		int index2 = 0, index3 = 0, index5 = 0;
		for (int i = 1; i < n; i++){
			int temp = min(res[index2] * 2, res[index3] * 3);
			temp = min(temp, res[index5] * 5);
			res[i] = temp;                      //注意等号  
			while (res[index2] * 2 <= res[i])   //(res[index2] * 2 == res[i])   
				index2++;
			while (res[index3] * 3 <= res[i])   //(res[index3] * 3 == res[i])  
				index3++;
			while (res[index5] * 5 <= res[i])   //(res[index5] * 5 == res[i])  
				index5++;
		}
		return res[n - 1];
	}
};