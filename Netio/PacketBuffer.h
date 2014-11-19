#pragma once

//
//  Buffer.h
//  Netio
//
//  Created by Sadullah Nader on 12/26/11.
//  Copyright (c) 2011. All rights reserved.
//

#include "Transport.h"
#include <numeric>
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
	size_t getSize() { return m_position; }
protected:
	size_t getPosition() { return m_position; }
	void setPosition(size_t position) { m_position = position; }
private:
	size_t m_capacity;
	size_t m_position;
	uint8_t m_bitOffset;
	char *m_buffer;
};

}
