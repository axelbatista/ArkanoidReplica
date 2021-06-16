/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Colliding.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rec(),
	paddle(),
	ball(),
	sound1(L"Sounds\\arkpad.wav"),
	sound2(L"Sounds\\arkbrick.wav")
{}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	paddle.move(wnd.mouse);
	ball.move();
	ball.isTouchingWall();
	if (Colliding::isTouching(ball, paddle)) {
		ball.setDir(1, -1);
		if (ball.isStarted())
		sound1.Play();
	}
	if (rec.isTouchingRecs(ball))
		sound2.Play();
}

void Game::ComposeFrame()
{
	if (!ball.isStarted()) {
		if (wnd.kbd.KeyIsPressed(VK_SPACE) && Colliding::isTouching(ball,paddle)) {
			Colliding::applyBall(ball, paddle);
		}
	}
	rec.draw(gfx);
	paddle.draw(gfx);
	SpriteCodex::DrawBall(ball.getSpot(), gfx);
}
