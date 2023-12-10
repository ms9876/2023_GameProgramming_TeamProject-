#include "pch.h"
#include "SceneMgr.h"
#include "Start_Scene.h"
#include "Game_Scene.h"
#include "StartScene.h"
#include "MainScene_B.h"
#include "MainScene_W.h"
#include "SubSceneOne.h"
#include "SubSceneTwo.h"
#include "EndScene.h"

void SceneMgr::Init()
{
	m_pCurScene = nullptr;
	// �� ���
	// ������ ��
	RegisterScene(L"Start_Scene",std::make_shared<Start_Scene>());
	RegisterScene(L"Game_Scene", std::make_shared<Game_Scene>());

	// �츮 ��
	RegisterScene(L"StartScene", std::make_shared<StartScene>());
	RegisterScene(L"MainScene_B", std::make_shared<MainScene_B>());
	RegisterScene(L"MainScene_W", std::make_shared<MainScene_W>());
	RegisterScene(L"SubSceneOne", std::make_shared<SubSceneOne>());
	RegisterScene(L"SubSceneTwo", std::make_shared<SubSceneTwo>());
	RegisterScene(L"EndScene", std::make_shared<EndScene>());

	// ù �� ����
	//LoadScene(L"StartScene");
	LoadScene(L"EndScene");
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}

void SceneMgr::LoadScene(const wstring& _scenename)
{
	// ���� ������
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		m_pCurScene->Init();
	}
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), {_scenename, _scene});
}
