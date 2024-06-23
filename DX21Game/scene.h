#pragma once

class CManager;

/**
 * @brief �V�[���̊��N���X
 */
class CScene
{
protected:
	CManager* m_pManager;

public:
	CScene(CManager* pManager) : m_pManager(pManager) {}
	virtual ~CScene() {}
	
	/**
	 * @brief �X�V
	 */
	virtual void Update() = 0;

	/**
	 * @brief �`��
	 */
	virtual void Draw() = 0;
};

/**
 * @brief �V�[���Ǘ��N���X
 */
class CManager
{
public:
	/**
	 * @brief ���݃V�[���̃|�C���^
	 */
	CScene* m_pScene;

	~CManager() { delete m_pScene; }

	/**
	 * @brief �X�V
	 */
	void Update() { m_pScene->Update(); }

	/**
	 * @brief �`��
	 */
	void Draw() { m_pScene->Draw(); }
};