#pragma once

class CManager;

/**
 * @brief シーンの基底クラス
 */
class CScene
{
protected:
	CManager* m_pManager;

public:
	CScene(CManager* pManager) : m_pManager(pManager) {}
	virtual ~CScene() {}
	
	/**
	 * @brief 更新
	 */
	virtual void Update() = 0;

	/**
	 * @brief 描画
	 */
	virtual void Draw() = 0;
};

/**
 * @brief シーン管理クラス
 */
class CManager
{
public:
	/**
	 * @brief 現在シーンのポインタ
	 */
	CScene* m_pScene;

	~CManager() { delete m_pScene; }

	/**
	 * @brief 更新
	 */
	void Update() { m_pScene->Update(); }

	/**
	 * @brief 描画
	 */
	void Draw() { m_pScene->Draw(); }
};