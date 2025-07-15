#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

int longestSubarray(int* nums, int numsSize, int limit) {
    int maxDeque[MAX_SIZE], minDeque[MAX_SIZE];
    int maxFront = 0, maxBack = 0;
    int minFront = 0, minBack = 0;

    int left = 0, result = 0;

    for (int right = 0; right < numsSize; ++right) {
        // Maintain maxDeque (decreasing)
        while (maxBack > maxFront && nums[right] > maxDeque[maxBack - 1])
            maxBack--;
        maxDeque[maxBack++] = nums[right];

        // Maintain minDeque (increasing)
        while (minBack > minFront && nums[right] < minDeque[minBack - 1])
            minBack--;
        minDeque[minBack++] = nums[right];

        // If difference exceeds limit, shrink window from left
        while (maxDeque[maxFront] - minDeque[minFront] > limit) {
            if (nums[left] == maxDeque[maxFront])
                maxFront++;
            if (nums[left] == minDeque[minFront])
                minFront++;
            left++;
        }

        // Update result
        int windowLength = right - left + 1;
        if (windowLength > result)
            result = windowLength;
    }

    return result;
}

