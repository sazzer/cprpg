#include "config.h"
#include "logging/logger.h"
#include <SDL.h>
#include "ui/main/gl/version.h"

static const Logging::Logger LOG("cprpg");

int main(void) {
    printf("%d.%d.%d\n", VersionMajor, VersionMinor, VersionMicro);
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        LOG(Logging::Level::ERROR, "Failed to initialize SDL");
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    auto window = SDL_CreateWindow("CPRPG", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED,
            600,
            400,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        LOG(Logging::Level::ERROR, "Failed to initialize SDL Window");
        return 2;
    }
    
    auto glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        LOG(Logging::Level::ERROR, "Failed to initialize OpenGL Context");
        return 3;
    }

    UI::GL::Version version;
    printf("%d.%d\n", version.major(), version.minor());
    printf("%s\n%s\n", version.vendor().c_str(), version.renderer().c_str());
    for (std::string e : version.extensions()) {
        printf("%s : ", e.c_str());
    }
    printf("%s\n", version.hasExtension("GL_ARB_texture_storage") ? "Yes" : "No");
    printf("%d\n", version.getVersion());
    return 0;
}
