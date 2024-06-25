#include "startScene.h"
#include "Game.h"
#include "lastScene.h"

CStartScene::CStartScene(CManager* pManager) : CScene(pManager)
{
	m_pCBackGround = new CBackGround();
	m_pCField = new CField();
	m_pCMissile = new CMissile();
	m_pCExplotion = new CExplosion();
	m_pCObject = new CObject();
}

CStartScene::~CStartScene()
{
	delete(m_pCBackGround);
	delete(m_pCField);
	delete(m_pCMissile);
	delete(m_pCExplotion);
	delete(m_pCObject);
}

void CStartScene::Update()
{
	m_nFrame = GetFrame();

	m_pCBackGround->Update();

	if (m_nFrame < 180)
	{
		m_cutScene = CutScene::NOMAL;
	}
	else if (m_nFrame < 360)
	{
		m_cutScene = CutScene::MISSILE;
	}
	else if (m_nFrame < 500)
	{
		m_cutScene = CutScene::EXPLOTION;
	}
	else
	{
		m_pManager->m_pScene = new CLastScene(m_pManager);
		SetFrame(0);
		delete(this);
	}

	switch (m_cutScene)
	{
	case CutScene::MISSILE:
		if (!(m_nFrame % 60)) m_pCMissile->Update();
		break;
	case CutScene::EXPLOTION:
		if (!(m_nFrame % 7)) m_pCExplotion->Update();
		break;
	}

	if (!(m_nFrame % 60)) m_pCField->Update();
}

void CStartScene::Draw()
{
	switch (m_cutScene)
	{
	case CutScene::NOMAL:
		m_pCField->Draw();
		m_pCObject->Draw();
		break;
	case CutScene::MISSILE:
		m_pCField->Draw();
		m_pCObject->Draw();
		m_pCMissile->Draw();
		break;
	case CutScene::EXPLOTION:
		m_pCField->Draw();
		m_pCObject->Draw();
		m_pCExplotion->Draw();
		break;
	}
	m_pCBackGround->Draw();
}
