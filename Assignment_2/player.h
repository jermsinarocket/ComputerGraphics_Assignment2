/**
 * @file player.h
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "shapes.h"
#include "colour.h"
#include "text.h"
#include "collision.h"
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()
#define PLAYER_X1 -0.57
#define PLAYER_X2 -0.43
#define PLAYER_Y1 -1.0
#define PLAYER_Y2 -0.60
//Can be changed to increase/decrease speed
#define PLAYER_SPEED 0.01

#define PLAYER_BOTTOM_TAIL_ANGLE 0.5
#define PLAYER_BOTTOM_TAIL_ROTATION_COUNT 0
#define BOTTOM_TAIL_UPWARDS TRUE

#define PLAYER_TOP_TAIL_ANGLE 1.0
#define PLAYER_TOP_TAIL_ROTATION_COUNT 0
#define TOP_TAIL_UPWARDS TRUE

#define PLAYER_EAR_ANGLE 1.0
#define PLAYER_EAR_ROTATION_COUNT 0
#define EAR_UPWARDS TRUE

class Player
{
public:
	/** Default constructor */
	Player();

	void render();
	void moveRight();
	void moveLeft();
	void scoreAdd();
	void resetScore();
	void resetAll();
	int getScore();
	void rotateBottomTail();
	void rotateTopTail();
	void rotateEar();
	virtual ~Player();

	double playerX1;
	double playerY1;
	double playerX2;
	double playerY2;
	double speed;
	bool rotateColli;

	Text playerScore;
	Collision collision;
	
protected:
private:
	int score;
	float bottomTailAngle;
	int bottomTailRotationCount;
	bool bottomTailUpwards;
	int totalBtmTailRotCount;

	float topTailAngle;
	int topTailRotationCount;
	bool topTailUpwards;
	int totalTopTailRotCount;

	float earAngle;
	int  earRotationCount;
	bool earUpwards;
	int totalEarRotCount;
};

#endif // PLAYER_H