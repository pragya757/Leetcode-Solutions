class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate the current area
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int currentArea = currentHeight * currentWidth;
            
            // Update the maximum area found so far
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

