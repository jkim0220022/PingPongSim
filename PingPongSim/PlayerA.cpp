#include "EinsSim.h"

class PlayerA : public UDEAModel
{
	enum _State { WAIT, ACT } m_State;
	enum _Inport { BALL_IN_FROM_B };
	enum _Outport { BALL_OUT_FROM_A };

public:
	PlayerA();
	~PlayerA();

	virtual bool ExtTransFn(UDEMessage*);
	virtual bool IntTransFn();
	virtual bool OutputFn(UDEMessage*);
	virtual double TimeAdvanceFn();
};