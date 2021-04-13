#include "EinsSim.h"

class PlayerA : public UDEAModel
{
	enum _State { WAIT, ACT } m_State;

public:
	enum _InPort { BALL_IN_FROM_B, START_FROM_REFREE };
	enum _OutPort { BALL_OUT_FROM_A };

	PlayerA();
	~PlayerA();

	virtual bool ExtTransFn(UDEMessage*);
	virtual bool IntTransFn();
	virtual bool OutputFn(UDEMessage*);
	virtual double TimeAdvanceFn();
};