# Measurement data

`raw/` holds per-run CSV logs from the evaluation phase (Phase 5): TLS handshake time, boot-time overhead, flash/RAM overhead, OTA update time — with and without each security layer, repeated enough runs to report mean ± SD.

Suggested CSV schema (one row per run):

```
timestamp,phase,layer_enabled,metric_name,value,unit,board_id,notes
```

`../analysis/` turns these CSVs into the tables and plots used in `../paper/`.
