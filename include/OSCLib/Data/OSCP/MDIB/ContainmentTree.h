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
 *  ContainmentTree.h
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

#ifndef CONTAINMENTTREE_H_
#define CONTAINMENTTREE_H_

#include "OSCLib/Data/OSCP/MDIB/SimpleTypesMapping.h"
#include "OSCLib/Data/OSCP/OSCP-fwd.h"
#include "osdm-fwd.hxx"

namespace OSCLib {
namespace Data {
namespace OSCP {

class ContainmentTree {
private:
	ContainmentTree(const CDM::ContainmentTree & object);
	operator CDM::ContainmentTree() const;
	friend class ConvertFromCDM;
	friend class ConvertToCDM;
public:
	ContainmentTree();
	ContainmentTree(const ContainmentTree & object);
	virtual ~ContainmentTree();
    
    void copyFrom(const ContainmentTree & object);
    ContainmentTree & operator=(const ContainmentTree & object);
    
    typedef CDM::ContainmentTree WrappedType;

	ContainmentTree & addEntry(const ContainmentTreeEntry & value);
	std::vector<ContainmentTreeEntry> getEntryLists() const;
	void clearEntryLists();
	
private:
	std::shared_ptr<CDM::ContainmentTree> data;
};

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */
#endif /* CONTAINMENTTREE_H_ */
