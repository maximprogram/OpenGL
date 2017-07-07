#include "../include/mbWindow_sdl.h"
#include <iostream>



// Constructor //
mbWindow_sdl::mbWindow_sdl(int w , int h, const std::string& str)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    this->m_window = SDL_CreateWindow(str.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_OPENGL);
    this->m_glContext = SDL_GL_CreateContext(this->m_window);


    unsigned int statusGL = glewInit();

    if(statusGL != GLEW_OK){
        std::cerr<<"Library GLEW failed to initialize!" << std::endl;
    }


    this->m_isClose = false;

    std::cout << "mbEngineFirst \"OpenGL + SDL\" " << std::endl << std::endl;


}


// Destructor //
mbWindow_sdl::~mbWindow_sdl()
{
    SDL_GL_DeleteContext(this->m_glContext);
    SDL_DestroyWindow(this->m_window);
    SDL_Quit();
}




mbWindow_sdl::mbWindow_sdl(const mbWindow_sdl& other)
{

}

mbWindow_sdl& mbWindow_sdl::operator=(const mbWindow_sdl& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


// function: IsClosed //
bool mbWindow_sdl::IsClosed()
{
    return this->m_isClose;
}


// function: ClearWindow //
void mbWindow_sdl::ClearWindow(float r,float g,float b)
{
    glClearColor(r,g,b,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


// function: Update //
void mbWindow_sdl::Update()
{
    SDL_GL_SwapWindow(this->m_window);

    SDL_Event e;


    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
            this->m_isClose = true;

    }
}
