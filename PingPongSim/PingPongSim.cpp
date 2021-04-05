#include <tchar.h>
#include "EinsSim.h"
#include "PingPongSim.h"
#include "easylogging++.h"

int _tmain(int argc, _TCHAR* argv[])
{

	UDEEngine* engineIF = new UDEEngine();
	SET_UDEIF(engineIF);

	engineIF->Randomize();
	engineIF->SetDefaultLogger();

	engineIF->SetModel(new PingPongSim());
	engineIF->SimulationStart();
	engineIF->DeleteModel();

	return 0;
}