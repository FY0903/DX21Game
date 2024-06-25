#include "lastScene.h"
#include "Game.h"
#include "startScene.h"

CLastScene::CLastScene(CManager* pManager) : CScene(pManager)
{
	m_pCObject = new CObject(true);
	m_pCText = new CText();
	m_pCRobo = new CRobo();
	m_pCTextBox = new CTextBox();
	m_pCRoboText = new CRoboText();
	m_pCField = new CField();
	m_pCExplotion = new CExplosion(true);
}

CLastScene::~CLastScene()
{
	delete(m_pCObject);
	delete(m_pCText);
	delete(m_pCRobo);
	delete(m_pCTextBox);
	delete(m_pCRoboText);
	delete(m_pCField);
	delete(m_pCExplotion);
}

void CLastScene::Update()
{
	m_nFrame = GetFrame();
	if (!(m_nFrame % 60)) m_pCField->Update();

	if (m_nFrame < 240)
	{
		m_cutScene = CLastScene::NICONICO;
	}
	else if (m_nFrame < 350)
	{
		m_cutScene = CLastScene::ROBO;
	}
	else if (m_nFrame < 500)
	{
		m_cutScene = CLastScene::END;
	}
	else if (m_nFrame < 640)
	{
		m_cutScene = CLastScene::EXPLOSION;
	}
	else
	{
		m_cutScene = CLastScene::CANGE;
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
		m_pCRobo->Update();
		m_pCTextBox->Update();
		m_pCRoboText->Update();
		break;
	case CLastScene::EXPLOSION:
		if (!(m_nFrame % 7)) m_pCExplotion->Update();
		break;
	case CLastScene::CANGE:
		m_pManager->m_pScene = new CStartScene(m_pManager);
		SetFrame(0);
		delete(this);
		break;
	}
}

void CLastScene::Draw()
{
	m_pCField->Draw();
	switch (m_cutScene)
	{
	case CLastScene::NICONICO:
		m_pCObject->Draw();
		break;
	case CLastScene::ROBO:
		m_pCRobo->Draw();
		break;
	case CLastScene::END:
		m_pCRobo->Draw();
		m_pCTextBox->Draw();
		m_pCRoboText->Draw();
		break;
	case CLastScene::EXPLOSION:
		m_pCTextBox->Draw();
		m_pCRobo->Draw();
		m_pCRoboText->Draw();
		m_pCExplotion->Draw();
		break;
	}
	m_pCText->Draw();
}
