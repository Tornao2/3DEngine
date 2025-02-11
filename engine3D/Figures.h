#pragma once
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Refreshable.h"
#include "EngineObject.h"

/** @class Figures
 *  Klasa podstawowa wszystkich figur
 */
class Figures: public virtual Refreshable, public virtual EngineObject {
protected:
	/** Zmienna wskazująca czy figura jest teksturowana */
	bool isTextured;
	/** Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury */
	std::vector <glm::vec4> data;
public:
	/**
	 * Funkcja zwracająca liczbę wierzchołków figury
	 * @return Liczba wierzchołków figury
	 */
	int getDataCount();
	/**
	 * Funkcja zwracająca wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 * @return Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 */
	std::vector <glm::vec4> getData();
	/**
	 * Funkcja ustawiająca dane figury
	 * @param readData Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 */
	void setData(std::vector <glm::vec4> readData);
	/**
	 * Funkcja zmieniająca punkt w danej figurze
	 * @param point Dane nowego punktu
	 * @param index Numer punktu w wektorze danych
	 */
	void changePoint(std::vector <glm::vec4> point, int index);
	/**
	 * Funkcja zwracająca punkt danej figury
	 * @param index Numer punktu w wektorze danych
	 * @return Dane punktu
	 */
	std::vector <glm::vec4> getPoint(int index);
	/**
	 * Funkcja zwracająca czy dany obiekt jest teksturowany
	 * @return Zmienna mówiąca czy dany obiekt jest teksturowany
	 */
	bool getTextured();
	/**
	 * Funkcja ustawiająca czy dany obiekt jest teksturowany
	 * @param readVal Zmienna mówiąca czy dany obiekt powinien być teksturowany
	 */
	void setTextured(bool readVal);
	/**
	 * Funkcja zwiększająca indeks przesłany jako parametr o liczbę wierzchołków danej figury
	 * @param index Numer pierwszego wierzchołka danej figury w buferze
	 */
	void updateIndex(int& index);
};