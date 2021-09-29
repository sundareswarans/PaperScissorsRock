#pragma once

#include "RpsStrategy.h"

#include <exception>
#include <string>

namespace Imc::Games::PaperScissorRock
{
    class Common
    {
    public:
        static const char* const GetRpsStrategyText(RpsStrategy strategy)
        {
            switch (strategy)
            {
            case RpsStrategy::None:
                return "None";
            case RpsStrategy::Rocks:
                return "Rocks";
            case RpsStrategy::Scissors:
                return "Scissors";
            case RpsStrategy::Paper:
                return "Paper";
            case RpsStrategy::Count:
            default:
                throw std::exception("Invalid strategy");
            };
        }
    };
}