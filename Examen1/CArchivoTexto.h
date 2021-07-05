#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class CArchivoTexto
{
private:

public:
	CArchivoTexto() {}
	~CArchivoTexto() {}
	vector<string>LeerDesdeArchivo(string rutaArchivo)
	{
		string linea;
		vector<string>resultado;
		ifstream miarchivo(rutaArchivo);
		if (miarchivo.fail())
			cout << "Error al leer desde archivo inexistente";
		else
		{
			while (!miarchivo.eof())
			{
				getline(miarchivo, linea);
				resultado.push_back(linea);
			}
			miarchivo.close();
		}
		return resultado;
	}
	void GrabarEnArchivo(string rutaArchivo, vector<string>datoagrabar)
	{
		//ofstream miarchivo(ruta_archivo); // BORRAR EL CONTENIDO DEL ARCHIVO ANTES DE ESCRIBIR LO NUEVO
		ofstream miarchivo(rutaArchivo, std::ofstream::app); // LOS DATOS NUEVOS LOS COLOCA AL FINAL. MANTIENE LO ANTERIOR
		if (miarchivo.fail())
			cout << "Error de grabar en archivo";
		else
		{
			for (int i = 0; i < datoagrabar.size(); i++)
			{
				miarchivo << datoagrabar.at(i);
			}
			miarchivo.flush();
			miarchivo.close();
		}
	}
	int retornarNumero(string rutaArchivo, int fila)
	{
		fstream miarchivo(rutaArchivo);
		vector<string>datosleidos;
		if (miarchivo.fail())
			cout << "Error de archivo inexistente";
		else
		{
			datosleidos = LeerDesdeArchivo(rutaArchivo);
		}
		return System::Convert::ToInt32(gcnew System::String(datosleidos.at(fila).c_str()));
	}

};