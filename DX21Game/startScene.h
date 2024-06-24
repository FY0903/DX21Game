#pragma once
#include "scene.h"
#include "BackGround.h"
#include "field.h"
#include "missile.h"
#include "explotion.h"
#include "object.h"

/**
 * @brief ��������܂ł̃V�[���Ǘ�
 */
class CStartScene : public CScene
{
public:
	/**
	 * @brief ���݂̃J�b�g�V�[��
	 */
	enum CutScene
	{
		NOMAL,
		MISSILE,
		EXPLOTION,
	};

public:
	CStartScene(CManager* pManager);
	~CStartScene();

	/**
	 * @brief �X�V
	 */
	void Update() override;

	/**
	 * @brief �`��
	 */
	void Draw() override;

private:
	CBackGround* m_pCBackGround;
	CField* m_pCField;
	CMissile* m_pCMissile;
	CExplotion* m_pCExplotion;
	CObject* m_pCObject;

	int m_nFrame{};
	int m_nAnimeFrame{};
	bool m_bUpdate{};
	CutScene m_cutScene{};
};