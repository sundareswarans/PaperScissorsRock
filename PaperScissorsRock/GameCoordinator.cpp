#include "GameCoordinator.h"

#include <future>
#include <iostream>

namespace Imc::Games::PaperScissorRock
{
    GameCoordinator::GameCoordinator(std::vector<std::unique_ptr<Player>>& players, std::ostream& outcomes)
        : players_(players)
        , outcomes_(outcomes)
    {
    }

    GameCoordinator::~GameCoordinator()
    {
    }

    void GameCoordinator::PlayGame(std::unique_ptr<IGameOutcomeStrategy>& gameOutcome)
    {
        if (players_.empty())
            return;

        std::vector<std::future<void>> futures;
        for (auto& player : players_)
            futures.emplace_back(std::async([this, &player] {PlayerTask(player); }));

        //Wait until all players played their turns...
        for (auto& future : futures)
            future.get();

        // Decide which player wins...
        gameOutcome->GetGameOutcome(players_, outcomes_);
    }

    void GameCoordinator::PlayerTask(std::unique_ptr<Player>& player)
    {
        player->ResetChosenStrategy();
        player->Play();
    }
}