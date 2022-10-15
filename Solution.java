
import java.util.Stack;

public class StockSpanner {

    private record StockData(int price, int span) {}
    private final Stack<StockData> stackStockData;

    public StockSpanner() {
        stackStockData = new Stack<>();
    }

    public int next(int price) {
        int previousSpan = 0;
        while (!stackStockData.isEmpty() && stackStockData.peek().price <= price) {
            previousSpan += stackStockData.peek().span;
            stackStockData.pop();
        }
        stackStockData.push(new StockData(price, previousSpan + 1));
        return stackStockData.peek().span;
    }
}
