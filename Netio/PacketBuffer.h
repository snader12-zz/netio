//
//  Buffer.h
//  Netio
//
//  Created by Sadullah Nader on 12/26/11.
//  Copyright (c) 2011. All rights reserved.
//

#ifndef Netio_PacketBuffer_h
#define Netio_PacketBuffer_h

#include "Transport.h"
#include <cstddef>

namespace netio 
{

class PacketBuffer
{
public:
	enum ReadResult
	{
		ReadResult_Empty,
		ReadResult_Partial,
		ReadResult_Full
	};
	
	enum WriteResult
	{
		WriteResult_Empty,
		WriteResult_Partial,
		WriteResult_Full
	};
	
	PacketBuffer();
	PacketBuffer(size_t bufferCapacity);
	~PacketBuffer();
	size_t getCapacity() { return m_capacity; }
	size_t getSize() { return m_size; }
	const void * getRawBuffer() { return m_buffer; }
	
	ReadResult readBits(char *byteArray, size_t bitsToRead);
	float readFloat(size_t bitsToRead);
	int readInt(size_t bitsToRead);
	double readDouble(size_t bitsToRead);
	
	WriteResult writeBits(char *byteArray, size_t bitsToWrite);
	WriteResult writeFloat(float number, size_t bitsToWrite);
	WriteResult writeInt(int number, size_t bitsToWrite);
	WriteResult writeDouble(double number, size_t bitsToWrite);
private:
	size_t m_capacity;
	size_t m_size;
	char *m_buffer;
};

}

#endif
