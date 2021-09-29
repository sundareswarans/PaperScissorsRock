#pragma once

#include "IGamePlayFactory.h"
#include "ManualGamePlay.h"

#include <memory>

namespace Imc::Games::PaperScissorRock
{
    class ManualGamePlayFactory : public IGamePlayFactory
    {
    public:
        ManualGamePlayFactory(std::istream& inStream, std::ostream& outStream)
            : inStream_(inStream)
            , outStream_(outStream)
        {}
        ManualGamePlayFactory(const ManualGamePlayFactory&) = delete;
        ManualGamePlayFactory& operator=(const ManualGamePlayFactory&) = delete;
        ManualGamePlayFactory(ManualGamePlayFactory&&) = default;
        ManualGamePlayFactory& operator=(ManualGamePlayFactory&&) = default;
        virtual ~ManualGamePlayFactory() = default;

        std::unique_ptr<IGamePlay> create() override
        {
            return std::make_unique<ManualGamePlay>(inStream_, outStream_);
        }

    private:
        std::istream& inStream_;
        std::ostream& outStream_;
    };
}