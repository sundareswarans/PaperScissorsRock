#pragma once

#include "IGameOutcomeStrategyFactory.h"
#include "SimpleGameOutcomeStrategy.h"

#include <memory>

namespace Imc::Games::PaperScissorRock
{
    class SimpleGameOutcomeStrategyFactory : public IGameOutcomeStrategyFactory
    {
    public:
        std::unique_ptr<IGameOutcomeStrategy> create() override
        {
            return std::make_unique<SimpleGameOutcomeStrategy>();
        }
    };
}