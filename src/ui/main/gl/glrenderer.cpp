#include "ui/renderer.h"
#include "ui/main/gl/version.h"
#include "logging/logger.h"
#include "ui/main/gl/shader.h"

namespace UI {
    static const Logging::Logger LOG("cprpg.ui.gl.renderer");
    namespace GL {
        /**
         * The OpenGL Renderer
         */
        class Renderer : public UI::Renderer {
            public:
                Renderer() {
                    Shader vertexShader(ShaderType::VERTEX);
                    vertexShader.source("void main(void) {\nvec4 a = gl_Vertex;\ngl_Position = gl_ModelViewProjectionMatrix * a;\n}");
                }
                virtual ~Renderer() {}
        };
    }

    /**
     * Create the renderer to use
     * @return the renderer
     */
    std::unique_ptr<Renderer> createRenderer() {
        std::unique_ptr<Renderer> renderer;
        UI::GL::Version glVersion;
        if (glVersion.compare(UI::GL::OpenGLVersions::OPENGL_3_0)) {
            LOG(Logging::Level::DEBUG, "Creating OpenGL 3.0 Renderer");
            renderer.reset(new UI::GL::Renderer);
        } else {
            LOG(Logging::Level::WARN, "Unable to create a renderer");
        }
        return renderer;
    }
}
