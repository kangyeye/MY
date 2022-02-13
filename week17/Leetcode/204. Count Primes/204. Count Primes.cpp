class Solution {
public:
    int countPrimes(int n) {
        vector<bool> record(n,true);
        for(int i = 2; i * i < n; i++){
            if(record[i]){
                for(int j = i * i; j < n; j += i){
                    record[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(record[i]){
                count++;
            }
        }
        return count;
    }
};
