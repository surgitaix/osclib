#include "OSCLib/Data/OSCP/MDIB/Mdib.h"
#include "OSCLib/Data/OSCP/MDIB/MdDescription.h"
#include "OSCLib/Data/OSCP/MDIB/MdState.h"
#include "OSCLib/Data/OSCP/MDIB/LocalizedText.h"
#include "OSCLib/Data/OSCP/MDIB/CodedValue.h"
#include "OSCLib/Data/OSCP/MDIB/InstanceIdentifier.h"
#include "OSCLib/Data/OSCP/MDIB/Range.h"
#include "OSCLib/Data/OSCP/MDIB/Measurement.h"
#include "OSCLib/Data/OSCP/MDIB/ApprovedJurisdictions.h"
#include "OSCLib/Data/OSCP/MDIB/OperatingJurisdiction.h"
#include "OSCLib/Data/OSCP/MDIB/ProductionSpecification.h"
#include "OSCLib/Data/OSCP/MDIB/CalibrationInfo.h"
#include "OSCLib/Data/OSCP/MDIB/MdsDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/MetaData.h"
#include "OSCLib/Data/OSCP/MDIB/Udi.h"
#include "OSCLib/Data/OSCP/MDIB/MdsState.h"
#include "OSCLib/Data/OSCP/MDIB/VmdDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/VmdState.h"
#include "OSCLib/Data/OSCP/MDIB/ChannelDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/ChannelState.h"
#include "OSCLib/Data/OSCP/MDIB/SystemSignalActivation.h"
#include "OSCLib/Data/OSCP/MDIB/AlertSystemDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/AlertSystemState.h"
#include "OSCLib/Data/OSCP/MDIB/CauseInfo.h"
#include "OSCLib/Data/OSCP/MDIB/RemedyInfo.h"
#include "OSCLib/Data/OSCP/MDIB/AlertConditionDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/AlertConditionState.h"
#include "OSCLib/Data/OSCP/MDIB/LimitAlertConditionDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/LimitAlertConditionState.h"
#include "OSCLib/Data/OSCP/MDIB/AlertSignalDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/AlertSignalState.h"
#include "OSCLib/Data/OSCP/MDIB/MetricQuality.h"
#include "OSCLib/Data/OSCP/MDIB/Annotation.h"
#include "OSCLib/Data/OSCP/MDIB/NumericMetricValue.h"
#include "OSCLib/Data/OSCP/MDIB/StringMetricValue.h"
#include "OSCLib/Data/OSCP/MDIB/SampleArrayValue.h"
#include "OSCLib/Data/OSCP/MDIB/ApplyAnnotation.h"
#include "OSCLib/Data/OSCP/MDIB/Relation.h"
#include "OSCLib/Data/OSCP/MDIB/NumericMetricDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/NumericMetricState.h"
#include "OSCLib/Data/OSCP/MDIB/StringMetricDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/StringMetricState.h"
#include "OSCLib/Data/OSCP/MDIB/EnumStringMetricDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/AllowedValue.h"
#include "OSCLib/Data/OSCP/MDIB/EnumStringMetricState.h"
#include "OSCLib/Data/OSCP/MDIB/RealTimeSampleArrayMetricDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/RealTimeSampleArrayMetricState.h"
#include "OSCLib/Data/OSCP/MDIB/DistributionSampleArrayMetricDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/DistributionSampleArrayMetricState.h"
#include "OSCLib/Data/OSCP/MDIB/ScoDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/ScoState.h"
#include "OSCLib/Data/OSCP/MDIB/SetValueOperationDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/SetValueOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/SetStringOperationDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/SetStringOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/AllowedValues.h"
#include "OSCLib/Data/OSCP/MDIB/ActivateOperationDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/Argument.h"
#include "OSCLib/Data/OSCP/MDIB/ActivateOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/SetContextStateOperationDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/SetContextStateOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/SetMetricStateOperationDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/SetMetricStateOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/SetComponentStateOperationDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/SetComponentStateOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/SetAlertStateOperationDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/SetAlertStateOperationState.h"
#include "OSCLib/Data/OSCP/MDIB/ClockDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/ClockState.h"
#include "OSCLib/Data/OSCP/MDIB/BatteryDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/BatteryState.h"
#include "OSCLib/Data/OSCP/MDIB/SystemContextDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/SystemContextState.h"
#include "OSCLib/Data/OSCP/MDIB/BaseDemographics.h"
#include "OSCLib/Data/OSCP/MDIB/PersonReference.h"
#include "OSCLib/Data/OSCP/MDIB/LocationDetail.h"
#include "OSCLib/Data/OSCP/MDIB/PatientContextDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/PatientDemographicsCoreData.h"
#include "OSCLib/Data/OSCP/MDIB/NeonatalPatientDemographicsCoreData.h"
#include "OSCLib/Data/OSCP/MDIB/PatientContextState.h"
#include "OSCLib/Data/OSCP/MDIB/LocationContextDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/LocationContextState.h"
#include "OSCLib/Data/OSCP/MDIB/WorkflowContextDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/ClinicalInfo.h"
#include "OSCLib/Data/OSCP/MDIB/RelatedMeasurement.h"
#include "OSCLib/Data/OSCP/MDIB/ReferenceRange.h"
#include "OSCLib/Data/OSCP/MDIB/ImagingProcedure.h"
#include "OSCLib/Data/OSCP/MDIB/LocationReference.h"
#include "OSCLib/Data/OSCP/MDIB/OrderDetail.h"
#include "OSCLib/Data/OSCP/MDIB/PersonParticipation.h"
#include "OSCLib/Data/OSCP/MDIB/WorkflowContextState.h"
#include "OSCLib/Data/OSCP/MDIB/WorkflowDetail.h"
#include "OSCLib/Data/OSCP/MDIB/RequestedOrderDetail.h"
#include "OSCLib/Data/OSCP/MDIB/PerformedOrderDetail.h"
#include "OSCLib/Data/OSCP/MDIB/OperatorContextDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/OperatorContextState.h"
#include "OSCLib/Data/OSCP/MDIB/MeansContextDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/MeansContextState.h"
#include "OSCLib/Data/OSCP/MDIB/EnsembleContextDescriptor.h"
#include "OSCLib/Data/OSCP/MDIB/EnsembleContextState.h"
#include "OSCLib/Data/OSCP/MDIB/ContainmentTree.h"
#include "OSCLib/Data/OSCP/MDIB/ContainmentTreeEntry.h"
#include "OSCLib/Data/OSCP/MDIB/DicomTransferCapability.h"
#include "OSCLib/Data/OSCP/MDIB/DicomNetworkAe.h"
#include "OSCLib/Data/OSCP/MDIB/DicomNetworkConnection.h"
#include "OSCLib/Data/OSCP/MDIB/DicomDeviceDescriptor.h"


// needed SimpleTypes?
#include "OSCLib/Data/OSCP/MDIB/SimpleTypesMapping.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertFromCDM.h"
#include "osdm.hxx"

#include <stdexcept>



/*
 * ConvertFromCDM.cpp
 *
 *  Created on: 22.06.2017
 *      Author: buerger
 *
 *  This file is autogenerated.
 *
 *  Do not edit this file. For customization please edit the ConvertFromCDM_beginning.cxx or ConvertFromCDM_ending.cxx
 */

namespace OSCLib {
namespace Data {
namespace OSCP {

ConvertFromCDM::ConvertFromCDM() {

}

ConvertFromCDM::~ConvertFromCDM() {

}

bool ConvertFromCDM::convert(const bool & source) {
	return source;
}

double ConvertFromCDM::convert(const double & source) {
	return source;
}

unsigned int ConvertFromCDM::convert(const unsigned int & source) {
	return source;
}

int ConvertFromCDM::convert(const int & source) {
	return source;
}

long ConvertFromCDM::convert(const long & source) {
	return source;
}

long long ConvertFromCDM::convert(const long long & source) {
	return source;
}

std::string ConvertFromCDM::convert(const std::string & source) {
	return source;
}

unsigned short int ConvertFromCDM::convert(const unsigned short int & source) {
	return source;
}

unsigned long ConvertFromCDM::convert(const unsigned long & source) {
	return source;
}

unsigned long long ConvertFromCDM::convert(const unsigned long long & source) {
	return source;
}

xml_schema::Duration ConvertFromCDM::convert(const xml_schema::Duration & source) {
	return source;
}


xml_schema::Qname ConvertFromCDM::convert(const xml_schema::Qname & source) {
	return source;
}

xml_schema::Language ConvertFromCDM::convert(const xml_schema::Language & source) {
	return source;
}

xml_schema::Uri ConvertFromCDM::convert(const xml_schema::Uri & source) {
	return source;
}

xml_schema::DateTime ConvertFromCDM::convert(const xml_schema::DateTime & source) {
	return source;
}


xml_schema::Idrefs ConvertFromCDM::convert(const xml_schema::Idrefs & source) {
	return source;
}


xml_schema::Id ConvertFromCDM::convert(const xml_schema::Id & source) {
	return source;
}


// autogenerated code


MeasurementValidity ConvertFromCDM::convert(const CDM::MeasurementValidity & source) {
	switch (source) {
		case CDM::MeasurementValidity::Vld: return MeasurementValidity::Vld;
		case CDM::MeasurementValidity::Vldated: return MeasurementValidity::Vldated;
		case CDM::MeasurementValidity::Ong: return MeasurementValidity::Ong;
		case CDM::MeasurementValidity::Qst: return MeasurementValidity::Qst;
		case CDM::MeasurementValidity::Calib: return MeasurementValidity::Calib;
		case CDM::MeasurementValidity::Inv: return MeasurementValidity::Inv;
		case CDM::MeasurementValidity::Oflw: return MeasurementValidity::Oflw;
		case CDM::MeasurementValidity::Uflw: return MeasurementValidity::Uflw;
		case CDM::MeasurementValidity::NA: return MeasurementValidity::NA;
	}
	throw std::runtime_error("Illegal value for MeasurementValidity");
}

SafetyClassification ConvertFromCDM::convert(const CDM::SafetyClassification & source) {
	switch (source) {
		case CDM::SafetyClassification::Inf: return SafetyClassification::Inf;
		case CDM::SafetyClassification::MedA: return SafetyClassification::MedA;
		case CDM::SafetyClassification::MedB: return SafetyClassification::MedB;
		case CDM::SafetyClassification::MedC: return SafetyClassification::MedC;
	}
	throw std::runtime_error("Illegal value for SafetyClassification");
}

ComponentActivation ConvertFromCDM::convert(const CDM::ComponentActivation & source) {
	switch (source) {
		case CDM::ComponentActivation::On: return ComponentActivation::On;
		case CDM::ComponentActivation::NotRdy: return ComponentActivation::NotRdy;
		case CDM::ComponentActivation::StndBy: return ComponentActivation::StndBy;
		case CDM::ComponentActivation::Off: return ComponentActivation::Off;
		case CDM::ComponentActivation::Shtdn: return ComponentActivation::Shtdn;
		case CDM::ComponentActivation::Fail: return ComponentActivation::Fail;
	}
	throw std::runtime_error("Illegal value for ComponentActivation");
}

CalibrationState ConvertFromCDM::convert(const CDM::CalibrationState & source) {
	switch (source) {
		case CDM::CalibrationState::No: return CalibrationState::No;
		case CDM::CalibrationState::Req: return CalibrationState::Req;
		case CDM::CalibrationState::Cal: return CalibrationState::Cal;
	}
	throw std::runtime_error("Illegal value for CalibrationState");
}

CalibrationType ConvertFromCDM::convert(const CDM::CalibrationType & source) {
	switch (source) {
		case CDM::CalibrationType::Offset: return CalibrationType::Offset;
		case CDM::CalibrationType::Gain: return CalibrationType::Gain;
		case CDM::CalibrationType::TP: return CalibrationType::TP;
		case CDM::CalibrationType::Unspec: return CalibrationType::Unspec;
	}
	throw std::runtime_error("Illegal value for CalibrationType");
}

MdsOperatingMode ConvertFromCDM::convert(const CDM::MdsOperatingMode & source) {
	switch (source) {
		case CDM::MdsOperatingMode::Nml: return MdsOperatingMode::Nml;
		case CDM::MdsOperatingMode::Dmo: return MdsOperatingMode::Dmo;
		case CDM::MdsOperatingMode::Srv: return MdsOperatingMode::Srv;
		case CDM::MdsOperatingMode::Mtn: return MdsOperatingMode::Mtn;
	}
	throw std::runtime_error("Illegal value for MdsOperatingMode");
}

AlertActivation ConvertFromCDM::convert(const CDM::AlertActivation & source) {
	switch (source) {
		case CDM::AlertActivation::On: return AlertActivation::On;
		case CDM::AlertActivation::Off: return AlertActivation::Off;
		case CDM::AlertActivation::Psd: return AlertActivation::Psd;
	}
	throw std::runtime_error("Illegal value for AlertActivation");
}

AlertConditionKind ConvertFromCDM::convert(const CDM::AlertConditionKind & source) {
	switch (source) {
		case CDM::AlertConditionKind::Phy: return AlertConditionKind::Phy;
		case CDM::AlertConditionKind::Tec: return AlertConditionKind::Tec;
		case CDM::AlertConditionKind::Oth: return AlertConditionKind::Oth;
	}
	throw std::runtime_error("Illegal value for AlertConditionKind");
}

AlertConditionPriority ConvertFromCDM::convert(const CDM::AlertConditionPriority & source) {
	switch (source) {
		case CDM::AlertConditionPriority::Lo: return AlertConditionPriority::Lo;
		case CDM::AlertConditionPriority::Me: return AlertConditionPriority::Me;
		case CDM::AlertConditionPriority::Hi: return AlertConditionPriority::Hi;
		case CDM::AlertConditionPriority::None: return AlertConditionPriority::None;
	}
	throw std::runtime_error("Illegal value for AlertConditionPriority");
}

AlertConditionMonitoredLimits ConvertFromCDM::convert(const CDM::AlertConditionMonitoredLimits & source) {
	switch (source) {
		case CDM::AlertConditionMonitoredLimits::All: return AlertConditionMonitoredLimits::All;
		case CDM::AlertConditionMonitoredLimits::LoOff: return AlertConditionMonitoredLimits::LoOff;
		case CDM::AlertConditionMonitoredLimits::HiOff: return AlertConditionMonitoredLimits::HiOff;
		case CDM::AlertConditionMonitoredLimits::None: return AlertConditionMonitoredLimits::None;
	}
	throw std::runtime_error("Illegal value for AlertConditionMonitoredLimits");
}

AlertSignalManifestation ConvertFromCDM::convert(const CDM::AlertSignalManifestation & source) {
	switch (source) {
		case CDM::AlertSignalManifestation::Aud: return AlertSignalManifestation::Aud;
		case CDM::AlertSignalManifestation::Vis: return AlertSignalManifestation::Vis;
		case CDM::AlertSignalManifestation::Tan: return AlertSignalManifestation::Tan;
		case CDM::AlertSignalManifestation::Oth: return AlertSignalManifestation::Oth;
	}
	throw std::runtime_error("Illegal value for AlertSignalManifestation");
}

AlertSignalPresence ConvertFromCDM::convert(const CDM::AlertSignalPresence & source) {
	switch (source) {
		case CDM::AlertSignalPresence::On: return AlertSignalPresence::On;
		case CDM::AlertSignalPresence::Off: return AlertSignalPresence::Off;
		case CDM::AlertSignalPresence::Latch: return AlertSignalPresence::Latch;
		case CDM::AlertSignalPresence::Ack: return AlertSignalPresence::Ack;
	}
	throw std::runtime_error("Illegal value for AlertSignalPresence");
}

AlertSignalPrimaryLocation ConvertFromCDM::convert(const CDM::AlertSignalPrimaryLocation & source) {
	switch (source) {
		case CDM::AlertSignalPrimaryLocation::Loc: return AlertSignalPrimaryLocation::Loc;
		case CDM::AlertSignalPrimaryLocation::Rem: return AlertSignalPrimaryLocation::Rem;
	}
	throw std::runtime_error("Illegal value for AlertSignalPrimaryLocation");
}

GenerationMode ConvertFromCDM::convert(const CDM::GenerationMode & source) {
	switch (source) {
		case CDM::GenerationMode::Real: return GenerationMode::Real;
		case CDM::GenerationMode::Test: return GenerationMode::Test;
		case CDM::GenerationMode::Demo: return GenerationMode::Demo;
	}
	throw std::runtime_error("Illegal value for GenerationMode");
}

MetricCategory ConvertFromCDM::convert(const CDM::MetricCategory & source) {
	switch (source) {
		case CDM::MetricCategory::Unspec: return MetricCategory::Unspec;
		case CDM::MetricCategory::Msrmt: return MetricCategory::Msrmt;
		case CDM::MetricCategory::Clc: return MetricCategory::Clc;
		case CDM::MetricCategory::Set: return MetricCategory::Set;
		case CDM::MetricCategory::Preset: return MetricCategory::Preset;
		case CDM::MetricCategory::Rcmm: return MetricCategory::Rcmm;
	}
	throw std::runtime_error("Illegal value for MetricCategory");
}

DerivationMethod ConvertFromCDM::convert(const CDM::DerivationMethod & source) {
	switch (source) {
		case CDM::DerivationMethod::Auto: return DerivationMethod::Auto;
		case CDM::DerivationMethod::Man: return DerivationMethod::Man;
	}
	throw std::runtime_error("Illegal value for DerivationMethod");
}

MetricAvailability ConvertFromCDM::convert(const CDM::MetricAvailability & source) {
	switch (source) {
		case CDM::MetricAvailability::Intr: return MetricAvailability::Intr;
		case CDM::MetricAvailability::Cont: return MetricAvailability::Cont;
	}
	throw std::runtime_error("Illegal value for MetricAvailability");
}

OperatingMode ConvertFromCDM::convert(const CDM::OperatingMode & source) {
	switch (source) {
		case CDM::OperatingMode::Dis: return OperatingMode::Dis;
		case CDM::OperatingMode::En: return OperatingMode::En;
		case CDM::OperatingMode::NA: return OperatingMode::NA;
	}
	throw std::runtime_error("Illegal value for OperatingMode");
}

ContextAssociation ConvertFromCDM::convert(const CDM::ContextAssociation & source) {
	switch (source) {
		case CDM::ContextAssociation::No: return ContextAssociation::No;
		case CDM::ContextAssociation::Pre: return ContextAssociation::Pre;
		case CDM::ContextAssociation::Assoc: return ContextAssociation::Assoc;
		case CDM::ContextAssociation::Dis: return ContextAssociation::Dis;
	}
	throw std::runtime_error("Illegal value for ContextAssociation");
}

Sex ConvertFromCDM::convert(const CDM::Sex & source) {
	switch (source) {
		case CDM::Sex::Unspec: return Sex::Unspec;
		case CDM::Sex::M: return Sex::M;
		case CDM::Sex::F: return Sex::F;
		case CDM::Sex::Unkn: return Sex::Unkn;
	}
	throw std::runtime_error("Illegal value for Sex");
}

PatientType ConvertFromCDM::convert(const CDM::PatientType & source) {
	switch (source) {
		case CDM::PatientType::Unspec: return PatientType::Unspec;
		case CDM::PatientType::Ad: return PatientType::Ad;
		case CDM::PatientType::Ado: return PatientType::Ado;
		case CDM::PatientType::Ped: return PatientType::Ped;
		case CDM::PatientType::Inf: return PatientType::Inf;
		case CDM::PatientType::Neo: return PatientType::Neo;
		case CDM::PatientType::Oth: return PatientType::Oth;
	}
	throw std::runtime_error("Illegal value for PatientType");
}

DicomTransferRole ConvertFromCDM::convert(const CDM::DicomTransferRole & source) {
	switch (source) {
		case CDM::DicomTransferRole::Scu: return DicomTransferRole::Scu;
		case CDM::DicomTransferRole::Scp: return DicomTransferRole::Scp;
	}
	throw std::runtime_error("Illegal value for DicomTransferRole");
}

TextWidth ConvertFromCDM::convert(const CDM::TextWidth & source) {
	switch (source) {
		case CDM::TextWidth::Shrt: return TextWidth::Shrt;
		case CDM::TextWidth::Nml: return TextWidth::Nml;
		case CDM::TextWidth::Lng: return TextWidth::Lng;
	}
	throw std::runtime_error("Illegal value for TextWidth");
}

CanEscalate ConvertFromCDM::convert(const CDM::CanEscalate & source) {
	switch (source) {
		case CDM::CanEscalate::Me: return CanEscalate::Me;
		case CDM::CanEscalate::Hi: return CanEscalate::Hi;
	}
	throw std::runtime_error("Illegal value for CanEscalate");
}

CanDeescalate ConvertFromCDM::convert(const CDM::CanDeescalate & source) {
	switch (source) {
		case CDM::CanDeescalate::Me: return CanDeescalate::Me;
		case CDM::CanDeescalate::Lo: return CanDeescalate::Lo;
	}
	throw std::runtime_error("Illegal value for CanDeescalate");
}

Kind ConvertFromCDM::convert(const CDM::Kind & source) {
	switch (source) {
		case CDM::Kind::Rcm: return Kind::Rcm;
		case CDM::Kind::PS: return Kind::PS;
		case CDM::Kind::SST: return Kind::SST;
		case CDM::Kind::ECE: return Kind::ECE;
		case CDM::Kind::Oth: return Kind::Oth;
	}
	throw std::runtime_error("Illegal value for Kind");
}

ChargeStatus ConvertFromCDM::convert(const CDM::ChargeStatus & source) {
	switch (source) {
		case CDM::ChargeStatus::Ful: return ChargeStatus::Ful;
		case CDM::ChargeStatus::ChB: return ChargeStatus::ChB;
		case CDM::ChargeStatus::DisChB: return ChargeStatus::DisChB;
		case CDM::ChargeStatus::DEB: return ChargeStatus::DEB;
	}
	throw std::runtime_error("Illegal value for ChargeStatus");
}

Criticality ConvertFromCDM::convert(const CDM::Criticality & source) {
	switch (source) {
		case CDM::Criticality::Lo: return Criticality::Lo;
		case CDM::Criticality::Hi: return Criticality::Hi;
	}
	throw std::runtime_error("Illegal value for Criticality");
}

Mdib ConvertFromCDM::convert(const CDM::Mdib & source) {
	return Mdib(source);
}

MdDescription ConvertFromCDM::convert(const CDM::MdDescription & source) {
	return MdDescription(source);
}

MdState ConvertFromCDM::convert(const CDM::MdState & source) {
	return MdState(source);
}

LocalizedText ConvertFromCDM::convert(const CDM::LocalizedText & source) {
	return LocalizedText(source);
}

CodedValue ConvertFromCDM::convert(const CDM::CodedValue & source) {
	return CodedValue(source);
}

InstanceIdentifier ConvertFromCDM::convert(const CDM::InstanceIdentifier & source) {
	return InstanceIdentifier(source);
}

Range ConvertFromCDM::convert(const CDM::Range & source) {
	return Range(source);
}

Measurement ConvertFromCDM::convert(const CDM::Measurement & source) {
	return Measurement(source);
}

ApprovedJurisdictions ConvertFromCDM::convert(const CDM::ApprovedJurisdictions & source) {
	return ApprovedJurisdictions(source);
}

OperatingJurisdiction ConvertFromCDM::convert(const CDM::OperatingJurisdiction & source) {
	return OperatingJurisdiction(source);
}

ProductionSpecification ConvertFromCDM::convert(const CDM::ProductionSpecification & source) {
	return ProductionSpecification(source);
}

CalibrationInfo ConvertFromCDM::convert(const CDM::CalibrationInfo & source) {
	return CalibrationInfo(source);
}

MdsDescriptor ConvertFromCDM::convert(const CDM::MdsDescriptor & source) {
	return MdsDescriptor(source);
}

MetaData ConvertFromCDM::convert(const CDM::MetaData & source) {
	return MetaData(source);
}

Udi ConvertFromCDM::convert(const CDM::Udi & source) {
	return Udi(source);
}

MdsState ConvertFromCDM::convert(const CDM::MdsState & source) {
	return MdsState(source);
}

VmdDescriptor ConvertFromCDM::convert(const CDM::VmdDescriptor & source) {
	return VmdDescriptor(source);
}

VmdState ConvertFromCDM::convert(const CDM::VmdState & source) {
	return VmdState(source);
}

ChannelDescriptor ConvertFromCDM::convert(const CDM::ChannelDescriptor & source) {
	return ChannelDescriptor(source);
}

ChannelState ConvertFromCDM::convert(const CDM::ChannelState & source) {
	return ChannelState(source);
}

SystemSignalActivation ConvertFromCDM::convert(const CDM::SystemSignalActivation & source) {
	return SystemSignalActivation(source);
}

AlertSystemDescriptor ConvertFromCDM::convert(const CDM::AlertSystemDescriptor & source) {
	return AlertSystemDescriptor(source);
}

AlertSystemState ConvertFromCDM::convert(const CDM::AlertSystemState & source) {
	return AlertSystemState(source);
}

CauseInfo ConvertFromCDM::convert(const CDM::CauseInfo & source) {
	return CauseInfo(source);
}

RemedyInfo ConvertFromCDM::convert(const CDM::RemedyInfo & source) {
	return RemedyInfo(source);
}

AlertConditionDescriptor ConvertFromCDM::convert(const CDM::AlertConditionDescriptor & source) {
	return AlertConditionDescriptor(source);
}

AlertConditionState ConvertFromCDM::convert(const CDM::AlertConditionState & source) {
	return AlertConditionState(source);
}

LimitAlertConditionDescriptor ConvertFromCDM::convert(const CDM::LimitAlertConditionDescriptor & source) {
	return LimitAlertConditionDescriptor(source);
}

LimitAlertConditionState ConvertFromCDM::convert(const CDM::LimitAlertConditionState & source) {
	return LimitAlertConditionState(source);
}

AlertSignalDescriptor ConvertFromCDM::convert(const CDM::AlertSignalDescriptor & source) {
	return AlertSignalDescriptor(source);
}

AlertSignalState ConvertFromCDM::convert(const CDM::AlertSignalState & source) {
	return AlertSignalState(source);
}

MetricQuality ConvertFromCDM::convert(const CDM::MetricQuality & source) {
	return MetricQuality(source);
}

Annotation ConvertFromCDM::convert(const CDM::Annotation & source) {
	return Annotation(source);
}

NumericMetricValue ConvertFromCDM::convert(const CDM::NumericMetricValue & source) {
	return NumericMetricValue(source);
}

StringMetricValue ConvertFromCDM::convert(const CDM::StringMetricValue & source) {
	return StringMetricValue(source);
}

SampleArrayValue ConvertFromCDM::convert(const CDM::SampleArrayValue & source) {
	return SampleArrayValue(source);
}

ApplyAnnotation ConvertFromCDM::convert(const CDM::ApplyAnnotation & source) {
	return ApplyAnnotation(source);
}

Relation ConvertFromCDM::convert(const CDM::Relation & source) {
	return Relation(source);
}

NumericMetricDescriptor ConvertFromCDM::convert(const CDM::NumericMetricDescriptor & source) {
	return NumericMetricDescriptor(source);
}

NumericMetricState ConvertFromCDM::convert(const CDM::NumericMetricState & source) {
	return NumericMetricState(source);
}

StringMetricDescriptor ConvertFromCDM::convert(const CDM::StringMetricDescriptor & source) {
	return StringMetricDescriptor(source);
}

StringMetricState ConvertFromCDM::convert(const CDM::StringMetricState & source) {
	return StringMetricState(source);
}

EnumStringMetricDescriptor ConvertFromCDM::convert(const CDM::EnumStringMetricDescriptor & source) {
	return EnumStringMetricDescriptor(source);
}

AllowedValue ConvertFromCDM::convert(const CDM::AllowedValue & source) {
	return AllowedValue(source);
}

EnumStringMetricState ConvertFromCDM::convert(const CDM::EnumStringMetricState & source) {
	return EnumStringMetricState(source);
}

RealTimeSampleArrayMetricDescriptor ConvertFromCDM::convert(const CDM::RealTimeSampleArrayMetricDescriptor & source) {
	return RealTimeSampleArrayMetricDescriptor(source);
}

RealTimeSampleArrayMetricState ConvertFromCDM::convert(const CDM::RealTimeSampleArrayMetricState & source) {
	return RealTimeSampleArrayMetricState(source);
}

DistributionSampleArrayMetricDescriptor ConvertFromCDM::convert(const CDM::DistributionSampleArrayMetricDescriptor & source) {
	return DistributionSampleArrayMetricDescriptor(source);
}

DistributionSampleArrayMetricState ConvertFromCDM::convert(const CDM::DistributionSampleArrayMetricState & source) {
	return DistributionSampleArrayMetricState(source);
}

ScoDescriptor ConvertFromCDM::convert(const CDM::ScoDescriptor & source) {
	return ScoDescriptor(source);
}

ScoState ConvertFromCDM::convert(const CDM::ScoState & source) {
	return ScoState(source);
}

SetValueOperationDescriptor ConvertFromCDM::convert(const CDM::SetValueOperationDescriptor & source) {
	return SetValueOperationDescriptor(source);
}

SetValueOperationState ConvertFromCDM::convert(const CDM::SetValueOperationState & source) {
	return SetValueOperationState(source);
}

SetStringOperationDescriptor ConvertFromCDM::convert(const CDM::SetStringOperationDescriptor & source) {
	return SetStringOperationDescriptor(source);
}

SetStringOperationState ConvertFromCDM::convert(const CDM::SetStringOperationState & source) {
	return SetStringOperationState(source);
}

AllowedValues ConvertFromCDM::convert(const CDM::AllowedValues & source) {
	return AllowedValues(source);
}

ActivateOperationDescriptor ConvertFromCDM::convert(const CDM::ActivateOperationDescriptor & source) {
	return ActivateOperationDescriptor(source);
}

Argument ConvertFromCDM::convert(const CDM::Argument & source) {
	return Argument(source);
}

ActivateOperationState ConvertFromCDM::convert(const CDM::ActivateOperationState & source) {
	return ActivateOperationState(source);
}

SetContextStateOperationDescriptor ConvertFromCDM::convert(const CDM::SetContextStateOperationDescriptor & source) {
	return SetContextStateOperationDescriptor(source);
}

SetContextStateOperationState ConvertFromCDM::convert(const CDM::SetContextStateOperationState & source) {
	return SetContextStateOperationState(source);
}

SetMetricStateOperationDescriptor ConvertFromCDM::convert(const CDM::SetMetricStateOperationDescriptor & source) {
	return SetMetricStateOperationDescriptor(source);
}

SetMetricStateOperationState ConvertFromCDM::convert(const CDM::SetMetricStateOperationState & source) {
	return SetMetricStateOperationState(source);
}

SetComponentStateOperationDescriptor ConvertFromCDM::convert(const CDM::SetComponentStateOperationDescriptor & source) {
	return SetComponentStateOperationDescriptor(source);
}

SetComponentStateOperationState ConvertFromCDM::convert(const CDM::SetComponentStateOperationState & source) {
	return SetComponentStateOperationState(source);
}

SetAlertStateOperationDescriptor ConvertFromCDM::convert(const CDM::SetAlertStateOperationDescriptor & source) {
	return SetAlertStateOperationDescriptor(source);
}

SetAlertStateOperationState ConvertFromCDM::convert(const CDM::SetAlertStateOperationState & source) {
	return SetAlertStateOperationState(source);
}

ClockDescriptor ConvertFromCDM::convert(const CDM::ClockDescriptor & source) {
	return ClockDescriptor(source);
}

ClockState ConvertFromCDM::convert(const CDM::ClockState & source) {
	return ClockState(source);
}

BatteryDescriptor ConvertFromCDM::convert(const CDM::BatteryDescriptor & source) {
	return BatteryDescriptor(source);
}

BatteryState ConvertFromCDM::convert(const CDM::BatteryState & source) {
	return BatteryState(source);
}

SystemContextDescriptor ConvertFromCDM::convert(const CDM::SystemContextDescriptor & source) {
	return SystemContextDescriptor(source);
}

SystemContextState ConvertFromCDM::convert(const CDM::SystemContextState & source) {
	return SystemContextState(source);
}

BaseDemographics ConvertFromCDM::convert(const CDM::BaseDemographics & source) {
	return BaseDemographics(source);
}

PersonReference ConvertFromCDM::convert(const CDM::PersonReference & source) {
	return PersonReference(source);
}

LocationDetail ConvertFromCDM::convert(const CDM::LocationDetail & source) {
	return LocationDetail(source);
}

PatientContextDescriptor ConvertFromCDM::convert(const CDM::PatientContextDescriptor & source) {
	return PatientContextDescriptor(source);
}

PatientDemographicsCoreData ConvertFromCDM::convert(const CDM::PatientDemographicsCoreData & source) {
	return PatientDemographicsCoreData(source);
}

NeonatalPatientDemographicsCoreData ConvertFromCDM::convert(const CDM::NeonatalPatientDemographicsCoreData & source) {
	return NeonatalPatientDemographicsCoreData(source);
}

PatientContextState ConvertFromCDM::convert(const CDM::PatientContextState & source) {
	return PatientContextState(source);
}

LocationContextDescriptor ConvertFromCDM::convert(const CDM::LocationContextDescriptor & source) {
	return LocationContextDescriptor(source);
}

LocationContextState ConvertFromCDM::convert(const CDM::LocationContextState & source) {
	return LocationContextState(source);
}

WorkflowContextDescriptor ConvertFromCDM::convert(const CDM::WorkflowContextDescriptor & source) {
	return WorkflowContextDescriptor(source);
}

ClinicalInfo ConvertFromCDM::convert(const CDM::ClinicalInfo & source) {
	return ClinicalInfo(source);
}

RelatedMeasurement ConvertFromCDM::convert(const CDM::RelatedMeasurement & source) {
	return RelatedMeasurement(source);
}

ReferenceRange ConvertFromCDM::convert(const CDM::ReferenceRange & source) {
	return ReferenceRange(source);
}

ImagingProcedure ConvertFromCDM::convert(const CDM::ImagingProcedure & source) {
	return ImagingProcedure(source);
}

LocationReference ConvertFromCDM::convert(const CDM::LocationReference & source) {
	return LocationReference(source);
}

OrderDetail ConvertFromCDM::convert(const CDM::OrderDetail & source) {
	return OrderDetail(source);
}

PersonParticipation ConvertFromCDM::convert(const CDM::PersonParticipation & source) {
	return PersonParticipation(source);
}

WorkflowContextState ConvertFromCDM::convert(const CDM::WorkflowContextState & source) {
	return WorkflowContextState(source);
}

WorkflowDetail ConvertFromCDM::convert(const CDM::WorkflowDetail & source) {
	return WorkflowDetail(source);
}

RequestedOrderDetail ConvertFromCDM::convert(const CDM::RequestedOrderDetail & source) {
	return RequestedOrderDetail(source);
}

PerformedOrderDetail ConvertFromCDM::convert(const CDM::PerformedOrderDetail & source) {
	return PerformedOrderDetail(source);
}

OperatorContextDescriptor ConvertFromCDM::convert(const CDM::OperatorContextDescriptor & source) {
	return OperatorContextDescriptor(source);
}

OperatorContextState ConvertFromCDM::convert(const CDM::OperatorContextState & source) {
	return OperatorContextState(source);
}

MeansContextDescriptor ConvertFromCDM::convert(const CDM::MeansContextDescriptor & source) {
	return MeansContextDescriptor(source);
}

MeansContextState ConvertFromCDM::convert(const CDM::MeansContextState & source) {
	return MeansContextState(source);
}

EnsembleContextDescriptor ConvertFromCDM::convert(const CDM::EnsembleContextDescriptor & source) {
	return EnsembleContextDescriptor(source);
}

EnsembleContextState ConvertFromCDM::convert(const CDM::EnsembleContextState & source) {
	return EnsembleContextState(source);
}

ContainmentTree ConvertFromCDM::convert(const CDM::ContainmentTree & source) {
	return ContainmentTree(source);
}

ContainmentTreeEntry ConvertFromCDM::convert(const CDM::ContainmentTreeEntry & source) {
	return ContainmentTreeEntry(source);
}

DicomTransferCapability ConvertFromCDM::convert(const CDM::DicomTransferCapability & source) {
	return DicomTransferCapability(source);
}

DicomNetworkAe ConvertFromCDM::convert(const CDM::DicomNetworkAe & source) {
	return DicomNetworkAe(source);
}

DicomNetworkConnection ConvertFromCDM::convert(const CDM::DicomNetworkConnection & source) {
	return DicomNetworkConnection(source);
}

DicomDeviceDescriptor ConvertFromCDM::convert(const CDM::DicomDeviceDescriptor & source) {
	return DicomDeviceDescriptor(source);
}

AlertConditionReference ConvertFromCDM::convert(const CDM::AlertConditionReference & source) {
	AlertConditionReference list;
	for (const auto & element : source) {
		list.push_back(element);
	}
	return list;
}

RealTimeValueType ConvertFromCDM::convert(const CDM::RealTimeValueType & source) {
	RealTimeValueType list;
	for (const auto & element : source) {
		list.push_back(element);
	}
	return list;
}



InvocationState ConvertFromCDM::convert(const MDM::InvocationState & source) {
	switch (source) {
		case MDM::InvocationState::Wait: return InvocationState::Wait;
		case MDM::InvocationState::Start: return InvocationState::Start;
		case MDM::InvocationState::Cnclld: return InvocationState::Cnclld;
		case MDM::InvocationState::CnclldMan: return InvocationState::CnclldMan;
		case MDM::InvocationState::Fin: return InvocationState::Fin;
		case MDM::InvocationState::FinMod: return InvocationState::FinMod;
		case MDM::InvocationState::Fail: return InvocationState::Fail;
	}
	throw std::runtime_error("Illegal value for InvocationState");
}


} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */
