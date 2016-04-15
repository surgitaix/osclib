/*
 * PingManager.h
 *
 *  Created on: 14.12.2015
 *      Author: matthias
 */

#ifndef OSELIB_DPWS_PINGMANAGER_H_
#define OSELIB_DPWS_PINGMANAGER_H_

#include "Poco/Thread.h"
#include "Poco/RunnableAdapter.h"

#include "OSCLib/Data/OSCP/OSCP-fwd.h"
#include "OSELib/fwd.h"

namespace OSELib {
namespace DPWS {

class PingManager {
public:
	PingManager(OSCLib::Data::OSCP::OSCPConsumer & consumer);
	virtual ~PingManager();

	void disable();

private:
	void run();
	mutable Poco::Mutex _mutex;

	Poco::Thread _thread;
	Poco::RunnableAdapter<PingManager> _runnableAdapter;
	OSCLib::Data::OSCP::OSCPConsumer & _consumer;
};

} /* namespace DPWS */
} /* namespace OSELib */

#endif /* OSELIB_DPWS_PINGMANAGER_H_ */
