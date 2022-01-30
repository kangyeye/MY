class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int len = intervals.size();
        int i = 0;
        //判断左边不重合
        while(i < len && intervals[i][1] < newInterval[0]){
            res.emplace_back(intervals[i]);
            i++;
        }
        //判断重合
        while(i < len && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        res.emplace_back(newInterval);
        //判断右边不重合
        while(i < len && intervals[i][0] > newInterval[1]){
            res.emplace_back(intervals[i]);
            i++;
        }
        return res;

    }
};
