#pragma once
#ifndef BOUNCE_CAMERA
#define BOUNCE_CAMERA

#include "../Engine/Engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace BounceRender {
    class Camera {
    public:
        Camera();
        Camera(vfloat fovy, vfloat aspect, vfloat near, vfloat far);

        void Show(vuint u_viewProj);

        void SetViewPosition(vfloat x, vfloat y, vfloat z);

        glm::mat4x4& GetView();

    private:
        glm::mat4x4 m_view;
        glm::mat4x4 m_projection;
    };
};

#endif 