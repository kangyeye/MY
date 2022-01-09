class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize != 0){
            return false;
        }
        sort(hand.begin(),hand.end());
        unordered_map<int,int> cnt;
        for(auto num : hand){
            cnt[num]++;
        }
        for(auto x : hand){
            if(cnt.count(x) == 0){
                continue;
            }
            for(int i = 0;i < groupSize; i++){
                int num = x + i;
                if(cnt.count(num) == 0){
                    return false;
                }
                cnt[num]--;
                if(cnt[num]==0){
                    cnt.erase(num);
                }
            }
        }
        return true;
    }
};
