class StockSpanner {
public:
    
    // First for the price and second for indexing
    stack<pair<int,int>> s;
    int i = -1;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        i++;
        
        if(s.empty())
        {
            s.push({price,i});
            return i+1;
        }
        
        while(!s.empty() && price >= s.top().first)
        {
            s.pop();
        }
        
        int ans = s.empty() ? i+1 : i - s.top().second;
        s.push({price,i});
        
        return ans;
    }
};
