// PaperScissorsRock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Player.h"
#include "GameCoordinator.h"

#include "RandomGamePlayFactory.h"
#include "ManualGamePlayFactory.h"
#include "SimpleGameOutcomeStrategyFactory.h"
#include "RandomRpsStrategyGenerator.h"

#include <iostream>

using namespace Imc::Games::PaperScissorRock;

int main()
{
    std::vector<std::unique_ptr<Player>> players;

    auto randomGamePlayFactory = RandonGamePlayFactory(std::make_unique<RandomRpsStrategyGenerator>());
    auto manualGamePlayFactory = ManualGamePlayFactory(std::cin, std::cout);

    // Manual player...
    players.emplace_back(std::make_unique<Player>(std::move(manualGamePlayFactory.create())));

    // Computer player...
    players.emplace_back(std::make_unique<Player>(std::move(randomGamePlayFactory.create())));

    auto simpleGameOutcomeStrategyFactory = SimpleGameOutcomeStrategyFactory();

    auto gameOutcomeStrategy = simpleGameOutcomeStrategyFactory.create();

    GameCoordinator gameCoordinator(players, std::cout);

    int count = 10000;
    while (count--)
        gameCoordinator.PlayGame(gameOutcomeStrategy);
}
