class Solution {
public:
    
    int firstUniqChar(string s) {
        
        vector<int> count(26,0);
        
        // Precalculating number of times each character appeared in the string s
        for(char ch : s) count[ch-'a']++;
        
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            
            // return the first character we encounter which appeared only 1 time
            if(count[ch-'a'] == 1) return i;
        }
        
        return -1;
    }
};
