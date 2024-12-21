#pragma once
#include "Figures.h"

/** @class Figures
 *  Klasa obiektów rysowanych za pomoc¹ glDrawElements
 */
class IndiceDraw: public virtual Figures{
protected:
	/** Wektor posiadaj¹cy dane jak ³¹czyæ kolejne wierzcho³ki aby utrzymaæ chcian¹ figurê */
	std::vector<int> indices;
public:
	/**
	 * Funkcja zwracaj¹ca wektor wskazuj¹cy jak rysowaæ kolejne œciany figury
	 * @return Wektor z danymi jak rysowaæ kolejne œciany figury
	 */
	std::vector<int> getIndices();
	/**
	 * Funkcja ustawiaj¹ca jak rysowaæ dan¹ figurê
	 * @param readIndices Dane jak rysowaæ dan¹ figurê
	 */
	void setIndices(std::vector<int> readIndices);
};