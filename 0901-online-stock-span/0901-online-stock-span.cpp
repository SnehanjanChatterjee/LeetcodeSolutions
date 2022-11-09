class StockSpanner {
private:
    vector<int> stocks;
    int stocksSize;

    int mySoln(int price) {
        int c = 1;
        for(int i=stocksSize-1; i>=0 ; i--, c++) {
            if(stocks[i] > price) break;
        }
        stocks.push_back(price);
        stocksSize++;
        return c;
    }

    // https://leetcode.com/problems/online-stock-span/solutions/2795090/c-stack-faster-easy-to-understand/
    
    // declare a stack of pair {price, count}
    // count will keep track of no. of consecutive elements less than or equal to price
    stack<pair<int, int>> st;

    int otherSoln(int price) {
        int count = 0;

        // find no. of elements less than or equal to curr price
        while(st.empty() == false && st.top().first <= price)
        {
            // update count
            count += st.top().second;

            // pop the smaller element
            st.pop();
        }

        // increment the count for curr price
        count++;

        // push the {price, count} into stack
        st.push({price, count});

        return count;
    }
public:
    StockSpanner() {
        // stocks = vector<int>();
        // stocksSize = 0;
    }
    
    int next(int price) {
        // return mySoln(price);

        return otherSoln(price);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */