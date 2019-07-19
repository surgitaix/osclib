#ifndef SCHEMA_BICEPS_MESSAGEMODEL_H
#define SCHEMA_BICEPS_MESSAGEMODEL_H

#include "SchemaBICEPSParticipantModel.h"

namespace SCHEMA
{
const static std::string SCHEMA_BICEPS_MESSAGEMODEL_NAME("BICEPS_MessageModel.xsd");

const static std::string SCHEMA_BICEPS_MESSAGEMODEL_CONTENT = std::string(R"(<?xml version="1.0" encoding="UTF-8"?>
<xsd:schema xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:ext="http://standards.ieee.org/downloads/11073/11073-10207-2017/extension" xmlns:pm="http://standards.ieee.org/downloads/11073/11073-10207-2017/participant" xmlns:msg="http://standards.ieee.org/downloads/11073/11073-10207-2017/message" targetNamespace="http://standards.ieee.org/downloads/11073/11073-10207-2017/message" elementFormDefault="qualified" attributeFormDefault="unqualified" xml:lang="en">
	<xsd:import namespace="http://standards.ieee.org/downloads/11073/11073-10207-2017/extension" schemaLocation=")" + SCHEMA_EXTENSIONPOINT_NAME + R"("/>
	<xsd:import namespace="http://standards.ieee.org/downloads/11073/11073-10207-2017/participant" schemaLocation=")" + SCHEMA_BICEPS_PARTICIPANTMODEL_NAME + R"("/>
	<xsd:annotation>
		<xsd:documentation>This XML schema defines the 'Basic Integrated Clinical Environment Protocol Specification' (BICEPS) that is a Domain Information Model (DIM) for point of care medical device communication.
			It encompasses the device model and the corresponding messages.
			This XML Schema is based on the ISO/IEEE 11073-10201 Domain Information Model standard,
			which belongs to the "Point-of-care medical device communication" standard family in ISO/IEEE 11073.
			This standard family should not to be confused with the ISO/IEEE 11073 "Personal Health Device" standard family.
			While former is based on the standards ISO/IEEE 11073-10101, 11073-10201, 11073-20101, and 11073-30200,
			the latter is based on ISO/IEEE 11073-20601 and ISO/IEEE 11073-104xx.
			The Domain Information model is subdivided into two parts, a static part (referred to as Descriptor)
			that provides general information about the hardware specification of the elements and
			a dynamic part (referred to as State) that may change during time.</xsd:documentation>
	</xsd:annotation>
	<!--Section: Base Types-->
	<xsd:simpleType name="TransactionId">
		<xsd:annotation>
			<xsd:documentation>TransactionId is a transaction identifier that SHALL be unique among an operation invocation transaction.</xsd:documentation>
		</xsd:annotation>
		<xsd:restriction base="xsd:unsignedInt"/>
	</xsd:simpleType>
	<xsd:simpleType name="InvocationState">
		<xsd:annotation>
			<xsd:documentation>Transaction state of an invoked operation.</xsd:documentation>
		</xsd:annotation>
		<xsd:restriction base="xsd:string">
			<xsd:enumeration value="Wait">
				<xsd:annotation>
					<xsd:documentation>Wait = Waiting. The operation has been queued and waits for execution.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Start">
				<xsd:annotation>
					<xsd:documentation>Start = Started. The execution of the operation has been started.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Cnclld">
				<xsd:annotation>
					<xsd:documentation>Cnclld = Cancelled. The execution has been cancelled by the SERVICE PROVIDER.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="CnclldMan">
				<xsd:annotation>
					<xsd:documentation>CnclldMan = Cancelled Manually. The execution has been cancelled by the operator.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Fin">
				<xsd:annotation>
					<xsd:documentation>Fin = Finished. The execution has been finished.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="FinMod">
				<xsd:annotation>
					<xsd:documentation>FinMod = Finished with modification. As the requested target value could not be reached, the next best value has been chosen and used as target value.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Fail">
				<xsd:annotation>
					<xsd:documentation>The execution has been failed.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
		</xsd:restriction>
	</xsd:simpleType>
	<xsd:simpleType name="InvocationError">
		<xsd:annotation>
			<xsd:documentation>InvocationError conveys details with respect to the origin of an operation invocation failure.</xsd:documentation>
		</xsd:annotation>
		<xsd:restriction base="xsd:string">
			<xsd:enumeration value="Unspec">
				<xsd:annotation>
					<xsd:documentation>Unspec = Unspecified. An unspecified error has occurred. No more information about the error is available.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Unkn">
				<xsd:annotation>
					<xsd:documentation>Unkn = Unknown Operation. The HANDLE to the operation object is not known.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Inv">
				<xsd:annotation>
					<xsd:documentation>Inv = Invalid Value. The HANDLE to the operation object does not match the invocation request MESSAGE.

Example: if a msg:SetString MESSAGE is received, in which the msg:SetString/msg:OperationHandleRef points to a msg:SetValue MESSAGE, the receiver replies with InvocationError "Inv".</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Oth">
				<xsd:annotation>
					<xsd:documentation>Oth = Other. Another type of error has occurred. More information on the error MAY be available.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
		</xsd:restriction>
	</xsd:simpleType>
	<xsd:complexType name="InvocationInfo">
		<xsd:annotation>
			<xsd:documentation>InvocationInfo conveys information to describe a transaction operation.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:element ref="ext:Extension" minOccurs="0"/>
			<xsd:element name="TransactionId" type="msg:TransactionId">
				<xsd:annotation>
					<xsd:documentation>Transaction identifier that has been assigned to the processing of a set operation.

The transaction identifier SHALL be used to identify a set operation transaction status that is delivered via msg:OperationInvokedReport MESSAGEs. The transaction's initial identifier is tramsmitted in the response of a set operation request.</xsd:documentation>
				</xsd:annotation>
			</xsd:element>
			<xsd:element name="InvocationState" type="msg:InvocationState">
				<xsd:annotation>
					<xsd:documentation>Processing state of an invoked operation.</xsd:documentation>
				</xsd:annotation>
			</xsd:element>
			<xsd:element name="InvocationError" type="msg:InvocationError" minOccurs="0">
				<xsd:annotation>
					<xsd:documentation>If ./msg:InvocationState indicates a failure, InvocationError may convey more information about the error.</xsd:documentation>
				</xsd:annotation>
			</xsd:element>
			<xsd:element name="InvocationErrorMessage" type="pm:LocalizedText" minOccurs="0" maxOccurs="unbounded">
				<xsd:annotation>
					<xsd:documentation>If ./msg:InvocationState indicates a failure, InvocationErrorMessage may convey a MESSAGE for a user with information about the error.</xsd:documentation>
				</xsd:annotation>
			</xsd:element>
		</xsd:sequence>
	</xsd:complexType>
	<!--Section: Service Operations Base Types-->
	<xsd:complexType name="AbstractGet">
		<xsd:annotation>
			<xsd:documentation>The GET SERVICE provides a set of request and response MESSAGEs. AbstractGet is the building block for any GET SERVICE request MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:element ref="ext:Extension" minOccurs="0"/>
		</xsd:sequence>
	</xsd:complexType>
	<xsd:complexType name="AbstractGetResponse">
		<xsd:annotation>
			<xsd:documentation>The GET SERVICE provides a set of request and response MESSAGEs. AbstractGetResponse is the building block for any GET SERVICE response MESSAGE.

Per convention any response MESSAGE ends up with "Response", whereas request MESSAGEs possess no specific suffix.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:element ref="ext:Extension" minOccurs="0"/>
		</xsd:sequence>
		<xsd:attributeGroup ref="pm:MdibVersionGroup"/>
	</xsd:complexType>
	<xsd:complexType name="AbstractReportPart">
		<xsd:annotation>
			<xsd:documentation>Any report that is delivered using msg:AbstractReport MAY consist of multiple report parts. AbstractReport is the building block for a single report part in a msg:AbstractReport.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:element ref="ext:Extension" minOccurs="0"/>
			<xsd:element name="SourceMds" type="pm:HandleRef" minOccurs="0">
				<xsd:annotation>
					<xsd:documentation>Reference to the MDS that has triggered the sending of the report part. An event sink MAY use this HANDLE reference for filtering.

- If the MDIB includes a single MDS only, SourceMds is OPTIONAL.
- If the MDIB includes multiple MDSs, SourceMds is REQUIRED.</xsd:documentation>
				</xsd:annotation>
			</xsd:element>
		</xsd:sequence>
	</xsd:complexType>
	<xsd:complexType name="AbstractReport">
		<xsd:annotation>
			<xsd:documentation>Event report services provide a set of MESSAGEs, which are distributed using a publish subscribe mechanism. AbstractReport is the building block for any event MESSAGE that is delivered to an event sink.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:element ref="ext:Extension" minOccurs="0"/>
		</xsd:sequence>
		<xsd:attributeGroup ref="pm:MdibVersionGroup"/>
	</xsd:complexType>
	<xsd:complexType name="AbstractSet">
		<xsd:annotation>
			<xsd:documentation>The SET SERVICE provides a set of request and response MESSAGEs. AbstractSet is the building block for any SET SERVICE request MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:element ref="ext:Extension" minOccurs="0"/>
			<xsd:element name="OperationHandleRef" type="pm:HandleRef">
				<xsd:annotation>
					<xsd:documentation>Handle of the set operation to invoke. 

A SERVICE PROVIDER SHALL accept a set request only if at least the operation target HANDLE is valid and the operation is enabled according to the POC MEDICAL DEVICE's MDIB. A target HANDLE is valid if the operation to invoke can be applied on the object referenced by the target HANDLE. An operation can be considered as enabled if pm:AbstractOperationStateType/@OperatingMode equals "En".</xsd:documentation>
				</xsd:annotation>
			</xsd:element>
		</xsd:sequence>
	</xsd:complexType>
	<xsd:complexType name="AbstractSetResponse">
		<xsd:annotation>
			<xsd:documentation>The SET SERVICE provides a set of request and response MESSAGEs. AbstractSetResponse is the building block for any SET SERVICE response MESSAGE.

Per convention any response MESSAGE ends up with "Response", whereas request MESSAGEs possess no specific suffix.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:element ref="ext:Extension" minOccurs="0"/>
			<xsd:element name="InvocationInfo" type="msg:InvocationInfo">
				<xsd:annotation>
					<xsd:documentation>Information set regarding the returned transaction. See pm:InvocationInfo.</xsd:documentation>
				</xsd:annotation>
			</xsd:element>
		</xsd:sequence>
		<xsd:attributeGroup ref="pm:MdibVersionGroup"/>
	</xsd:complexType>
	<!--Section: Get-->
	<xsd:element name="GetMdib">
		<xsd:annotation>
			<xsd:documentation>GetMdib is the request to a msg:GetMdibResponse MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetMdibResponse">
		<xsd:annotation>
			<xsd:documentation>GetMdibResponse is the response to a msg:GetMdib MESSAGE It conveys the complete MDIB. 

Since contexts might include privacy-related information, a SERVICE PROVIDER MAY decide to leave the MDS contexts empty. To acquire context information, a client has to send a msg:GetContextStates request.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="Mdib" type="pm:Mdib">
							<xsd:annotation>
								<xsd:documentation>Current snapshot of the MDIB.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetMdDescription">
		<xsd:annotation>
			<xsd:documentation>GetMdDescription is the request to a msg:GetMdDescriptionResponse MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="HandleRef" type="pm:HandleRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of HANDLEs that specify which descriptors are requested. See msg:GetMdDescriptionResponse/msg:MdDescription.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetMdDescriptionResponse">
		<xsd:annotation>
			<xsd:documentation>GetMdDescriptionResponse is the response to a msg:GetMdDescription MESSAGE. It transports a set of MDS descriptors.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="MdDescription" type="pm:MdDescription">
							<xsd:annotation>
								<xsd:documentation>MdDescription comprises the requested set of MDS descriptors. Which MDS descriptors SHALL be included depends on the msg:GetMdDescription/msg:HandleRef list:

- If the HANDLE reference list is empty, all MDS descriptors are included in the result list.
- If a HANDLE reference does match an MDS descriptor, it is included in the result list.
- If a HANDLE reference does not match an MDS descriptor (i.e., any other descriptor), the MDS descriptor that is in the parent tree of the HANDLE reference is included in the result list.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetMdState">
		<xsd:annotation>
			<xsd:documentation>GetMdState is the request to a msg:GetMdStateResponse MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="HandleRef" type="pm:HandleRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of HANDLEs that specify which states are requested. See msg:GetMdStateResponse/msg:MdState.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetMdStateResponse">
		<xsd:annotation>
			<xsd:documentation>GetMdStateResponse is the response to a msg:GetMdState MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="MdState" type="pm:MdState">
							<xsd:annotation>
								<xsd:documentation>MdState comprises the requested set of MDS states. Which MDS states SHALL be included depends on the msg:GetMdState/msg:HandleRef list:

- If the HANDLE reference list is empty, all states in the MDIB are included in the result list.
- If a HANDLE reference does match a multi state HANDLE, the corresponding multi state is included in the result list.
- If a HANDLE reference does match a descriptor HANDLE, all states that belong to the corresponding descriptor are included in the result list.

Since context states might include privacy-related information, a SERVICE PROVIDER can decide to skip any contexts states. Context states have to be requested by sending a msg:GetContextStates request.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: Context-->
	<xsd:element name="GetContextStates">
		<xsd:annotation>
			<xsd:documentation>GetContextStates is the request to a msg:GetContextStatesResponse MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="HandleRef" type="pm:HandleRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of HANDLEs that specify which context states are requested. See msg:GetContextStatesResponse/msg:ContextState.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetContextStatesResponse">
		<xsd:annotation>
			<xsd:documentation>GetContextStatesResponse is the response to a msg:GetContextStates MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="ContextState" type="pm:AbstractContextState" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>ContextState comprises the requested set of context states.

__R5039: If the msg:GetContextStates/msg:HandleRef list is empty, all context states in the MDIB SHALL be included in the result list.__

__R5040: If a HANDLE reference from the msg:GetContextStates/msg:HandleRef list does match a context descriptor HANDLE, then all context states that belong to the corresponding context descriptor SHALL be included in the result list.__

__R5041: If a HANDLE reference from the msg:GetContextStates/msg:HandleRef list does match a context state HANDLE, then the corresponding context state SHALL be included in the result list.__

__R5042: If a HANDLE reference from the msg:GetContextStates/msg:HandleRef list does match an MDS descriptor, then all context states that are part of this MDS SHALL be included in the result list.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetContextStatesByIdentification">
		<xsd:annotation>
			<xsd:documentation>GetContextStatesByIdentification is the request to a msg:GetContextStatesByIdentificationResponse MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="Identification" type="pm:InstanceIdentifier" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of pm:InstanceIdentifier ELEMENTs that specify which context states are requested based on their pm:AbstractContextState/pm:Identification. See msg:GetContextStatesByIdentificationResponse/msg:ContextState.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
					<xsd:attribute name="ContextType" type="xsd:QName">
						<xsd:annotation>
							<xsd:documentation>ContextType defines the type of context to return (e.g., pm:LocationContextState or pm:PatientContextState).</xsd:documentation>
						</xsd:annotation>
					</xsd:attribute>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetContextStatesByIdentificationResponse">
		<xsd:annotation>
			<xsd:documentation>GetContextStatesByIdentificationResponse is the response to a msg:GetContextStatesByIdentification MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="ContextState" type="pm:AbstractContextState" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>ContextState comprises the requested set of context states.

__R5036: If the msg:GetContextStates/msg:Identification list is empty, then no context states SHALL be included in the result list.__

__R5037: The result list SHALL enclose all context states of the requested msg:GetContextStates/@ContextType that match at least all ELEMENTs from the msg:GetContextStates/msg:Identification list.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetContextStatesByFilter">
		<xsd:annotation>
			<xsd:documentation>GetContextStatesByFilter is the request to a msg:GetContextStatesByFilterResponse.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="Filter" type="xsd:string" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of XPath expressions that specify which context states are requested based on XPath expressions. See msg:GetContextStatesByFilterResponse/msg:ContextState.

__R5045: The root node of the XPath expression SHALL be the pm:MdState ELEMENT of the target MDIB.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
					<xsd:attribute name="ContextType" type="xsd:QName">
						<xsd:annotation>
							<xsd:documentation>ContextType defines the type of context to return (e.g., pm:LocationContextState or pm:PatientContextState).</xsd:documentation>
						</xsd:annotation>
					</xsd:attribute>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetContextStatesByFilterResponse">
		<xsd:annotation>
			<xsd:documentation>GetContextStatesByFilterResponse is the response to a msg:GetContextStatesByFilter MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="ContextState" type="pm:AbstractContextState" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>ContextState comprises the requested set of context states.

__R5043: If the msg:GetContextStates/msg:Filter list is empty, then no context states SHALL be included in the result list.__

__R5044: The result SHALL enclose all context states of the requested msg:GetContextStates/@ContextType that match the filter criteria from the msg:GetContextStates/msg:Filter list where all filter criteria are concatenated by a logical "and".__

NOTE—For a logical "or" concatenation a SERVICE CONSUMER has to send multiple requests. This is similar to the Types and Scopes filtering mechanism of WS-Discovery [WS-Discovery].
</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetContextState">
		<xsd:annotation>
			<xsd:documentation>SetContextState is the request to a msg:SetContextStateResponse MESSAGE. Its function is to insert a new or modify an existing context state.

The corresponding operation description is defined by pm:SetContextStateOperationDescriptor.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSet">
					<xsd:sequence>
						<xsd:element name="ProposedContextState" type="pm:AbstractContextState" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>ProposedContextState comprises the context states that have to be inserted or updated:

- If ProposedContextState/@Handle is equal ProposedContextState/@DescriptorHandle, the proposed object SHOULD be created as a new context state.
- If ProposedContextState/@Handle is not equal ProposedContextState/@DescriptorHandle, the proposed object SHOULD be modified.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetContextStateResponse">
		<xsd:annotation>
			<xsd:documentation>Response MESSAGE to a SetContextState request MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSetResponse"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:complexType name="AbstractContextReport">
		<xsd:annotation>
			<xsd:documentation>AbstractContextReport is a change report that contains updated pm:AbstractContextState instances.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexContent>
			<xsd:extension base="msg:AbstractReport">
				<xsd:sequence>
					<xsd:element name="ReportPart" minOccurs="0" maxOccurs="unbounded">
						<xsd:annotation>
							<xsd:documentation>List of report containers associated to one MDS.</xsd:documentation>
						</xsd:annotation>
						<xsd:complexType>
							<xsd:annotation/>
							<xsd:complexContent>
								<xsd:extension base="msg:AbstractReportPart">
									<xsd:sequence>
										<xsd:element name="ContextState" type="pm:AbstractContextState" minOccurs="0" maxOccurs="unbounded">
											<xsd:annotation>
												<xsd:documentation>List of changed pm:AbstractContextState instances.</xsd:documentation>
											</xsd:annotation>
										</xsd:element>
									</xsd:sequence>
								</xsd:extension>
							</xsd:complexContent>
						</xsd:complexType>
					</xsd:element>
				</xsd:sequence>
			</xsd:extension>
		</xsd:complexContent>
	</xsd:complexType>
	<xsd:element name="PeriodicContextReport">
		<xsd:annotation>
			<xsd:documentation>PeriodicContextReport is an msg:AbstractContextReport that is delivered periodically.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractContextReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="EpisodicContextReport">
		<xsd:annotation>
			<xsd:documentation>EpisodicContextReport is an msg:AbstractContextReport that is delivered episodically. It is sent if at least one pm:AbstractContextState has changed. It SHALL contain only pm:AbstractContextState instances where at least one child ELEMENT or ATTRIBUTE have changed.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractContextReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: Localization-->
	<xsd:element name="GetLocalizedText">
		<xsd:annotation>
			<xsd:documentation>GetLocalizedText is the request to a msg:GetLocalizedTextResponse MESSAGE. Its intended use is to obtain a localized text that is referenced in the MDIB.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="Ref" type="pm:LocalizedTextRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>Zero or more reference names of the texts that are requested. The ELEMENT SHALL have the following impacts on the information conveyed in msg:GetLocalizedTextResponse/msg:Text:

- If there is no Ref ELEMENT given in the request MESSAGE, then all texts are returned in msg:GetLocalizedTextResponse/msg:Text.
- If there is at least one Ref ELEMENT given, then msg:GetLocalizedTextResponse/msg:Text contains all texts that match the Ref ELEMENTs of the msg:GetLocalizedText request MESSAGE.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="Version" type="pm:ReferencedVersion" minOccurs="0">
							<xsd:annotation>
								<xsd:documentation>Revision of the referenced text that is requested. The ELEMENT SHALL have the following impacts on the information conveyed in msg:GetLocalizedTextResponse/msg:Text:

- If the referenced text is not available in the specific version, then msg:GetLocalizedTextResponse/msg:Text is empty.
- If Version is not specified, then msg:GetLocalizedTextResponse contains the latest version of the text in msg:GetLocalizedTextResponse/msg:Text.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="Lang" type="xsd:language" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>Zero or more language identifiers according to RFC 5646 (see http://tools.ietf.org/html/rfc5646) to get different translations of the requested text. The ELEMENT SHALL have the following impacts on the information conveyed in msg:GetLocalizedTextResponse/msg:Text:

- If there is no Lang ELEMENT given in the request MESSAGE, then all translations are returned in msg:GetLocalizedTextResponse/msg:Text.
- If there is at least one Lang ELEMENT given, then msg:GetLocalizedTextResponse/msg:Text contains translations in all languages matching the Lang ELEMENTs of the msg:GetLocalizedText request MESSAGE. If a text is not available in a specific language, the result for that specific language is omitted.

NOTE—A set of supported languages is retrievable using msg:GetSupportedLanguages.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="TextWidth" type="pm:LocalizedTextWidth" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>Zero or more pm:LocalizedTextWidth itentifiers to filter for different text widths. The ELEMENT SHALL have the following impacts on the information conveyed in msg:GetLocalizedTextResponse/msg:Text:

- If there is no TextWidth ELEMENT given in the request MESSAGE, then all text widths are returned in msg:GetLocalizedTextResponse/msg:Text.
- If there is at least one TextWidth ELEMENT given, then msg:GetLocalizedTextResponse/msg:Text contains texts with all text widths matching the TextWidth ELEMENTs of the msg:GetLocalizedText request MESSAGE. Matching in this case means that the number of full width characters in the text is less or equal to the TextWidth ELEMENTs.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="NumberOfLines" type="xsd:integer" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>Zero or more numbers to filter for number of lines. The ELEMENT SHALL have the following impacts on the information conveyed in msg:GetLocalizedTextResponse/msg:Text:

- If there is no NumberOfLines ELEMENT given in the request MESSAGE, then all texts independent of the number of lines are returned in msg:GetLocalizedTextResponse/msg:Text.
- If there is at least one NumberOfLines ELEMENT given, msg:GetLocalizedTextResponse/msg:Text contains texts that match the number of lines defined by the NumberOfLines ELEMENTs of the msg:GetLocalizedText request MESSAGE. Matching in this case means that the number of lines in the text is less or equal to the NumberOfLines ELEMENTs.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetLocalizedTextResponse">
		<xsd:annotation>
			<xsd:documentation>GetLocalizedTextResponse is the response to a msg:GetLocalizedText MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="Text" type="pm:LocalizedText" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>A list of texts that SHALL contain a result according to the selection constituted by msg:GetLocalizedText/msg:Ref, msg:GetLocalizedText/msg:Version, and msg:GetLocalizedText/msg:Lang.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetSupportedLanguages">
		<xsd:annotation>
			<xsd:documentation>GetSupportedLanguages is the request to a msg:GetSupportedLanguagesResponse MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence/>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetSupportedLanguagesResponse">
		<xsd:annotation>
			<xsd:documentation>GetSupportedLanguagesResponse is the response to a msg:GetSupportedLanguagesResponse MESSAGE. A GetSupportedLanguagesResponse MESSAGE SHALL be send in answer to a GetSupportedLanguages request MESSAGE and contains all language identifiers available for referenced localized texts.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="Lang" type="xsd:language" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of language identifiers available to request referenced localized texts. The format is given in accordance to RFC 5646 (see http://tools.ietf.org/html/rfc5646).</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: Archive-->
	<xsd:complexType name="VersionFrame">
		<xsd:annotation>
			<xsd:documentation>VersionFrame constitutes a version frame by defining ./@Start and ./@End, whereby ./@Start is REQUIRED to be lesser than or equal to ./@End.</xsd:documentation>
		</xsd:annotation>
		<xsd:attribute name="Start" type="pm:ReferencedVersion">
			<xsd:annotation>
				<xsd:documentation>The start version of the version frame.</xsd:documentation>
			</xsd:annotation>
		</xsd:attribute>
		<xsd:attribute name="End" type="pm:ReferencedVersion">
			<xsd:annotation>
				<xsd:documentation>The end version of the version frame.</xsd:documentation>
			</xsd:annotation>
		</xsd:attribute>
	</xsd:complexType>
	<xsd:complexType name="TimeFrame">
		<xsd:annotation>
			<xsd:documentation>TimeFrame constitutes a time frame by defining ./@Start and ./@End, whereby ./@Start is REQUIRED to be lesser than ./@End.</xsd:documentation>
		</xsd:annotation>
		<xsd:attribute name="Start" type="pm:Timestamp">
			<xsd:annotation>
				<xsd:documentation>The start time of the time frame.</xsd:documentation>
			</xsd:annotation>
		</xsd:attribute>
		<xsd:attribute name="End" type="pm:Timestamp">
			<xsd:annotation>
				<xsd:documentation>The end time of the time frame.</xsd:documentation>
			</xsd:annotation>
		</xsd:attribute>
	</xsd:complexType>
	<xsd:element name="GetDescriptorsFromArchive">
		<xsd:annotation>
			<xsd:documentation>GetDescriptorsFromArchive is the request to a msg:GetDescriptorsFromArchiveResponse MESSAGE. Its intended use is used to request descriptors from the MDIB archive related to a specific descriptor version and/or time frame.

__R5015: GetDescriptorsFromArchive SHALL at least expect ./msg:DescriptorRevisions or ./msg:TimeFrame as a filter condition.__

__R5016: If both ./msg:DescriptorRevisions and ./msg:TimeFrame are given, the filter SHALL be applied by conjunction. If none are defined, the MESSAGE is invalid.__</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="DescriptorRevisions" type="msg:VersionFrame" minOccurs="0">
							<xsd:annotation>
								<xsd:documentation>DescriptorRevisions is a version-based filter. It designates the referenced descriptor version frame that is requested. By adding this optional ELEMENT to the request, msg:GetDescriptorsFromArchiveResponse SHALL only respond with descriptors that match this version frame.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="TimeFrame" type="msg:TimeFrame" minOccurs="0">
							<xsd:annotation>
								<xsd:documentation>TimeFrame defines a time-based filter. By adding this ELEMENT to the request, msg:GetDescriptorsFromArchiveResponse SHALL only respond with descriptors that matches this time frame.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="Handle" type="pm:HandleRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>A list of HANDLE references that serve as a filter for the response.

__R5017: If one or more HANDLE references are defined, msg:GetDescriptorsFromArchiveResponse SHALL respond only with descriptors that match these HANDLE references at the given revision and/or time frame.__

__R5018: If no HANDLE references are defined, msg:GetDescriptorsFromArchiveResponse SHALL respond with all descriptors at the given revision and/or time frame.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetDescriptorsFromArchiveResponse">
		<xsd:annotation>
			<xsd:documentation>GetDescriptorsFromArchiveResponse MESSAGE is sent as the response to a GetDescriptorsFromArchive request MESSAGE using the ARCHIVE SERVICE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="Descriptor" type="pm:AbstractDescriptor" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>A list of descriptors. The descriptors SHALL match the time frame as well as the version and HANDLE references of the GetDescriptorsFromArchive request MESSAGE.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetStatesFromArchive">
		<xsd:annotation>
			<xsd:documentation>GetStatesFromArchive MESSAGE is used by the ARCHIVE SERVICE to request states related to a specific state version and/or time frame.

__R5019: GetStatesFromArchive SHALL at least expect a version or a time frame filter.__

__R5020: If both a version and a time frame are defined, the filter SHALL apply by conjunction. If none are defined, the MESSAGE is invalid.__

NOTE—It is not sufficient to provide HANDLEs only.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="StateRevisions" type="msg:VersionFrame" minOccurs="0">
							<xsd:annotation>
								<xsd:documentation>StateRevisions is a version filter. It designates the referenced state version frame that is requested. By adding this optional ELEMENT to the request, GetStatesFromArchiveResponse SHALL only respond with states matching this version frame.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="TimeFrame" type="msg:TimeFrame" minOccurs="0">
							<xsd:annotation>
								<xsd:documentation>TimeFrame defines a time-based filter. By adding this optional ELEMENT to the request, GetStatesFromArchiveResponse SHALL only respond with states matching this time frame.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
						<xsd:element name="Handle" type="pm:HandleRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>A list of HANDLE references which serve as a filter for the response.

__R5021: If one or more HANDLE references are defined, GetStatesFromArchiveResponse SHALL respond only with states matching these HANDLE references at the given revision and/or time frame.__

__R5022: If no HANDLE references are defined, GetStatesFromArchiveResponse SHALL respond with all states at the given revision and/or time frame.__

__R5023: If a HANDLE is a descriptor HANDLE that points to a multi state, GetStatesFromArchiveResponse SHALL respond with all states referring to the descriptor HANDLE.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetStatesFromArchiveResponse">
		<xsd:annotation>
			<xsd:documentation>GetStatesFromArchiveResponse MESSAGE is sent as the response to a GetStatesFromArchive request MESSAGE using the ARCHIVE SERVICE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="State" type="pm:AbstractState" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>A list of states. The states SHALL match the time frame as well as the version and HANDLE references of the GetStatesFromArchive request MESSAGE.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: Set-->
	<xsd:element name="SetValue">
		<xsd:annotation>
			<xsd:documentation>SetValue is the request to a msg:SetValueResponse MESSAGE.

The corresponding operation description is defined by pm:SetValueOperationDescriptor.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSet">
					<xsd:sequence>
						<xsd:element name="RequestedNumericValue" type="xsd:decimal">
							<xsd:annotation>
								<xsd:documentation>Value of pm:NumericMetricState/pm:ObservedValue/@Value to set.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetValueResponse">
		<xsd:annotation>
			<xsd:documentation>SetValueResponse is the response to a msg:SetValue MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSetResponse"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetString">
		<xsd:annotation>
			<xsd:documentation>SetString is the request to a msg:SetStringResponse MESSAGE.

The corresponding operation description is defined by pm:SetStringOperationDescriptor.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSet">
					<xsd:sequence>
						<xsd:element name="RequestedStringValue" type="xsd:string">
							<xsd:annotation>
								<xsd:documentation>Value of pm:StringMetricState/pm:ObservedValue/@Value to set.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetStringResponse">
		<xsd:annotation>
			<xsd:documentation>SetStringResponse is the response to a msg:SetString MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSetResponse"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="Activate">
		<xsd:annotation>
			<xsd:documentation>Activate is the request to an msg:ActivateResponse MESSAGE. It allows invocation of a predefined job, e.g., to silence alarms.

The corresponding operation description is defined by pm:ActivateOperationDescriptor.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSet">
					<xsd:sequence>
						<xsd:element name="Argument" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of arguments that can be used for invocation. The type list of the arguments can be obtained by the operation description in the MDIB. Furthermore, the ordering of Argument SHALL match the ordering in pm:ActivateOperationDescriptor/pm:Argument.</xsd:documentation>
							</xsd:annotation>
							<xsd:complexType>
								<xsd:sequence>
									<xsd:element ref="ext:Extension" minOccurs="0"/>
									<xsd:element name="ArgValue" type="xsd:anySimpleType">
										<xsd:annotation>
											<xsd:documentation>Argument value.</xsd:documentation>
										</xsd:annotation>
									</xsd:element>
								</xsd:sequence>
							</xsd:complexType>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="ActivateResponse">
		<xsd:annotation>
			<xsd:documentation>ActivateResponse is the response to an msg:Activate MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSetResponse"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetAlertState">
		<xsd:annotation>
			<xsd:documentation>SetAlertState is the request to a msg:SetAlertStateResponse MESSAGE. The intended use is to modifiy alert states.

The corresponding operation description is defined by pm:SetAlertStateOperationDescriptor.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSet">
					<xsd:sequence>
						<xsd:element name="ProposedAlertState" type="pm:AbstractAlertState">
							<xsd:annotation>
								<xsd:documentation>ProposedAlertState comprises the alert states that have to be updated.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetAlertStateResponse">
		<xsd:annotation>
			<xsd:documentation>SetAlertStateResponse is the response to a msg:SetAlertState MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSetResponse"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetComponentState">
		<xsd:annotation>
			<xsd:documentation>SetComponentState is the request to a msg:SetComponentStateResponse MESSAGE. Its intended use is to modify an existing component state.

The corresponding operation description is defined by pm:SetComponentStateOperationDescriptor.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSet">
					<xsd:sequence>
						<xsd:element name="ProposedComponentState" type="pm:AbstractDeviceComponentState" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>ProposedComponentState comprises the component states that have to be updated.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetComponentStateResponse">
		<xsd:annotation>
			<xsd:documentation>SetComponentStateResponse is the response to a msg:SetComponentState MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSetResponse"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetMetricState">
		<xsd:annotation>
			<xsd:documentation>SetMetricState is the request to a msg:SetMetricStateResponse MESSAGE.

The corresponding operation description is defined by pm:SetMetricStateOperationDescriptor.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSet">
					<xsd:sequence>
						<xsd:element name="ProposedMetricState" type="pm:AbstractMetricState" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>ProposedMetricState comprises the METRIC states that have to be updated.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="SetMetricStateResponse">
		<xsd:annotation>
			<xsd:documentation>SetMetricStateResponse is the response to a msg:SetMetricState MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractSetResponse"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="OperationInvokedReport">
		<xsd:annotation>
			<xsd:documentation>OperationInvokedReport is a change report that contains updated invocation information. It is delivered if the state of the execution of a remote operation request has changed.

To identify which state of a multi state is changed or created, OperationInvokedReport SHALL include msg:OperationInvokedReportPart/@OperationTarget. This ATTRIBUTE defines the multi state that is created or updated.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractReport">
					<xsd:sequence>
						<xsd:element name="ReportPart" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of report containers associated to one MDS.</xsd:documentation>
							</xsd:annotation>
							<xsd:complexType>
								<xsd:complexContent>
									<xsd:extension base="msg:AbstractReportPart">
										<xsd:sequence>
											<xsd:element name="InvocationInfo" type="msg:InvocationInfo">
												<xsd:annotation>
													<xsd:documentation>Information set regarding the report's transaction status. See pm:InvocationInfo.</xsd:documentation>
												</xsd:annotation>
											</xsd:element>
											<xsd:element name="InvocationSource" type="pm:InstanceIdentifier">
												<xsd:annotation>
													<xsd:documentation>Identifies the PARTICIPANT that has requested the execution of the operation.

NOTE—If another PARTICIPANT is interested in who requested a certain operation, it is able to track that information by means of InvocationSource.</xsd:documentation>
												</xsd:annotation>
											</xsd:element>
										</xsd:sequence>
										<xsd:attribute name="OperationHandleRef" type="pm:HandleRef" use="required">
											<xsd:annotation>
												<xsd:documentation>A REQUIRED HANDLE reference that provides a link to the set operation processed by the transaction.</xsd:documentation>
											</xsd:annotation>
										</xsd:attribute>
										<xsd:attribute name="OperationTarget" type="pm:HandleRef">
											<xsd:annotation>
												<xsd:documentation>An OPTIONAL HANDLE reference that provides a link to the CONTAINMENT TREE ENTRY affected by the transaction.</xsd:documentation>
											</xsd:annotation>
										</xsd:attribute>
									</xsd:extension>
								</xsd:complexContent>
							</xsd:complexType>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: ContainmentTree-->
	<xsd:element name="GetContainmentTree">
		<xsd:annotation>
			<xsd:documentation>GetContainmentTree is the request to a msg:GetContainmentTreeResponse MESSAGE. It is intended to be used as a tool to navigate through the CONTAINMENT TREE of an MDIB.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="HandleRef" type="pm:HandleRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of HANDLE references that specify which CONTAINMENT TREE ENTRYs are requested.

__R5030: All HANDLE references SHALL share the same parent. Otherwise, the result of GetContainmentTree is undefined.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetContainmentTreeResponse">
		<xsd:annotation>
			<xsd:documentation>GetContainmentTreeResponse is the response to a msg:GetContainmentTree MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="ContainmentTree" type="pm:ContainmentTree">
							<xsd:annotation>
								<xsd:documentation>ContainmentTreeInfo as described in pm:ContainmentTree.

__R5031: The result SHALL contain CONTAINMENT TREE information of all ELEMENTs that are matched by msg:GetContainmentTree/msg:HandleRef.__

__R5032: If no HANDLE reference is provided, all CONTAINMENT TREE ELEMENTs on MDS level SHALL be returned.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetDescriptor">
		<xsd:annotation>
			<xsd:documentation>GetDescriptor is the request to a msg:GetDescriptorResponse MESSAGE. It is proposed to be used to resolve the HANDLE references that are requested by msg:GetContainmentTree.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGet">
					<xsd:sequence>
						<xsd:element name="HandleRef" type="pm:HandleRef" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of HANDLE references that specify which descriptors are requested.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="GetDescriptorResponse">
		<xsd:annotation>
			<xsd:documentation>GetDescriptorResponse is the response to a msg:GetDescriptorResponse MESSAGE.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractGetResponse">
					<xsd:sequence>
						<xsd:element name="Descriptor" type="pm:AbstractDescriptor" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of pm:AbstractDescriptor ELEMENTs.

__R5033: Resulting descriptors SHALL NOT contain child descriptors.__

__R5034: The result SHALL contain CONTAINMENT TREE information of all descriptors that are matched by msg:GetDescriptor/msg:HandleRef.__

__R5035: If no HANDLE is provided, all descriptors SHALL be returned.__</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: StateEvent-->
	<!--Sub-section: Metric Reports-->
	<xsd:complexType name="AbstractMetricReport">
		<xsd:annotation>
			<xsd:documentation>AbstractMetricReport is a change report that contains updated pm:AbstractMetricState instances.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexContent>
			<xsd:extension base="msg:AbstractReport">
				<xsd:sequence>
					<xsd:element name="ReportPart" minOccurs="0" maxOccurs="unbounded">
						<xsd:annotation>
							<xsd:documentation>List of report containers associated to one MDS.</xsd:documentation>
						</xsd:annotation>
						<xsd:complexType>
							<xsd:complexContent>
								<xsd:extension base="msg:AbstractReportPart">
									<xsd:sequence>
										<xsd:element name="MetricState" type="pm:AbstractMetricState" minOccurs="0" maxOccurs="unbounded">
											<xsd:annotation>
												<xsd:documentation>List of changed pm:AbstractMetricState instances.</xsd:documentation>
											</xsd:annotation>
										</xsd:element>
									</xsd:sequence>
								</xsd:extension>
							</xsd:complexContent>
						</xsd:complexType>
					</xsd:element>
				</xsd:sequence>
			</xsd:extension>
		</xsd:complexContent>
	</xsd:complexType>
	<xsd:element name="EpisodicMetricReport">
		<xsd:annotation>
			<xsd:documentation>EpisodicMetricReport is an msg::AbstractMetricReport that is delivered episodically. It is sent if at least one pm:AbstractMetricState has changed. It SHALL contain only pm:AbstractMetricState instances where at least one child ELEMENT or ATTRIBUTE have changed.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractMetricReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="PeriodicMetricReport">
		<xsd:annotation>
			<xsd:documentation>PeriodicMetricReport is an msg:AbstractMetricReport that is delivered periodically.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractMetricReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Sub-section: Component Reports-->
	<xsd:complexType name="AbstractComponentReport">
		<xsd:annotation>
			<xsd:documentation>AbstractComponentReport is a change report that contains updated pm:AbstractComponentState instances.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexContent>
			<xsd:extension base="msg:AbstractReport">
				<xsd:sequence>
					<xsd:element name="ReportPart" minOccurs="0" maxOccurs="unbounded">
						<xsd:annotation>
							<xsd:documentation>List of report containers associated to one MDS.</xsd:documentation>
						</xsd:annotation>
						<xsd:complexType>
							<xsd:complexContent>
								<xsd:extension base="msg:AbstractReportPart">
									<xsd:sequence>
										<xsd:element name="ComponentState" type="pm:AbstractDeviceComponentState" minOccurs="0" maxOccurs="unbounded">
											<xsd:annotation>
												<xsd:documentation>List of changed pm:AbstractComponentState instances.</xsd:documentation>
											</xsd:annotation>
										</xsd:element>
									</xsd:sequence>
								</xsd:extension>
							</xsd:complexContent>
						</xsd:complexType>
					</xsd:element>
				</xsd:sequence>
			</xsd:extension>
		</xsd:complexContent>
	</xsd:complexType>
	<xsd:element name="EpisodicComponentReport">
		<xsd:annotation>
			<xsd:documentation>EpisodicComponentReport is an msg:AbstractComponentReport that is delivered episodically. It is sent if at least one pm:AbstractComponentState has changed. It SHALL contain only pm:AbstractComponentState instances where at least one child ELEMENT or ATTRIBUTE have changed.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractComponentReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="PeriodicComponentReport">
		<xsd:annotation>
			<xsd:documentation>PeriodicComponentReport is an msg:AbstractComponentReport that is delivered periodically.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractComponentReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Sub-section: Alert Reports-->
	<xsd:complexType name="AbstractAlertReport">
		<xsd:annotation>
			<xsd:documentation>AbstractAlertReport is a change report that contains updated pm:AbstractAlertState instances.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexContent>
			<xsd:extension base="msg:AbstractReport">
				<xsd:sequence>
					<xsd:element name="ReportPart" minOccurs="0" maxOccurs="unbounded">
						<xsd:annotation>
							<xsd:documentation>List of report containers associated to one MDS.</xsd:documentation>
						</xsd:annotation>
						<xsd:complexType>
							<xsd:complexContent>
								<xsd:extension base="msg:AbstractReportPart">
									<xsd:sequence>
										<xsd:element name="AlertState" type="pm:AbstractAlertState" minOccurs="0" maxOccurs="unbounded">
											<xsd:annotation>
												<xsd:documentation>List of changed pm:AbstractAlertState instances.</xsd:documentation>
											</xsd:annotation>
										</xsd:element>
									</xsd:sequence>
								</xsd:extension>
							</xsd:complexContent>
						</xsd:complexType>
					</xsd:element>
				</xsd:sequence>
			</xsd:extension>
		</xsd:complexContent>
	</xsd:complexType>
	<xsd:element name="EpisodicAlertReport">
		<xsd:annotation>
			<xsd:documentation>EpisodicAlertReport is an msg:AbstractAlertReport that is delivered episodically. It is sent if at least one pm:AbstractAlertState has changed. It SHALL contain only pm:AbstractAlertState instances where at least one child ELEMENT or ATTRIBUTE have changed.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractAlertReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="PeriodicAlertReport">
		<xsd:annotation>
			<xsd:documentation>PeriodicAlertReport is an msg:AbstractAlertReport that is delivered periodically.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractAlertReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Sub-section: Operation State Reports-->
	<xsd:complexType name="AbstractOperationalStateReport">
		<xsd:annotation>
			<xsd:documentation>AbstractOperationalStateReport is a change report that contains updated pm:AbstractOperationState instances.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexContent>
			<xsd:extension base="msg:AbstractReport">
				<xsd:sequence>
					<xsd:element name="ReportPart" minOccurs="0" maxOccurs="unbounded">
						<xsd:annotation>
							<xsd:documentation>List of report containers associated to one MDS.</xsd:documentation>
						</xsd:annotation>
						<xsd:complexType>
							<xsd:complexContent>
								<xsd:extension base="msg:AbstractReportPart">
									<xsd:sequence>
										<xsd:element name="OperationState" type="pm:AbstractOperationState" minOccurs="0" maxOccurs="unbounded">
											<xsd:annotation>
												<xsd:documentation>List of changed pm:AbstractOperationState instances.</xsd:documentation>
											</xsd:annotation>
										</xsd:element>
									</xsd:sequence>
								</xsd:extension>
							</xsd:complexContent>
						</xsd:complexType>
					</xsd:element>
				</xsd:sequence>
			</xsd:extension>
		</xsd:complexContent>
	</xsd:complexType>
	<xsd:element name="EpisodicOperationalStateReport">
		<xsd:annotation>
			<xsd:documentation>EpisodicOperationalStateReport is an msg:AbstractOperationalStateReport that is delivered episodically. It is sent if at least one pm:AbstractOperationState has changed. It SHALL contain only pm:AbstractOperationState instances where at least one child ELEMENT or ATTRIBUTE have changed.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractOperationalStateReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="PeriodicOperationalStateReport">
		<xsd:annotation>
			<xsd:documentation>PeriodicOperationalStateReport is an msg:AbstractOperationalStateReport that is delivered periodically.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractOperationalStateReport"/>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Sub-section: System Error Reports-->
	<xsd:element name="SystemErrorReport">
		<xsd:annotation>
			<xsd:documentation>SystemErrorReport is an msg:AbstractReport. It is sent episodically when a system error has occurred.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractReport">
					<xsd:sequence>
						<xsd:element name="ReportPart" minOccurs="1" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>List of report containers associated to one MDS. Every report part contains an error code plus an OPTIONAL, human-readable description.</xsd:documentation>
							</xsd:annotation>
							<xsd:complexType>
								<xsd:complexContent>
									<xsd:extension base="msg:AbstractReportPart">
										<xsd:sequence>
											<xsd:element name="ErrorCode" type="pm:CodedValue">
												<xsd:annotation>
													<xsd:documentation>CODED VALUE of the error.</xsd:documentation>
												</xsd:annotation>
											</xsd:element>
											<xsd:element name="ErrorInfo" type="pm:LocalizedText" minOccurs="0">
												<xsd:annotation>
													<xsd:documentation>Additional textual information. ErrorInfo SHALL NOT make use of the pm:LocalizedTextType/@Ref ATTRIBUTE.</xsd:documentation>
												</xsd:annotation>
											</xsd:element>
										</xsd:sequence>
									</xsd:extension>
								</xsd:complexContent>
							</xsd:complexType>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: DescriptionEvent-->
	<xsd:simpleType name="DescriptionModificationType">
		<xsd:annotation>
			<xsd:documentation>DescriptionModificationType designates the modification mode when a msg:DescriptionModificationReport is sent.</xsd:documentation>
		</xsd:annotation>
		<xsd:restriction base="xsd:string">
			<xsd:enumeration value="Crt">
				<xsd:annotation>
					<xsd:documentation>Crt = Created. Indicates that the object transmitted by a modification MESSAGE has been created, i.e. inserted into the MDIB.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Upt">
				<xsd:annotation>
					<xsd:documentation>Upt = Updated. Indicates that the object transmitted by a modification MESSAGE has been updated.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Del">
				<xsd:annotation>
					<xsd:documentation>Del = Deleted. Indicates that the object transmitted by a modification MESSAGE has been deleted, i.e. removed from the MDIB.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
		</xsd:restriction>
	</xsd:simpleType>
	<xsd:element name="DescriptionModificationReport">
		<xsd:annotation>
			<xsd:documentation>DescriptionModificationReport is an msg:AbstractReport that is delivered episodically. It is sent if at least one pm:AbstractDescriptor has changed. It SHALL contain only pm:AbstractDescriptor instances where at least one child ELEMENT or ATTRIBUTE have changed, i.e., inserted, updated, or deleted.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractReport">
					<xsd:sequence>
						<xsd:element name="ReportPart" maxOccurs="unbounded">
							<xsd:annotation/>
							<xsd:complexType>
								<xsd:annotation>
									<xsd:documentation>List of report containers associated to one MDS.</xsd:documentation>
								</xsd:annotation>
								<xsd:complexContent>
									<xsd:extension base="msg:AbstractReportPart">
										<xsd:sequence>
											<xsd:element name="Descriptor" type="pm:AbstractDescriptor" minOccurs="0" maxOccurs="unbounded">
												<xsd:annotation>
													<xsd:documentation>Descriptor that was inserted into, updated from or deleted from the MDIB. The mode is stored in the ./@ModificationType ATTRIBUTE.

__R5024: Descriptors in this list SHALL not include nested descriptors.__

NOTE—If nested descriptors are also modified, then they can be included as children of the report part.

__R5025: Updated descriptors SHALL be ordered in the way that parent descriptors appear before child descriptors.__

__R5046: If a parent descriptor is deleted, then all child descriptors of that parent SHALL communicated as deleted in advance.__</xsd:documentation>
												</xsd:annotation>
											</xsd:element>
											<xsd:element name="State" type="pm:AbstractState" minOccurs="0" maxOccurs="unbounded">
												<xsd:annotation>
													<xsd:documentation>The descriptor's corresponding state(s).

__R5051: If ./@ModificationType is "Crt", then the descriptor version referenced by State SHALL match the descriptor given in ./Descriptor.__

__R5052: If ./@ModificationType is "Upt", then the descriptor version referenced by State SHALL match the descriptor given in ./Descriptor.__

__R5053: If ./@ModificationType is "Del", then State SHALL be omitted from the MESSAGE.__</xsd:documentation>
												</xsd:annotation>
											</xsd:element>
										</xsd:sequence>
										<xsd:attribute name="ParentDescriptor" type="pm:HandleRef" use="optional">
											<xsd:annotation>
												<xsd:documentation>The HANDLE reference of the parent descriptor. The HANDLE reference SHALL be empty if an pm:MdsDescriptor is inserted, updated or deleted.</xsd:documentation>
											</xsd:annotation>
										</xsd:attribute>
										<xsd:attribute name="ModificationType" type="msg:DescriptionModificationType" use="optional">
											<xsd:annotation>
												<xsd:documentation>Determines if the descriptor stored in ./msg:Descriptor has been inserted into, updated from or deleted from the MDIB. The implied value SHALL be "Upt".</xsd:documentation>
											</xsd:annotation>
										</xsd:attribute>
									</xsd:extension>
								</xsd:complexContent>
							</xsd:complexType>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: Waveform-->
	<xsd:element name="WaveformStream">
		<xsd:annotation>
			<xsd:documentation>The WaveformStream MESSAGE is sent in order to transmit a set of samples of one or more waveforms.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractReport">
					<xsd:sequence>
						<xsd:element name="State" type="pm:RealTimeSampleArrayMetricState" minOccurs="0" maxOccurs="unbounded">
							<xsd:annotation>
								<xsd:documentation>State represents a list of sample arrays of a waveform.</xsd:documentation>
							</xsd:annotation>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<xsd:element name="ObservedValueStream">
		<xsd:annotation>
			<xsd:documentation>The ObservedValueStream MESSAGE is sent in order to transmit observed values of one or more waveforms. This object MAY be used for optimized waveform value transmission.

__R5026: If ObservedValueStream is supported, any changes to the observed value of pm:RealTimeSampleArrayMetricState SHALL be reported by ObservedValueStream while other changes are reported through pm:WaveformStream.__</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:complexContent>
				<xsd:extension base="msg:AbstractReport">
					<xsd:sequence>
						<xsd:element name="Value" minOccurs="0" maxOccurs="unbounded">
							<xsd:complexType>
								<xsd:annotation>
									<xsd:documentation>A stream ELEMENT that contains observed values of a stream-able state.</xsd:documentation>
								</xsd:annotation>
								<xsd:sequence>
									<xsd:element name="Value" type="pm:SampleArrayValue" minOccurs="0" maxOccurs="1"/>
								</xsd:sequence>
								<xsd:attribute name="Metric" type="pm:HandleRef" use="required">
									<xsd:annotation>
										<xsd:documentation>Handle reference to the descriptor the observed values belong to.</xsd:documentation>
									</xsd:annotation>
								</xsd:attribute>
								<xsd:attribute name="StateVersion" type="pm:VersionCounter" use="optional">
									<xsd:annotation>
										<xsd:documentation>Version number of the state. The implied value SHALL be "0".</xsd:documentation>
									</xsd:annotation>
								</xsd:attribute>
							</xsd:complexType>
						</xsd:element>
					</xsd:sequence>
				</xsd:extension>
			</xsd:complexContent>
		</xsd:complexType>
	</xsd:element>
	<!--Section: Retrievability Method-->
	<xsd:simpleType name="RetrievabilityMethod">
		<xsd:annotation>
			<xsd:documentation>The method on how it is retrieve the information about a state.</xsd:documentation>
		</xsd:annotation>
		<xsd:restriction base="xsd:string">
			<xsd:enumeration value="Get">
				<xsd:annotation>
					<xsd:documentation>The CONTAINMENT TREE ENTRY is retrievable via a get request. Use the corresponding get MESSAGE.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Per">
				<xsd:annotation>
					<xsd:documentation>Per = Periodic. The CONTAINMENT TREE ENTRY is retrievable via a periodic event report. Use the corresponding periodic event report MESSAGE (e.g., pm:PeriodicMetricReport).</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Ep">
				<xsd:annotation>
					<xsd:documentation>Ep = Episodic. The CONTAINMENT TREE ENTRY is retrievable via an episodic event report. Use the corresponding episodic event report MESSAGE (e.g., pm:EpisodicMetricReport).</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
			<xsd:enumeration value="Strm">
				<xsd:annotation>
					<xsd:documentation>Strm = Stream. The CONTAINMENT TREE ENTRY is retrievable via a waveform stream. Use the msg:WaveformStream or msg:ObservedValueStream MESSAGE.</xsd:documentation>
				</xsd:annotation>
			</xsd:enumeration>
		</xsd:restriction>
	</xsd:simpleType>
	<xsd:complexType name="RetrievabilityInfo">
		<xsd:annotation>
			<xsd:documentation>Retrievability provides information on how it is possible to access a state.</xsd:documentation>
		</xsd:annotation>
		<xsd:sequence>
			<xsd:sequence>
				<xsd:element ref="ext:Extension" minOccurs="0"/>
			</xsd:sequence>
		</xsd:sequence>
		<xsd:attribute name="Method" type="msg:RetrievabilityMethod" use="required">
			<xsd:annotation>
				<xsd:documentation>The method on how to retrieve a state.</xsd:documentation>
			</xsd:annotation>
		</xsd:attribute>
		<xsd:attribute name="UpdatePeriod" type="xsd:duration">
			<xsd:annotation>
				<xsd:documentation>The periodicity in which updates can be expected to be communicated as a periodic event. The implied value SHALL be "PT1S".</xsd:documentation>
			</xsd:annotation>
		</xsd:attribute>
	</xsd:complexType>
	<xsd:element name="Retrievability">
		<xsd:annotation>
			<xsd:documentation>Extension point that SHOULD be included as a pm:AbstractMetricDescriptor extension to describe METRIC retrievability (see msg:RetrievabilityMethod). Since a METRIC might be retrievable by several methods, Retrievability comprises a list of msg:RetrievabilityInfo ELEMENTs.</xsd:documentation>
		</xsd:annotation>
		<xsd:complexType>
			<xsd:sequence>
				<xsd:element name="By" type="msg:RetrievabilityInfo" minOccurs="0" maxOccurs="unbounded">
					<xsd:annotation>
						<xsd:documentation>Retrievability information set.</xsd:documentation>
					</xsd:annotation>
				</xsd:element>
			</xsd:sequence>
		</xsd:complexType>
	</xsd:element>
</xsd:schema>)");

}
#endif