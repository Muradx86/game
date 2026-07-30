#ifndef PORT_H
#define PORT_H
#include "Types.h"
U0 OutU8(U16 port,U8 val);
U0 OutU16(U16 port,U16 val);
U8 InU8(U16 port);
U16 InU16(U16 port);
#endif
