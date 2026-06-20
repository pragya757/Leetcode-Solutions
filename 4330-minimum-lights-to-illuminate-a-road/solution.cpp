class Solution {
public:
    int minLights(vector<int>& lights) {

        int n = lights.size();
        auto ravelunico = lights;

        vector<int> diff(n+1,0);

        
        for(int i=0;i<n;i++){

            if(lights[i]>0){

                int left = max(0, i-lights[i]);
                int right = min(n-1, i+lights[i]);

                diff[left]++;

                if(right+1<n)
                    diff[right+1]--;
            }
        }

        vector<bool> visible(n,false);

        int curr=0;

        for(int i=0;i<n;i++){

            curr += diff[i];

            if(curr>0)
                visible[i]=true;
        }

        int count=0;
        int i=0;

        while(i<n){

            if(visible[i]){

                i++;
            }
            else{

                count++;

                i += 3;     
            }
        }

        return count;
    }
};
