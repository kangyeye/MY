class Solution {
public:
    string reversePrefix(string word, char ch) {
        int end = 0;
        while(end < word.length() && word[end] != ch){
            end++;
        }
        if(end == word.length()){
            return word;
        }
        reverse(word.begin(),word.begin() + end + 1);
        return word;
    }
};
