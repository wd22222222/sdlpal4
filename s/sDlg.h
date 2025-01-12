
// sDlg.h: 头文件
//

#pragma once

#include "../main/cscript.h"
#include "cgetpaldata.h"
#include "CsDataGrid.h"
#include "CsTree.h"
#include "CFileDir.h"



// CsDlg 对话框
class CsDlg : public CDialogEx,public CFileDir
{
// 构造
public:
	CsDlg(CWnd* pParent = nullptr);	// 标准构造函数
	~CsDlg();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_S_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	virtual void PostNcDestroy();


// 实现
protected:
	HICON m_hIcon;

	void Set_Defalse_Tree();
	void DataUpDate(int Work);

	afx_msg	LRESULT Edit_ScriptEntry(WPARAM w_wparam, LPARAM w_lparam);

	afx_msg	LRESULT Edit_EnemyTeam(WPARAM w_wparam, LPARAM w_lparam);

	afx_msg LRESULT Text_Message(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_BattleField(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg	LRESULT Edit_EventObject(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_Store(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_PlayerLevelUPMagic(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_Player(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_Parameters(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Edit_Enemy(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_Magic(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_1(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Post_Text(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_Dir(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg	LRESULT Edit_Defalse(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT OK_Return(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Cansel_Return(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg	LRESULT Edit_ObjectItem(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg	LRESULT Edit_Poison(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg	LRESULT Edit_Scene(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg	LRESULT Edit_Invenyory(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg LRESULT Edit_Explain(WPARAM wParam, LPARAM lParam);
	afx_msg	LRESULT PackPal(WPARAM w_wparam, LPARAM w_lparam);
	afx_msg	LRESULT UnPackPal(WPARAM w_wparam, LPARAM w_lparam);
protected:
	afx_msg LRESULT Edit_Map(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTestRun(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTestEentryEdit(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnClose();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	//void Set_Tree();
	void Set_Archived_Tree();
	void Set_Begin_Tree( );
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void MessageText(LPCTSTR text);
	CEdit m_Edit;
	CTreeCtrl m_Tree;
	CButton m_ButtonOK;
	CButton m_ButtonCancel;
	CsDataGrid m_Grid;
	CsListCtrl m_ListCtrl;
	//存档文件缓存
	//PDATABUF pSaveData[10]{};

	CGetPalData * Pal = nullptr;
	//进程控制
	int JobCtrl{};//文件控制，从那个文件读取
	int WorkCtrl{};//进程控制，目前进行的是那个进程
	int okExit{};//退出时按下正常退出键=1
	CString  WorkDir;//工作目录
	CString  ExeDir;//执行文件所在目录
	//下拉表数据结构数组,存放不同的数据 -0- ITEM数据 
	SELECT_ITEN_ARRAY Select_Item_Array;
	class CTestData* pTestData{};//
	BOOL isUpData{ 0 };//是否需要重新载入数据

private:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg LRESULT OnSendMsgStr(WPARAM wParam, LPARAM lParam);

private:

	LPCSTR p_SrcToStr(int i);
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	afx_msg LRESULT OnPostMessageScript(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDeployOnTheMap(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Edit_The_Map(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Edit_ObjectName(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Edit_Dialog(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Edit_ObjectPict(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Edit_BettlePict(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Edit_Pal_Options(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnListscriptentry(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnScriptCaller(WPARAM wParam, LPARAM lParam);
};

