//
//  ReadPacketBuffer.cpp
//  Netio
//
//  Created by Sadullah Nader on 8/15/14.
//  Copyright (c) 2014. All rights reserved.
//

#include "ReadPacketBuffer.h"

namespace netio
{

ReadPacketBuffer::ReadResult ReadPacketBuffer::readBits(char *byteArray, size_t bytesToRead)
{
	if (getPosition() == 0)
		return ReadResult_Empty;
	if (getSize() < bytesToRead)
		memcpy(byteArray, m_buffer, getSize());
	else
		memcpy(byteArray, m_buffer, bytesToRead);
	
	return ReadResult_Empty;
}
	
ReadPacketBuffer::ReadResult ReadPacketBuffer::readFloat(float &number)
{
	return  ReadResult_Success;
}

ReadPacketBuffer::ReadResult ReadPacketBuffer::readCompressedFloat(float &number)
{
    return ReadResult_Success;
}

ReadPacketBuffer::ReadResult ReadPacketBuffer::readInt(int32_t &number, size_t bitsToRead)
{
    return ReadResult_Success;
}

ReadPacketBuffer::ReadResult ReadPacketBuffer::readDouble(double &number)
{
    return ReadResult_Success;
}

	
}