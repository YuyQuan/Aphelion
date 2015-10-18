#ifndef APHELION_UTILITIES_FILE
#define APHELION_UTILITIES_FILE

namespace aphelion
{
	namespace utilities
	{
		extern const char* readFile(const char* pFilePath);
		
		extern void writeToFile(const char* pFilePath, const char* pMessage, ...);
	}
}

#endif // APHELION_UTILITIES_FILE