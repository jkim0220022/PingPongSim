#include "Refree.h"

Refree::Refree()
{
	SetName("Refree");
	m_State = _State::ACT;

	AddInPort(_InPort::STOP);
	AddOutPort(_OutPort::START);
}

Refree::~Refree()
{

}

bool Refree::ExtTransFn(UDEMessage* _msg)
{
	if (_msg->GetPort() == _InPort::STOP)
	{
		m_State = _State::WAIT;
		UDEIF->SimulationEnd();
		return true;
	}
	else return false;
		
}

bool Refree::IntTransFn()
{
	return true;
}

bool Refree::OutputFn(UDEMessage* _msg)
{
	_msg->SetPortValue(_OutPort::START, nullptr);
	return true;
}

double Refree::TimeAdvanceFn()
{
	if (m_State == _State::ACT) return 1.0;
	return Infinity;
}