//
// Created by Milton Loayza on 4/25/15.
//

#include "Game.h"

namespace EasyOpenGL
{
    Game* Game::internalInstance = nullptr;

    // Create Object and set DEFAULT values
    Game::Game(const std::string& windowTitle)
            : window(nullptr), windowTitle(windowTitle),
              screenWidth(800), screenHeight(600),
              screenBackgroundColor(&ColorHelper::CornflowerBlue[0]),
              positionX(100), positionY(100),
              fullScreen(false),
              majorVersion(3), minorVersion(2),
              depthStencilBufferEnabled(false),
              components(), keyboardHandlers()
    {
    }

    Game::~Game()
    {
        components.clear();
    }

    GLFWwindow* Game::getWindow() const
    {
        return window;
    }

    const std::string& Game::getWindowTitle() const
    {
        return windowTitle;
    }

    bool Game::isDepthBufferEnabled() const
    {
        return depthStencilBufferEnabled;
    }

    int Game::getScreenWidth() const
    {
        return screenWidth;
    }

    int Game::getScreenHeight() const
    {
        return screenHeight;
    }

    float Game::getAspectRatio() const
    {
        return static_cast<float>(screenWidth) / screenHeight;
    }

    bool Game::isFullScreen() const
    {
        return fullScreen;
    }

    void Game::setScreenDimension(unsigned screenWidth, unsigned screenHeight, bool fullScreen)
    {
        this->screenWidth = screenWidth;
        this->screenHeight = screenHeight;
        this->fullScreen = fullScreen;
    }
    void Game::setScreenPosition(unsigned positionX, unsigned positionY)
    {
        this->positionX = positionX;
        this->positionY = positionY;
    }

    std::vector<GameComponent*>& Game::getComponents()
    {
        return components;
    }


    void Game::run()
    {
        internalInstance = this;

        initializeWindow();
        initializeOpenGL();
        initialize();

        printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

        while (!glfwWindowShouldClose(window))
        {
            glClearBufferfv(GL_COLOR, 0, screenBackgroundColor);
            update();
            draw();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        shutdown();
    }

    void Game::exit()
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    void Game::initialize()
    {
        for (GameComponent* component : components)
        {
            component->initialize();
        }

    }

    void Game::update()
    {
        for (GameComponent* component : components)
        {
            if (component->isEnabled())
            {
                component->update();
            }
        }

    }

    void Game::draw()
    {
        for (GameComponent* component : components)
        {
            if (component->isEnabled())
            {
                component->draw();
            }
        }

    }

    void Game::initializeWindow()
    {
        if (!glfwInit())
        {
            throw GameException("glfwInit() failed.");
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        GLFWmonitor* monitor = (fullScreen ? glfwGetPrimaryMonitor() : nullptr);
        window = glfwCreateWindow(screenWidth, screenHeight, windowTitle.c_str(), monitor, nullptr);
        if (window == nullptr)
        {
            shutdown();
            throw GameException("glfwCreateWindow() failed.");
        }

        glfwSetWindowPos(window, positionX, positionY);
    }

    void Game::initializeOpenGL()
    {
        glfwMakeContextCurrent(window);

        if (gl3wInit() != 0)
        {
            throw GameException("gl3wInit() failed.");
        }

        glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
        glGetIntegerv(GL_MINOR_VERSION, &minorVersion);

        if (depthStencilBufferEnabled)
        {
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
        }

        glViewport(0, 0, screenWidth, screenHeight);

        glfwSetKeyCallback(window, Game::onKey);

        glfwSetWindowSizeCallback(window, Game::onWindowResize);
    }

    void Game::shutdown()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Game::addKeyboardHandler(KeyboardHandler handler)
    {
        keyboardHandlers[&handler] = handler;
    }

    void Game::removeKeyboardHandler(KeyboardHandler handler)
    {
        keyboardHandlers.erase(&handler);
    }

    void Game::onKey(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        for (auto handler : internalInstance->keyboardHandlers)
        {
            handler.second(key, scancode, action, mods);
        }
    }

    void  Game::onWindowResize(GLFWwindow *window, int width, int height) {
        glClearBufferfv(GL_COLOR, 0, internalInstance->screenBackgroundColor);
        internalInstance->update();
        internalInstance->draw();
        glfwSwapBuffers(window);
    }

}