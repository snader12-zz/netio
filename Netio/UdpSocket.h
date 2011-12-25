//
//  UdpSocket.h
//  Netio
//
//  Created by Sadullah Nader on 11/18/11.
//  Copyright 2011 F9E. All rights reserved.
//

#ifndef Netio_UdpSocket_h
#define Netio_UdpSocket_h

#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "IpAddress.h"

namespace netio
{

class UdpSocket
{
public:
    
    enum Direction
    {
        Incoming,
        Outgoing
    };
    
    UdpSocket();
    UdpSocket(IpAddress address);
    ~UdpSocket();
    
    void setAddress(IpAddress address);
    const IpAddress & getAddress();
    
    bool open();
    bool close();
    
    bool toggleBlocking(bool blocking);
    bool isBlocking();
   
    bool setBufferSize(Direction bufferDirection, size_t bufferSize);
    size_t getBufferSize(Direction bufferDirection);
    
    bool send(IpAddress address);
    bool recv(IpAddress address);
    
private:    
    int m_socket;
    IpAddress m_address;
};

}
    
#endif
