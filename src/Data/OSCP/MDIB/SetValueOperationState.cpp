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
 *  SetValueOperationState.cpp
 *
 *  @Copyright (C) 2015, SurgiTAIX AG
 *  Author: besting, roehser
 */
 
/**
 * THIS FILE IS GENERATED AUTOMATICALLY! DO NOT MODIFY!
 *
 * YOUR CHANGES WILL BE OVERWRITTEN!
 * 
 * USE THE DEFINITION FILES IN THE FOLDER "codegenerator" INSTEAD!
 */

#include "OSCLib/Data/OSCP/MDIB/SetValueOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertToCDM.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertFromCDM.h"
#include "OSCLib/Data/OSCP/MDIB/custom/Defaults.h"

#include "osdm.hxx"

#include "OSCLib/Data/OSCP/MDIB/Range.h"

namespace OSCLib {
namespace Data {
namespace OSCP {

SetValueOperationState::SetValueOperationState() : data(Defaults::SetValueOperationState()) {
}

SetValueOperationState::operator CDM::SetValueOperationState() const {
	return *data;
}

SetValueOperationState::SetValueOperationState(const CDM::SetValueOperationState & object) : data(new CDM::SetValueOperationState(object)) {

}

SetValueOperationState::SetValueOperationState(const SetValueOperationState & object) : data(new CDM::SetValueOperationState(*object.data)) {

}

SetValueOperationState::~SetValueOperationState() {

}

void SetValueOperationState::copyFrom(const SetValueOperationState & object) {
	*data = *object.data;
}

SetValueOperationState & SetValueOperationState:: operator=(const SetValueOperationState & object) {
	copyFrom(object);
	return *this;
}


SetValueOperationState & SetValueOperationState::setStateVersion(const VersionCounter & value) {
	data->StateVersion(ConvertToCDM::convert(value));
	return *this;
}


VersionCounter SetValueOperationState::getStateVersion() const {
	return ConvertFromCDM::convert(data->StateVersion());
}
	
SetValueOperationState & SetValueOperationState::setDescriptorHandle(const HandleRef & value) {
	data->DescriptorHandle(ConvertToCDM::convert(value));
	return *this;
}


HandleRef SetValueOperationState::getDescriptorHandle() const {
	return ConvertFromCDM::convert(data->DescriptorHandle());
}
	
SetValueOperationState & SetValueOperationState::setDescriptorVersion(const ReferencedVersion & value) {
	data->DescriptorVersion(ConvertToCDM::convert(value));
	return *this;
}


ReferencedVersion SetValueOperationState::getDescriptorVersion() const {
	return ConvertFromCDM::convert(data->DescriptorVersion());
}
	
SetValueOperationState & SetValueOperationState::setOperatingMode(const OperatingMode & value) {
	data->OperatingMode(ConvertToCDM::convert(value));
	return *this;
}


OperatingMode SetValueOperationState::getOperatingMode() const {
	return ConvertFromCDM::convert(data->OperatingMode());
}
	
SetValueOperationState & SetValueOperationState::addallowedRange(const Range & value) {
	data->allowedRange().push_back(ConvertToCDM::convert(value));
	return *this;
}

std::vector<Range> SetValueOperationState::getallowedRangeLists() const {
	std::vector<Range> result;
	result.reserve(data->allowedRange().size());
	for (const auto & value: data->allowedRange()) {
		result.push_back(ConvertFromCDM::convert(value));
	}
	return result;
}

void SetValueOperationState::clearallowedRangeLists() {
	data->allowedRange().clear();
}


} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */

