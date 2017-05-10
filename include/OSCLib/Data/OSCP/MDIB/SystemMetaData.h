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
 *  SystemMetaData.h
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

#ifndef SYSTEMMETADATA_H_
#define SYSTEMMETADATA_H_

#include "OSCLib/Data/OSCP/MDIB/custom/EnumMappings.h"
#include "OSCLib/Data/OSCP/OSCP-fwd.h"
#include "osdm-fwd.hxx"

namespace OSCLib {
namespace Data {
namespace OSCP {

class SystemMetaData {
private:
	SystemMetaData(const CDM::SystemMetaData & object);
	operator CDM::SystemMetaData() const;
	friend class ConvertFromCDM;
	friend class ConvertToCDM;
public:
	SystemMetaData();
	SystemMetaData(const SystemMetaData & object);
	virtual ~SystemMetaData();
    
    void copyFrom(const SystemMetaData & object);
    SystemMetaData & operator=(const SystemMetaData & object);
    
    typedef CDM::SystemMetaData WrappedType;

	SystemMetaData & setUDI(const std::string & value);
	std::string getUDI() const;
	bool getUDI(std::string & out) const;
	bool hasUDI() const;

	SystemMetaData & addManufacturer(const LocalizedText & value);
	std::vector<LocalizedText> getManufacturer() const;
	void clearManufacturer();
	
	SystemMetaData & addModelName(const LocalizedText & value);
	std::vector<LocalizedText> getModelName() const;
	void clearModelName();
	
	SystemMetaData & addModelNumber(const std::string & value);
	std::vector<std::string> getModelNumber() const;
	void clearModelNumber();
	
	SystemMetaData & addSerialNumber(const std::string & value);
	std::vector<std::string> getSerialNumber() const;
	void clearSerialNumber();
	
private:
	std::shared_ptr<CDM::SystemMetaData> data;
};

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */
#endif /* SYSTEMMETADATA_H_ */
