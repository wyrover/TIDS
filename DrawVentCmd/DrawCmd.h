#pragma once

class DrawCmd
{
public:
	/* 实现在DrawVent.cpp中 */
	//static void DrawJoint(void);
	static void DrawTunnel(void);
	static void DrawArcTunnel(void);
	static void DrawWS(void);

	/* 实现在DrawTTunnel.cpp中 */
	static void DrawTTunnel();
	static void ResetInTunnel();
	static void ShowInTunnel();

	static void DrawMainFan();
	static void DrawLocalFan();
	static void DrawFanTag();
	static void DrawGate(int flag);
	static void DrawCasement(int flag);
	static void DrawWindBridge();
	static void DrawJoint();
	static void DrawWall(int flag);
	static void DrawStorage(int flag);
	static void DrawDirection(void);
	static void DrawWindLibrary(void);


	static void DrawChimney(void);
	//static void DrawCompass();

	/* 实现在AutoDraw.cpp中 */
	static void AutoDraw();
	static void AutoDraw2();

	/* 自动标注风流方向 */
	static void AutoDirection();

	static double ControlDirByMethods(AcDbObjectId objId,double angle);

	/* 自动更新测风站数据 */
	static void UpdateAllWindStationData();

	// 通用编辑命令
	static void JunctionEnclose(void);
	static void ReverseDirection();
	static void ReBindEdge();
	static void ZoomMineGE();
	static void SplitTunnel(AcDbObjectId objId,AcGePoint3d spt,AcGePoint3d ept,AcGePoint3d pt);
	static void SplitDeal();
	static void MergeChimney();
	static void Merging(AcDbObjectId sourceId,AcDbObjectId mergeId);
	static void DrawQTagGE();
	static void DrawEffectRanGE();

	static void DeleteDirection();
	static void DeleteFanTag();
	static void DeleteQTag();
	static void DeleteEDTag();

	//static AcDbObjectId GetRelatedTW(AcDbObjectId objId);

	static void testHD();
};