//逆序双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int curr = m + n - 1;
        int p = m - 1;
        int q = n - 1;
        while(p >= 0 && q >= 0){
            if(nums1[p] > nums2[q]){
                nums1[curr] = nums1[p--];
            } else{
                nums1[curr] = nums2[q--];
            }
            curr--;
        }
        if(q >= 0){
            while(curr >= 0){
                nums1[curr] = nums2[q--];
                curr--;
            }
        }
    }
};
