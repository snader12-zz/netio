#pragma once

//
//  IpAddress.h
//  Netio
//
//  Created by Sadullah Nader on 11/19/11.
//  Copyright 2011. All rights reserved.
//

#include <string>

namespace netio
{

class Endpoint
{
public:
    // addressString should be formatted as a dotted ip address, e.g. "X.X.X.X"
	// port can be as is, i.e. port 12345.
	Endpoint(std::string addressString, uint16_t port)
		: m_addressString(addressString), m_port(port)
	{
	}
	
	Endpoint(uint32_t ipAddress, uint16_t port)
		: m_addressString(), m_port(port)
	{
		
	}
	
	Endpoint(const Endpoint &rhs)
		: m_addressString(rhs.m_addressString), m_port(rhs.m_port)
	{
	}
	
	
	const std::string & getAddress() { return m_addressString; }
    unsigned short getPort() { return m_port; }
private:
	std::string m_addressString;
    unsigned short m_port;
};

}

