//方法一：暴力枚举
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};


//方法二：哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;      //创建哈希表
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);     //find()函数返回一个迭代器指向键值为key的元素，如果没有找到就返回指向map尾部的迭代器。
            if (it != hashtable.end()) {
                return {it->second, i};         //用迭代器访问元素的键值对应的元素值 it->second
            }
            hashtable[nums[i]] = i;         //map添加数据   hashtable[key]=value;
        }
        return {};
    }
};
