/**
 * @file shapes.cpp
 *
 * @brief CSED541 Computer Graphics Assignment 1
 *
 * @author Tan Wei Xuan (49003140), Ong Wei Hua (49003139)
 * Contact: tanweixuan@postech.ac.kr, ongweihua@postech.ac.kr
 *
 */

#include "shapes.h"


Shapes::Shapes() {
}

void Shapes::rectangle(double x1, double y1, double x2, double y2) {
	glRectf(x1, y1, x2, y2);
}

void Shapes::quad(double x1, double y1, double x2, double y2,Color color) {
	glColor3f(SETCOLOR(color));
	glBegin(GL_QUADS);
		glVertex2f(x1, y1);
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y1);
	glEnd();

}

void Shapes::circle(double ballX,double ballY, double radius, Color color) {
	
	float angle;
	float x2, y2;
	glColor3f(SETCOLOR(color));
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(ballX, ballY);

	
	for (angle = 1.0f; angle < 3*PI; angle += 0.2)
	{
		x2 = ballX + sin(angle)*radius;
		y2 = ballY + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
	
}

void Shapes::boundaryBox(double x1, double y1, double x2, double y2,Color color) {
	glColor3f(SETCOLOR(color));
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1, y1);
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y1);
	glEnd();
}

void Shapes::electricity(double x1, double y1,double x2,double y2,Color color) {

	glColor3f(SETCOLOR(color));
	glBegin(GL_LINE_STRIP);

	for (double i = x1; i <= x2; i += 0.02)
	{
		if(y2 > y1)
			glVertex2f(i,  (y2+0.06 - y1) * ((double)rand() / (double)RAND_MAX) + y1);
		else {
			glVertex2f(i, (y1+0.06 - y2) * ((double)rand() / (double)RAND_MAX) + y2);
		}
		
	}
	glEnd();
}


void Shapes::triangle(double x1, double y1, double x2, double y2, double x3, double y3, Color color) {
	glColor3f(SETCOLOR(color));
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, y1,0);
		glVertex3f(x2, y2,0);
		glVertex3f(x3, y3,0);
	glEnd();
}

void Shapes::ellipse(double cx, double cy, double radiusX,double radiusY,Color color_btm,Color color_top) {

	float theta = 2 * PI / 10;
	float c = cosf(theta);
	float s = sinf(theta);
	float t;

	float x = 1;
	float y = 0;

	glBegin(GL_TRIANGLE_FAN);
	for (int ii = 0; ii < 10; ii++)
	{

		if (ii % 2 == 0)
			glColor3f(SETCOLOR(color_top));
		else
			glColor3f(SETCOLOR(color_btm));

		//apply radius and offset
		glVertex2f(x * radiusX + cx, y * radiusY + cy);//output vertex 

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}


Shapes::~Shapes()
{
	
}