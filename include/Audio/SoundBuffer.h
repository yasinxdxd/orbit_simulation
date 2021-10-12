#ifndef GO_SOUNDBUFFER_H
#define GO_SOUNDBUFFER_H

#include "Core/Definitions.h"

namespace go
{

	class SoundBuffer
	{
	public:
		SoundBuffer();
		SoundBuffer(GOcchar* file_path);
		~SoundBuffer();
	public:
		void loadFromFile(GOcchar* file_path);
	private:
		GOuint m_buffer;
		GOuint m_channel, m_sample_rate, m_bps, m_size;
		char* m_data;
		GOuint m_format;
	
	friend class SoundSource;
	};

}


#endif // GO_SOUNDBUFFER_H