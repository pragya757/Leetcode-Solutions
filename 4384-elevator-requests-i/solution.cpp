class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr=0;
        int time=0;
        for(int floor:requests){
            time+=abs(curr-floor);
            curr=floor;
        }
        return time;
    }
};
