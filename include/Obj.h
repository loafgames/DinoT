#pragma once

#include "Spr.h"

class Obj
{
protected:
	void init();

	enum ObjectType
	{
	    OBJ_DINO,
	    OBJ_TILE_WATER
	};

	enum Sides
	{
		RIGHT,
		UP,
		LEFT,
		DOWN
	};

public:
	bool doesExist;

	bool visible;

	ObjectType objectType;

	double imageIndex;
	double imageSpeed;

	double x;
	double y;

	double xstart;
	double ystart;

	double xprev;
	double yprev;

	double hspeed;
	double vspeed;

	double gravity;
	double gravityDirection;

	double friction;

	Spr* sprite;

	Obj(void);
	Obj(double x, double y);
	~Obj(void);

	virtual void destroy();

	virtual void onEvent(sf::Event event);
	virtual void onStep();
	virtual void onDraw();

	bool isColliding(ObjectType type);
	bool isCollidingAt(double x, double y, ObjectType type);

	bool isOutsideRoom();
	bool isOutsideRoom(Sides side);

	virtual void onAnimationEnd();

	template <class DstType, class SrcType>
	bool IsType(const SrcType* src);

	bool isObjectAtPoint(double x, double y);
    static Obj* getCollisionPoint(double x, double y, ObjectType obj);
	static Obj* getCollisionLine(double x1, double y1, double x2, double y2, ObjectType obj, int steps);
};
