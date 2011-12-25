//
//  IpAddress.h
//  Netio
//
//  Created by Sadullah Nader on 11/19/11.
//  Copyright 2011 F9E. All rights reserved.
//

#ifndef Netio_IpAddress_h
#define Netio_IpAddress_h

#include <string>

namespace netio
{

class IpAddress
{
public:
    // addressString : should be formatted as a dotted ip address, e.g. "X.X.X.X"
    IpAddress(std::string addressString, unsigned short port);
    IpAddress(sockaddr_in & addressAndPort);
	const std::string & getAddress() { return m_addressString; }
    unsigned short getPort() { return m_port; }
    sockaddr_in toSockAddrIn();
private:
	std::string m_addressString;
    unsigned short m_port;
};

}

#endif
