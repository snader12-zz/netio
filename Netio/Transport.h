/* 
 * File:   Transport.h
 * Author: snader12
 *
 * Created on January 1, 2012, 11:48 PM
 */

#ifndef TRANSPORT_H
#define	TRANSPORT_H

#ifndef __clang__
#if (__GNUC__ == 4) && (__GNUC_MINOR__ < 6)
const int nullptr = 0;
#endif
#endif

#include <cstring>

#include "Endpoint.h"
#include "PacketBuffer.h"

#endif	/* TRANSPORT_H */

