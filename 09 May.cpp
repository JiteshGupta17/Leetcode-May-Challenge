class Solution {
public:
    bool isPerfectSquare(int num) {
        // Maths
        // 1 = 1;
        // 1 + 3 = 4;
        // 1 + 3 + 5 = 8;
        // 1 + 3 + 5 + 7 = 16;
        
        int x = 1;
        while(num>0)
        {
            num -= x;
            x += 2; // odd series
        }
        
        return num==0;
    }
};

//===========================================================
class Solution {
public:
    bool isPerfectSquare(int num) {
        // Binary Search
        long long mid;
        int l = 1, r = num;
        
        while(l<=r)
        {
            mid = l + (r-l)/2;
            
            long long cur = mid*mid;
            
            if(cur==num) return true;
            if(cur > num) r = mid-1;
            else l = mid + 1;
        }
        
        return false;
        
    }
};
