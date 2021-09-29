
#include "Common.h"
#include "Player.h"
#include "SimpleGameOutcomeStrategy.h"

#include <algorithm>
#include <string>
#include <iostream>

namespace Imc::Games::PaperScissorRock
{
    void SimpleGameOutcomeStrategy::GetGameOutcome(const std::vector<std::unique_ptr<Player>>& players, std::ostream& outcomes)
    {
        if (players.size() < 2)
            return;

        auto playerStrategy = players.front()->GetChosenStrategy();

        bool isTie = std::all_of(
            std::cbegin(players),
            std::cend(players),
            [playerStrategy](const std::unique_ptr<Player>& player) -> bool {
            return playerStrategy == player->GetChosenStrategy();
        });

        if (isTie)
        {
            outcomes << "Outcome is a tie. All players have chosen: " << Common::GetRpsStrategyText(playerStrategy) << "\n";
            return;
        }
        if (players.size() == 2)
        {
            auto otherPlayerStrategy = players.back()->GetChosenStrategy();

            outcomes << "Player 1 has chosen: " << Common::GetRpsStrategyText(playerStrategy) << "\n";
            outcomes << "Player 2 has chosen: " << Common::GetRpsStrategyText(otherPlayerStrategy) << "\n";

            bool player1Wins = false;
            switch (playerStrategy)
            {
            case RpsStrategy::Rocks:
                player1Wins = (otherPlayerStrategy == RpsStrategy::Scissors);
                break;
            case RpsStrategy::Scissors:
                player1Wins = (otherPlayerStrategy == RpsStrategy::Paper);
                break;
            case RpsStrategy::Paper:
                player1Wins = (otherPlayerStrategy == RpsStrategy::Rocks);
                break;

            };
            if (player1Wins)
                outcomes << "Player 1 wins.\n";
            else
                outcomes << "Player 2 wins.\n";
        }
        else
        {
            throw std::exception("Support for more than 2 players to be implemented...");
        }
    }
}