#include "StdAfx.h"
#include "resource.h"

#include "../MineGE/HelperClass.h"

#include "DrawCmd.h"

// 定义注册服务名称
#ifndef DRAW_VENT_CMD_SERVICE_NAME
#define DRAW_VENT_CMD_SERVICE_NAME _T("DRAWVENTCMD_SERVICE_NAME")
#endif

class CDrawVentCmdApp : public AcRxArxApp
{

public:
    CDrawVentCmdApp () : AcRxArxApp () {}

    virtual AcRx::AppRetCode On_kInitAppMsg ( void* pkt )
    {

        AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg ( pkt ) ;

        // 注册服务
        acrxRegisterService( DRAW_VENT_CMD_SERVICE_NAME );

        acutPrintf( _T( "\nDrawVentCmd::On_kLoadAppMsg\n" ) );

        return ( retCode ) ;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg ( void* pkt )
    {

        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg ( pkt ) ;

        // 删除服务
        delete acrxServiceDictionary->remove( DRAW_VENT_CMD_SERVICE_NAME );

        acutPrintf( _T( "\nDrawVentCmd::On_kUnloadAppMsg\n" ) );

        return ( retCode ) ;
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg( void* pkt )
    {
        AcRx::AppRetCode retCode = AcRxDbxApp::On_kLoadDwgMsg ( pkt ) ;

        acutPrintf( _T( "\nDrawVentCmd::On_kLoadDwgMsg\n" ) );

        return retCode;
    }

    virtual AcRx::AppRetCode On_kUnloadDwgMsg( void* pkt )
    {
        AcRx::AppRetCode retCode = AcRxDbxApp::On_kUnloadDwgMsg ( pkt ) ;

        acutPrintf( _T( "\nDrawVentCmd::On_kUnloadDwgMsg\n" ) );

        return retCode;
    }

    virtual void RegisterServerComponents ()
    {
    }

    // 绘制巷道
    static void JL_DrawTunnel( void )
    {
        DrawCmd::DrawTunnel();        // 使用普通命令行交互绘制巷道
		//DrawCmd::testHD();
    }
	// 绘制弧线巷道
	static void JL_DrawArcTunnel( void )
	{
		DrawCmd::DrawArcTunnel();        // 使用普通命令行交互绘制巷道
	}


    // 绘制掘进工作面
    static void JL_DrawTTunnel()
    {
        DrawCmd::DrawTTunnel();  // 绘制掘进工作面
    }

    static void JL_ResetInTunnel()
    {
        DrawCmd::ResetInTunnel();  // 重新设置掘进工作面的导风巷道
    }

    static void JL_ShowInTunnel()
    {
        DrawCmd::ShowInTunnel();  // 高亮显示掘进工作面的导风巷道
    }

    // 绘制风流方向
    static void JL_DrawDirection()
    {
        DrawCmd::DrawDirection();       // 使用普通命令行交互绘制风流方向
    }

    // 绘制局部扇风机
    static void JL_DrawLocalFan()
    {
        DrawCmd::DrawLocalFan();       // 使用普通命令行交互绘制风机
    }

	static void JL_DrawLocalFanTag()
	{
		DrawCmd::DrawFanTag(); 
	}

	static void JL_DrawChimney()
	{
		DrawCmd::DrawChimney();
	}

	//绘制风库
	static void JL_DrawWindLibrary(void)
	{
		DrawCmd::DrawWindLibrary();
	}

    static void JL_AutoDraw( void )
    {
        DrawCmd::AutoDraw();
    }

	//节点绘制
	static void JL_DrawJoint(void)
	{
		DrawCmd::DrawJoint();
	}

    static void JL_AutoDirection( void )
    {
        DrawCmd::AutoDirection();
    }

    static void JL_TunnelJunctionEnclose()
    {
        DrawCmd::JunctionEnclose();
    }

    static void JL_ReverseDirection( void )
    {
        DrawCmd::ReverseDirection();
    }

    static void JL_ReBindTagGE( void )
    {
        DrawCmd::ReBindEdge();
    }

    static void JL_SplitTunnel( void )
    {
        DrawCmd::SplitDeal();
    }

	static void JL_MergeChimney( void )
	{
		DrawCmd::MergeChimney();
	}

	static void JL_DrawedQTagGE(void)
	{
		DrawCmd::DrawQTagGE();
	}

	static void JL_DrawedEDTagGE(void)
	{
		DrawCmd::DrawEffectRanGE();
	}

	static void JL_DeleteDirections( void )
	{
		DrawCmd::DeleteDirection();
	}

	static void JL_DeleteFanTags( void )
	{
		DrawCmd::DeleteFanTag();
	}

	static void JL_DeleteQTags( void )
	{
		DrawCmd::DeleteQTag();
	}

	static void JL_DeleteEDTags( void )
	{
		DrawCmd::DeleteEDTag();
	}


} ;


IMPLEMENT_ARX_ENTRYPOINT( CDrawVentCmdApp )

//ACED_ARXCOMMAND_ENTRY_AUTO(CDrawVentCmdApp, JL, _DrawJoint, DrawJoint, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawTunnel, DrawTunnel, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawArcTunnel, DrawArcTunnel, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawTTunnel, DrawTTunnel, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _ResetInTunnel, ResetInTunnel, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _ShowInTunnel, ShowInTunnel, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawLocalFan, DrawLocalFan, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawLocalFanTag, DrawLocalFanTag, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawChimney, DrawChimney, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawWindLibrary, DrawWindLibrary, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawDirection, DrawDirection, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawJoint, DrawJoint, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _AutoDraw, AutoDraw, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _AutoDirection, AutoDirection, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _TunnelJunctionEnclose, TunnelJunctionEnclose, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _ReverseDirection, ReverseDirection, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _ReBindTagGE, ReBindTagGE, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _SplitTunnel, SplitTunnel, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _MergeChimney, MergeChimney, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DeleteDirections, DeleteDirections, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DeleteFanTags, DeleteFanTags, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawedQTagGE, DrawedQTagGE, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DeleteQTags, DeleteQTages, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DrawedEDTagGE, DrawedEDTagGE, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CDrawVentCmdApp, JL, _DeleteEDTags, DeleteEDTages, ACRX_CMD_TRANSPARENT, NULL )
