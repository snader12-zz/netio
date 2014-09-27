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
	
PacketBuffer::ReadResult PacketBuffer::readBits(char *byteArray, size_t bitsToRead)
{
	if (m_ == 0)
		return ReadResult_Empty;
	if (m_size < bitsToRead)
		memcpy(byteArray, m_buffer, m_size);
	else
		memcpy(byteArray, m_buffer, bitsToRead);
	
	return ReadResult_Empty;
}
	
PacketBuffer::ReadResult PacketBuffer::readInt(int32_t &number, size_t bitsToRead)
{
	if (m_size < sizeof()
	return ReadResult_Success;
}
	
PacketBuffer::ReadResult PacketBuffer::readFloat(float &number, size_t bitsToRead)
{
	return  ReadResult_Success;
}
	
PacketBuffer::WriteResult PacketBuffer::writeBits(char *byteArray, size_t bitsToWrite)
{
	if (m_size >= m_capacity)
		return WriteResult_Full;
//	else if (
	
	return WriteResult_Success;
}

}