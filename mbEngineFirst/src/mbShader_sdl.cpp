#include "../include/mbShader_sdl.h"
#include <iostream>
#include <fstream>



// Declarations Functions //
std::string LoadShader(const std::string& fileName);


// Constructor //
mbShader_sdl::mbShader_sdl(const std::string& fileName)
{

}

// Destructor //
mbShader_sdl::~mbShader_sdl()
{

}

// function: Bind //
void mbShader_sdl::Bind()
{

}


// function: LoaderSheder //
std::string LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;


    if(file.is_open()){
        while(file.good()){
            getline(file,line);
            output.append(line + "\n");
        }

    }
    else
        std::cerr << "Uneble to load shader: " << fileName << std::endl;



    return output;
}



// function: ShaderError //
void ShaderError(unsigned int _shader, unsigned int _flag, bool _isProgram, const std::string& errorMessage)
{
    int success = 0;
    char error[1024] = {0};

    if(_isProgram)
        glGetProgramiv(_shader,_flag,&success);
    else
        glGetProgramiv(_shader,_flag,&success);


    if(success == GL_FALSE){
        if(_isProgram)
            glGetProgramInfoLog(_shader,sizeof(error),NULL,error);
        else
            glGetProgramInfoLog(_shader,sizeof(error),NULL,error);

        std::cerr << "ErrorMessage" <<": '" << error << "'" << std::endl;

    }

}


// function: CreateShader //
unsigned int CreateShader(const std::string& _text, unsigned int _type)
{
    unsigned int shader = glCreateShader(_type);

    if(shader == 0)
        std::cerr << "Error compiling shader type" << _type << std::endl;

    const char* p[1];

    p[0] = _text.c_str();
    int lengths[1];
    lengths[0] = _text.length();

    glShaderSource(shader,1,p,lengths);
    glCompileShader(shader);

    ShaderError(shader,GL_COMPILE_STATUS,false,"Error compiling shader!");

    return shader;
}
