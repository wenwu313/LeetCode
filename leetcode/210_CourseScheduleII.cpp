class Solution {
public:
	//BFS  类似拓扑排序 看有木有环  
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> map(numCourses, 0);
		int len = prerequisites.size();
		for (int i = 0; i < len; i++){
			map[prerequisites[i].first]++;
		}
		queue<int> que;
		for (int i = 0; i < map.size(); i++){
			if (map[i] == 0)
				que.push(i);
		}
		vector<int> result;
		int count = que.size();
		while (!que.empty()){
			int x = que.front();
			result.push_back(x);
			que.pop();
			for (int i = 0; i < len; i++){
				if (prerequisites[i].second == x){
					int y = prerequisites[i].first;
					map[y]--;
					if (!map[y]){
						que.push(y);
						count++;
					}
				}
			}
		}
		if (count != numCourses)
			return{};
		else
			return result;
	}
};