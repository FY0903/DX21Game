#pragma once
#include "scene.h"
#include "object.h"
#include "text.h"
#include "robo.h"

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
	
	int m_nFrame{};
	CutScene m_cutScene{};
};

