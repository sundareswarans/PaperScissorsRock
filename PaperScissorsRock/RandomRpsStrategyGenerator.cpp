#include "RandomRpsStrategyGenerator.h"

#include <chrono>
#include <ctime>

namespace Imc::Games::PaperScissorRock
{
    RandomRpsStrategyGenerator::RandomRpsStrategyGenerator()
    {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        // Use the current epoch as seed value...
        engine_.seed(static_cast<int32_t>(time));
        distribution_ = std::uniform_int_distribution(0, static_cast<int32_t>(RpsStrategy::Count) - 1);
    }

    RpsStrategy RandomRpsStrategyGenerator::generate()
    {
        return RpsStrategy(distribution_(engine_));
    }
}