#pragma once
#include "scene.h"
#include "BackGround.h"
#include "field.h"
#include "missile.h"
#include "explotion.h"
#include "object.h"

/**
 * @brief 爆発するまでのシーン管理
 */
class CStartScene : public CScene
{
public:
	/**
	 * @brief 現在のカットシーン
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
	 * @brief 更新
	 */
	void Update() override;

	/**
	 * @brief 描画
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