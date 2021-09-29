#include "ManualGamePlay.h"

#include <iostream>

namespace Imc::Games::PaperScissorRock
{
    ManualGamePlay::ManualGamePlay(std::istream& inStream, std::ostream& outStream)
        : inStream_(inStream)
        , outStream_(outStream)
    {
    }

    RpsStrategy ManualGamePlay::Play()
    {
        int32_t input = -1;
        while (true)
        {
            if (input >= static_cast<int32_t>(RpsStrategy::Rocks) && input <= static_cast<int32_t>(RpsStrategy::Paper))
            {
                return static_cast<RpsStrategy>(input);
            }
            else
            {
                outStream_ << "Enter strategy: \n";
                outStream_ << "0: Rock \n";
                outStream_ << "1: Scissors\n";
                outStream_ << "2: Paper\n";
            }
            inStream_ >> input;
        }
    }
}