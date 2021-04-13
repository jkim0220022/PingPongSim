#include "PlayerB.h"

PlayerB::PlayerB()
{
	SetName("PlayerB");
	m_State = _State::WAIT;

	AddInPort(_InPort::BALL_IN_FROM_A);
	AddOutPort(_OutPort::BALL_OUT_FROM_B);
}

PlayerB::~PlayerB()
{

}

bool PlayerB::ExtTransFn(UDEMessage* _msg)
{
	if (_msg->GetPort() == _InPort::BALL_IN_FROM_A)
	{
		m_State = _State::ACT;
		return true;
	}
	else return false;
}

bool PlayerB::IntTransFn()
{
	if (m_State == _State::ACT) m_State = _State::WAIT;
	return true;
}

bool PlayerB::OutputFn(UDEMessage* _msg)
{
	if (m_State == _State::ACT) _msg->SetPortValue(BALL_OUT_FROM_B, nullptr);
	return true;
}

double PlayerB::TimeAdvanceFn()
{
	if (m_State == _State::ACT) return 1.0;
	return Infinity;
}