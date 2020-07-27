#ifndef RF_RX_H
#define RF_RX_H

#include "nRF24L01.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CE_PIN  0
#define CSN_PIN 1

#define OFF_TO_POWERDOWN_MILLIS        100
#define POWERDOWN_TO_RXTX_MODE_MILLIS  5
#define CE_TRANSMISSION_MICROS         10
#define CONFIG_REG_SETTINGS_FOR_RX_MODE (_BV(PWR_UP) | _BV(PRIM_RX) | _BV(EN_CRC))

#define BITRATE250KBPS  0b00100000
#define BITRATE1MBPS    0b00000000
#define BITRATE2MBPS    0b00001000

#define RF_TX_PWR_MAX  0b110
#define RF_TX_PWR_HIGH 0b100
#define RF_TX_PWR_LOW  0b010
#define RF_TX_PWR_MIN  0b000

#define _BV(bit)			 (1<<bit)
#define ce(state)            set_GPIO_pin(CE_PIN, state)
#define csn(state)           set_GPIO_pin(CSN_PIN, state)
#define flushTx()            writeRegister(FLUSH_TX, 0xFF)
#define flushRx()            writeRegister(FLUSH_RX, 0xFF)
#define getStatus()          readRegister(STATUS_NRF)
#define resetStatus()        writeRegister(STATUS_NRF, _BV(RX_DR) | _BV(TX_DS) | _BV(MAX_RT))
#define setChannel(channel)  writeRegister(RF_CH,channel)

void preInit (void * spi_handle);

uint8_t initRadio (uint8_t * receive_address, uint8_t bitrate, uint8_t channel);
uint8_t hasData();
void readData (void * data, uint8_t size);


#endif
