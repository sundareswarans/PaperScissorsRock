#pragma once
#include "IGamePlay.h"

#include <memory>

namespace Imc::Games::PaperScissorRock
{
    struct IGamePlayFactory
    {
        virtual std::unique_ptr<IGamePlay> create() = 0;
    };
}