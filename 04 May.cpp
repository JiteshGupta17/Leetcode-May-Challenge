// Method - 1 Time complexity at max is O(32) as while loop runs till the last set bit of num
class Solution {
public:
    int findComplement(int num) {

        int ans = 0;
        int i =  0;
        while (num)
        {
            int cur_bit = num & 1 == 1 ? 0 : 1;

            // if cur_bit (ith bit) is not set in num, then set the ith bit of ans
            if (cur_bit)
            {
                ans |= (1 << i);
            }
            i++;
            num >>= 1;
        }
        return ans;
    }
};

// Method - 2 Tme Complexity same as above
class Solution {
public:
    int findComplement(int num) {

        unsigned int mask = ~0;
        // mask = 111111111111 32 bits

        while (num & mask) mask <<= 1;

        // num   = 00000101;
        // mask  = 11111000;
        // ~mask & ~num = 00000010;

        return ~mask & ~num;
    }
};
