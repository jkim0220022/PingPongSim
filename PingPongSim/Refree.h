#include "EinsSim.h"

class Refree : public UDEAModel
{
	enum _State { WAIT, ACT } m_State;

public:
	enum _InPort { STOP };
	enum _OutPort { START };

	Refree();
	~Refree();

	virtual bool ExtTransFn(UDEMessage*);
	virtual bool IntTransFn();
	virtual bool OutputFn(UDEMessage*);
	virtual double TimeAdvanceFn();
};