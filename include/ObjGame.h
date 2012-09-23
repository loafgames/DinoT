#ifndef OBJGAME_H
#define OBJGAME_H

#include <Obj.h>


class ObjGame : public Obj
{
    public:
        ObjGame(double x, double y);
        virtual ~ObjGame();
        void onStep();
    protected:
    private:
};

#endif // OBJGAME_H
