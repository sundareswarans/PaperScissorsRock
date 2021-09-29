#include "RoundRobinRpsStrategyGenerator.h"

#include <chrono>
#include <ctime>

namespace Imc::Games::PaperScissorRock
{
    RoundRobinRpsStrategyGenerator::RoundRobinRpsStrategyGenerator() 
        : rpsStrategy_(RpsStrategy::None)
    {
    }

    RpsStrategy RoundRobinRpsStrategyGenerator::generate()
    {
        rpsStrategy_ = static_cast<RpsStrategy>(static_cast<int32_t>(rpsStrategy_) + 1);
        if (static_cast<int32_t>(rpsStrategy_) >= static_cast<int32_t>(RpsStrategy::Count))
            rpsStrategy_ = RpsStrategy::Rocks;
        return rpsStrategy_;
    }
}