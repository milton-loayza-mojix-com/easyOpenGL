//
// Created by Milton Loayza on 4/25/15.
//

#ifndef EASYOPENGL_GAMECOMPONENT_H
#define EASYOPENGL_GAMECOMPONENT_H

namespace EasyOpenGL
{
    class GameComponent
    {

    public:
        GameComponent();
        ~GameComponent();

        bool isEnabled() const;
        void setEnabled(bool enabled);

        virtual void initialize();
        virtual void update();
        virtual void draw();

    protected:
        bool enabled;

    };
}

#endif //EASYOPENGL_GAMECOMPONENT_H
