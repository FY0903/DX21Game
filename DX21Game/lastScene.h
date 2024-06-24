#pragma once
#include "scene.h"
#include "object.h"

/**
 * @brief 爆発後のシーン管理
 */
class CLastScene : public CScene
{
public:
	CLastScene(CManager* pManager);
	~CLastScene();

	/**
	 * @brief 更新
	 */
	void Update() override;

	/**
	 * @brief 描画
	 */
	void Draw() override;

private:
	CObject* m_pCObject;

};

