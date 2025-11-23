#pragma once

#include <iostream>
#include <algorithm>
#include <optional>
#include <memory>
#include <list>
#include <map>
#include <unordered_map>

#include "Usings.h"
#include "Order.h"
#include "Trade.h"
#include "OrderModify.h"
#include "OrderbookLevelInfos.h"

class Orderbook 
{
private:
    struct OrderEntry 
    {
        OrderPointer order_ = nullptr;
        OrderPointers::iterator location_;
    };

    std::map<Price, OrderPointers, std::greater<Price>> bids_;
    std::map<Price, OrderPointers, std::less<Price>> asks_;
    std::unordered_map<OrderId, OrderEntry> orders_;

    bool canMatch(Side side, Price price) const;
    Trades MatchOrders();

public:
    Trades AddOrder(OrderPointer order);
    void CancelOrder(OrderId orderId);
    Trades ModifyOrder(OrderModify order);
    std::size_t Size() const { return orders_.size(); }
    OrderBookLevelInfos GetOrderInfo() const;
    
};