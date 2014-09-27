#pragma once

//
//  ReadPacketBuffer.h
//  Netio
//
//  Created by Sadullah Nader on 8/15/14.
//  Copyright (c) 2014 F9E. All rights reserved.
//

#include <iostream>
#include "PacketBuffer.h"

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
	
private:
	
};