class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        vector<int> indegree(numCourses);

        for (auto & edge : prerequisites)
        {
            int u = edge[1], v = edge[0];
            graph[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int counter = 0; // Number of nodes that can be reached

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            counter++;
            for (auto v : graph[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return counter == numCourses;

    }
};
