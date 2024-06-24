#include "lastScene.h"
#include "Game.h"

CLastScene::CLastScene(CManager* pManager) : CScene(pManager)
{
	m_pCObject = new CObject(true);
}

CLastScene::~CLastScene()
{
	delete(m_pCObject);
}

void CLastScene::Update()
{
}

void CLastScene::Draw()
{
	m_pCObject->Draw();
}
