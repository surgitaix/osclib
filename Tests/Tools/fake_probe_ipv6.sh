printf "<soap:Envelope xmlns:soap=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:wsa=\"http://www.w3.org/2005/08/addressing\" xmlns:wsd=\"http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01\" xmlns:dpws=\"http://docs.oasis-open.org/ws-dd/ns/dpws/2009/01\" xmlns:i6=\"http://p11073-10207/draft8/msg/2017/08/07\"><soap:Header><wsa:MessageID>1c427d9d-d134-4c4f-90fa-7e196911fce7</wsa:MessageID><wsa:To>urn:docs-oasis-open-org:ws-dd:ns:discovery:2009:01</wsa:To><wsa:Action>http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/Probe</wsa:Action><wsd:AppSequence InstanceId=\"424238335\" MessageNumber=\"1\"/></soap:Header><soap:Body><wsd:Probe><wsd:Types>dpws:Device i6:MedicalDevice</wsd:Types><wsd:Scopes/></wsd:Probe></soap:Body></soap:Envelope>" | nc -un6 -i 1 -w 1 ff02::c%eth0 3702
