#ifndef GO_SOUNDSOURCE_H
#define GO_SOUNDSOURCE_H

#include "SoundBuffer.h"

namespace go
{
	
	class SoundSource
	{
	public:
		SoundSource();
		SoundSource(go::SoundBuffer& soundBuffer);
		~SoundSource();

	public:
		//setters:
		void setSoundBuffer(go::SoundBuffer& soundBuffer);
		void play();
		void stop();

		//getters:
		SoundBuffer getSoundBuffer() const;

	private:
		GOuint m_source;
		SoundBuffer* m_SoundBuffer;
	};
}


#endif // GO_SOUNDSOURCE_H