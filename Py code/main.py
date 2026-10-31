import tkinter as tk


def tekan_tombol(item):
    global ekspresi
    ekspresi = ekspresi + str(item)
    input_teks.set(ekspresi)


def hapus_layar():
    global ekspresi
    ekspresi = ""
    input_teks.set("")


def hitung():
    global ekspresi
    try:
        hasil = str(eval(ekspresi))
        input_teks.set(hasil)
        ekspresi = hasil
    except:
        input_teks.set("Error")
        ekspresi = ""


window = tk.Tk()
window.title("Kalkulator Desimal Python")
window.geometry("350x450")
window.resizable(False, False)

ekspresi = ""
input_teks = tk.StringVar()

layar = tk.Entry(
    window,
    textvariable=input_teks,
    font=("Arial", 20),
    bd=10,
    insertwidth=4,
    width=14,
    borderwidth=5,
    justify="right",
)
layar.grid(row=0, column=0, columnspan=4, ipady=15, sticky="nsew")

tombol = ["7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "C", "0", ".", "+"]

baris = 1
kolom = 0

for t in tombol:
    if t == "C":
        action = hapus_layar
    else:
        action = lambda x=t: tekan_tombol(x)

    tk.Button(window, text=t, font=("Arial", 14), command=action).grid(
        row=baris, column=kolom, sticky="nsew", padx=2, pady=2
    )

    kolom += 1
    if kolom > 3:
        kolom = 0
        baris += 1

tk.Button(
    window,
    text="=",
    font=("Arial", 14),
    bg="#4CAF50",
    fg="black",
    command=hitung,
).grid(row=baris, column=0, columnspan=4, sticky="nsew", padx=2, pady=2)

for i in range(4):
    window.grid_columnconfigure(i, weight=1)
for i in range(baris + 1):
    window.grid_rowconfigure(i, weight=1)

window.mainloop()