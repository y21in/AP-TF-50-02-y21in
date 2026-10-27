import math

# Nilai eksak S_inf
s_inf = (math.pi**2) / 6

print("--- 1. Perhitungan Berdasarkan N ---")
n_values = [10, 100, 1000, 10000]
print(f"{'N':<8} | {'SN':<18} | {'Galat Absolut':<18}")
print("-" * 50)

for N in n_values:
    s_n = sum(1 / (n**2) for n in range(1, N + 1))
    galat = abs(s_inf - s_n)
    print(f"{N:<8} | {s_n:<18.10f} | {galat:<18.10f}")

print("\n--- 2. Penghentian Berdasarkan Toleransi Suku Berikutnya ---")
toleransi = 1e-6
s_tol = 0.0
n = 1

while True:
    suku = 1 / (n**2)
    if suku < toleransi:
        break
    s_tol += suku
    n += 1

print(f"Toleransi          : {toleransi}")
print(f"Suku terakhir      : {1 / ((n-1)**2)}")
print(f"Jumlah suku (N)    : {n - 1}")
print(f"Hasil S_tol        : {s_tol:.10f}")
print(f"Galat dari S_inf   : {abs(s_inf - s_tol):.10f}")