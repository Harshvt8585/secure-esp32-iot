# Certificates (Phase 2)

**Never commit real private keys or certificates to this repo** — `.gitignore` already blocks common key/cert patterns, but double-check before every commit.

This folder will hold:
- `gen_ca.sh` — generates a self-signed CA for the project (OpenSSL)
- `gen_device_cert.sh` — generates a per-device certificate signed by that CA (basic PKI for device identity)
- `ca.crt` (public, OK to commit) — the CA certificate the broker and devices trust

Keep actual `.key` files and the CA's private key **outside the repo** (or in a local, gitignored subfolder) — losing or leaking them means every signed cert/update needs to be reissued.
