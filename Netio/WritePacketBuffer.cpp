//
//  WritePacketBuffer.cpp
//  Netio
//
//  Created by Sadullah Nader on 10/11/14.
//  Copyright (c) 2014. All rights reserved.
//

#include "WritePacketBuffer.h"

namespace netio
{

WritePacketBuffer::WritePacketBuffer()
{
    
}

WritePacketBuffer::~WritePacketBuffer()
{
    
}

WritePacketBuffer::WriteResult WritePacketBuffer::writeBits(char *byteArray, size_t bitsToWrite)
{
    return WriteResult_Success;
}

WritePacketBuffer::WriteResult WritePacketBuffer::writeFloat(float number, size_t bitsToWrite)
{
    return WriteResult_Success;
}

WritePacketBuffer::WriteResult WritePacketBuffer::writeInt(int number, size_t bitsToWrite)
{
    return WriteResult_Success;
}

WritePacketBuffer::WriteResult WritePacketBuffer::writeDouble(double number, size_t bitsToWrite)
{
    return WriteResult_Success;
}

}