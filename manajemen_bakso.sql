-- Nama Database: manajemen_bakso
CREATE DATABASE manajemen_bakso;
USE manajemen_bakso;

-- Tabel Admin
CREATE TABLE admiin(
    admin_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    PASSWORD VARCHAR(255) NOT NULL
);

-- Tabel Pegawai
CREATE TABLE pegawai (
    pegawai_id INT AUTO_INCREMENT PRIMARY KEY,
    nama VARCHAR(100) NOT NULL,
    username VARCHAR(50) NOT NULL,
    PASSWORD VARCHAR(255) NOT NULL,
    status_aktif BOOLEAN DEFAULT TRUE
);

-- Tabel Barang
CREATE TABLE barang (
    barang_id INT AUTO_INCREMENT PRIMARY KEY,
    nama_barang VARCHAR(100) NOT NULL,
    stok INT NOT NULL,
    harga_beli DECIMAL(10,2) NOT NULL,
    harga_jual DECIMAL(10,2) NOT NULL,
    stok_minimum INT NOT NULL
);

CREATE TABLE stok_pegawai (
    stok_id INT AUTO_INCREMENT PRIMARY KEY,
    pegawai_id INT NOT NULL,
    bakso_halus INT NOT NULL DEFAULT 0,
    bakso_kasar INT NOT NULL DEFAULT 0,
    bakso_puyuh INT NOT NULL DEFAULT 0,
    tahu INT NOT NULL DEFAULT 0,
    somay INT NOT NULL DEFAULT 0,
    FOREIGN KEY (pegawai_id) REFERENCES pegawai(pegawai_id)
);

-- Tabel Penjualan
CREATE TABLE penjualan (
    penjualan_id INT AUTO_INCREMENT PRIMARY KEY,
    pegawai_id INT NOT NULL,
    tanggal_penjualan DATE NOT NULL,
    total_penjualan DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (pegawai_id) REFERENCES pegawai(pegawai_id)
);

-- Tabel Laporan
CREATE TABLE laporan (
    laporan_id INT AUTO_INCREMENT PRIMARY KEY,
    pegawai_id INT NOT NULL,
    tanggal_laporan DATE NOT NULL,
    total_penjualan DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (pegawai_id) REFERENCES pegawai(pegawai_id)
);

-- Tabel Laporan Keuangan
CREATE TABLE laporan_keuangan (
    keuangan_id INT AUTO_INCREMENT PRIMARY KEY,
    periode_awal DATE NOT NULL,
    periode_akhir DATE NOT NULL,
    total_pendapatan DECIMAL(10,2) NOT NULL,
    total_pengeluaran DECIMAL(10,2) NOT NULL,
    laba_bersih DECIMAL(10,2) NOT NULL
);

-- Tabel Notifikasi Stok
CREATE TABLE notifikasi_stok (
    notifikasi_id INT AUTO_INCREMENT PRIMARY KEY,
    barang_id INT NOT NULL,
    waktu_notifikasi DATETIME NOT NULL,
    FOREIGN KEY (barang_id) REFERENCES barang(barang_id)
);

-- Tabel Audit Log
CREATE TABLE audit_log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    ROLE ENUM('admin', 'pegawai') NOT NULL,
    aksi VARCHAR(255) NOT NULL,
    waktu_aksi DATETIME NOT NULL
);

