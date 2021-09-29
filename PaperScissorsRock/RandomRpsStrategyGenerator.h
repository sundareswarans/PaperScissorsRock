#pragma once

#include "IRpsStrategyGenerator.h"
#include "RpsStrategy.h"

#include <random>

namespace Imc::Games::PaperScissorRock
{
    class RandomRpsStrategyGenerator : public IRpsStrategyGenerator
    {
    public:
		RandomRpsStrategyGenerator();
		RandomRpsStrategyGenerator(const RandomRpsStrategyGenerator&) = delete;
		RandomRpsStrategyGenerator& operator=(const RandomRpsStrategyGenerator&) = delete;
		RandomRpsStrategyGenerator(RandomRpsStrategyGenerator&&) = default;
		RandomRpsStrategyGenerator& operator=(RandomRpsStrategyGenerator&&) = default;
		virtual ~RandomRpsStrategyGenerator() = default;
		
		RpsStrategy generate() override;

	private:
        std::mt19937 engine_;
		std::uniform_int_distribution<> distribution_;
    };
}