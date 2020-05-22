// Less time - 12ms
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;
        for (auto ch : s) mp[ch]++;


        vector<pair<int, char>> v;
        for (auto ele : mp)
        {
            v.push_back({ele.second, ele.first});
        }

        sort(v.begin(), v.end());

        string ans = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += string(v[i].first, v[i].second);
        }

        return ans;

    }
};

// ======================================================================

// Greater time  - 76ms
class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};

        for (char ch : s)
            ++counts[ch];

        sort(s.begin(), s.end(), [&](char a, char b) {
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
        });

        return s;
    }
};

