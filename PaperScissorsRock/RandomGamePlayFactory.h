#pragma once

#include "IGamePlayFactory.h"
#include "RandomGamePlay.h"
#include "IRpsStrategyGenerator.h"

#include <memory>

namespace Imc::Games::PaperScissorRock
{
    class RandonGamePlayFactory : public IGamePlayFactory
    {
    public:
        RandonGamePlayFactory(std::unique_ptr<IRpsStrategyGenerator> rpsStrategyGenerator)
            : rpsStrategyGenerator_(std::move(rpsStrategyGenerator))
        {}
        RandonGamePlayFactory(const RandonGamePlayFactory&) = delete;
        RandonGamePlayFactory& operator=(const RandonGamePlayFactory&) = delete;
        RandonGamePlayFactory(RandonGamePlayFactory&&) = default;
        RandonGamePlayFactory& operator=(RandonGamePlayFactory&&) = default;
        virtual ~RandonGamePlayFactory() = default;

        std::unique_ptr<IGamePlay> create() override
        {
            return std::make_unique<RandomGamePlay>(rpsStrategyGenerator_);
        }

    private:
        std::unique_ptr<IRpsStrategyGenerator> rpsStrategyGenerator_;
    };
}