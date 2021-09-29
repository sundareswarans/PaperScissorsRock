#pragma once
#include "IGameOutcomeStrategy.h"

#include <memory>

namespace Imc::Games::PaperScissorRock
{
    struct IGameOutcomeStrategyFactory
    {
        virtual std::unique_ptr<IGameOutcomeStrategy> create() = 0;
    };
}