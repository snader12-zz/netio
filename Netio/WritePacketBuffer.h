#pragma once

//
//  WritePacketBuffer.h
//  Netio
//
//  Created by Sadullah Nader on 10/11/14.
//  Copyright (c) 2014. All rights reserved.
//

#include <iostream>
#include "PacketBuffer.h"

namespace netio
{
class WritePacketBuffer: public PacketBuffer
{
public:
	enum WriteResult
	{
		WriteResult_Success,
		WriteResult_Empty,
		WriteResult_Partial,
		WriteResult_Full
	};
	
	WritePacketBuffer();
	~WritePacketBuffer();
	
	WriteResult writeBits(char *byteArray, size_t bitsToWrite);
	WriteResult writeFloat(float number, size_t bitsToWrite);
	WriteResult writeInt(int number, size_t bitsToWrite);
	WriteResult writeDouble(double number, size_t bitsToWrite);
	
private:
	
};
}