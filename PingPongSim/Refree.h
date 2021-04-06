#include "EinsSim.h"

class Refree : public UDEAModel
{
	enum _State { WAIT, JUDGE } m_State;

public:
	enum _Inport { RESULT };
	enum _Outport { START };

	Refree();
	~Refree();

	virtual bool ExtTransFn(UDEMessage*);
	virtual bool IntTransFn();
	virtual bool OutputFn(UDEMessage*);
	virtual double TimeAdvanceFn();
};