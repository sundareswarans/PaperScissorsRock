#pragma once
#include "IGameOutcomeStrategy.h"


namespace Imc::Games::PaperScissorRock
{
	class SimpleGameOutcomeStrategy : public IGameOutcomeStrategy
	{
	public:
		SimpleGameOutcomeStrategy() = default;
		SimpleGameOutcomeStrategy(const SimpleGameOutcomeStrategy&) = delete;
		SimpleGameOutcomeStrategy& operator=(const SimpleGameOutcomeStrategy&) = delete;
		SimpleGameOutcomeStrategy(SimpleGameOutcomeStrategy&&) = default;
		SimpleGameOutcomeStrategy& operator=(SimpleGameOutcomeStrategy&&) = default;
		virtual ~SimpleGameOutcomeStrategy() = default;

		void GetGameOutcome(const std::vector<std::unique_ptr<Player>>& players, std::ostream& outcomes) override;
	};
}