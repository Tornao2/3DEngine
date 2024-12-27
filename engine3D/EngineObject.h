#pragma once

/** @class EngineObject
 *  Klasa podstawowa wszystkich obiekt�w silnika
 */
class EngineObject {
protected:
    /** Indentyfikator obiektu */
	int id;
    /** Zmienna wskazuj�ca czy obiekt jest aktywny */
	bool active;
public:
    /**
     * Funkcja zwracaj�ca indentyfikator danego obiektu
     * @return Indentyfikator danego obiektu
     */
    int getId();
    /**
     * Funkcja ustawiaj�ca indentyfikator danego obiektu
     * @param id Indentyfikator danego obiektu
     */
    void setId(int id);
    /**
     * Funkcja zwracaj�ca czy dany obiekt jest aktywny
     * @return Warto�� oznaczaj�ca czy obiekt jest aktywny
     */
    bool isActive();
    /**
     * Funkcja ustawiaj�ca czy dany obiekt powinien by� aktywny
     * @param readActive Warto�� oznaczaj�ca czy dany obiekt powinien by� aktywny
     */
    void setActive(bool readActive);
};
