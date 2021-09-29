#pragma once

#include "IGameOutcomeStrategy.h"
#include "Player.h"

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

namespace Imc::Games::PaperScissorRock
{
	class GameCoordinator
	{
	public:
		GameCoordinator(std::vector<std::unique_ptr<Player>>& players, std::ostream& outcomes);
		GameCoordinator(const GameCoordinator&) = delete;
		GameCoordinator& operator=(const GameCoordinator&) = delete;
		GameCoordinator(GameCoordinator&&) = default;
		GameCoordinator& operator=(GameCoordinator&&) = default;
		virtual ~GameCoordinator();

		void PlayGame(std::unique_ptr<IGameOutcomeStrategy>& gameOutcome);

	protected:
		void PlayerTask(std::unique_ptr<Player>& player);

	private:
		std::ostream& outcomes_;
		std::vector<std::unique_ptr<Player>>& players_;
	};
}