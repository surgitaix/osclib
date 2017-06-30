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
 *  MeansContextState.h
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

#ifndef MEANSCONTEXTSTATE_H_
#define MEANSCONTEXTSTATE_H_

#include "OSCLib/Data/OSCP/MDIB/SimpleTypesMapping.h"
#include "OSCLib/Data/OSCP/OSCP-fwd.h"
#include "osdm-fwd.hxx"

namespace OSCLib {
namespace Data {
namespace OSCP {

class MeansContextState {
private:
	MeansContextState(const CDM::MeansContextState & object);
	operator CDM::MeansContextState() const;
	friend class ConvertFromCDM;
	friend class ConvertToCDM;
public:
	MeansContextState();
	MeansContextState(const MeansContextState & object);
	virtual ~MeansContextState();
    
    void copyFrom(const MeansContextState & object);
    MeansContextState & operator=(const MeansContextState & object);
    
    typedef CDM::MeansContextState WrappedType;

	MeansContextState & setStateVersion(const VersionCounter & value);
	VersionCounter getStateVersion() const;

	MeansContextState & setDescriptorHandle(const HandleRef & value);
	HandleRef getDescriptorHandle() const;

	MeansContextState & setDescriptorVersion(const ReferencedVersion & value);
	ReferencedVersion getDescriptorVersion() const;

	MeansContextState & setCategory(const CodedValue & value);
	CodedValue getCategory() const;
	bool getCategory(CodedValue & out) const;
	bool hasCategory() const;

	MeansContextState & setHandle(const Handle & value);
	Handle getHandle() const;

	MeansContextState & setContextAssociation(const ContextAssociation & value);
	ContextAssociation getContextAssociation() const;

	MeansContextState & setBindingMdibVersion(const ReferencedVersion & value);
	ReferencedVersion getBindingMdibVersion() const;
	bool getBindingMdibVersion(ReferencedVersion & out) const;
	bool hasBindingMdibVersion() const;

	MeansContextState & setUnbindingMdibVersion(const ReferencedVersion & value);
	ReferencedVersion getUnbindingMdibVersion() const;

	MeansContextState & setBindingStartTime(const Timestamp & value);
	Timestamp getBindingStartTime() const;

	MeansContextState & setBindingEndTime(const Timestamp & value);
	Timestamp getBindingEndTime() const;

	MeansContextState & addValidator(const InstanceIdentifier & value);
	std::vector<InstanceIdentifier> getValidatorLists() const;
	void clearValidatorLists();
	
	MeansContextState & addIdentification(const InstanceIdentifier & value);
	std::vector<InstanceIdentifier> getIdentificationLists() const;
	void clearIdentificationLists();
	
private:
	std::shared_ptr<CDM::MeansContextState> data;
};

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */
#endif /* MEANSCONTEXTSTATE_H_ */
