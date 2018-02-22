class Solution {
public:
    //BFS  类似拓扑排序 看有木有环  
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> map(numCourses, 0);
        int len = prerequisites.size();
        for (int i = 0; i < len; i++) {
            map[prerequisites[i].first]++;
        }
        queue<int> que;
        for (int i = 0; i < map.size(); i++) {
            if (map[i] == 0)
                que.push(i);
        }
        int count = que.size();
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            for (int i = 0; i < len; i++) {
                if (prerequisites[i].second == x) {
                    int y = prerequisites[i].first;
                    map[y]--;
                    if (!map[y]) {
                        que.push(y);
                        count++;
                    }
                }
            }
        }
        return count == numCourses;
    }
};