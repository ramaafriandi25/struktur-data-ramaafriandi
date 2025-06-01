<?php
function connection() {
    $host = "localhost";       // atau sesuai server DB kamu
    $user = "root";            // sesuaikan
    $password = "";            // sesuaikan
    $dbname = "manajemen_bakso"; // nama database kamu

    $conn = mysqli_connect($host, $user, $password, $dbname);

    if (!$conn) {
        die("Koneksi gagal: " . mysqli_connect_error());
    }
    return $conn;
}
?>
