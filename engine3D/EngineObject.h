#pragma once

/** @class EngineObject
 *  Klasa podstawowa wszystkich obiektów silnika
 */
class EngineObject {
protected:
    /** Indentyfikator obiektu */
	int id;
    /** Zmienna wskazuj¹ca czy obiekt jest aktywny */
	bool active;
public:
    /**
     * Funkcja zwracaj¹ca indentyfikator danego obiektu
     * @return Indentyfikator danego obiektu
     */
    int getId();
    /**
     * Funkcja ustawiaj¹ca indentyfikator danego obiektu
     * @param id Indentyfikator danego obiektu
     */
    void setId(int id);
    /**
     * Funkcja zwracaj¹ca czy dany obiekt jest aktywny
     * @return Wartoœæ oznaczaj¹ca czy obiekt jest aktywny
     */
    bool isActive();
    /**
     * Funkcja ustawiaj¹ca czy dany obiekt powinien byæ aktywny
     * @param readActive Wartoœæ oznaczaj¹ca czy dany obiekt powinien byæ aktywny
     */
    void setActive(bool readActive);
};
