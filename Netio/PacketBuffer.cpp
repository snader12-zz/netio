#include "PacketBuffer.h"

namespace netio
{

PacketBuffer::PacketBuffer()
: m_buffer(nullptr)
, m_position(0)
, m_bitOffset(0)
, m_capacity(0)
{
	
}

PacketBuffer::PacketBuffer(size_t bufferCapacity)
{
	
}

PacketBuffer::~PacketBuffer()
{
	if (m_buffer)
		delete[] m_buffer;
	m_position = 0;
	m_capacity = 0;
}
}