/**
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  *
  */

/*
 * MDIBContainer.h
 *
 *  @Copyright (C) 2014, SurgiTAIX AG
 *  Author: roehser, besting
 */

#ifndef MDIBCONTAINER_H_
#define MDIBCONTAINER_H_

#include "OSCLib/Data/OSCP/MDIB/MDIB-fwd.h"

#include <string>

namespace OSCLib {
namespace Data {
namespace OSCP {

class MdibContainer {
public:
    MdibContainer();
    virtual ~MdibContainer();

    void setMdDescription(const MdDescription & mdd);
    MdDescription getMdDescription() const;
    void setMdState(const MdState & mds);
    MdState getMdState() const;
    void setMdibVersion(const unsigned long long version);
    unsigned long long int getMdibVersion() const;

    typedef CDM::Mdib WrappedType;

	bool findDescriptor(const std::string & handle, AlertConditionDescriptor & outDescriptor) const;
	bool findDescriptor(const std::string & handle, AlertSignalDescriptor & outDescriptor) const;
	bool findDescriptor(const std::string & handle, AlertSystemDescriptor & outDescriptor) const;
	bool findDescriptor(const std::string & handle, LimitAlertConditionDescriptor & outDescriptor) const;

    bool findDescriptor(const std::string & handle, EnumStringMetricDescriptor & outDescriptor) const;
    bool findDescriptor(const std::string & handle, NumericMetricDescriptor & outDescriptor) const;
    bool findDescriptor(const std::string & handle, RealTimeSampleArrayMetricDescriptor & outDescriptor) const;
    bool findDescriptor(const std::string & handle, StringMetricDescriptor & outDescriptor) const;

    // TODO: use new unique_ptr implementations
	template<class TState>
	std::unique_ptr<TState> findState(const std::string & handle) const;
//	bool findState(const std::string & handle, NumericMetricState & outState) const;
//	bool findState(const std::string & handle, RealTimeSampleArrayMetricState & outState) const;
//	bool findState(const std::string & handle, StringMetricState & outState) const;

private:
    std::shared_ptr<MdDescription> mddescription;
    std::shared_ptr<MdState> mdstate;
    unsigned long long int mdibVersion;
};

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */
#endif /* MDIBCONTAINER_H_ */