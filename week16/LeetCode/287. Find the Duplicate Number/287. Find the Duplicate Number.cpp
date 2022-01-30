//二分法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n - 1, ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i = 0; i < n; i++){
                count += nums[i] <= mid;
            }
            if(count <= mid){
                left = mid + 1;
            }
            else{
                right = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};


//快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
