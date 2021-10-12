#ifndef GO_UTILS_H
#define GO_UTILS_H

#include <iostream>
#include <fstream>
#include <cstring>

namespace go
{
	namespace utils
	{

	   /*
		*static bool isBigIndian()
		*static int convertCharToInteger(char* buffer,  int length)
		*static char* loadWAV(const char* file_path, unsigned int& channel, unsigned int& sample_rate, unsigned int& bps, unsigned int& size)
		*
		*https://www.youtube.com/watch?v=tmVRpNFP9ys&list=WL&index=1&t=2293s
		*www.youtube.com/thecplusplusguy thanks for this tutorial :)
		*
		*/	


		static bool isBigIndian()
		{
			int a = 1;
			return ((char*)&a)[0];
		}

		static int convertCharToInteger(char* buffer,  int length)
		{
			int a = 0;
			if (isBigIndian)
				for (int i = 0; i < length; i++)
					((char*)&a)[i] = buffer[i];
			else
				for (int i = 0; i < length; i++)
					((char*)&a)[3-i] = buffer[i];
			return a;
		}


		static char* loadWAV(const char* file_path, unsigned int& channel, unsigned int& sample_rate, unsigned int& bps, unsigned int& size)
		{
			char buffer[4];
			std::ifstream in(file_path, std::ios::binary);
			in.read(buffer, 4);
			
			if (strncmp(buffer, "RIFF", 4) != 0)
			{
				std::cout << "Cannot find .WAV file!" << std::endl;
				return NULL;
			}

			in.read(buffer, 4); 
			in.read(buffer, 4); //WAVE
			in.read(buffer, 4); //fmt
			in.read(buffer, 4); //16
			in.read(buffer, 2); //1
			in.read(buffer, 2); 
			channel = convertCharToInteger(buffer, 2);
			in.read(buffer, 4);
			sample_rate = convertCharToInteger(buffer, 4);
			in.read(buffer, 4);
			in.read(buffer, 2);
			in.read(buffer, 2);
			bps = convertCharToInteger(buffer, 2);
			in.read(buffer, 4); //data
			in.read(buffer, 4);
			size = convertCharToInteger(buffer, 4);
			char* data = new char[size];
			in.read(data, size);

			return data;

		}


	}
}

#endif // GO_UTILS_H