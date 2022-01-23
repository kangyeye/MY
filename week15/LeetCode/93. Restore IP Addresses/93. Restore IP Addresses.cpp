class Solution {
private:
    void dfs(string s,int n,int begin,string& path,vector<string>& res){
        int leftLength = s.length() - path.length() + 4 - n;
        if(leftLength > n * 3){
            return;
        }
        if(leftLength == 0){
            int count = 0;
            for(int i = 0; i < path.length(); i++){
                if(path[i] == '.'){
                    count++;
                }
            }          
            if(count == 4){
                res.emplace_back(path.substr(0,path.length()-1));
                return;
            } 
        }
        for(int j = 1; j <= 3; j++){
            if(path.length() + j - 4 + n > s.length()){
                break;
            }
            int num = stoi(s.substr(begin,j));
            if(j != 1 && s[begin] == '0'){
                continue;
            }
            if(num >= 0 && num <= 255){
                path += s.substr(begin,j) + ".";
                dfs(s,n-1,begin+j,path,res);
                path = path.substr(0,path.length()-j-1);
            }
            else{
                continue;
            } 
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> res;
        if(len < 4 || len > 12){
            return res;
        }
        string path;
        dfs(s,4,0,path,res);
        return res;
    }
};
