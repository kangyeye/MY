//二分法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return -1;
        }
        if(len == 1 && target != nums[0]){
            return -1;
        }
        int left = 0;
        int right = len - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target <= nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
