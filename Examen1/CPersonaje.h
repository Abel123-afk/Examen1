#pragma once
#include"CMovil.h"
class CPersonaje: public CMovil
{
private:
	int paciencia;
	bool visible;
	int puntos;
public:
	CPersonaje(Graphics^ g)
	{
		paciencia = 95;
		x = rand() % ((int)g->VisibleClipBounds.Width - width);
		y = rand() % ((int)g->VisibleClipBounds.Height - height);
		do
		{
			dx = (rand() % 3 - 1) * 20;
			dy = (rand() % 3 - 1) * 20;
		} while (dx == 0 && dy == 0);
		col = rand() % 2;
		tipo = col;
		maxcol = 6;
		maxfil = 5;
		//Tipo 0->Azul;
		//Tipo 1->Rojo;
		visible = true;//SI es false ya no podra unirse a otros
		puntos = 0;
	}
	~CPersonaje(){}
	void mover(Graphics^ g) 
	{ 
		if (x + dx<0 || x + dx + width>g->VisibleClipBounds.Width ||
			y + dy<0 || y + dy + height>g->VisibleClipBounds.Height || rand() % 100 >= paciencia)
		{
			movinvalido(0);
		}
		else
		{
			x += dx;
			y += dy;
		}
	}
	void mostrar(Graphics^ g, Bitmap^ bmp) 
	{
		Rectangle sectionShow = Rectangle (col * bmp->Width / maxcol, fil * bmp->Height / maxfil, bmp->Width / maxcol, bmp->Height / maxfil);
		g->DrawImage(bmp, this->getRec(), sectionShow, GraphicsUnit::Pixel);
		fil++;
		if (fil >= maxfil)
		{
			fil = 0;
		}

	}
	void movinvalido(int n)
	{
		do
		{
			dx = (rand() % 3 - 1) * 10;
			dy = (rand() % 3 - 1) * 10;
		} while (dx == 0 && dy == 0);
	}
	bool getVisible()
	{
		return visible;
	}
	void setVisible(bool nuevo)
	{
		visible = nuevo;
	}
	void increasePuntos()
	{
		puntos++;
	}
	int getPuntos()
	{
		return puntos;
	}
};