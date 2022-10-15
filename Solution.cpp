
#include <stack>
using namespace std;

class StockSpanner {

    struct StockData {
        int price{};
        int span{};
        StockData(int price, int span) : price{price}, span{ span}{}
    };
    
    stack<StockData> stackStockData;

public:
    StockSpanner() = default;

    int next(int price) {
        int previousSpan = 0;
        while (!stackStockData.empty() && stackStockData.top().price <= price) {
            previousSpan += stackStockData.top().span;
            stackStockData.pop();
        }
        stackStockData.emplace(StockData(price, previousSpan + 1));
        return stackStockData.top().span;
    }
};
