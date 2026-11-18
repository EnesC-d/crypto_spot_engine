#pragma once

#include<algorithm>
#include<array>
#include<cstdint>
#include<string_view>
#include<type_traits>

namespace engine::core{
    using Price = std::int64_t; //Avoiding decimals for prices; Precision to 1*10**9
    using Quantity = std::uint64_t; //Amount of tokens in order
    using OrderId = std::uint64_t; 
    using SequenceTracker = std::uint64_t; //Event tracker
    using Timestamp = std::uint64_t; 
    using ParticipantId = std::uint32_t; //Uniqe participant id
    using MatchId = std::uint64_t; //Id of match seller and buyer

    inline constexpr Price PRICE_SCALE = 1'000'000'000;

    enum class Side : std::uint8_t {
        BUY,
        SELL,
    };

    enum class OrderType : std::uint8_t{
        LIMIT, //resting order
        MARKET, //Fill anything
        IOC, //Fill whatever is possible at certan price and cancel
        FOK, //Fill everything or cancel
        GTC, 
    };
}