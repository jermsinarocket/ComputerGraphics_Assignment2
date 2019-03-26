/**
 * @file background.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include "background.h"

Background::Background() {
	//For Cloud Rotation
	cloudRotationAngle = CLOUD_ROTATION_ANGLE;
	totalRotations = TOTAL_ROTATIONS;
	upwards = UPWARDS;

	//For Cloud Movement
	cloudMoveSpeed = CLOUD_MOVE_SPEED;
	totalMovements = TOTAL_MOVEMENTS;
	left = LEFT;
}

void Background::render() {
	
	sun();

	glPushMatrix();

		moveCloud();

		cloud();

		//Second Cloud
		glPushMatrix();
			glScalef(CLOUD_FAR, CLOUD_FAR, 0);
			glTranslatef(0.6f,0,0);
			cloud();
		glPopMatrix();
		
		//Third Cloud
		glPushMatrix();
			glScalef(CLOUD_NEAR, CLOUD_NEAR, 0);
			glTranslatef(0.8f, 0.05f, 0);
			cloud();
		glPopMatrix();

	glPopMatrix();

}

void Background::sun() {

	Color color;

	color.setColor("fdf78c");

	//colour of sun background
	glColor3f(SETCOLOR(color));
	glPushMatrix();
		Shapes::rectangle(-0.9f, 0.55f, -0.70f, 0.85f);	
	glPopMatrix();

	// color of sun

	color.setColor("fff200");
	glColor3f(SETCOLOR(color));
	glPushMatrix();
		Shapes::rectangle(-0.88, 0.58f, -0.72f, 0.83f);
	glPopMatrix();
}

void Background::cloud() {

	Color color;
	color.setColor("FFFFFF");
	glColor3f(SETCOLOR(color));

	glPushMatrix();
		//Top Cloud - 1st Level
		Shapes::circle(CLOUD_X, CLOUD_Y, CLOUD_RADIUS, color);

		//Left Cloud - 2nd Level
		glPushMatrix();
			glTranslatef(-0.05, -0.12f, 0.0f);
			Shapes::circle(CLOUD_X, CLOUD_Y, CLOUD_RADIUS, color);
		glPopMatrix();

		//Right Cloud - 2nd Level
		glPushMatrix();
			glTranslatef(0.05, -0.12f, 0.0f);
			Shapes::circle(CLOUD_X, CLOUD_Y, CLOUD_RADIUS, color);
		glPopMatrix();

		//Moving Left Cloud - 2nd Level
		glPushMatrix();
			rotateCloud();
			glTranslatef(-0.08, -0.05f, 0.0f);
			Shapes::circle(CLOUD_X, CLOUD_Y, CLOUD_RADIUS, color);
		glPopMatrix();

		//Moving Right Cloud 2nd Level
		glPushMatrix();
			rotateCloud();
			glTranslatef(0.08, -0.05f, 0.0f);
			Shapes::circle(CLOUD_X, CLOUD_Y, CLOUD_RADIUS, color);
		glPopMatrix();
	glPopMatrix();


}

void Background::rotateCloud() {

	if (upwards) {
		glTranslatef(0.0f, cloudRotationAngle += 0.0005, 0.0);
		++totalRotations;
	}
	else{
		glTranslatef(0.0f, cloudRotationAngle -= 0.0005, 0.0);
		--totalRotations;
	}
	
	if (totalRotations == 125) {
		upwards = false;
	}else if (totalRotations == 0) {
		upwards = true;
	}

}

void Background::moveCloud() {

	if (left) {
		glTranslatef(cloudMoveSpeed -= 0.0005f, 0.0f, 0.0f);
		++totalMovements;
	}
	else {
		glTranslatef(cloudMoveSpeed += 0.0005f, 0.0f, 0.0f);
		--totalMovements;
	}

	if (totalMovements == 400) {
		left = false;
	}
	else if (totalMovements == 0) {
		left = true;
	}

}

Background::~Background()
{
}