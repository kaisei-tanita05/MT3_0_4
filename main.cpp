#include "function.h"
#include <Novice.h>
#include <Vector3.h>

const char kWindowTitle[] = "LE2C_20_タニタ_カイセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 rotate{0.4f, 1.43f, -0.8f};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);

		Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);

		Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);

		Matrix4x4 rotateXYZMatrix = Matrix4x4(Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix)));

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(0, 0, "rotateXMatrix");
		MatrixScreenPrintf(0, 20, rotateXMatrix, "rotateXMatrix");

		Novice::ScreenPrintf(0, kRowHeight * 5, "rotateYMatrix");
		MatrixScreenPrintf(0, kRowHeight * 5 + 20, rotateYMatrix, "rotateYMatrix");

		Novice::ScreenPrintf(0, kRowHeight * 5 * 2, "rotateZMatrix");
		MatrixScreenPrintf(0, kRowHeight * 5 * 2 + 20, rotateZMatrix, "rotateZMatrix");

		Novice::ScreenPrintf(0, kRowHeight * 5 * 3, "rotateXYZMatrix");
		MatrixScreenPrintf(0, kRowHeight * 5 * 3 + 20, rotateXYZMatrix, "rotateXYZMatrix");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
