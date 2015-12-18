#include "StdAfx.h"
#include "resource.h"

#include "UIHelper.h"
#include "ReactorHelper.h"
//#include "../MineGE/HelperClass.h"
//#include "../ArxHelper/HelperClass.h"

// 定义注册服务名称
#ifndef VENT_TVNS_SERVICE_NAME
#define VENT_TVNS_SERVICE_NAME _T("VENTEVALUATE_SERVICE_NAME")
#endif

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CTVNSCaculApp : public AcRxArxApp {

public:
	CTVNSCaculApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		ReactorHelper::CreateSelectedGE_EditorReactor();	
		acrxRegisterService( VENT_TVNS_SERVICE_NAME );

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;
		
		ReactorHelper::RemoveSelectedGE_EditorReactor();
		delete acrxServiceDictionary->remove( VENT_TVNS_SERVICE_NAME );
		
		UIHelper::DestroyDataInputDockBar();

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}

	static void JL_baseParamDlg( void )
	{
		UIHelper::ShowBaseParamDlg();
	}

	static void JL_caculParamDlg()
	{
		UIHelper::InputBaseParam();
	}

	static void JL_caculateQ()
	{
		UIHelper::CaculateRequirAirFlow();
	}

	static void JL_caculateR()
	{
		UIHelper::CaculateChimwindage();
	}

	static void JL_CaculateLeakage()
	{
		UIHelper::LeakageCacul();
	}

	static void JL_LeakageParamInput()
	{
		UIHelper::InputLeakageParam();
	}

	static void JL_FansEnsured()
	{
		UIHelper::EnsureFan();
	}

	static void JL_FanCheaked()
	{
		UIHelper::CheakFan();
	}

	static void JL_InsertNewFan()
	{
		UIHelper::InsertFan();
	}

	static void JL_FindFan()
	{
		UIHelper::FindFanByDB();
	}
	static void JL_Test( void )
	{
		//UIHelper::EnsureFan();
		//CString ss;
		//acutPrintf(_T("\nxxx:%s"),ss);
		//TWSDatas();
		//TunnelDatas();
		//ChimneyDatas();
		//BaseparamDatas();
		//UIHelper::LeakageCacul();
		//SetAlpha(0);
		//CString ret = GetAlpha(0,_T("400"));
		//UIHelper::ChimSort();
		//acutPrintf(_T("\n\nret->%s"),ret);
	}

	static void JL_testDataInputDlg( void )
	{
		UIHelper::ShowDataInputDockBar();
	}


} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CTVNSCaculApp)
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _Test, hdtest, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _testDataInputDlg, testDataInputDlg, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _baseParamDlg, hdBaseParamdlg, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _caculParamDlg, hdCaculParamdlg, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _caculateQ, hdCaculateQ, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _caculateR, caculateR, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _CaculateLeakage, CaculateLeakage, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _LeakageParamInput, LeakageParamInput, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _FansEnsured, FansEnsured, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _FanCheaked, FanCheaked, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _InsertNewFan, InsertNewFan, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CTVNSCaculApp, JL, _FindFan, FindFan, ACRX_CMD_TRANSPARENT, NULL )
