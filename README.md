# Secure ESP32 IoT Device with Encrypted Communication and Signed Firmware Updates

A layered ("defense-in-depth") security retrofit for a cheap ESP32 sensor node — built as a 3rd-year mini project at Lloyd Institute of Engineering and Technology (AKTU), continuing into a 4th-year major project.

Most student IoT projects send real sensor data over the network with zero protection and run whatever code gets flashed to them. This project starts from that same plain pipeline and adds one real security layer at a time — TLS-encrypted MQTT, device certificates, signed OTA firmware updates, and (dev-mode) Secure Boot V2 / Flash Encryption — measuring the cost of each layer and demonstrating, live, that it actually stops the attack it claims to stop.

> Full build plan, sourcing, skills, and research-documentation guide: see the [Build and Research Plan](https://claude.ai/code/artifact/0b7e4bdd-7983-4559-b9a6-2668edc062b4).

## Why this project

A hacked IoT device isn't valuable for its data — it's valuable as a foothold (Mirai, Verkada). Almost no student-scale IoT project defends against that, because each individual device feels too unimportant to protect. This project treats a boring water-quality sensor node as what it actually is: a tiny internet-connected computer that needs the same baseline trust guarantees as anything else on the network.

**Research gap:** academic literature on lightweight crypto and secure OTA is mostly survey/theory-level; there are few reproducible, low-cost, full end-to-end demonstrations on commodity hardware (ESP32) with a documented threat model and measured overhead. This project builds and demonstrates that pipeline rather than just describing it.

## Roadmap

**Year 3 — build the trust chain, in order:**
1. Plain baseline pipeline (sensor → ESP32 → MQTT → dashboard, unencrypted)
2. TLS-encrypted MQTT (port 8883)
3. Signed OTA updates — with a **live demo of a tampered/unsigned update being rejected**
4. Device certificates (basic PKI, per-device identity)
5. Secure Boot V2 + Flash Encryption — **development mode first**, on a sacrificial board
6. Written threat model (attack matrix: rogue broker, fake device, tampered firmware, replay, rollback)

**Year 4 — extend it:**
- OTA hardening: rollback / anti-downgrade protection
- Rule-based anomaly detection on device behavior
- Small multi-device fleet

Signed OTA is built *before* the irreversible eFuse-based steps (Secure Boot / Flash Encryption) deliberately: OTA is software-only and reversible, eFuse changes are permanent and can brick a board.

## Hardware

| Component | Requirement |
|---|---|
| ESP32 dev board | **ESP32-WROOM-32E module, chip revision ≥ v3.0** (ESP32-D0WD-V3) — required for Secure Boot V2. Pin count (30-pin vs 38-pin) doesn't matter; the silicon revision does. Verify with `esptool chip_id`. |
| Second ESP32 board | Sacrificial board for burning eFuses in dev mode — never experiment on your only board. |
| DHT11 sensor | Already owned |
| Breadboard + jumper wires | Already owned |
| USB cable | Data-capable, not charge-only |

Sourcing details, prices, and verified vendor links are in the Build and Research Plan linked above.

## Repository layout

```
firmware/        ESP-IDF project (main app + components)
  main/          App entry point, sensor read, MQTT client, OTA check
  components/    Custom components (signature verification, device identity, etc.)
broker/          Mosquitto config for TLS + plaintext test listeners
certs/           CA / device cert generation scripts (no private keys committed — see certs/README.md)
data/raw/        Lab-log CSVs: timing/overhead measurements per phase
analysis/        Scripts that turn data/raw/*.csv into the paper's tables and plots
paper/           Research paper draft + figures (IEEE format)
docs/            Threat model, phase checklists, viva notes
```

## Build phases (summary)

| Phase | What it adds | Status |
|---|---|---|
| 0 | Dev environment setup (ESP-IDF, toolchain, board bring-up) | ☐ |
| 1 | Plain sensor → MQTT → dashboard pipeline | ☐ |
| 2 | TLS-encrypted MQTT + device certs | ☐ |
| 3 | Signed OTA updates, tampered-update rejection demo | ☐ |
| 4 | Secure Boot V2 + Flash Encryption (dev mode) + anti-rollback | ☐ |
| 5 | Evaluation: measured overhead, attack matrix, write-up | ☐ |

Detailed steps, commands, and skills for each phase are in the Build and Research Plan.

## Security note

Secure Boot and Flash Encryption are **not unbreakable** — documented fault-injection attacks against the ESP32's hardware trust features exist (see references in the paper). The goal here is defense-in-depth that raises the bar well above a typical unprotected student project, not a claim of perfect security.

## Author

Harsh — 3rd year B.Tech (EEE), Lloyd Institute of Engineering and Technology, AKTU.

## License

MIT — see [LICENSE](LICENSE).
