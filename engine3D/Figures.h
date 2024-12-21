#pragma once
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Refreshable.h"
#include "EngineObject.h"

/**
 * @enum vecType
 * Enum wskazuje r�ne typy wektor�w, kt�re mog� by� wykorzystywane
 */
typedef enum vecType {
	/** Wektor pozycji */
	pos,
	/** Wektor koloru */
	col,
	/** Wektor normalny */
	nor
}vecType;

/** @class Figures
 *  Klasa podstawowa wszystkich figur
 */
class Figures: public virtual Refreshable, public virtual EngineObject {
protected:
	/** Zmienna wskazuj�ca czy figura jest teksturowana */
	bool isTextured;
	/** Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury */
	std::vector <glm::vec4> data;
public:
	/**
	 * Funkcja zwracaj�ca liczb� wierzcho�k�w figury
	 * @return Liczba wierzcho�k�w figury
	 */
	int getDataCount();
	/**
	 * Funkcja zwracaj�ca wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 * @return Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 */
	std::vector <glm::vec4> getData();
	/**
	 * Funkcja ustawiaj�ca dane figury
	 * @param readData Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 */
	void setData(std::vector <glm::vec4> readData);
	/**
	 * Funkcja zmieniaj�ca punkt w danej figurze
	 * @param point Dane nowego punktu
	 * @param index Numer punktu w wektorze danych
	 */
	void changePoint(std::vector <glm::vec4> point, int index);
	/**
	 * Funkcja zwracaj�ca punkt danej figury
	 * @param index Numer punktu w wektorze danych
	 * @return Dane punktu
	 */
	std::vector <glm::vec4> getPoint(int index);
	/**
	 * Funkcja zwracaj�ca czy dany obiekt jest teksturowany
	 * @return Zmienna m�wi�ca czy dany obiekt jest teksturowany
	 */
	bool getTextured();
	/**
	 * Funkcja ustawiaj�ca czy dany obiekt jest teksturowany
	 * @param readVal Zmienna m�wi�ca czy dany obiekt powinien by� teksturowany
	 */
	void setTextured(bool readVal);
	/**
	 * Funkcja zwi�kszaj�ca indeks przes�any jako parametr o liczb� wierzcho�k�w danej figury
	 * @param index Numer pierwszego wierzcho�ka danej figury w buferze
	 */
	void updateIndex(int& index);
};