#pragma once
#include "scene.h"

/**
 * @brief ������̃V�[���Ǘ�
 */
class CLastScene : public CScene
{
	public:
	CLastScene(CManager* pManager) : CScene(pManager) {}
	~CLastScene() {}

	/**
	 * @brief �X�V
	 */
	void Update() override;

	/**
	 * @brief �`��
	 */
	void Draw() override;
};

