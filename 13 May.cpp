class Solution {
public:
	string removeKdigits(string num, int k) {

		if (k == 0) return num;
		if (k >= num.length()) return "0";

		// 1540200 - 140200 - 10200 - 200
		// 1400300 - 100300 - 300

		num.push_back('0');

		int prev = -1;
		string s = "";

		for (int i = 0; i < num.length(); i++)
		{

			while (!s.empty() && k && s.back() > num[i])
			{
				s.pop_back();
				k--;
			}

			if (num[i] != '0')
				s.push_back(num[i]);
			else if (!s.empty()) s.push_back(num[i]);

		}

		if (s.empty()) return "0";

		// To remove the zero we added at last
		s.pop_back();

		return s;

	}
};
