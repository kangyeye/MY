class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int weeksSum = 0;
        int daysSum = 0;
        for(int i=weeks+1;i<=days+weeks;i++){
            daysSum = daysSum + i;
        }
        weeksSum = weeks*28;
        for(int j=2;j<=weeks;j++){
            weeksSum += 7*(j-1);
        }
        return weeksSum + daysSum;
    }
};
