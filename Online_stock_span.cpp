class StockSpanner {
    stack<pair<int,int>>s;
    vector<int>v;
    int i;
public:
    StockSpanner() {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        i=0;
    }
    
    int next(int price) {
       // for(i=0;i<price.size();i++){
            if(s.size()==0) v.push_back(-1);
            else if(s.size()>0 && s.top().first>price){
                    v.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first<=price){
                while(s.size()>0 && s.top().first<=price)
                s.pop();
                if(s.empty()) v.push_back(-1);
                else v.push_back(s.top().second);
            }
            s.push({price,i});
            i++;
       // }

        //for(int j=0;j<v.size();j++)
           return  (i-1)-v[i-1];
        

        //return v;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */