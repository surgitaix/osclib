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
 *  DistributionSampleArrayMetricState.cpp
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

#include "OSCLib/Data/OSCP/MDIB/DistributionSampleArrayMetricState.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertToCDM.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertFromCDM.h"
#include "OSCLib/Data/OSCP/MDIB/custom/Defaults.h"

#include "osdm.hxx"

#include "OSCLib/Data/OSCP/MDIB/SampleArrayValue.h"
#include "OSCLib/Data/OSCP/MDIB/Range.h"
#include "OSCLib/Data/OSCP/MDIB/CodedValue.h"

namespace OSCLib {
namespace Data {
namespace OSCP {

DistributionSampleArrayMetricState::DistributionSampleArrayMetricState() : data(Defaults::DistributionSampleArrayMetricState()) {
}

DistributionSampleArrayMetricState::operator CDM::DistributionSampleArrayMetricState() const {
	return *data;
}

DistributionSampleArrayMetricState::DistributionSampleArrayMetricState(const CDM::DistributionSampleArrayMetricState & object) : data(new CDM::DistributionSampleArrayMetricState(object)) {

}

DistributionSampleArrayMetricState::DistributionSampleArrayMetricState(const DistributionSampleArrayMetricState & object) : data(new CDM::DistributionSampleArrayMetricState(*object.data)) {

}

DistributionSampleArrayMetricState::~DistributionSampleArrayMetricState() {

}

void DistributionSampleArrayMetricState::copyFrom(const DistributionSampleArrayMetricState & object) {
	*data = *object.data;
}

DistributionSampleArrayMetricState & DistributionSampleArrayMetricState:: operator=(const DistributionSampleArrayMetricState & object) {
	copyFrom(object);
	return *this;
}


DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::setStateVersion(const VersionCounter & value) {
	data->StateVersion(ConvertToCDM::convert(value));
	return *this;
}


VersionCounter DistributionSampleArrayMetricState::getStateVersion() const {
	return ConvertFromCDM::convert(data->StateVersion());
}
	
DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::setDescriptorHandle(const HandleRef & value) {
	data->DescriptorHandle(ConvertToCDM::convert(value));
	return *this;
}


HandleRef DistributionSampleArrayMetricState::getDescriptorHandle() const {
	return ConvertFromCDM::convert(data->DescriptorHandle());
}
	
DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::setDescriptorVersion(const ReferencedVersion & value) {
	data->DescriptorVersion(ConvertToCDM::convert(value));
	return *this;
}


ReferencedVersion DistributionSampleArrayMetricState::getDescriptorVersion() const {
	return ConvertFromCDM::convert(data->DescriptorVersion());
}
	
DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::setActivationState(const ComponentActivation & value) {
	data->ActivationState(ConvertToCDM::convert(value));
	return *this;
}


ComponentActivation DistributionSampleArrayMetricState::getActivationState() const {
	return ConvertFromCDM::convert(data->ActivationState());
}
	
DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::setActiveDeterminationPeriod(const xml_schema::Duration & value) {
	data->ActiveDeterminationPeriod(ConvertToCDM::convert(value));
	return *this;
}


xml_schema::Duration DistributionSampleArrayMetricState::getActiveDeterminationPeriod() const {
	return ConvertFromCDM::convert(data->ActiveDeterminationPeriod());
}
	
DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::setLifeTimePeriod(const xml_schema::Duration & value) {
	data->LifeTimePeriod(ConvertToCDM::convert(value));
	return *this;
}

bool DistributionSampleArrayMetricState::getLifeTimePeriod(xml_schema::Duration & out) const {
	if (data->LifeTimePeriod().present()) {
		out = ConvertFromCDM::convert(data->LifeTimePeriod().get());
		return true;
	}
	return false;
}

xml_schema::Duration DistributionSampleArrayMetricState::getLifeTimePeriod() const {
	return ConvertFromCDM::convert(data->LifeTimePeriod().get());
}
	
bool DistributionSampleArrayMetricState::hasLifeTimePeriod() const {
	return data->LifeTimePeriod().present();
}
	
DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::addBodySite(const CodedValue & value) {
	data->BodySite().push_back(ConvertToCDM::convert(value));
	return *this;
}

std::vector<CodedValue> DistributionSampleArrayMetricState::getBodySiteLists() const {
	std::vector<CodedValue> result;
	result.reserve(data->BodySite().size());
	for (const auto & value: data->BodySite()) {
		result.push_back(ConvertFromCDM::convert(value));
	}
	return result;
}

void DistributionSampleArrayMetricState::clearBodySiteLists() {
	data->BodySite().clear();
}

DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::setMetricValue(const SampleArrayValue & value) {
	data->MetricValue(ConvertToCDM::convert(value));
	return *this;
}

bool DistributionSampleArrayMetricState::getMetricValue(SampleArrayValue & out) const {
	if (data->MetricValue().present()) {
		out = ConvertFromCDM::convert(data->MetricValue().get());
		return true;
	}
	return false;
}

SampleArrayValue DistributionSampleArrayMetricState::getMetricValue() const {
	return ConvertFromCDM::convert(data->MetricValue().get());
}
	
bool DistributionSampleArrayMetricState::hasMetricValue() const {
	return data->MetricValue().present();
}
	
DistributionSampleArrayMetricState & DistributionSampleArrayMetricState::addPhysiologicalRange(const Range & value) {
	data->PhysiologicalRange().push_back(ConvertToCDM::convert(value));
	return *this;
}

std::vector<Range> DistributionSampleArrayMetricState::getPhysiologicalRangeLists() const {
	std::vector<Range> result;
	result.reserve(data->PhysiologicalRange().size());
	for (const auto & value: data->PhysiologicalRange()) {
		result.push_back(ConvertFromCDM::convert(value));
	}
	return result;
}

void DistributionSampleArrayMetricState::clearPhysiologicalRangeLists() {
	data->PhysiologicalRange().clear();
}


} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */

