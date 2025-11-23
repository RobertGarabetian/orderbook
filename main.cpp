
#include "Orderbook.h"

int main ()
{
    Orderbook orderBook;

    const OrderId orderId = 1;
    orderBook.AddOrder(
        std::make_shared<Order>(OrderType::GoodTillCancel, orderId, Side::Buy, 100, 10));
    std::cout << orderBook.Size() << std::endl;
    orderBook.CancelOrder(orderId);
    std::cout << orderBook.Size() << std::endl;


    return 0;
}