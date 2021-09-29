#include "gtest/gtest.h"

#include "../PaperScissorsRock/ManualGamePlay.h"
#include "../PaperScissorsRock/RandomGamePlay.h"
#include "../PaperScissorsRock/RoundRobinRpsStrategyGenerator.h"

#include <future>
#include <sstream>

using namespace Imc::Games::PaperScissorRock;

TEST(TestGamePlay, TestManualGamePlay) {

    for (int32_t i = 0; i < static_cast<int32_t>(RpsStrategy::Count); ++i)
    {
        auto inStream = std::stringstream();
        auto outStream = std::ostringstream();

        ManualGamePlay manualGamePlay(inStream, outStream);

        inStream << i;
        EXPECT_EQ(static_cast<RpsStrategy>(i), manualGamePlay.Play());
    }
}

TEST(TestGamePlay, TestRandomGamePlay) {

    // Randomness can't be unit-tested,
    // hence using round robin strategy...

    std::unique_ptr<IRpsStrategyGenerator> strategyGenerator = std::make_unique<RoundRobinRpsStrategyGenerator>();

    RandomGamePlay randomGamePlay(strategyGenerator);
    for (int32_t i = 0; i < static_cast<int32_t>(RpsStrategy::Count); ++i)
    {
        EXPECT_EQ(static_cast<RpsStrategy>(i), randomGamePlay.Play());
    }
}