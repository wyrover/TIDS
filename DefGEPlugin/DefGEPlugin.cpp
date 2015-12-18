#include "StdAfx.h"
#include "DefGEPlugin.h"

// 双线巷道
#include "DoubleTunnelDraw.h"

// 单线巷道
#include "SingleTunnelDraw.h"

// 多段线巷道
#include "PolyLineTunnelDraw.h"

// 单箭头
#include "SimpelDirectionDraw.h"

// 多段线箭头
#include "PolyLineDirectionDraw.h"

// 简单风机
#include "SimpleLocalFanDraw.h"
#include "FanTagGEDraw.h"

// 简单风筒
#include "SimpleChimneyDraw.h"


// 掘进工作面
#include "DoubleTTunnelDraw.h"
#include "PolyLineTTunnelDraw.h"

//节点
#include "SimpleJointDraw.h"

// 简单风库
#include "SimpleWindLibraryDraw.h"

//风筒的出入口风量
#include "QTagGEDraw.h"

//有效射程
#include "EffectRanTagGEDraw.h"

// 井筒
//#include "DoubleShaftDraw.h"

// 指北针
//#include "CompassBlockDraw.h"

// CircularJointDraw绘制效果的Jig实现
//#include "CircularJointDraw_Jig.h"

// SingleTunnelDraw绘制效果的Jig实现
//#include "SingleTunnelDraw_Jig.h"

// DoubleTunnelDraw绘制效果的Jig实现
//#include "DoubleTunnelDraw_Jig.h"

// DoubleArcTunnelDraw绘制效果的Jig实现
//#include "SingleArcTunnelDraw_Jig.h"

// DoubleArcTunnelDraw绘制效果的jig实现
//#include "DoubleArcTunnelDraw_Jig.h"

// DoubleWorkSurfaceDraw绘制效果的jig实现
//#include "DoubleWorkSurfaceDraw_Jig.h"

void DefGEPlugin::initialize( MineGEDrawManager* pGEDrawManager )
{
    BEGIN_REGISTER_MINEGE_DRAW( MineGEDrawManager, pGEDrawManager )
    // 巷道
    REGISTER_MINEGE_DRAW( Tunnel, DoubleTunnelDraw )
    REGISTER_MINEGE_DRAW( Tunnel, PolyLineTunnelDraw )
    REGISTER_MINEGE_DRAW( Tunnel, SingleTunnelDraw )
    //REGISTER_MINEGE_DRAW_JIG(Tunnel, DoubleTunnelDraw, DoubleTunnelDraw_Jig)
    //REGISTER_MINEGE_DRAW_JIG(Tunnel, SingleTunnelDraw, SingleTunnelDraw_Jig)

	// 弧线巷道
	REGISTER_MINEGE_DRAW( ArcTunnel, DoubleArcTunnelDraw )

    // 掘进工作面
    REGISTER_MINEGE_DRAW( TTunnel, DoubleTTunnelDraw )
    REGISTER_MINEGE_DRAW( TTunnel, PolyLineTTunnelDraw )

	//风流方向
    REGISTER_MINEGE_DRAW( WindDirection, PolyLineDirectionDraw )
    REGISTER_MINEGE_DRAW( WindDirection, SimpelDirectionDraw )

    // 风机
    REGISTER_MINEGE_DRAW( LocalFan, SimpleLocalFanDraw )
	REGISTER_MINEGE_DRAW( FanTagGE, FanTagGEDraw )

	//节点
	REGISTER_MINEGE_DRAW( Joint, SimpleJointDraw )


    // 风筒
    REGISTER_MINEGE_DRAW( Chimney, SimpleChimneyDraw )

	// 风库
	REGISTER_MINEGE_DRAW( WindLibrary, SimpleWindLibraryDraw )
	
	//风筒出入口风量
	REGISTER_MINEGE_DRAW( QTagGE, QTagGEDraw )

	REGISTER_MINEGE_DRAW( EffectRanTagGE, EffectRanTagGEDraw )

    //REGISTER_MINEGE_DRAW(Shaft, DoubleShaftDraw)

    // 指北针
    //REGISTER_MINEGE_DRAW(Compass, CompassBlockDraw)

    END_REGISTER_MINEGE_DRAW
}

void DefGEPlugin::unInitialize( MineGEDrawManager* pGEDrawManager )
{
    BEGIN_UNREGISTER_MINEGE_DRAW( MineGEDrawManager, pGEDrawManager )
    // 巷道
    UNREGISTER_MINEGE_DRAW( Tunnel, DoubleTunnelDraw )
    UNREGISTER_MINEGE_DRAW( Tunnel, PolyLineTunnelDraw )
    UNREGISTER_MINEGE_DRAW( Tunnel, SingleTunnelDraw )

	// 弧线巷道
	UNREGISTER_MINEGE_DRAW( ArcTunnel, DoubleArcTunnelDraw )

    // 掘进工作面
    UNREGISTER_MINEGE_DRAW( TTunnel, DoubleTTunnelDraw )
    UNREGISTER_MINEGE_DRAW( TTunnel, PolyLineTTunnelDraw )

    // 风流方向
    UNREGISTER_MINEGE_DRAW( WindDirection, PolyLineDirectionDraw )
    UNREGISTER_MINEGE_DRAW( WindDirection, SimpelDirectionDraw )

    // 风机
    UNREGISTER_MINEGE_DRAW( LocalFan, SimpleLocalFanDraw )
	UNREGISTER_MINEGE_DRAW( FanTagGE, FanTagGEDraw )

	// 节点
	UNREGISTER_MINEGE_DRAW( Joint, SimpleJointDraw )

    // 风筒
    UNREGISTER_MINEGE_DRAW( Chimney, SimpleChimneyDraw )

	// 风库
	UNREGISTER_MINEGE_DRAW( WindLibrary, SimpleWindLibraryDraw )

	//风筒出入口风量
	UNREGISTER_MINEGE_DRAW( QTagGE, QTagGEDraw )

	UNREGISTER_MINEGE_DRAW( EffectRanTagGE, EffectRanTagGEDraw )

    //UNREGISTER_MINEGE_DRAW(Shaft, DoubleShaftDraw)

    // 指北针
    //UNREGISTER_MINEGE_DRAW(Compass, CompassBlockDraw)

    END_UNREGISTER_MINEGE_DRAW
}

// 插件创建函数定义实现并导出
MINEGE_PLUGIN_CREATE_FUNC_IMPL( DefGEPlugin )

//MINEGE_DRAW_JIG_CREATE_FUNC_IMPL(Joint, CircularJointDraw, CircularJointDraw_Jig)

//MINEGE_DRAW_JIG_CREATE_FUNC_IMPL(Tunnel, SingleTunnelDraw, SingleTunnelDraw_Jig)
//MINEGE_DRAW_JIG_CREATE_FUNC_IMPL(Tunnel, DoubleTunnelDraw, DoubleTunnelDraw_Jig)
//
//MINEGE_DRAW_JIG_CREATE_FUNC_IMPL(ArcTunnel, DoubleArcTunnelDraw, SingleArcTunnelDraw_Jig)
//MINEGE_DRAW_JIG_CREATE_FUNC_IMPL(ArcTunnel, DoubleArcTunnelDraw, DoubleArcTunnelDraw_Jig)
//
//MINEGE_DRAW_JIG_CREATE_FUNC_IMPL(WorkSurface, DoubleWorkSurfaceDraw, DoubleWorkSurfaceDraw_Jig)

// draw创建函数实现宏(删除了，因为还不能确定draw的构造方式，目前的draw是通过"名称+ARX RTTI"来创建的)
