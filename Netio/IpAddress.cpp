//
//  IpAddress.cpp
//  Netio
//
//  Created by Sadullah Nader on 12/24/11.
//  Copyright (c) 2011 F9E. All rights reserved.
//

#include <netinet/in.h>
#include "IpAddress.h"

namespace netio 
{
	IpAddress::IpAddress(std::string addressString, unsigned short port)
	: m_addressString(addressString), m_port(port)
	{
	}
	
	IpAddress::IpAddress(sockaddr_in & addressAndPort)
	{
		
	}
}