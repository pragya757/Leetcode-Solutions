class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int st=1;
        int end=n-2;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){ 
                //acts as a mountain peak
                return mid;
            }
            if(arr[mid-1]<arr[mid]){ 
                //if it is on left side then take the right half
                st=mid+1;
            }else{
                //if it is on right side then take the left half
                end=mid-1;
            }
        }
        return -1;
    }
};
