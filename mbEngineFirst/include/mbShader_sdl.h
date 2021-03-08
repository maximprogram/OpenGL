#ifndef MBSHADER_SDL_H
#define MBSHADER_SDL_H

/*==========================================
* Developer: Max
* GitHub: https://github.com/maxcccp
============================================*/

#include <string>
#include <GL/glew.h>



// Class: mbShader_sdl //
class mbShader_sdl
{
    public:
        mbShader_sdl(const std::string& fileName);
        void Bind();
        virtual ~mbShader_sdl();

    protected:

    private:
        static const unsigned int NUM_SHADER = 2;
        static const unsigned int NUM_UNIFORMS = 3;
        unsigned int m_program;
        unsigned int m_shaders[NUM_SHADER];
        unsigned int m_uniforms[NUM_UNIFORMS];


};

#endif // MBSHADER_SDL_H
