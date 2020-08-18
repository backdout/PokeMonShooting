// macroFunction.h
#pragma once
#include "pch.h"

inline void RenderLine(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

inline RECT GetRect(int x, int y, int size)
{
	RECT rc = { x, y, x + size, y + size };
	return rc;
}

inline RECT GetRectToCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2),
		x + (width / 2), y + (height / 2) };
	return rc;
}

inline void RenderRect(HDC hdc, int x, int y, int size)
{
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x + size, y);
	LineTo(hdc, x + size, y + size);
	LineTo(hdc, x, y + size);
	LineTo(hdc, x, y);
}

inline void RenderEllipse(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void RenderEllipseToCenter(HDC hdc, int centerX, int centerY,
	int width, int height)
{
	Ellipse(hdc, centerX - (width / 2), centerY - (height / 2),
		centerX + (width / 2), centerY + (height / 2));
}

// x, y : 시작위치
// width, height : 너비, 높이
inline void RenderRect(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

// centerX, centerY : 사각형의 중점
// width, height : 너비, 높이
inline void RenderRectToCenter(HDC hdc, int centerX, int centerY,
	int width, int height)
{
	Rectangle(hdc, centerX - (width / 2), centerY - (height / 2),
		centerX + (width / 2), centerY + (height / 2));
}

// 충돌체크 함수
inline bool CheckRectCollision(RECT rc1, RECT rc2)
{
	if (rc1.left > rc2.right ||
		rc1.right < rc2.left ||
		rc1.top > rc2.bottom ||
		rc1.bottom < rc2.top)
	{
		return false;
	}
	return true;
}

inline int GetMin(int num1, int num2)
{
	if (num1 < num2)
		return num1;

	return num2;
}

inline int GetMax(int num1, int num2)
{
	if (num1 > num2)
		return num1;

	return num2;
}

inline void RoatateFunction(float _theta, float _posX, float _posY, int _width, int _height, POINT *point)
{
	POINT temppoint[3];
	float theta;

	temppoint[0].x = -_width / 2;
	temppoint[0].y = -_height / 2;
	temppoint[1].x = _width / 2;
	temppoint[1].y = -_height / 2;
	temppoint[2].x = -_width / 2;
	temppoint[2].y = _height / 2;

	theta = DEGREE_TO_RADIAN(_theta);

	for (int i = 0; i < 3; i++)
	{
		//원점이동
		point[i].x = temppoint[i].x*cosf(theta) - temppoint[i].y*sinf(theta) + _posX;
		point[i].y = temppoint[i].x*sinf(theta) + temppoint[i].y*cosf(theta) + _posY;

	}


}

inline float GetDistance(float x1, float y1, float x2, float y2)
{
	float distance = 0;
	distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

	return distance;
}

inline bool CheckCirCollision(FPOINT pos1, int pos1Size, FPOINT pos2, int pos2Size)
{
	float h = (pos1.x - pos2.x)*(pos1.x - pos2.x) + (pos1.y - pos2.y)*(pos1.y - pos2.y);
	h = sqrtf(h);
	if (h <= (pos1Size + pos2Size))
	{
		return true;
	}
	return false;
}