#pragma once
class Rectangle{
public:
	Rectangle();
	Rectangle(float w, float h);

	float getWidth();
	float getHeight();
	float getArea();
	float getPerimeter();

	void setWidth(float w);
	void setHeight(float h);

private:
	float _width;
	float _height;
};

