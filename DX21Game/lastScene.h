#pragma once
#include "scene.h"
#include "object.h"
#include "text.h"
#include "robo.h"

/**
 * @brief 爆発後のシーン管理
 */
class CLastScene : public CScene
{
public:
	/**
	* @brief 現在のカットシーン
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
	 * @brief 更新
	 */
	void Update() override;

	/**
	 * @brief 描画
	 */
	void Draw() override;

private:
	CObject* m_pCObject;
	CText* m_pCText;
	CRobo* m_pCRobo;
	
	int m_nFrame{};
	CutScene m_cutScene{};
};

