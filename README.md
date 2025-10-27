### Files structure
`
aes-encryption/
│
├── include/                  # Header files (.h, .hpp)
│   ├── aes.h                 # Deklarasi fungsi AES (C)
│   ├── aes.hpp               # (Opsional) Versi C++ interface
│
├── src/                      # Implementasi kode sumber (.c, .cpp)
│   ├── aes.c                 # Implementasi algoritma AES
│
├── tests/                    # Unit tests / contoh penggunaan
│   ├── test_c.c              # Testing versi C
│   ├── test_cpp.cpp          # Testing versi C++
│
├── examples/                 # Contoh program penggunaan AES
│   ├── encrypt_example.c
│   ├── decrypt_example.c
│
├── build/                    # Folder hasil build (dibuat otomatis)
│
├── cmake/                    # File konfigurasi tambahan untuk CMake (opsional)
│
├── scripts/                  # Script tambahan untuk CI/CD atau build otomatis
│   ├── run_tests.sh
│   ├── build_lib.sh
│
├── CMakeLists.txt            # Konfigurasi CMake
├── Makefile                  # Alternatif manual build
├── README.md                 # Penjelasan proyek
├── LICENSE.txt               # Lisensi (misal Unlicense)
└── conanfile.py              # Konfigurasi dependency (opsional, untuk C++)
`

### Explanation
| Folder                                     | Fungsi                                                                                                                                 |
| ------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------- |
| **include/**                               | Menyimpan header file, yaitu deklarasi fungsi, struct, dan macro yang akan digunakan di file lain.                                     |
| **src/**                                   | Implementasi dari fungsi-fungsi yang dideklarasikan di header file. Ini inti dari library AES.                                         |
| **tests/**                                 | Berisi file test untuk memastikan algoritma berjalan dengan benar. Bisa gunakan framework seperti `Unity` atau `CMocka`.               |
| **examples/**                              | Menyediakan contoh program sederhana untuk encrypt/decrypt string atau file agar pengguna mudah memahami cara pakai.                   |
| **build/**                                 | Folder hasil kompilasi otomatis (misalnya `.o`, `.a`, `.so`, atau binary hasil `make`). Biasanya diabaikan di Git dengan `.gitignore`. |
| **cmake/**                                 | Konfigurasi tambahan untuk sistem build seperti CMake (jika proyek besar). Bisa menyimpan module finders.                              |
| **scripts/**                               | Script untuk otomatisasi build, testing, atau integrasi CI (Continuous Integration).                                                   |
| **root files (README, LICENSE, Makefile)** | Dokumentasi, lisensi, dan cara build proyek.                                                                                           |

