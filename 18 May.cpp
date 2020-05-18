class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> s1_cnt(26,0) , s2_cnt(26,0);
        
        if(s1.length() > s2.length()) return false;
        
        for(int i = 0;i<s1.length();i++)
        {
            s1_cnt[s1[i]-'a']++;
            s2_cnt[s2[i]-'a']++;
        }
        
        if(s1_cnt==s2_cnt) return true;
        
        for(int i = s1.length();i<s2.length();i++)
        {
            s2_cnt[s2[i]-'a']++;
            s2_cnt[s2[i-s1.length()] - 'a']--;
            
            if(s1_cnt==s2_cnt) return true;
        }
        
        return false;
    }
};
