/*
 * OSCPProviderRealTimeSampleArrayMetricStateHandler.cpp
 *
 *  Created on: 05.05.2015
 *      Author: roehser
 */

#include "OSCLib/Data/OSCP/OSCPProviderRealTimeSampleArrayMetricStateHandler.h"
#include "OSCLib/Data/OSCP/MDIB/RealTimeSampleArrayMetricState.h"

namespace OSCLib {
namespace Data {
namespace OSCP {

OSCPProviderRealTimeSampleArrayMetricStateHandler::OSCPProviderRealTimeSampleArrayMetricStateHandler() {

}

OSCPProviderRealTimeSampleArrayMetricStateHandler::~OSCPProviderRealTimeSampleArrayMetricStateHandler() {

}

InvocationState OSCPProviderRealTimeSampleArrayMetricStateHandler::onStateChangeRequest(const RealTimeSampleArrayMetricState & , const OperationInvocationContext & ) {
	log_error([] { return "Method not overridden: onStateChangeRequest(RealTimeSampleArrayMetricState)!"; });
    return InvocationState::FAILED;
}

void OSCPProviderRealTimeSampleArrayMetricStateHandler::updateState(const OSCLib::Data::OSCP::RealTimeSampleArrayMetricState & object) {
	notifyMDIBObjectChangedImpl(object);
}

std::string OSCPProviderRealTimeSampleArrayMetricStateHandler::getDescriptorHandle() {
    return getInitialClonedState().getDescriptorHandle();
}

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */
