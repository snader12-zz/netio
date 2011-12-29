//
//  Buffer.h
//  Netio
//
//  Created by Sadullah Nader on 12/26/11.
//  Copyright (c) 2011. All rights reserved.
//

#ifndef Netio_Buffer_h
#define Netio_Buffer_h

namespace netio 
{

class PacketBuffer
{
public:
	PacketBuffer();
	~PacketBuffer();
	size_t getCapacity() { return m_capacity; }
	size_t getSize() { return m_size; }
	const void * getRawBuffer() { return m_buffer; }
	//void 
private:
	size_t m_capacity;
	size_t m_size;
	char *m_buffer;
};

}

#endif
