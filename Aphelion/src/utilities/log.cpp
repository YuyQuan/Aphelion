#include "log.h"
#include <cstdio>
#include <cstdarg>

namespace aphelion
{
	namespace utilities
	{
		void logMessage(const char* pMessage, ...)
		{
			va_list vl;

			va_start(vl, pMessage);
			
			vprintf(pMessage, vl);
			
			va_end(vl);
		}
	}
}
