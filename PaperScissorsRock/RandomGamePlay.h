#pragma once

#include "IGamePlay.h"
#include "IRpsStrategyGenerator.h"

#include <cstdint>
#include <random>
#include <memory>

namespace Imc::Games::PaperScissorRock
{
	class RandomGamePlay : public IGamePlay
	{
	public:
		RandomGamePlay(std::unique_ptr<IRpsStrategyGenerator>& rpsStrategyGenerator);
		RandomGamePlay(const RandomGamePlay&) = delete;
		RandomGamePlay& operator=(const RandomGamePlay&) = delete;
		RandomGamePlay(RandomGamePlay&&) = default;
		RandomGamePlay& operator=(RandomGamePlay&&) = default;
		virtual ~RandomGamePlay() = default;

		RpsStrategy Play() override;

	private:
		std::unique_ptr<IRpsStrategyGenerator>&  rpsStrategyGenerator_;
	};
}