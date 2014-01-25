#ifndef CPRPG_UI_GL_PROGRAM_H
#define CPRPG_UI_GL_PROGRAM_H

#include "ui/main/gl/shader.h"
#include <memory>
#include <map>

namespace UI {
    namespace GL {
        /**
         * Representation of a shader program
         */
        class Program {
            public:
                /**
                 * Create the shader program
                 */
                Program();
                /**
                 * Destroy the shader program
                 */
                ~Program();
                /**
                 * Add a new shader to the program. This will replace an existing shader
                 * of the same type
                 * @param shader The shader to add
                 */
                void addShader(std::shared_ptr<Shader> shader);
            protected:
            private:
                /** The ID of the program */
                int id_;
                /** The shaders that make up the program */
                std::map<ShaderType, std::shared_ptr<Shader> > shaders_;
        };
    }
}
#endif

