#pragma once
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Refreshable.h"
#include "EngineObject.h"

/**
 * @enum vecType
 * Enum wskazuje ró¿ne typy wektorów, które mog¹ byæ wykorzystywane
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
	/** Zmienna wskazuj¹ca czy figura jest teksturowana */
	bool isTextured;
	/** Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury */
	std::vector <glm::vec4> data;
public:
	/**
	 * Funkcja zwracaj¹ca liczbê wierzcho³ków figury
	 * @return Liczba wierzcho³ków figury
	 */
	int getDataCount();
	/**
	 * Funkcja zwracaj¹ca wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 * @return Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 */
	std::vector <glm::vec4> getData();
	/**
	 * Funkcja ustawiaj¹ca dane figury
	 * @param readData Wektor ze wszystkimi wektorami potrzebnymi do rysowania danej figury
	 */
	void setData(std::vector <glm::vec4> readData);
	/**
	 * Funkcja zmieniaj¹ca punkt w danej figurze
	 * @param point Dane nowego punktu
	 * @param index Numer punktu w wektorze danych
	 */
	void changePoint(std::vector <glm::vec4> point, int index);
	/**
	 * Funkcja zwracaj¹ca punkt danej figury
	 * @param index Numer punktu w wektorze danych
	 * @return Dane punktu
	 */
	std::vector <glm::vec4> getPoint(int index);
	/**
	 * Funkcja zwracaj¹ca czy dany obiekt jest teksturowany
	 * @return Zmienna mówi¹ca czy dany obiekt jest teksturowany
	 */
	bool getTextured();
	/**
	 * Funkcja ustawiaj¹ca czy dany obiekt jest teksturowany
	 * @param readVal Zmienna mówi¹ca czy dany obiekt powinien byæ teksturowany
	 */
	void setTextured(bool readVal);
	/**
	 * Funkcja zwiêkszaj¹ca indeks przes³any jako parametr o liczbê wierzcho³ków danej figury
	 * @param index Numer pierwszego wierzcho³ka danej figury w buferze
	 */
	void updateIndex(int& index);
};