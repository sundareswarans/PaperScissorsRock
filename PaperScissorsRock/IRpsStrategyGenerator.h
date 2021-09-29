#pragma once
#include "RpsStrategy.h"

namespace Imc::Games::PaperScissorRock
{
    struct IRpsStrategyGenerator
    {
        virtual RpsStrategy generate() = 0;
    };
}