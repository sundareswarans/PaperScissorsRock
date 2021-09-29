#include "gtest/gtest.h"

#include "../PaperScissorsRock/Player.h"
#include "../PaperScissorsRock/GameCoordinator.h"

#include "../PaperScissorsRock/RandomGamePlayFactory.h"
#include "../PaperScissorsRock/ManualGamePlayFactory.h"
#include "../PaperScissorsRock/SimpleGameOutcomeStrategyFactory.h"
#include "../PaperScissorsRock/RoundRobinRpsStrategyGenerator.h"

#include <iostream>

using namespace Imc::Games::PaperScissorRock;

TEST(TestGameCoordinator, TestPlayGameForTie) {

    // Randomness can't be unit-tested,
    // hence using round robin strategy...

    std::unique_ptr<IRpsStrategyGenerator> strategyGenerator = std::make_unique<RoundRobinRpsStrategyGenerator>();
    auto randomGamePlayFactory = RandonGamePlayFactory(std::move(strategyGenerator));

    for (int32_t i = 0; i < static_cast<int32_t>(RpsStrategy::Count); ++i)
    {
        std::vector<std::unique_ptr<Player>> players;

        auto inStream = std::stringstream();
        auto outStream = std::ostringstream();

        inStream << i;

        auto manualGamePlayFactory = ManualGamePlayFactory(inStream, outStream);

        // Manual player...
        players.emplace_back(std::make_unique<Player>(std::move(manualGamePlayFactory.create())));

        // Computer player...
        players.emplace_back(std::make_unique<Player>(std::move(randomGamePlayFactory.create())));

        auto simpleGameOutcomeStrategyFactory = SimpleGameOutcomeStrategyFactory();

        auto gameOutcomeStrategy = simpleGameOutcomeStrategyFactory.create();

        std::stringstream outcomes;
        GameCoordinator gameCoordinator(players, outcomes);
        gameCoordinator.PlayGame(gameOutcomeStrategy);

        outcomes.seekg(0);
        EXPECT_NE(outcomes.str().find("Outcome is a tie. "), std::string::npos);
    }
}
