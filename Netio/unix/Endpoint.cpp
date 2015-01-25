//
//  Endpoint.cpp
//  Netio
//
//  Created by Sadullah Nader on 8/6/14.
//  Copyright (c) 2014. All rights reserved.
//

#include "Endpoint.h"
#include <iostream>

using namespace std;

namespace netio
{
	
uint8_t convertEndpointTypeToFamily(EndpointType type)
{
	switch (type)
	{
		case EndpointType_None:
			return AF_UNSPEC;
		case EndpointType_Ipv4:
			return AF_INET;
		case EndpointType_Ipv6:
			return AF_INET6;
		default:
			cerr << "Error converting endpoint type/n";
	}
	return AF_UNSPEC;
}

Endpoint::Endpoint()
	: m_type(EndpointType_None)
{
	memset(&m_address, 0, sizeof(m_address));
}

Endpoint::Endpoint(std::string& addressString, uint16_t port, EndpointType addressType)
	: m_type(addressType)
{
	memset(&m_address, 0, sizeof(m_address));
	int result = 0;
	switch (m_type)
	{
		case EndpointType_Ipv4:
			m_address.ipv4.sin_family = AF_INET;
			m_address.ipv4.sin_port = htons(port);
			result = inet_pton(m_address.ipv4.sin_family, addressString.c_str(), &m_address.ipv4.sin_addr);
			break;
		case EndpointType_Ipv6:
			m_address.ipv6.sin6_family = AF_INET6;
			m_address.ipv6.sin6_port = htons(port);
			result = inet_pton(m_address.ipv6.sin6_family, addressString.c_str(), &m_address.ipv6.sin6_addr);
			break;
		default:
			break;
	}
	
	if (result <= 0)
	{
		cerr << " failed to parse ip address: " << addressString << ", error code: " << result << endl;
		return;
	}
	
	
}

Endpoint::Endpoint(in_addr ipAddress, uint16_t port)
	: m_type(EndpointType_Ipv4)
{
	memset(&m_address, 0, sizeof(m_address));
	m_address.ipv4.sin_family = AF_INET;
	m_address.ipv4.sin_port = htons(port);
	m_address.ipv4.sin_addr = ipAddress;
}

Endpoint::Endpoint(const Endpoint &rhs)
	: m_type(rhs.m_type)
{
	switch (m_type)
	{
		case EndpointType_Ipv4:
		{
			m_address.ipv4 = rhs.m_address.ipv4;
			break;
		}
		case EndpointType_Ipv6:
		{
			m_address.ipv6 = rhs.m_address.ipv6;
			break;
		}
		default:
			cerr << "Why use an endpoint that has no type set?\n";
	}
}

std::string Endpoint::getAddress()
{
	const void* address = nullptr;
	int addressFamily = AF_UNSPEC;
	socklen_t addressSize = 0;
	
	switch (m_type)
	{
		case EndpointType_Ipv4:
		{
			addressFamily = m_address.ipv4.sin_family;
			address = static_cast<void*>(&m_address.ipv4.sin_addr);
			addressSize  = sizeof(m_address.ipv4.sin_addr);
			break;
		}
		case EndpointType_Ipv6:
		{
			addressFamily = m_address.ipv6.sin6_family;
			address = static_cast<void*>(&m_address.ipv6.sin6_addr);
			addressSize  = sizeof(m_address.ipv6.sin6_addr);
			break;
		}
		default:
			break;
	}
	if (addressFamily == AF_UNSPEC)
		return "";
	
	char addressStr[INET6_ADDRSTRLEN];
	memset(addressStr, 0, sizeof(addressStr));
	
	inet_ntop(addressFamily, address, addressStr, addressSize);
	if (addressStr[0] == 0)
		return "";
	
	return addressStr;
}

uint16_t Endpoint::getPort()
{
	uint16_t port = 0;
	
	switch (m_type)
	{
		case EndpointType_Ipv4:
		{
			
			port = m_address.ipv4.sin_port;
			break;
		}
		case EndpointType_Ipv6:
		{
			port = m_address.ipv6.sin6_port;
			break;
		}
		default:
			break;
	}
	
	return port;
}

}