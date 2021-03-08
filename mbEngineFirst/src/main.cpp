#include "../include/mbWindow_sdl.h"


int main()
{
    // Create Window //
    mbWindow_sdl windowGL(800,600,"mbEngineFirst \"OpenGL + SDL\" ");


    // GAME LOOP //
    while(!windowGL.IsClosed())
    {
        windowGL.ClearWindow(0.3f,0.7f,0.5f);




        windowGL.Update();
    }

    return 0;
}
