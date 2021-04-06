#include "PlayerA.h"

PlayerA::PlayerA()
{
	SetName("PlayerA");
	m_State = _State::WAIT;

	AddInPort(_Inport::BALL_IN_FROM_B);
	AddOutPort(_Outport::BALL_OUT_FROM_A);


}