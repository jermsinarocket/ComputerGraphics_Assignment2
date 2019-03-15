/**
 * @file ai.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include "ai.h"

Ai::Ai() {

	aiX1 = AI_X1;
	aiY1 = AI_Y1;
	aiX2 = AI_X2;
	aiY2 = AI_Y2;
	speed = AI_SPEED;
	score = 0;
}

void Ai::render() {

	Color color;
	color.setColor("145214");

	//Create the AI Bounding Box
	Shapes::boundaryBox(aiX1, aiY1, aiX2, aiY2, color);
	color.setColor("F6BD20");
	glPushMatrix();
		//Body of Pikachu - 1st
		Shapes::quad(aiX1, aiY1, aiX2, -0.74, color);
		//Head of Pikachu - 1st
		glPushMatrix();
			glTranslatef(0, 0.33, 0);
			Shapes::circle(((abs(aiX1) + abs(aiX2)) / 2), aiY1, 0.07, color);
		glPopMatrix();
	glPopMatrix();


	color.setColor("145214");
	//Render the score
	glPushMatrix();
		glTranslatef(0.48, 0, 0);
		aiScore.score(color, score);
	glPopMatrix();

	//Move AI constantly by x,y speed
	aiX1 += speed;
	aiX2 += speed;

	//Check AI - Window Collision
	if (collision.rightWindowCollision(aiX2) || collision.rightNetCollision(aiX1)) {
		speed = -speed;
	}

}

//Add AI score
void Ai::scoreAdd() {
	score++;
}

//Reset AI Score
void Ai::resetScore() {
	score = 0;
}

//Get AI Score
int Ai::getScore() {
	return score;
}

//Reset AI
void Ai::resetAll() {

	aiX1 = AI_X1;
	aiY1 = AI_Y1;
	aiX2 = AI_X2;
	aiY2 = AI_Y2;
	speed = AI_SPEED;
	resetScore();
}

Ai::~Ai() {

}