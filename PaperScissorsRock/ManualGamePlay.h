#pragma once

#include "IGamePlay.h"

#include <iostream>

namespace Imc::Games::PaperScissorRock
{
	class ManualGamePlay : public IGamePlay
	{
	public:
		ManualGamePlay(std::istream& inStream, std::ostream& outStream);
		ManualGamePlay(const ManualGamePlay&) = delete;
		ManualGamePlay& operator=(const ManualGamePlay&) = delete;
		ManualGamePlay(ManualGamePlay&&) = default;
		ManualGamePlay& operator=(ManualGamePlay&&) = default;
		virtual ~ManualGamePlay() = default;

		RpsStrategy Play() override;

	private:
		std::istream& inStream_;
		std::ostream& outStream_;
	};
}