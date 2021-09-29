#pragma once

#include "IGamePlay.h"

#include <memory>

namespace Imc::Games::PaperScissorRock
{
	class Player
	{
	public:
		Player(std::unique_ptr<IGamePlay> gamePlay);
		Player(const Player&) = delete;
		Player& operator=(const Player&) = delete;
		Player(Player&&) = default;
		Player& operator=(Player&&) = default;
		~Player() = default;

		void Play();

		RpsStrategy GetChosenStrategy() const;

		void ResetChosenStrategy();

	private:
		RpsStrategy chosenStrategy_;
		std::unique_ptr<IGamePlay> gamePlay_;
	};
}