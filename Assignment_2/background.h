/**
 * @file background.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "shapes.h"
#include "colour.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define CLOUD_X -0.15f
#define CLOUD_Y 0.65f
#define CLOUD_RADIUS 0.08f
#define CLOUD_NEAR 1.1
#define CLOUD_FAR  0.7

#define CLOUD_ROTATION_ANGLE  0.0005
#define TOTAL_ROTATIONS 0
#define UPWARDS TRUE


#define CLOUD_MOVE_SPEED -0.0005
#define TOTAL_MOVEMENTS 0
#define LEFT TRUE

class Background
{
public:
	/** Default constructor */
	Background();
	void render();

	void sun();
	void cloud();
	void rotateCloud();
	void moveCloud();

	/** Default destructor */
	virtual ~Background();
protected:

private:
	float cloudRotationAngle;
	int totalRotations;
	bool upwards;

	float cloudMoveSpeed;
	int totalMovements;
	bool left;
};

#endif // BACKGROUND_H