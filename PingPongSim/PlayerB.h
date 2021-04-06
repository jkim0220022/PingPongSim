#include "EinsSim.h"

class PlayerB : public UDEAModel
{
	enum _State { WAIT, ACT } m_State;

public:
	enum _Inport { BALL_IN_FROM_A };
	enum _Outport { BALL_OUT_FROM_B };

	PlayerB();
	~PlayerB();

	virtual bool ExtTransFn(UDEMessage*);
	virtual bool IntTransFn();
	virtual bool OutputFn(UDEMessage*);
	virtual double TimeAdvanceFn();
};
