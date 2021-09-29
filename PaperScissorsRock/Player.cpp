#include "Player.h"


namespace Imc::Games::PaperScissorRock
{
    Player::Player(std::unique_ptr<IGamePlay> gamePlay)
        : gamePlay_(std::move(gamePlay))
        , chosenStrategy_(RpsStrategy::None)
    {
    }

    void Player::Play()
    {
        chosenStrategy_ = gamePlay_->Play();
    }

    RpsStrategy Player::GetChosenStrategy() const
    {
        return chosenStrategy_;
    }

    void Player::ResetChosenStrategy()
    {
        chosenStrategy_ = RpsStrategy::None;
    }
}