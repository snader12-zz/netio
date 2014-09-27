#pragma once

//
//  IpAddress.h
//  Netio
//
//  Created by Sadullah Nader on 11/19/11.
//  Copyright 2011. All rights reserved.
//
#include <string>
#include "Transport.h"

namespace netio
{

enum EndpointType
{
	EndpointType_None,
	EndpointType_Ipv4,
	EndpointType_Ipv6,
	EndpointType_Count
};
	
class Endpoint
{
public:
    
	// addressString should be formatted as a dotted ip address, e.g. "X.X.X.X"
	// port can be as is, i.e. port 12345.
	Endpoint();
	explicit Endpoint(std::string& addressString, uint16_t port, EndpointType addressType);
	explicit Endpoint(in_addr ipAddress, uint16_t port);
	Endpoint(const Endpoint &rhs);
	
	std::string getAddress();
    uint16_t getPort();
	
	EndpointType getEndpointType() { return m_type; }
	const sockaddr_in6& getAsIpv6Addr() { return m_address.ipv6; }
	const sockaddr_in& getAsIpv4Addr()  { return m_address.ipv4; }
	bool isValid() { return m_type != EndpointType_None; }
	
private:
	union Addr
	{
		sockaddr_in ipv4;
		sockaddr_in6 ipv6;
	};
	
	Addr m_address;
	EndpointType m_type;
};
	
uint8_t convertEndpointTypeToFamily(EndpointType type);

}

