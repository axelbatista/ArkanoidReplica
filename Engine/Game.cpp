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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(),
	rec(),
	paddle(),
	ball()
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	for (const auto& each : rec.getRecs()) {
		gfx.DrawRect(each.getSpot().x, each.getSpot().y, each.getSpot().x + 38, each.getSpot().y + 18, each.getColor());
	}
	gfx.DrawRect(paddle.getSpot().x, paddle.getSpot().y, paddle.getSpot().x + Paddle::width, paddle.getSpot().y + Paddle::height, paddle.getColor());
	paddle.move(wnd.mouse);
	gfx.DrawCircle(ball.getSpot().x, ball.getSpot().y, ball.getSize(), ball.getColor());
}

void Game::ComposeFrame()
{
	if (gameIsStarted) {
		for (int i = 0; i < 80; i++) {
			Rectangs tme = brd.chooseRandom();
			rec.add(tme);
		}
		brd.removeVec();
		gameIsStarted = false;
	}
}
