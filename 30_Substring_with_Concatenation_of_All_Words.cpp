class Solution {
public:
    int wordLen;
    bool match(string s, unordered_map<string,int> words, int b,int e){
        string temp ="";
        for(int i = b; i<=e; i++){
            temp += s[i];
            if((i-b+1)%wordLen ==0){
                if(words[temp] == 0)return false;
                words[temp]--;
                temp = "";
            }
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        wordLen = words[0].size();
        int n = words.size() * wordLen;
        vector<int> ans;
        unordered_map<string, int>mpp;
        
        for(auto w:words)mpp[w]++;
        
        for(int i = 0; i+ n-1 < s.size(); i++)
            if(match(s,mpp, i, i+n-1))ans.push_back(i);
        
        return ans;
        
    }
};
