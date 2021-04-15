#pragma once
#ifndef BOUNCE_SHADER
#define BOUNCE_SHADER

#include <fstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace BounceRender {
    class Shader {
    public:
        Shader(const vchar* vertexShaderSource, const vchar* fragmentShaderSource);
        Shader(std::string vertexShaderFilename, std::string fragmentShaderFilename, vbool loadFromFile);

        void Bind();
        void Unbind();

        vuint GetUniformLocation(vchar* uniform);
        vint GetAttribLocation(vchar* attrib);
        vuint GetProgram();

    private:
        int m_program;

    };
};

#endif 