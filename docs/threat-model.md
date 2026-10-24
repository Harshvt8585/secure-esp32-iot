# Threat model (draft — fill in as Phase 2–4 land)

## Assets
- Sensor data integrity/confidentiality in transit
- Device identity (is this really our ESP32 talking to the broker?)
- Firmware integrity (is the code running on the device what we actually signed?)
- The signing key and device private keys

## Attackers considered
| Attack | Layer that should stop it | Status |
|---|---|---|
| Passive eavesdropping on MQTT traffic (plaintext) | TLS (Phase 2) | ☐ |
| Rogue/impersonating MQTT broker | TLS + broker cert validation (Phase 2) | ☐ |
| Fake device publishing bogus sensor data | Device certificates / mutual TLS (Phase 2) | ☐ |
| Tampered or unsigned OTA firmware pushed to device | Signed OTA verification (Phase 3) | ☐ |
| Firmware rollback to a known-vulnerable older version | Anti-rollback / anti-downgrade (Year 4) | ☐ |
| Unsigned/malicious code flashed via physical access | Secure Boot V2 (Phase 4, dev mode) | ☐ |
| Reading secrets/code off a stolen board's flash | Flash Encryption (Phase 4, dev mode) | ☐ |
| Physical fault-injection attack on eFuse-stored keys | **Not fully mitigated** — documented in literature (see paper refs); acknowledged as a residual risk, not claimed as solved | — |

## Out of scope (acknowledged, not defended against in this project)
- Side-channel/fault-injection attacks against the ESP32 silicon itself
- Supply-chain compromise of the dev board before purchase
- Attacks on the dashboard/cloud backend beyond the broker

## Demo moments (for viva/HOD presentation)
1. Wireshark before/after: plaintext MQTT vs TLS-encrypted MQTT
2. Live rejection of a tampered/unsigned OTA update
3. (Phase 4) Live rejection of unsigned firmware by Secure Boot
