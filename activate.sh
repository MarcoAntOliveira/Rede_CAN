#!/bin/bash

# Diretórios
SENSOR_DIR="sensor"
CENTRAL_DIR="central"
NAVEGACAO_DIR="navegacao"

# Caminhos de destino para os firmwares
DEST_SENSOR="../firmware_sensor.hex"
DEST_CENTRAL="../firmware_central.hex"
DEST_NAVEGACAO="../firmware_navegacao.hex"

echo "🔧 Compilando código do sensor..."
(
  cd "$SENSOR_DIR" || exit 1
  pio run || { echo "❌ Falha ao compilar o sensor"; exit 1; }
  cp .pio/build/*/firmware.hex "$DEST_SENSOR" && echo "✅ Firmware do sensor copiado para $DEST_SENSOR"
)

echo "🔧 Compilando código da central..."
(
  cd "$CENTRAL_DIR" || exit 1
  pio run || { echo "❌ Falha ao compilar a central"; exit 1; }
  cp .pio/build/*/firmware.hex "$DEST_CENTRAL" && echo "✅ Firmware da central copiado para $DEST_CENTRAL"
)

echo "🔧 Compilando código de navegação..."
(
  cd "$NAVEGACAO_DIR" || exit 1
  pio run || { echo "❌ Falha ao compilar a navegação"; exit 1; }
  cp .pio/build/*/firmware.hex "$DEST_NAVEGACAO" && echo "✅ Firmware da navegação copiado para $DEST_NAVEGACAO"
)

echo "✅ Compilação e cópia finalizadas com sucesso."
