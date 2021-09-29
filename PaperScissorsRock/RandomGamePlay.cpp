#include "RandomGamePlay.h"

#include <chrono>
#include <ctime>
#include <functional>

namespace Imc::Games::PaperScissorRock
{
    RandomGamePlay::RandomGamePlay(std::unique_ptr<IRpsStrategyGenerator>& rpsStrategyGenerator)
        : rpsStrategyGenerator_(rpsStrategyGenerator)
    {
    }

    RpsStrategy RandomGamePlay::Play()
    {
        return rpsStrategyGenerator_->generate();
    }
}