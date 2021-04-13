#include "PlayerA.h"

PlayerA::PlayerA()
{
	SetName("PlayerA");
	m_State = _State::WAIT;

	AddInPort(_InPort::BALL_IN_FROM_B);
	AddInPort(_InPort::START_FROM_REFREE);
	AddOutPort(_OutPort::BALL_OUT_FROM_A);
}

PlayerA::~PlayerA()
{

}

bool PlayerA::ExtTransFn(UDEMessage* _msg)
{
	if (_msg->GetPort() == _InPort::START_FROM_REFREE)
	{
		m_State = _State::ACT;
		return true;
	}
	else if (_msg->GetPort() == _InPort::BALL_IN_FROM_B)
	{
		m_State = _State::ACT;
		return true;
	}
	else return false;
}

bool PlayerA::IntTransFn()
{
	if (m_State == _State::ACT) m_State = _State::WAIT;
	return true;
}

bool PlayerA::OutputFn(UDEMessage* _msg)
{
	if (m_State == _State::ACT) _msg->SetPortValue(BALL_OUT_FROM_A, nullptr);
	return true;
}

double PlayerA::TimeAdvanceFn()
{
	if (m_State == _State::ACT) return 1.0;
	return Infinity;
}