class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int x = coordinates[0][0], y = coordinates[0][1];
        
        double slope = (double)(coordinates[1][1] - y)/(double)(coordinates[1][0] - x);
        
        for(int i = 2;i<coordinates.size();i++)
        {
            double Nr = coordinates[i][1] - y;
            double Dr = coordinates[i][0] - x;
            
            if(Nr/Dr != slope) return false;
        }
        
        return true;
        
    }
};
