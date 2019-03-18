/**
 * @file player.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */


#include "player.h"

Player::Player() {

	playerX1 = PLAYER_X1;
	playerY1 = PLAYER_Y1;
	playerX2 = PLAYER_X2;
	playerY2 = PLAYER_Y2;
	speed = PLAYER_SPEED;
	score = 0;

	bottomTailAngle = PLAYER_BOTTOM_TAIL_ANGLE;
	bottomTailRotationCount = PLAYER_BOTTOM_TAIL_ROTATION_COUNT;
	bottomTailUpwards = BOTTOM_TAIL_UPWARDS;

	topTailAngle = PLAYER_TOP_TAIL_ANGLE;
	topTailRotationCount = PLAYER_TOP_TAIL_ROTATION_COUNT;
	topTailUpwards = TOP_TAIL_UPWARDS;
}

void Player::render() {

	Color color;
	color.setColor("c13450");

	//Create the Player Bounding Box
	Shapes::boundaryBox(playerX1, playerY1, playerX2, playerY2, color);

	
	glPushMatrix();
		color.setColor("F6BD20");
		//Body of Pikachu - top level
		Shapes::quad(playerX1, playerY1, playerX2, -0.74, color);

		//Head of Pikachu - 2nd level
		glPushMatrix();
			glTranslatef(0,0.33,0);
			Shapes::circle(-((abs(playerX1) + abs(playerX2)) / 2), playerY1, 0.07, color);
		glPopMatrix();

		//First Part of Tail - 2nd Level
		glPushMatrix();	
			//Rotate Bottom Tail
		    glTranslatef(playerX1,playerY1,0);
			rotateBottomTail();
			glTranslatef(-playerX1, -playerY1, 0);

			color.setColor("f4dc26");
			glTranslatef(0.04, 0.05, 0);
			Shapes::triangle(playerX1, playerY1, playerX1-0.09, playerY1+0.06, playerX1-0.07, playerY1+0.11, color);
			
			//Second Part of Tail - 3rd Level
			glPushMatrix();
				//Rotation Top Tail - Fourth Level
				glTranslatef(playerX1, playerY1, 0); //Translate to Origin
				rotateTopTail();
				glTranslatef(-playerX1, -playerY1, 0); //Translate Back

				color.setColor("5c3613");
				glTranslatef(-0.07, 0.06, 0);
				Shapes::triangle(playerX1, playerY1, playerX1 - 0.02, playerY1 + 0.12, playerX1 + 0.03, playerY1 + 0.15, color);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix(); 

	//Check Left Window Collision
	if (collision.leftWindowCollision(playerX1)) {
		moveRight();
	}
	
	//Check Left Net Collision
	if(collision.leftNetCollision(playerX2)) {
		moveLeft();
	}

	color.setColor("c13450");
	//Render the score
	glPushMatrix();
		glTranslatef(-0.55, 0, 0);
		playerScore.score(color, score);
	glPopMatrix();
}

//Move Player Right
void Player::moveRight() {
	playerX1 += speed;
	playerX2 += speed;
}

//Move Player Left
void Player::moveLeft(){
	playerX1 -= speed;
	playerX2 -= speed;
}

//Add Player's Score
void Player::scoreAdd() {
	score++;
}

//Reset Player's Score
void Player::resetScore() {
	score = 0;
}

//Get Player Score
int Player::getScore() {
	return score;
}

void Player::rotateBottomTail() {

	if (bottomTailUpwards) {
		glRotatef(bottomTailAngle += 0.5f, 0.0f, 0.0f, 1.0f);
		++bottomTailRotationCount;
	}
	else {
		glRotatef(bottomTailAngle -= 0.5f, 0.0f, 0.0f, 1.0f);
		--bottomTailRotationCount;
	}

	if (bottomTailRotationCount == 60) {
		bottomTailUpwards = false;
	}
	else if (bottomTailRotationCount == 0) {
		bottomTailUpwards = true;
	}

}

void Player::rotateTopTail() {

	if (topTailUpwards) {
		glRotatef(topTailAngle += 0.8f, 0.0f, 0.0f, 1.0f);
		++topTailRotationCount;
	}
	else {
		glRotatef(topTailAngle -= 0.8f, 0.0f, 0.0f, 1.0f);
		--topTailRotationCount;
	}

	if (topTailRotationCount == 10) {
		topTailUpwards = false;
	}
	else if (topTailRotationCount == 0) {
		topTailUpwards = true;
	}

}

//Reset Player
void Player::resetAll() {
	playerX1 = PLAYER_X1;
	playerY1 = PLAYER_Y1;
	playerX2 = PLAYER_X2;
	playerY2 = PLAYER_Y2;
	speed = PLAYER_SPEED;
	resetScore();
}

Player::~Player() {

}