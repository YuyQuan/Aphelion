#include "file.h"
#include "log.h"
#include <cstdio>
#include <cstring>
#include <cstdarg>

namespace aphelion
{
	namespace utilities
	{
		const char* readFile(const char* pFilePath)
		{
			FILE* file = fopen(pFilePath, "rb");

			if(!file) {
				logError("Failed to find %s, returning empty string!\n", pFilePath);
				
				return nullptr;
			}

			fseek(file, 0, SEEK_END);

			long length = ftell(file);

			char* result = new char[length + 1];

			memset(result, 0, length + 1);

			fseek(file, 0, SEEK_SET);
			fread(result, 1, length, file);
			fclose(file);

			return result;
		}

		void writeToFile(const char* pFilePath, const char* pMessage, ...)
		{
			va_list vl;

			va_start(vl, pMessage);
			
			FILE* file = fopen(pFilePath, "ab");

			if(!file) {
				logWarning("Failed to find %s, creating file!\n", pFilePath);
			}

			vfprintf(file, pMessage, vl);

			fclose(file);

			va_end(vl);
		}
	}
}