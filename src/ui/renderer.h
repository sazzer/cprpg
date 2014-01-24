#ifndef CPRPG_UI_RENDERER_H
#define CPRPG_UI_RENDERER_H

#include <memory>

namespace UI {
    /**
     * The interface describing the renderer
     */
    class Renderer {
        public:
            /** Virtual destructor */
            virtual ~Renderer() {}
    };

    /**
     * Create the renderer to use
     * @return the renderer
     */
    std::unique_ptr<Renderer> createRenderer();
}

#endif
