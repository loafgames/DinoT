#ifndef OBJDINO_H
#define OBJDINO_H

#include <Obj.h>


class ObjDino : public Obj
{
    public:
        ObjDino(double x, double y);
        virtual ~ObjDino();

        void onStep();

        static const int WALK_DELAY;
        static const int SHOOT_DELAY;
    protected:
    private:
        int walkDelay;
        int shootDelay;
};

#endif // OBJDINO_H
