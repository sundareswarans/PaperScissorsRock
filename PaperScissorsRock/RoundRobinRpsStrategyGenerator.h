#pragma once

#include "IRpsStrategyGenerator.h"
#include "RpsStrategy.h"

#include <random>

namespace Imc::Games::PaperScissorRock
{
	class RoundRobinRpsStrategyGenerator : public IRpsStrategyGenerator
	{
	public:
		RoundRobinRpsStrategyGenerator();
		RoundRobinRpsStrategyGenerator(const RoundRobinRpsStrategyGenerator&) = delete;
		RoundRobinRpsStrategyGenerator& operator=(const RoundRobinRpsStrategyGenerator&) = delete;
		RoundRobinRpsStrategyGenerator(RoundRobinRpsStrategyGenerator&&) = default;
		RoundRobinRpsStrategyGenerator& operator=(RoundRobinRpsStrategyGenerator&&) = default;
		virtual ~RoundRobinRpsStrategyGenerator() = default;

		RpsStrategy generate() override;

	private:
		RpsStrategy rpsStrategy_;
	};
}