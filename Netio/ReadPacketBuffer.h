#pragma once

//
//  ReadPacketBuffer.h
//  Netio
//
//  Created by Sadullah Nader on 8/15/14.
//  Copyright (c) 2014. All rights reserved.
//

#include <iostream>
#include "PacketBuffer.h"

namespace netio
{

class ReadPacketBuffer: public PacketBuffer
{
public:
	enum ReadResult
	{
		ReadResult_Success,
		ReadResult_Empty,
		ReadResult_Partial,
		ReadResult_Full
	};
	
	ReadPacketBuffer(char* data, size_t dataLength);
	
	ReadResult readBits(char *byteArray, size_t bytesToRead);
	ReadResult readFloat(float &number);
	ReadResult readCompressedFloat(float &number);
	ReadResult readInt(int32_t &number, size_t bitsToRead);
	double readDouble(size_t bitsToRead);
	
private:
	
};

}