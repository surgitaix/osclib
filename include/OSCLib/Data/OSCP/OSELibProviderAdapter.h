/*
 * OSELibProviderAdapter.h
 *
 *  Created on: 09.12.2015
 *      Author: matthias
 */

#ifndef DATA_OSCP_OSELIBPROVIDERADAPTER_H_
#define DATA_OSCP_OSELIBPROVIDERADAPTER_H_

#include "Poco/Mutex.h"

#include "OSCP-fwd.h"
#include "OSELib/fwd.h"
#include <set>

namespace OSCLib {
namespace Data {
namespace OSCP {

class OSELibProviderAdapter {
public:
	OSELibProviderAdapter(OSCPProvider & provider, const unsigned int port);
	virtual ~OSELibProviderAdapter();

	void start();
	void stop();

	void notifyEvent(const CDM::EpisodicAlertReport & report);
	void notifyEvent(const CDM::EpisodicContextChangedReport & report);
	void notifyEvent(const CDM::EpisodicMetricReport & report);
	void notifyEvent(const CDM::PeriodicAlertReport & report);
	void notifyEvent(const CDM::PeriodicContextChangedReport & report);
	void notifyEvent(const CDM::PeriodicMetricReport & report);
	void notifyEvent(const CDM::OperationInvokedReport & report);
	void notifyEvent(const CDM::WaveformStream & stream);

	unsigned int getPort() const;
	void setPort(unsigned int port);

	void addStreamingPort(const int port);
	void removeStreamingPort(const int port);

private:
	OSCPProvider & _provider;

	mutable Poco::Mutex mutex;
	std::unique_ptr<Poco::ThreadPool> _threadPool;

	unsigned int _port;
	std::set<int> streamingPorts;

	std::unique_ptr<OSELib::DPWS::SubscriptionManager> _subscriptionManager;
	std::unique_ptr<OSELib::DPWS::MDPWSHostAdapter> _dpwsHost;
	std::unique_ptr<Poco::Net::HTTPServer> _httpServer;
};

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */

#endif /* DATA_OSCP_OSELIBPROVIDERADAPTER_H_ */