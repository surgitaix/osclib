#ifndef SCHEMA_WSDISCOVERY_H
#define SCHEMA_WSDISCOVERY_H

#include <string.h>

namespace SCHEMA
{
const static std::string SCHEMA_WSDISCOVERY_NAME("wsdd-discovery-1.1-schema-os.xsd");

const static std::string SCHEMA_WSDISCOVERY_CONTENT = std::string(R"(<?xml version="1.0" encoding="UTF-8"?>
<!--
Copyright (c) OASIS(r) 2009. All Rights Reserved.

All capitalized terms in the following text have the meanings assigned to them in the OASIS Intellectual Property Rights Policy (the "OASIS IPR Policy"). The full Policy may be found at the OASIS website.

This document and translations of it may be copied and furnished to others, and derivative works that comment on or otherwise explain it or assist in its implementation may be prepared, copied, published, and distributed, in whole or in part, without restriction of any kind, provided that the above copyright notice and this section are included on all such copies and derivative works. However, this document itself may not be modified in any way, including by removing the copyright notice or references to OASIS, except as needed for the purpose of developing any document or deliverable produced by an OASIS Technical Committee (in which case the rules applicable to copyrights, as set forth in the OASIS IPR Policy, must be followed) or as required to translate it into languages other than English.

The limited permissions granted above are perpetual and will not be revoked by OASIS or its successors or assigns.

This document and the information contained herein is provided on an "AS IS" basis and OASIS DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY WARRANTY THAT THE USE OF THE INFORMATION HEREIN WILL NOT INFRINGE ANY OWNERSHIP RIGHTS OR ANY IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

OASIS requests that any OASIS Party or any other party that believes it has patent claims that would necessarily be infringed by implementations of this OASIS Committee Specification or OASIS Standard, to notify OASIS TC Administrator and provide an indication of its willingness to grant patent licenses to such patent claims in a manner consistent with the IPR Mode of the OASIS Technical Committee that produced this specification.

OASIS invites any party to contact the OASIS TC Administrator if it is aware of a claim of ownership of any patent claims that would necessarily be infringed by implementations of this specification by a patent holder that is not willing to provide a license to such patent claims in a manner consistent with the IPR Mode of the OASIS Technical Committee that produced this specification. OASIS may include such claims on its website, but disclaims any obligation to do so.

OASIS takes no position regarding the validity or scope of any intellectual property or other rights that might be claimed to pertain to the implementation or use of the technology described in this document or the extent to which any license under such rights might or might not be available; neither does it represent that it has made any effort to identify any such rights. Information on OASIS' procedures with respect to rights in any document or deliverable produced by an OASIS Technical Committee can be found on the OASIS website. Copies of claims of rights made available for publication and any assurances of licenses to be made available, or the result of an attempt made to obtain a general license or permission for the use of such proprietary rights by implementers or users of this OASIS Committee Specification or OASIS Standard, can be obtained from the OASIS TC Administrator. OASIS makes no representation that any information or list of intellectual property rights will at any time be complete, or that any claims in such list are, in fact, Essential Claims.

The name "OASIS" is trademarks of OASIS, the owner and developer of this specification, and should be used only to refer to the organization and its official outputs. OASIS welcomes reference to, and implementation and use of, specifications, while reserving the right to enforce its marks against misleading uses. Please see http://www.oasis-open.org/who/trademark.php for above guidance.
-->
<xs:schema targetNamespace="http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01" xmlns:tns="http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01" xmlns:wsa="http://www.w3.org/2005/08/addressing" xmlns:xs="http://www.w3.org/2001/XMLSchema" elementFormDefault="qualified" blockDefault="#all">

  <xs:import namespace="http://www.w3.org/2005/08/addressing" schemaLocation="ws-addressing.xsd"/>

  <!-- //////////////////// Discovery Messages //////////////////// -->

  <xs:element name="Hello" type="tns:HelloType"/>
  <xs:complexType name="HelloType">
    <xs:sequence>
      <xs:element ref="wsa:EndpointReference"/>
      <xs:element ref="tns:Types" minOccurs="0"/>
      <xs:element ref="tns:Scopes" minOccurs="0"/>
      <xs:element ref="tns:XAddrs" minOccurs="0"/>
      <xs:element ref="tns:MetadataVersion"/>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>

  <xs:element name="Bye" type="tns:ByeType"/>
  <xs:complexType name="ByeType">
    <xs:sequence>
      <xs:element ref="wsa:EndpointReference"/>
      <xs:element ref="tns:Types" minOccurs="0"/>
      <xs:element ref="tns:Scopes" minOccurs="0"/>
      <xs:element ref="tns:XAddrs" minOccurs="0"/>
      <xs:element ref="tns:MetadataVersion" minOccurs="0"/>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>

  <xs:element name="Probe" type="tns:ProbeType"/>
  <xs:complexType name="ProbeType">
    <xs:sequence>
      <xs:element ref="tns:Types" minOccurs="0"/>
      <xs:element ref="tns:Scopes" minOccurs="0"/>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>

  <xs:element name="ProbeMatches" type="tns:ProbeMatchesType"/>
  <xs:complexType name="ProbeMatchesType">
    <xs:sequence>
      <xs:element name="ProbeMatch" type="tns:ProbeMatchType" minOccurs="0" maxOccurs="unbounded">
      </xs:element>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>
  <xs:complexType name="ProbeMatchType">
    <xs:sequence>
      <xs:element ref="wsa:EndpointReference"/>
      <xs:element ref="tns:Types" minOccurs="0"/>
      <xs:element ref="tns:Scopes" minOccurs="0"/>
      <xs:element ref="tns:XAddrs" minOccurs="0"/>
      <xs:element ref="tns:MetadataVersion"/>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>

  <xs:element name="Resolve" type="tns:ResolveType"/>
  <xs:complexType name="ResolveType">
    <xs:sequence>
      <xs:element ref="wsa:EndpointReference"/>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>

  <xs:element name="ResolveMatches" type="tns:ResolveMatchesType"/>
  <xs:complexType name="ResolveMatchesType">
    <xs:sequence>
      <xs:element name="ResolveMatch" type="tns:ResolveMatchType" minOccurs="0"/>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>
  <xs:complexType name="ResolveMatchType">
    <xs:sequence>
      <xs:element ref="wsa:EndpointReference"/>
      <xs:element ref="tns:Types" minOccurs="0"/>
      <xs:element ref="tns:Scopes" minOccurs="0"/>
      <xs:element ref="tns:XAddrs" minOccurs="0"/>
      <xs:element ref="tns:MetadataVersion"/>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType>

  <xs:element name="Types" type="tns:QNameListType"/>
  <xs:simpleType name="QNameListType">
    <xs:list itemType="xs:QName"/>
  </xs:simpleType>

  <xs:element name="Scopes" type="tns:ScopesType"/>
  <xs:complexType name="ScopesType">
    <xs:simpleContent>
      <xs:extension base="tns:UriListType">
        <xs:attribute name="MatchBy" type="xs:anyURI"/>
        <xs:anyAttribute namespace="##other" processContents="lax"/>
      </xs:extension>
    </xs:simpleContent>
  </xs:complexType>

  <xs:element name="XAddrs" type="tns:UriListType"/>
  <xs:simpleType name="UriListType">
    <xs:list itemType="xs:anyURI"/>
  </xs:simpleType>

  <xs:element name="MetadataVersion" type="xs:unsignedInt"/>

  <!-- //////////////////// Faults //////////////////// -->

  <xs:simpleType name="FaultCodeType">
	<xs:restriction base="xs:QName">
	  <xs:enumeration value="tns:MatchingRuleNotSupported"/>
	</xs:restriction>
  </xs:simpleType>
  <xs:simpleType name="FaultCodeOpenType">
    <xs:union memberTypes="tns:FaultCodeType xs:QName"/>
  </xs:simpleType>

  <xs:element name="SupportedMatchingRules" type="tns:UriListType"/>

  <!-- //////////////////// Compact Signature //////////////////// -->

  <xs:attribute name="Id" type="xs:ID"/>

  <xs:element name="Security" type="tns:SecurityType"/>
  <xs:complexType name="SecurityType">
    <xs:sequence>
      <xs:element ref="tns:Sig" minOccurs="0"/>
    </xs:sequence>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType> 

  <xs:element name="Sig" type="tns:SigType"/>
  <xs:complexType name="SigType">
    <xs:sequence>
      <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
    </xs:sequence>
    <xs:attribute name="Scheme" type="xs:anyURI" use="required"/>
    <xs:attribute name="KeyId" type="xs:base64Binary"/>
    <xs:attribute name="Refs" type="xs:IDREFS" use="required"/>
    <xs:attribute name="Sig" type="xs:base64Binary" use="required"/>
    <xs:anyAttribute namespace="##other" processContents="lax"/>
  </xs:complexType> 

  <!-- //////////////////// General Headers //////////////////// -->

  <xs:element name="AppSequence" type="tns:AppSequenceType"/>
  <xs:complexType name="AppSequenceType">
    <xs:complexContent>
      <xs:restriction base="xs:anyType">
        <xs:attribute name="InstanceId" type="xs:unsignedInt" use="required"/>
        <xs:attribute name="SequenceId" type="xs:anyURI"/>
        <xs:attribute name="MessageNumber" type="xs:unsignedInt" use="required"/>
        <xs:anyAttribute namespace="##other" processContents="lax"/>
      </xs:restriction>
    </xs:complexContent>
  </xs:complexType>

</xs:schema>)");

}
#endif
