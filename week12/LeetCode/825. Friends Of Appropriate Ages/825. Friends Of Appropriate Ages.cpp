class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121);
        for(int i=0;i<ages.size();i++){
            count[ages[i]]++;
        }
        vector<int> pre(121);
        for(int i=1;i<=120;i++){
            pre[i]=count[i]+pre[i-1];
        }
        int ans=0;
        for(int i=15;i<121;i++){
            if(count[i]){
                int bound=0.5*i+8;
                ans=ans+count[i]*(pre[i]-pre[bound-1]-1);
            }
        }
        return ans;
    }
};
