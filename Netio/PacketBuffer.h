#pragma once

//
//  Buffer.h
//  Netio
//
//  Created by Sadullah Nader on 12/26/11.
//  Copyright (c) 2011. All rights reserved.
//

#include "Transport.h"

namespace netio 
{

class PacketBuffer
{
public:
	
	enum WriteResult
	{
		WriteResult_Success,
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
	ReadResult readFloat(float &number, size_t bitsToRead);
	ReadResult readInt(int32_t &number, size_t bitsToRead);
	double readDouble(size_t bitsToRead);
	
	WriteResult writeBits(char *byteArray, size_t bitsToWrite);
	WriteResult writeFloat(float number, size_t bitsToWrite);
	WriteResult writeInt(int number, size_t bitsToWrite);
	WriteResult writeDouble(double number, size_t bitsToWrite);
private:
	size_t m_capacity;
	size_t m_position;
	int32_t m_bitOffset;
	char *m_buffer;
};

}
