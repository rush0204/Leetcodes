class Solution {
public:
//     bool isCycle(vector<vector<int>>&pre,vector<int> fr,int p){
//          vector<int> vis(p,0);
//         queue<vector<int>> v;
//         v.push(fr);
//         vis[fr[0]] = 1;
//         while(!v.empty()){
//             vector<int> front = v.front();
//             cout<<front[0]<<" "<<front[1]<<endl;
//              if(front[0]==front[1]) return true;
//             v.pop();
//             for(int i = 0;i<pre.size();i++){
//                 if(pre[i][1]==front[0]){
//                     v.push(pre[i]);
//                      if(vis[pre[i][1]]==1) return true;
//                     vis[pre[i][1]] = 1;
//                 }
//             }
//         }
// return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         if(prerequisites.size()==0) return true;
//         int p = numCourses;
//         int m = 2;
//         int n = prerequisites.size();
//       vector<int> vis(p,0);
//         queue<vector<int>> qq;
//         qq.push(prerequisites[0]);
//     //    while(!qq.empty()){
//     //        vector<int> fr = qq.front();
//     //        qq.pop();
//     //         if(vis[fr[0]]==1) continue;
//     //        bool ff = isCycle(prerequisites,fr,numCourses);
//     //        if(ff==true) return false;
//     //    }
//        for(int i = 0 ;i<prerequisites.size();i++){
//       //  if(vis[prerequisites[i][0]]==1) continue;
//            bool ff = isCycle(prerequisites,prerequisites[i],numCourses);
//            if(ff==true) return false;
          
//        }
//        return true;
//     }
bool dfs(vector<vector<int>>& graph, vector<int>& visited, int course) {
    if (visited[course] == 1) {
        return false;
    }
    
    if (visited[course] == 2) {
        return true;
    }
    
    visited[course] = 1; // Mark as being visited
    
    for (int dependentCourse : graph[course]) {
        if (!dfs(graph, visited, dependentCourse)) {
            return false;
        }
    }
    
    visited[course] = 2; // Mark as visited
    
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    
    // Build the adjacency list
    for (const vector<int>& prerequisite : prerequisites) {
        int course = prerequisite[0];
        int prerequisiteCourse = prerequisite[1];
        graph[course].push_back(prerequisiteCourse);
    }
    
    vector<int> visited(numCourses, 0); // 0: unvisited, 1: being visited, 2: visited
    
    // Perform DFS on each course
    for (int course = 0; course < numCourses; course++) {
        if (!dfs(graph, visited, course)) {
            return false;
        }
    }
    
    return true;
}
};