#ifndef STEUERUNG_HPP_
#define STEUERUNG_HPP_

/**
 * @file Steuerung.hpp
 * @author Arne v.Irmer (Arne.vonIrmer @ tu-dortmund.de)
 * @brief
 * Header, der alle nötigen Includes beinhaltet. Und allgemeine Definitionen
 *
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/** @name I²C-Defines */
/// @{
#define WIRE_SDA 33 ///< SDA
#define WIRE_SCL 32 ///< SCL
/// @}

#include <Arduino.h>
#include <Display.hpp>
#include <Encoder.hpp>
#include <Stepper.hpp>
#include <log.h>


#endif // STEUERUNG_HPP_