#include"Canvas.h"
#include<stdlib.h>
#include<string.h>
#include <stdio.h>

Canvas::Canvas(int width, int height):width(width), height(height)
{
	this->matrix = (char**)malloc(this->height * sizeof(char*));
	for (int i = 0; i < this->height; ++i) {
		this->matrix[i] = (char*)malloc(this->width * sizeof(char));
		memset(this->matrix[i], ' ', this->width);
	}
	
}
Canvas::~Canvas() {
	for (int i = 0; i < this->height; ++i) {
		if(this->matrix[ i ] != nullptr)
			free(this->matrix[i]);
	}
	if(this->matrix != nullptr)
		free(this->matrix);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	/*int borderXMin = (x - ray) > 0 ? (x - ray) : 0;
	int borderXMax = (x + ray) < height? (x + ray) : (height - 1);
	int dist = 0, borderCircle = 0;
	int borderYMin = 0;
	int borderYMax = 0;
	for (int i = borderXMin; i <= borderXMax; ++i)
	{
		dist = (x - i) > 0 ? (x - i) : (-x + i);
		borderCircle = (ray - dist);
		borderYMin = (y - borderCircle);
		borderYMax = (y + borderCircle);
		if (borderYMin >= 0 && borderYMin < width)
			matrix[i][borderYMin] = ch;
		if (borderYMax >= 0 && borderYMax < width)
			matrix[i][borderYMax] = ch;
	}*/
	// Era un romb bun

	for (int i = x - ray; i <= x + ray; ++i)
		for (int j = y - ray; j <= y + ray; ++j)
			if (i >= 0 && i < this->height && j >= 0 && j < this->width && (i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				this->matrix[i][j] = ch;

}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	/*int borderXMin = (x - ray) > 0 ? (x - ray) : 0;
	int borderXMax = (x + ray) < height ? (x + ray) : (height - 1);
	int dist = 0, borderCircle = 0;
	int borderYMin = 0;
	int borderYMax = 0;
	for (int i = borderXMin; i <= borderXMax; ++i)
	{
		dist = (x - i) > 0 ? (x - i) : (-x + i);
		borderCircle = (ray - dist);
		borderYMin = (y - borderCircle) > 0 ? (y - borderCircle) : 0;
		borderYMax = (y + borderCircle) < width ? (y + borderCircle) : (width - 1);
		for (int j = borderYMin; j <= borderYMax; ++j)
			matrix[i][j] = ch;
		
	}*/
	// Era un romb umplut bun...
	for (int i = x - ray; i <= x + ray; ++i)
		for (int j = y - ray; j <= y + ray; ++j)
			if (i >= 0 && i < this->height && j >= 0 && j < this->width && (i - x) * (i - x) + (j - y) * (j - y) <= ray * ray )
				this->matrix[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for(int j = left ; j <= right ; ++j)
		if (top >= 0 && top < this->height && j >= 0 && j < this->width)
			this->matrix[top][j] = ch;
	for (int j = left; j <= right; ++j)
		if (bottom >= 0 && bottom < this->height && j >= 0 && j < this->width)
			this->matrix[bottom][j] = ch;
	for(int i = top; i <= bottom ; ++i)
		if (i >= 0 && i < this->height && left >= 0 && left < this->width)
			this->matrix[i][left] = ch;
	for (int i = top; i <= bottom; ++i)
		if (i >= 0 && i < this->height && right >= 0 && right < this->width)
			this->matrix[i][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; ++i)
		for (int j = left; j <= right; ++j)
			if (i >= 0 && i < this->height && j >= 0 && j < this->width)
				this->matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < this->height && y >= 0 && y < this->width)
		this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x1 - x2;
	if (dx < 0)
		dx *= -1;
	int sx = x1 < x2 ? 1 : -1;
	int dy = y1 - y2;
	if (dy > 0)
		dy *= -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = dx + dy;
	while (true)
	{
		if( x1 < this->height && x1 >= 0 && y1 < this->width && y1 >= 0)
			this->matrix[x1][y1] = ch;
		if (x2 == x1 && y2 == y1) 
			break;
		int e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->height; ++i, printf("\n"))
		for (int j = 0; j < this->width; ++j)
			printf("%c", this->matrix[i][j]);

}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; ++i) {
		memset(this->matrix[i], ' ', this->width);
	}
}
