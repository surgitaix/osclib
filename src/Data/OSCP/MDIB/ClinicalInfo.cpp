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
 *  ClinicalInfo.cpp
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

#include "OSCLib/Data/OSCP/MDIB/ClinicalInfo.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertToCDM.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertFromCDM.h"
#include "OSCLib/Data/OSCP/MDIB/custom/Defaults.h"

#include "osdm.hxx"

#include "OSCLib/Data/OSCP/MDIB/CodedValue.h"
#include "OSCLib/Data/OSCP/MDIB/LocalizedText.h"
#include "OSCLib/Data/OSCP/MDIB/Measurement.h"
#include "OSCLib/Data/OSCP/MDIB/Range.h"
#include "OSCLib/Data/OSCP/MDIB/CodedValue.h"

namespace OSCLib {
namespace Data {
namespace OSCP {

ClinicalInfo::ClinicalInfo() : data(Defaults::ClinicalInfo()) {
}

ClinicalInfo::operator CDM::ClinicalInfo() const {
	return *data;
}

ClinicalInfo::ClinicalInfo(const CDM::ClinicalInfo & object) : data(new CDM::ClinicalInfo(object)) {

}

ClinicalInfo::ClinicalInfo(const ClinicalInfo & object) : data(new CDM::ClinicalInfo(*object.data)) {

}

ClinicalInfo::~ClinicalInfo() {

}

void ClinicalInfo::copyFrom(const ClinicalInfo & object) {
	*data = *object.data;
}

ClinicalInfo & ClinicalInfo:: operator=(const ClinicalInfo & object) {
	copyFrom(object);
	return *this;
}


ClinicalInfo & ClinicalInfo::setType(const CodedValue & value) {
	data->Type(ConvertToCDM::convert(value));
	return *this;
}

bool ClinicalInfo::getType(CodedValue & out) const {
	if (data->Type().present()) {
		out = ConvertFromCDM::convert(data->Type().get());
		return true;
	}
	return false;
}

CodedValue ClinicalInfo::getType() const {
	return ConvertFromCDM::convert(data->Type().get());
}
	
bool ClinicalInfo::hasType() const {
	return data->Type().present();
}
	
ClinicalInfo & ClinicalInfo::setValue(const Measurement & value) {
	data->Value(ConvertToCDM::convert(value));
	return *this;
}


Measurement ClinicalInfo::getValue() const {
	return ConvertFromCDM::convert(data->Value());
}
	
ClinicalInfo & ClinicalInfo::setRange(const Range & value) {
	data->Range(ConvertToCDM::convert(value));
	return *this;
}


Range ClinicalInfo::getRange() const {
	return ConvertFromCDM::convert(data->Range());
}
	
ClinicalInfo & ClinicalInfo::setMeaning(const CodedValue & value) {
	data->Meaning(ConvertToCDM::convert(value));
	return *this;
}

bool ClinicalInfo::getMeaning(CodedValue & out) const {
	if (data->Meaning().present()) {
		out = ConvertFromCDM::convert(data->Meaning().get());
		return true;
	}
	return false;
}

CodedValue ClinicalInfo::getMeaning() const {
	return ConvertFromCDM::convert(data->Meaning().get());
}
	
bool ClinicalInfo::hasMeaning() const {
	return data->Meaning().present();
}
	
ClinicalInfo & ClinicalInfo::setValidity(const MeasurementValidity & value) {
	data->Validity(ConvertToCDM::convert(value));
	return *this;
}


MeasurementValidity ClinicalInfo::getValidity() const {
	return ConvertFromCDM::convert(data->Validity());
}
	
ClinicalInfo & ClinicalInfo::addDescription(const LocalizedText & value) {
	data->Description().push_back(ConvertToCDM::convert(value));
	return *this;
}

std::vector<LocalizedText> ClinicalInfo::getDescriptionLists() const {
	std::vector<LocalizedText> result;
	result.reserve(data->Description().size());
	for (const auto & value: data->Description()) {
		result.push_back(ConvertFromCDM::convert(value));
	}
	return result;
}

void ClinicalInfo::clearDescriptionLists() {
	data->Description().clear();
}


} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */

