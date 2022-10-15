
class StockSpanner {

    stackStockData = [];

    /** 
     * @param {number} price
     * @return {number}
     */
    next(price) {
        let previousSpan = 0;
        let stackSize = this.stackStockData.length;
        while (stackSize > 0 && this.stackStockData[stackSize - 1].price <= price) {
            previousSpan += this.stackStockData.pop().span;
            --stackSize;
        }
        this.stackStockData.push(new StockData(price, previousSpan + 1));
        return this.stackStockData[stackSize].span;
    }
}

function StockData(price, span) {
    this.price = price;
    this.span = span;
}
