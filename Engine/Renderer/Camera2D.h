#include "Camera.h"

namespace BounceRender {
    class Camera2D {
        public:
            Camera2D();
            Camera2D(float orthoSize, float aspectRatio, float near, float far);

            void Show(vuint u_viewProj);

            void SetViewPosition(vfloat x, vfloat y, vfloat z);

            glm::mat4x4& GetView();

        private:
            glm::mat4x4 m_view;
            glm::mat4x4 m_projection;
    };
};