#pragma once
#include "Figures.h"

/** @class Figures
 *  Klasa obiekt�w rysowanych za pomoc� glDrawElements
 */
class IndiceDraw: public virtual Figures{
protected:
	/** Wektor posiadaj�cy dane jak ��czy� kolejne wierzcho�ki aby utrzyma� chcian� figur� */
	std::vector<int> indices;
public:
	/**
	 * Funkcja zwracaj�ca wektor wskazuj�cy jak rysowa� kolejne �ciany figury
	 * @return Wektor z danymi jak rysowa� kolejne �ciany figury
	 */
	std::vector<int> getIndices();
	/**
	 * Funkcja ustawiaj�ca jak rysowa� dan� figur�
	 * @param readIndices Dane jak rysowa� dan� figur�
	 */
	void setIndices(std::vector<int> readIndices);
};