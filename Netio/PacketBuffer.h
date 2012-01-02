//
//  Buffer.h
//  Netio
//
//  Created by Sadullah Nader on 12/26/11.
//  Copyright (c) 2011. All rights reserved.
//

#ifndef Netio_PacketBuffer_h
#define Netio_PacketBuffer_h

#include <cstddef>

namespace netio 
{

class PacketBuffer
{
public:
	PacketBuffer();
	PacketBuffer(size_t bufferCapacity);
	~PacketBuffer();
	size_t getCapacity() { return m_capacity; }
	size_t getSize() { return m_size; }
	const void * getRawBuffer() { return m_buffer; }
	void readBits(char *byteArray, size_t bitsToRead);
	void writeBits(char *byteArray, size_t bitsToWrite);
private:
	size_t m_capacity;
	size_t m_size;
	char *m_buffer;
};

}

#endif
