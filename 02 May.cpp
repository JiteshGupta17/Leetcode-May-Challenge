class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // Method - 1 to use self defined array
        // vector<int> characters(126,0);
        
        // Method - 2 use of set
        unordered_set<char> set;
        
        for(char ch : J){
            // characters[ch]++;
            set.insert(ch);
        }
        
        int ans = 0;
        for(char ch : S)
        {
            // if(characters[ch]) ans++;
            if(set.find(ch) != set.end()) ans++;
        }
        
        return ans;
    }
};
