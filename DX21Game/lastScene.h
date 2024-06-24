#pragma once
#include "scene.h"
#include "object.h"

/**
 * @brief ������̃V�[���Ǘ�
 */
class CLastScene : public CScene
{
public:
	CLastScene(CManager* pManager);
	~CLastScene();

	/**
	 * @brief �X�V
	 */
	void Update() override;

	/**
	 * @brief �`��
	 */
	void Draw() override;

private:
	CObject* m_pCObject;

};

