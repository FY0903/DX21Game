#include "lastScene.h"
#include "Game.h"


CLastScene::CLastScene(CManager* pManager) : CScene(pManager)
{
	m_pCObject = new CObject(true);
	m_pCText = new CText();
	m_pCRobo = new CRobo();
}

CLastScene::~CLastScene()
{
	delete(m_pCObject);
	delete(m_pCText);
	delete(m_pCRobo);
}

void CLastScene::Update()
{
	m_nFrame = GetFrame();

	if (m_nFrame < 240)
	{
		m_cutScene = CLastScene::NICONICO;
	}
	else if (m_nFrame < 1000)
	{
		m_cutScene = CLastScene::ROBO;
	}
	else
	{
		m_cutScene = CLastScene::END;
	}

	switch (m_cutScene)
	{
	case CLastScene::NICONICO:
		m_pCObject->Update();
		m_pCText->Update();
		break;
	case CLastScene::ROBO:
		m_pCRobo->Update();
		break;
	case CLastScene::END:
		break;
	}
}

void CLastScene::Draw()
{
	switch (m_cutScene)
	{
	case CLastScene::NICONICO:
		m_pCObject->Draw();
		break;
	case CLastScene::ROBO:
		m_pCRobo->Draw();
		break;
	}

	m_pCText->Draw();
}
