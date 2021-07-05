#pragma once
#include"CPersonaje.h"
#include<vector>
#include<ctime>
using namespace std;
using namespace System;
class CControladora
{
private:
	vector<CPersonaje*> personajes;
	int n;
	int segundos, tiempo;
	time_t inicio, actual, reloj;
	bool termino;
public:
	CControladora(Graphics^g, int segundos, int tiempo)
	{
		srand(time(NULL));
		n = rand() % 7 + 6;
		personajes = vector<CPersonaje*>();
		for (int i = 0; i < n; i++)
		{
			personajes.push_back(new CPersonaje(g));
		}
		this->segundos = segundos;
		this->tiempo = tiempo;
		time(&inicio);
		reloj = time(0);
		termino = false;
	}
	~CControladora()
	{
		while (personajes.size())
		{
			personajes.erase(personajes.begin());
			delete personajes.at(0);
		}
	}
	void mostrarTodos(Graphics^ g, Bitmap^ imgJugador)
	{
		for (int i = 0; i < personajes.size(); i++)
		{
			personajes.at(i)->mostrar(g, imgJugador);
		}
	}
	void moverTodos(Graphics^ g)
	{
		for (int i = 0; i < personajes.size(); i++)
		{
			personajes.at(i)->mover(g);
		}
	}
	void run(Graphics^ g, Bitmap^ imgJugador)
	{
		time(&actual);
		moverTodos(g);
		if (difftime(actual, inicio) >= segundos)
		{
			time(&inicio);
			mostrarTodos(g, imgJugador);
			for (int i = 0; i < personajes.size(); i++)
			{
				personajes.at(i)->reposicionar(g);
			}
		}
		//mostrarTodos(g, imgJugador);
		verificarColisiones();
		if (difftime(actual, reloj) >= 1)
		{
			reloj = time(0);
			tiempo--;
		}
		if (tiempo <= 0)
			termino = true;
		if (termino)
			showRanking(g);
	}
	void verificarColisiones()
	{
		for (int i = 0; i < personajes.size(); i++)
		{
			for (int j = i + 1; j < personajes.size(); j++)
			{
				if (personajes.at(i)->colision(personajes.at(j)->getRec()) 
					&& personajes.at(i)->getVisible() && personajes.at(j)->getVisible()
					&& personajes.at(i)->getTipo()!=personajes.at(j)->getTipo())
				{
					int conquistaAleatoria = rand() % 2;
					if (conquistaAleatoria==0)
					{
						personajes.at(i)->increasePuntos();
						personajes.at(i)->setWidth(personajes.at(i)->getWidth() + 30);
						personajes.at(i)->setHeight(personajes.at(i)->getHeight() + 30);
						personajes.at(j)->setVisible(false);
						personajes.at(j)->setColumna(personajes.at(i)->getTipo());
					}
					else
					{
						personajes.at(j)->increasePuntos();
						personajes.at(j)->setWidth (personajes.at(j)->getWidth()+30);
						personajes.at(j)->setHeight(personajes.at(j)->getHeight() + 30);
						personajes.at(i)->setVisible(false);
						personajes.at(i)->setColumna(personajes.at(j)->getTipo());
					}
					break;
				}
			}
		}
	}
	void showRanking(Graphics^g)
	{
		int puntosA=0, puntosB=0, puntosC=0, puntosD=0, puntosE=0, puntosF=0;
		for (int i = 0; i < personajes.size(); i++)
		{
			switch (personajes.at(i)->getTipo())
			{
				case 0: 
					puntosA += personajes.at(i)->getPuntos();
					break;
				case 1: 
					puntosB += personajes.at(i)->getPuntos();
					break;
				case 2: 
					puntosC += personajes.at(i)->getPuntos();
					break;
				case 3: 
					puntosD += personajes.at(i)->getPuntos();
					break;
				case 4: 
					puntosE += personajes.at(i)->getPuntos();
					break;
				case 5: 
					puntosF += personajes.at(i)->getPuntos(); 
					break;
			}
		}
		g->Clear(Color::Black);
		Font^ f = gcnew Font("Arial", 18);
		SolidBrush^ b = gcnew SolidBrush(Color::Red);
		String^ sms="Cantidad de Conquistados: "+"\n";
		sms += "Azul conquisto a " + Convert::ToSingle(puntosA)+"\n";
		sms += "Rojo conquisto a " + Convert::ToSingle(puntosB) + "\n";
		sms += "Morado conquisto a " + Convert::ToSingle(puntosC) + "\n";
		sms += "Plomo conquisto a " + Convert::ToSingle(puntosD) + "\n";
		sms += "Negro conquisto a " + Convert::ToSingle(puntosE) + "\n";
		sms += "Rosado conquisto a " + Convert::ToSingle(puntosF) + "\n";
		g->DrawString(sms, f, b, 50, 50);		
	}
	bool getTermino()
	{
		return termino;
	}
};
