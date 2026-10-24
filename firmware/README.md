# Firmware (ESP-IDF project)

This will hold the ESP-IDF project for the sensor node. Not yet initialized with real code — fill in as each phase lands.

## Setup (once ESP-IDF is installed)

```bash
cd firmware
idf.py set-target esp32
idf.py menuconfig   # Wi-Fi creds, MQTT broker URI, etc. — Phase 0/1
idf.py build
idf.py -p <PORT> flash monitor
```

## MQTT dependency (ESP-IDF v6+)

MQTT is a managed component, not a built-in example, from ESP-IDF v6 onward:

```bash
idf.py add-dependency "espressif/mqtt"
```

Reference example: `protocols/mqtt` in the `esp-idf` repo (the old `protocols/mqtt/tcp` and `protocols/mqtt/ssl_mutual_auth` paths were removed in v6).

## Phase map

- `main/` — app entry point: DHT11 read → MQTT publish. Grows TLS, cert auth, and OTA-check logic as phases 2–4 land.
- `components/` — custom components as they're split out (e.g. firmware-signature verification, device identity helpers).

## Chip revision check (before Phase 4)

```bash
esptool.py chip_id
```

Confirms ESP32-D0WD-V3 (rev ≥ 3.0) before attempting Secure Boot V2 — older silicon uses the V1 scheme with different steps.
