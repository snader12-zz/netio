//
//  UdpSocket.cpp
//  Netio
//
//  Created by Sadullah Nader on 11/18/11.
//  Copyright 2011. All rights reserved.
//

#include "UdpSocket.h"

#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

namespace netio
{
	const int SOCKET_ERROR = -1;
	const int INVALID_SOCKET = -1;
    UdpSocket::UdpSocket()
		: m_endpoint("", 0), m_socket(INVALID_SOCKET)
    {
        
    }
	
	UdpSocket::UdpSocket(const Endpoint &endpoint)
		: m_endpoint(endpoint), m_socket(INVALID_SOCKET)
	{
		
	}
	
	void UdpSocket::setEndpoint(const netio::Endpoint &endpoint)
	{
		m_endpoint = endpoint;
	}
	
	bool UdpSocket::open()
	{
		m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (m_socket == INVALID_SOCKET)
		{
			// TODO: Add log here for failed socket creation
			return false;
		}
		
		if (m_endpoint.getAddress().compare("") != 0 || m_endpoint.getPort() != 0)
		{
			sockaddr_in sockAddress;
			memset(&sockAddress, 0, sizeof(sockAddress));
			sockAddress.sin_family = AF_INET;
			sockAddress.sin_len = sizeof(sockAddress);
			int result = inet_pton(AF_INET, m_endpoint.getAddress().c_str(), &sockAddress.sin_addr);
			if (result != SOCKET_ERROR)
			{
				// TODO: Add log here to show error
				return false;
			}
			sockAddress.sin_port = htons(m_endpoint.getPort());
			
			// bind the socket to the endpoint...
			
			result = bind(m_socket, (sockaddr *)&sockAddress, sizeof(sockAddress));
			if (result == SOCKET_ERROR)
			{
				// TODO: Add log here to show error
				return false;
			}
		}
		
		return true;
	}
	
	bool UdpSocket::close()
	{
		int result = ::close(m_socket);
		if (result == SOCKET_ERROR)
		{
			// TODO: Add log here to show error
			return false;
		}
		return true;
	}
	
	bool UdpSocket::toggleBlocking(bool blocking)
	{
		if (m_socket == INVALID_SOCKET)
		{
			// TODO: Add log here for bad socket
			return false;
		}
		
		int flags = fcntl(m_socket, F_GETFL);

		if (blocking)
			flags &= ~O_NONBLOCK;
		else
			flags |= O_NONBLOCK;
		
		if (fcntl(m_socket, F_SETFL, flags) == SOCKET_ERROR)
		{
			// TODO: Add log here to show error
			return false; 
		}
		return true;
	}
	
	bool UdpSocket::isBlocking()
	{
		if (m_socket == INVALID_SOCKET)
		{
			// TODO: Add log here to show a bad socket
			return false;
		}
		
		int flags = fcntl(m_socket, F_GETFL);
		if (flags & O_NONBLOCK)
			return true;
		return false;
	}
	bool UdpSocket::setBufferSize(Direction bufferDirection, size_t bufferSize)
	{
		if (m_socket == INVALID_SOCKET)
		{
			// TODO: Add log here to show a bad socket
			return false;
		}
		
		
		int result = setsockopt(m_socket, SOL_SOCKET, bufferDirection == Incoming ? SO_RCVBUF : SO_SNDBUF, &bufferSize, sizeof(bufferSize));
		if (result == SOCKET_ERROR)
		{
			// TODO: Add log here to show error
			return false;
		}
	
		return true;
	}
	
	size_t UdpSocket::getBufferSize(Direction bufferDirection)
	{
		if (m_socket == INVALID_SOCKET)
		{
			// TODO: Add log here to show a bad socket
			return 0;
		}
		size_t bufferSize;
		socklen_t lengthHolder;
		int result = getsockopt(m_socket, SOL_SOCKET, bufferDirection == Incoming ? SO_RCVBUF : SO_SNDBUF, &bufferSize, &lengthHolder);
		if (result == SOCKET_ERROR)
		{
			// TODO: Add log here to show error
			
		}
		return bufferSize;
	}
}