#pragma once
#include<iostream>
using namespace std;
using namespace System::Drawing;

enum movimiento { arriba, derecha, izquierda, abajo, ninguno };
class CMovil
{
protected:
	int x, dx, dy, y, fil, col, maxcol, maxfil, width, height;
	movimiento direccion;
	bool eliminar;
	int tipo;
public:
	CMovil()
	{
		x = y = 0;
		dx = dy = 0;
		fil = col = 0;
		maxcol = maxfil = 0;
		eliminar = false;
		direccion = ninguno;
		tipo = 0;
		width = height = 50;
	}
	~CMovil()
	{

	}
	virtual void mover(Graphics^ g) { cout << "Error de mover Base"; }
	virtual void mostrar(Graphics^ g, Bitmap^ bmp) { cout << "Error de mostrar Base"; }
	void setX(int ex)
	{
		x = ex;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setDx(int edx)
	{
		dx = edx;
	}
	void setDy(int edy)
	{
		dy = edy;
	}
	void setHeight(int nuevo)
	{
		height = nuevo;
	}
	void setWidth(int newLarge)
	{
		width = newLarge;
	}
	void setColumna(int nuevo)
	{
		col = nuevo;
	}
	void setFila(int nuevo)
	{
		fil = nuevo;
	}
	void setMaxColumna(int nuevo)
	{
		maxcol = nuevo;
	}
	void setMaxFila(int nuevo)
	{
		maxfil = nuevo;
	}
	void setDireccion(movimiento edireccion)
	{
		direccion = edireccion;
	}
	void setEliminar(bool nuevo)
	{
		eliminar = nuevo;
	}
	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getHeight() { return height; }
	int getWidth() { return width; }
	bool getEliminar() { return eliminar; }
	int geFila() { return fil; }
	int getColumna() { return col; }
	int getMaxFila() { return maxfil; }
	int getMaxColumna() { return maxcol; }
	movimiento getDireccion() { return direccion; }
	virtual void movinvalido(int n)
	{
		dx = dy = 0;
	}
	int getTipo()
	{
		return tipo;
	}
	Rectangle getFutRec()
	{
		return Rectangle(x + dx, y + dy, width, height);
	}
	void reposicionar(Graphics^g)
	{
		x = rand() % ((int)g->VisibleClipBounds.Width - this->getWidth());
		y = rand() % ((int)g->VisibleClipBounds.Height - this->getHeight());
	}
	Rectangle getRec()
	{
		return Rectangle(x, y, width, height);
	}
	bool colision(Rectangle rec)
	{
		return rec.IntersectsWith(this->getRec());
	}
};