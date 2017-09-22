/*
 * ConvertToCDM.h
 *
 *  Created on: 22.06.2017
 *      Author: buerger
 *
 *  This file is autogenerated.
 *
 *  Do not edit this file. For customization please edit the ConvertToCDM_beginning.hxx or ConvertToCDM_ending.hxx
 */

#ifndef DATA_OSCP_MDIB_CONVERTTOCDM_H_
#define DATA_OSCP_MDIB_CONVERTTOCDM_H_

#include "OSCLib/Data/OSCP/MDIB/SimpleTypesMapping.h"
#include "OSCLib/Data/OSCP/MDIB/MDIB-fwd.h"
#include "osdm-fwd.hxx"

namespace OSCLib {
namespace Data {
namespace OSCP {

class ConvertToCDM {
public:
	ConvertToCDM();
	virtual ~ConvertToCDM();

	// build-in type conversions for the basetyes (see typedefs in SimpleTypesMapping.h)
	static bool convert(const bool & source);
	static double convert(const double & source);
	static unsigned int convert(const unsigned int & source);
	static int convert(const int & source);
	static long convert(const long & source);
	static long long convert(const long long & source);
	static std::string convert(const std::string & source);
	static unsigned short int convert(const unsigned short int & source);
	static unsigned long convert(const unsigned long & source);
	static unsigned long long convert(const unsigned long long & source);
	static xml_schema::Duration convert(const xml_schema::Duration & source);
	static xml_schema::Qname convert(const xml_schema::Qname & source);
	static xml_schema::Language convert(const xml_schema::Language & source);
	static xml_schema::Uri convert(const xml_schema::Uri & source);
	static xml_schema::DateTime convert(const xml_schema::DateTime & source);
	static xml_schema::Idrefs convert(const xml_schema::Idrefs & source);
	static xml_schema::Id convert(const xml_schema::Id & source);

	static MDM::InvocationState convert(const InvocationState & source);

	// autogenerated here
