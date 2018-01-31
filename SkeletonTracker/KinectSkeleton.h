#pragma once

#include "Skeleton.h"
#include "SimpleSkeleton.h"

class KinectSkeleton : public Skeleton
{
	static const int        cStatusMessageMaxLen = MAX_PATH * 2;

public:
	struct RenderHelper
	{
		ID2D1HwndRenderTarget*  pRenderTarget;
		ID2D1SolidColorBrush*   pBrushJointTracked;
		ID2D1SolidColorBrush*   pBrushJointInferred;
		ID2D1SolidColorBrush*   pBrushBoneTracked;
		ID2D1SolidColorBrush*   pBrushBoneInferred;
		NUI_SKELETON_FRAME*		pSkeletonFrame;
		int windowWidth;
		int windowHeight;
	};

	KinectSkeleton();
	~KinectSkeleton();

	void Render(const RenderHelper& helper);
	void PrintJoints();
	void FixTpose();
	void PrintSimplePose();
	void GetSimplePose(SimpleRotations& rotations);
	bool isTposeCalibrated() { return m_isTposeCalibrated; }

private:

	// For printing, only one skeleton supported
	D2D1_POINT_2F            m_Points[NUI_SKELETON_POSITION_COUNT];
	Vector4                  m_SkeletonPositions[NUI_SKELETON_POSITION_COUNT];
	NUI_SKELETON_BONE_ORIENTATION m_SkeletonTposeOrientations[NUI_SKELETON_POSITION_COUNT];
	NUI_SKELETON_BONE_ORIENTATION m_SkeletonOrientations[NUI_SKELETON_POSITION_COUNT];
	bool					 m_isTposeCalibrated;

	void DrawSkeleton(const NUI_SKELETON_DATA & skel, const RenderHelper& helper);
	void DrawBone(const NUI_SKELETON_DATA & skel, const RenderHelper& helper, 
		NUI_SKELETON_POSITION_INDEX bone0, NUI_SKELETON_POSITION_INDEX bone1);
};
