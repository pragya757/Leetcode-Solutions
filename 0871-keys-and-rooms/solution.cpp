class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int totalRooms = rooms.size();
        int visitedCount = 0;
      
        vector<bool> visited(totalRooms, false);
      
        function<void(int)> dfs = [&](int currentRoom) {
            if (visited[currentRoom]) {
                return;
            }
            visited[currentRoom] = true;
            visitedCount++;
            for (int nextRoom : rooms[currentRoom]) {
                dfs(nextRoom);
            }
        };
        dfs(0);
        return visitedCount == totalRooms;
    }
};
