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
            if(nums[i]>0){      //nums[i]>0 则sum>0;
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){      //题目中要求去重，所以要判断这次选中的第一个数字是否和上一次选中的第一个数是否相同
                continue;
            }
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]==0){
                    Ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){      //去重
                        left=left+1;
                    }
                    while(left<right and nums[right]==nums[right-1]){       //去重
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
