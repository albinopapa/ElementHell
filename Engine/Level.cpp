#include "Level.h"
#include <cassert>

void Level::StartEarth0()
{
	timer = 0.0f;
	score = 0.0f;
	spritesEarth0a.resize(Earth0a::nSpritesEarth0a);
	for (int i = 0; i < Earth0a::nSpritesEarth0a; ++i)
	{
		const std::string bitmapFile = "Sprites\\Enemies\\Earth0a\\Earth0a" + std::to_string(i) + ".bmp";
		spritesEarth0a[i] = Surface(bitmapFile);
		assert(spritesEarth0a[i].GetWidth() == Earth0a::spriteEarth0aWidth
			&& spritesEarth0a[i].GetHeight() == Earth0a::spriteEarth0aHeight);
	}
	spritesBullet.resize(Earth0a::nSpritesBullet);
	for (int i = 0; i < Earth0a::nSpritesBullet; ++i)
	{
		const std::string bitmapFile = "Sprites\\Enemies\\Earth0aBul\\Earth0aBul" + std::to_string(i) + ".bmp";
		spritesBullet[i] = Surface(bitmapFile);
		assert(spritesBullet[i].GetWidth() == Earth0a::spriteBulletDim
			&& spritesBullet[i].GetHeight() == Earth0a::spriteBulletDim);
	}
}

void Level::UpdateEarth0(Player& player0, Player& player1, bool multiplayer, float dt)
{
	/* frame rate test
	if (dt > (1.0f / 56.0f) / 12.0f)
	{
		player0.Damaged(10);
	}*/
	timer += dt;
	spawnTimer += dt;
	switch (curSpawn)
	{
	case 0:
		if (spawnTimer > 6.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 100.0f }, { -20.0f, 10.0f } });
		}
		break;
	case 1:
		if (spawnTimer > 4.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 150.0f }, { -10.0f, 10.0f } });
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 150.0f }, { 10.0f, 10.0f } });
		}
	case 2:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 100.0f }, { -10.0f, 0.0f } });
		}
	case 3:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 150.0f }, { -10.0f, 0.0f } });
		}
	case 4:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 200.0f }, { -10.0f, 0.0f } });
		}
	case 5:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 250.0f }, { -10.0f, 0.0f } });
		}
	case 6:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 300.0f }, { -10.0f, 0.0f } });
		}
	case 7:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 350.0f }, { -10.0f, 0.0f } });
		}
	case 8:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 400.0f }, { -10.0f, 0.0f } });
		}
	case 9:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 450.0f }, { -10.0f, 0.0f } });
		}
	case 10:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.right, 500.0f }, { -10.0f, 0.0f } });
		}
	case 11:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 500.0f }, { 10.0f, 0.0f } });
		}
	case 12:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 450.0f }, { 10.0f, 0.0f } });
		}
	case 13:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 400.0f }, { 10.0f, 0.0f } });
		}
	case 14:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 350.0f }, { 10.0f, 0.0f } });
		}
	case 15:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 300.0f }, { 10.0f, 0.0f } });
		}
	case 16:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 250.0f }, { 10.0f, 0.0f } });
		}
	case 17:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 200.0f }, { 10.0f, 0.0f } });
		}
	case 18:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 150.0f }, { 10.0f, 0.0f } });
		}
	case 19:
		if (spawnTimer > 2.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { movementRegionEarth0a.left, 100.0f }, { 10.0f, 0.0f } });
		}
	case 20:
		if (spawnTimer > 14.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { 120.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.top }, { 0.0f, 10.0f } });
			enemiesEarth0a.emplace_back(Earth0a{ { 220.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.top }, { 0.0f, 10.0f } });
			enemiesEarth0a.emplace_back(Earth0a{ { 320.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.top }, { 0.0f, 10.0f } });
			enemiesEarth0a.emplace_back(Earth0a{ { 420.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.top }, { 0.0f, 10.0f } });
		}
	case 21:
		if (spawnTimer > 19.0f)
		{
			++curSpawn;
			spawnTimer = 0.0f;
			enemiesEarth0a.emplace_back(Earth0a{ { 120.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.bottom }, { 0.0f, -10.0f } });
			enemiesEarth0a.emplace_back(Earth0a{ { 220.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.bottom }, { 0.0f, -10.0f } });
			enemiesEarth0a.emplace_back(Earth0a{ { 320.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.bottom }, { 0.0f, -10.0f } });
			enemiesEarth0a.emplace_back(Earth0a{ { 420.0f - float(Earth0a::spriteEarth0aWidth / 2), movementRegionEarth0a.bottom }, { 0.0f, -10.0f } });
		}
	default:
		break;
	}
	for (auto& e : enemiesEarth0a)
	{
		e.Move(dt);
		e.Fire(dt);
		e.UpdateBullets(movementRegionEarth0aBullet, dt);
		e.HitPlayer(player0);
		e.GetHit(player0, dt);
		if (multiplayer)
		{
			e.HitPlayer(player1);
			e.GetHit(player1, dt);
		}
	}
	for (int i = 0; i < enemiesEarth0a.size(); ++i)
	{
		if (enemiesEarth0a[i].Clamp(movementRegionEarth0a) && enemiesEarth0a[i].BulletsEmpty())
		{
			std::swap(enemiesEarth0a[i], enemiesEarth0a.back());
			enemiesEarth0a.pop_back();
			--i;
		}
		else if (enemiesEarth0a[i].IsDead())
		{
			std::swap(enemiesEarth0a[i], enemiesEarth0a.back());
			enemiesEarth0a.pop_back();
			--i;
		}
	}
}

void Level::DrawEarth0(Graphics& gfx) const
{
	for (const auto& e : enemiesEarth0a)
	{
		e.Draw(spritesEarth0a, gfx);
		e.DrawBullets(spritesBullet, gfx);
	}
}