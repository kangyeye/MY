class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<3){
            return {};
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]==0){
                    Ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                        left=left+1;
                    }
                    while(left<right and nums[right]==nums[right-1]){
                        right=right-1;
                    }
                        
                    left=left+1;
                    right=right-1;
                    continue;
                }
                if(nums[i]+nums[left]+nums[right]<0){
                    left=left+1;
                    continue;
                }
                if(nums[i]+nums[left]+nums[right]>0){
                    right=right-1;
                    continue;
                }
            }
        }
        return Ans;
    }
};
