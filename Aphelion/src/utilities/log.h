#ifndef APHELION_UTILITIES_LOG
#define APHELION_UTILITIES_LOG

namespace aphelion
{
	namespace utilities
	{
		extern void logMessage(const char* pMessage, ...);
		extern void logWarning(const char* pWarning, ...);
		extern void logError(const char* pError, ...);
	}
}

#endif // APHELION_UTILITIES_LOG
