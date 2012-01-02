#include "PacketBuffer.h"

namespace netio
{

PacketBuffer::PacketBuffer()
: m_buffer(nullptr)
, m_size(0)
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
	m_size = 0;
	m_capacity = 0;
}

}