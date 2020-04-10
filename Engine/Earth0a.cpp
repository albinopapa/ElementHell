#include "Earth0a.h"
#include <cassert>

Earth0a::Earth0a(const VecF& pos, const VecF& vel)
	:
	pos(pos),
	vel(vel.GetNormalized() * speed)
{
}

void Earth0a::Move(float dt)
{
	pos += vel * dt;
}

bool Earth0a::Clamp(const RectF& movementRegionEarth0a)
{
	if (pos.x < movementRegionEarth0a.left)
	{
		return true;
	}
	else if (pos.x > movementRegionEarth0a.right)
	{
		return true;
	}
	if (pos.y < movementRegionEarth0a.top)
	{
		return true;
	}
	else if (pos.y > movementRegionEarth0a.bottom)
	{
		return true;
	}
	return false;
}

void Earth0a::Fire(float dt)
{
	if (RectF(pos, spriteEarth0aWidth, spriteEarth0aHeight).isContained(Graphics::GetGameRectF()))
	{
		const VecF earth0aCenter{ pos.x + float(spriteEarth0aWidth) / 2.0f,
			pos.y + float(spriteBulletDim) / 2.0f  + 3.0f};
		curFireBaseEarth0aAnim += dt;
		while (curFireBaseEarth0aAnim >= maxFireTimeEarth0aAnim)
		{
			curFireBaseEarth0aAnim -= maxFireTimeEarth0aAnim;
			bullets.emplace_back(Bullet{
				{ earth0aCenter.x - float(spriteBulletDim) / 2.0f, earth0aCenter.y - float(spriteBulletDim) / 2.0f },
				VecF{ vel.x, vel.y + bulletSpeed } });
		}
	}
	else
	{
		curFireBaseEarth0aAnim = 0.0f;
	}
}

void Earth0a::UpdateBullets(const RectF& movementRegionBullet, float dt)
{
	for (auto& bc : bullets)
	{
		bc.Move(dt);
		bc.Animate(dt);
	}

	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].Clamp(movementRegionBullet))
		{
			PopBullet(i);
			--i;
		}
	}
}

void Earth0a::PopBullet(int i)
{
	std::swap(bullets[i], bullets.back());
	bullets.pop_back();
}

bool Earth0a::BulletsEmpty() const
{
	return bullets.size() == 0;
}

void Earth0a::Draw(const std::vector<Surface>& sprites, Graphics& gfx) const
{
	const int iEarth0a = int(curFireBaseEarth0aAnim * nSpritesEarth0a / maxFireTimeEarth0aAnim);
	gfx.DrawSprite(int(pos.x), int(pos.y), sprites[iEarth0a], gfx.GetGameRect());
}

void Earth0a::DrawBullets(const std::vector<Surface>& spritesBullet, Graphics& gfx) const
{
	for (const auto& bc : bullets)
	{
		bc.Draw(spritesBullet, gfx);
	}
}

Earth0a::Bullet::Bullet(const VecF& pos, const VecF& vel)
	:
	pos(pos),
	vel(vel)
{
}

void Earth0a::Bullet::Move(float dt)
{
	pos += vel * dt;
}

void Earth0a::Bullet::Animate(float dt)
{
	curAnimTime += dt;
	while (curAnimTime >= maxAnimTime)
	{
		curAnimTime -= maxAnimTime;
	}
}

bool Earth0a::Bullet::Clamp(const RectF& bulletRegion)
{
	if (pos.x < bulletRegion.left)
	{
		return true;
	}
	else if (pos.x > bulletRegion.right)
	{
		return true;
	}
	if (pos.y < bulletRegion.top)
	{
		return true;
	}
	else if (pos.y > bulletRegion.bottom)
	{
		return true;
	}
	return false;
}

void Earth0a::Bullet::Draw(const std::vector<Surface>& sprites, Graphics& gfx) const
{
	const int iBullet = int(curAnimTime * nSpritesBullet / maxAnimTime);
	gfx.DrawSprite(int(pos.x), int(pos.y), sprites[iBullet], gfx.GetGameRect());
}
