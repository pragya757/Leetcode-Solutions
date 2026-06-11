class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        unordered_set<int> s;

        for(int candy : candyType) {
            s.insert(candy);
        }

        return min((int)s.size(),
                   (int)candyType.size()/2);
    }
};
