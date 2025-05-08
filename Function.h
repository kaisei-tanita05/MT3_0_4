#pragma once
#include <Vector3.h>
#include <math.h>
#include <time.h>
#define _USE_MATH_DEFINE
#include "Matrix4x4.h"
#include <Novice.h>
#include <Vector4.h>
#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

// スカラー倍
Vector3 Multiply(float scalar, const Vector3& v1);

// 内積
float Dot(const Vector3& v1, const Vector3& v2);

// 長さ(ノルム)
float Length(const Vector3& v1);

// 1.行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

// 2.行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

// 3.行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

// 4.逆行列
Matrix4x4 Inverse(const Matrix4x4& m);

// 5.転置行列
Matrix4x4 Transpose(const Matrix4x4& m);

// 6.単位行列の作成
Matrix4x4 MakeIdenity4x4();

// 1.平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

// 2.拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

// 3.座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

// X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian);

// Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian);

// Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian);

// 結果の表示
static const int kRowHeight = 20;
static const int kColumnWidth = 60;

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);