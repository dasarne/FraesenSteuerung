#ifndef ENCODER_HPP_
#define ENCODER_HPP_

/**
 * @file Encoder.hpp
 * @author Arne v.Irmer (Arne.vonIrmer @ tu-dortmund.de)
 * @brief Hier wird der Rotary-Encoder ausgelesen
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <Steuerung.hpp>
#include "AS5600.h"
#include "Wire.h"

class Encoder
{
private:
    AS5600 as5600;
    int32_t nullPosition; ///< Die initiale Position um korrekt Null anzuzeigen 
    int16_t counts360 = 410; ///< Schritte für eine Umdrehung

public:
    
    /**
     * @brief Initialisierung der Hardware
     */
    void init()
    {
        as5600 = AS5600(&Wire);

        Wire.begin(WIRE_SDA, WIRE_SCL);

        as5600.begin(4);                        //  set direction pin.
        as5600.setDirection(AS5600_CLOCK_WISE); // default, just be explicit.
        as5600.setOutputMode(2);
        resetPos();
    }

    /**
     * @brief Setzen der Schritte für eine Umdrehung
     *
     * @param counts Anzahl der Schritte für eine Umdrehung
     */
    void setCounts360(u_int16_t counts)
    {
        counts360 = counts;
    }
    /**
     * @brief Auslesen der aktuellen Position
     * @return int32_t Aktuelle Position
     */
    int32_t readPos()
    {
        return (float)(as5600.getCumulativePosition() - nullPosition) / 4096 * counts360;
    }

    /**
     * @brief Wie viele volle Umdrehungen?
     * 
     * @return int32_t Anzahl der vollen Umdrehungen
     */
    int32_t readUmdrehungen()
    {
        return as5600.getRevolutions();
    }

    /**
     * @brief Setzt die aktuelle Position auf null
     */
    void resetPos()
    {
        //  set initial position
        as5600.resetCumulativePosition();
        nullPosition = as5600.getCumulativePosition();
    }
};

#endif // ENCODER_HPP_