class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // To map the lowercase characters
        vector<int> characters(26,0);
        
        for(char ch : magazine) characters[ch-'a']++;
        
        for(char ch : ransomNote)
        {
            if(characters[ch-'a']==0) return false;
            characters[ch-'a']--;
        }
        
        return true;
        
    }
};
