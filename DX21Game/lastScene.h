#pragma once
#include "scene.h"
#include "object.h"
#include "text.h"
#include "robo.h"
#include "textBox.h"
#include "roboText.h"
#include "field.h"
#include "explosion.h"

/**
 * @brief ������̃V�[���Ǘ�
 */
class CLastScene : public CScene
{
public:
	/**
	* @brief ���݂̃J�b�g�V�[��
	*/
	enum CutScene
	{
		NICONICO,
		ROBO,
		END,
		EXPLOSION,
		CANGE,
	};

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
	CText* m_pCText;
	CRobo* m_pCRobo;
	CTextBox* m_pCTextBox;
	CRoboText* m_pCRoboText;
	CField* m_pCField;
	CExplosion* m_pCExplotion;
	
	int m_nFrame{};
	CutScene m_cutScene{};
};

