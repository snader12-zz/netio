//
//  UdpSocket.h
//  Netio
//
//  Created by Sadullah Nader on 11/18/11.
//  Copyright 2011. All rights reserved.
//

#ifndef Netio_UdpSocket_h
#define Netio_UdpSocket_h

#include "Transport.h"

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
    UdpSocket(const Endpoint & address);
    ~UdpSocket();
    
    void setEndpoint(const Endpoint &endpoint);
    const Endpoint & getEndpoint() { return m_endpoint; }
    
    bool open();
    bool close();
    
    bool toggleBlocking(bool blocking);
    bool isBlocking();
   
    bool setBufferSize(Direction bufferDirection, size_t bufferSize);
    size_t getBufferSize(Direction bufferDirection);
    
    bool send(const Endpoint &remoteEndpoint, const PacketBuffer & sendBuffer);
    
	bool recv(Endpoint &remoteEndpoint, PacketBuffer & sendBuffer);
    
private:    
    int m_socket;
    Endpoint m_endpoint;
};

}
    
#endif
