#include "Extern.h"
#include "Math.h"
F64 Sin(F64 deg)
{
	return SinWrapper((PI/180)*deg);
}
F64 Cos(F64 deg)
{
	return CosWrapper((PI/180)*deg);
}
