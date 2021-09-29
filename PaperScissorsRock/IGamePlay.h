#pragma once
#include "RpsStrategy.h"

namespace Imc::Games::PaperScissorRock
{
    struct IGamePlay
    {
        virtual RpsStrategy Play() = 0;
    };
}