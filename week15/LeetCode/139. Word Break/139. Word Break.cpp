//dp[i]=dp[j] && check(s[j..i−1])
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        int longestWord = 0;
        for(auto word : wordDict){
            wordDictSet.insert(word);
            int currword = word.length();
            longestWord = max(longestWord,currword);
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<=i;j++){
                if(dp[j] && wordDictSet.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};



//优化    dp[i]只需要往前探索到词典里最长的单词即可
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        int longestWord = 0;
        for(auto word : wordDict){
            wordDictSet.insert(word);
            int currword = word.length();
            longestWord = max(longestWord,currword);
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=0 && j>=i-longestWord;j--){
                if(dp[j] && wordDictSet.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
