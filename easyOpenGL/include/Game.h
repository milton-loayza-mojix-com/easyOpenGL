//
// Created by Milton Loayza on 4/25/15.
//

#ifndef EASYOPENGL_GAME_H
#define EASYOPENGL_GAME_H
#include "EasyOpenGL.h"

namespace  EasyOpenGL {

    class Game
    {
    public:

        Game(const std::string& windowTitle);
        ~Game();

        GLFWwindow* getWindow() const;
        bool isDepthBufferEnabled() const;
        const std::string& getWindowTitle() const;
        int getScreenWidth() const;
        int getScreenHeight() const;
        float getAspectRatio() const;
        bool isFullScreen() const;
        void setScreenDimension(unsigned screenWidth, unsigned screenHeight, bool fullScreen);
        void setScreenPosition(unsigned positionX, unsigned positionY);
        std::vector<GameComponent*>& getComponents();

        virtual void initialize();
        virtual void update();
        virtual void draw();
        virtual void run();
        virtual void exit();
        void addKeyboardHandler(KeyboardHandler handler);
        void removeKeyboardHandler(KeyboardHandler handler);

    protected:
        virtual void initializeWindow();
        virtual void initializeOpenGL();
        virtual void shutdown();

        GLFWwindow* window;
        std::string windowTitle;
        unsigned screenWidth;
        unsigned screenHeight;
        float const *screenBackgroundColor;
        unsigned positionX;
        unsigned positionY;
        bool fullScreen;
        GLint majorVersion;
        GLint minorVersion;
        bool depthStencilBufferEnabled;

        std::vector<GameComponent*> components;
        std::map<KeyboardHandler*, KeyboardHandler> keyboardHandlers;

        static void onKey(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void onWindowResize(GLFWwindow *window, int width, int height);
    private:
        static Game* internalInstance;
    };
}

#endif //EASYOPENGL_GAME_H
