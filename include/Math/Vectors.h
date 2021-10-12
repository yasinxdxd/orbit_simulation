#pragma once
#ifndef GO_VECTORS_H
#define GO_VECTORS_H

#include <cmath>
#include "Core/Definitions.h"

#define GO_PI 3.14159265359
#define GO_R2D(radian) radian * 180 / GO_PI
#define GO_D2R(degree) degree * GO_PI / 180 
#define GO_DIST(x1,y1,x2,y2) sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))



namespace go
{

	template<class T>

	class Vec2
	{
	public:
		T x, y;

		Vec2() { this->x = 0; this->y = 0; }

		Vec2(T x, T y) { this->x = x; this->y = y; }

		Vec2<T> operator+(Vec2<T> v) const
		{
			Vec2<T> result = go::Vec2<T>(this->x + v.x, this->y + v.y);
			return result;
		}

		Vec2<T> operator-(Vec2<T> v) const
		{
			Vec2<T> result = go::Vec2<T>(this->x - v.x, this->y - v.y);
			return result;
		}

		template<typename N>
		Vec2<T> operator*(N n) const
		{
			Vec2<T> result = go::Vec2<T>(this->x*n, this->y*n);
			return result;
		}

		Vec2<T> operator+=(Vec2<T> v) 
		{
			*this = *this + v;
			return *this;
		}

		Vec2<T> operator-=(Vec2<T> v) 
		{
			*this = *this - v;
			return *this;
		}

		template<typename N>
		Vec2<T> operator*=(N n) 
		{
			*this = *this * n;
			return *this;
		}


	};

	template<class T>

	class Vec3
	{
	public:
		T x, y, z;

		Vec3() { this->x = 0; this->y = 0;  this->z = 0; }

		Vec3(T x, T y, T z) { this->x = x; this->y = y; this->z = z; }

		Vec3<T> operator+(Vec3<T> v) const
		{
			Vec3<T> result = go::Vec3<T>(this->x + v.x, this->y + v.y, this->z + v.z);
			return result;
		}

		Vec3<T> operator-(Vec2<T> v) const
		{
			Vec3<T> result = go::Vec3<T>(this->x - v.x, this->y - v.y, this->z - v.z);
			return result;
		}

		template<typename N>
		Vec3<T> operator*(N n) const
		{
			Vec3<T> result = go::Vec3<T>(this->x * n, this->y * n, this->z * n);
			return result;
		}

		Vec3<T> operator+=(Vec3<T> v)
		{
			*this = *this + v;
			return *this;
		}

		Vec3<T> operator-=(Vec3<T> v)
		{
			*this = *this - v;
			return *this;
		}

		template<typename N>
		Vec3<T> operator*=(N n)
		{
			*this = *this * n;
			return *this;
		}

	};

	template<class T>

	class Vec4
	{
	public:
		T x, y, z, w;

		Vec4() { this->x = 0; this->y = 0;  this->z = 0; this->w = 0; }

		Vec4(T x, T y, T z, T w) { this->x = x; this->y = y; this->z = z; this->w = w; }

	};

	typedef Vec2<GOuint> Vec2ui;
	typedef Vec2<GOfloat> Vec2f;
	typedef Vec2<GOint> Vec2i;
	typedef Vec2<GOdouble> Vec2d;

	typedef Vec3<GOuint> Vec3ui;
	typedef Vec3<GOfloat> Vec3f;
	typedef Vec3<GOint> Vec3i;

	typedef Vec3<GOsint> Vec3si;

	typedef Vec4<GOuint> Vec4ui;
	typedef Vec4<GOfloat> Vec4f;
	typedef Vec4<GOint> Vec4i;
}

#endif //GO_VECTORS_H
