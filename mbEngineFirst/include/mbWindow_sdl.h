#ifndef MBWINDOW_SDL_H
#define MBWINDOW_SDL_H

/*==========================================
* Developer: Maks
* GitHub: https://github.com/maximprogram
============================================*/


#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>




// Class: mbWindow_sdl//
class mbWindow_sdl
{
    public:
        mbWindow_sdl(int w , int h, const std::string& str);
        virtual ~mbWindow_sdl();

        void Update();
        void ClearWindow(float r,float g,float b);
        bool IsClosed();

        mbWindow_sdl(const mbWindow_sdl& other);
        mbWindow_sdl& operator=(const mbWindow_sdl& other);

    protected:

    private:

        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        bool m_isClose;
};

#endif // MBWINDOW_SDL_H
