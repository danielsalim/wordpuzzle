 Tugas Kecil 1 Strategi Algoritma - Word Puzzle

### Program Penyelesain Word Search Puzzle sebagai Tugas Kecil 1 IF2211 Strategi Algoritma

Daniel Salim / K02 / 13520008

## Deskripsi Program

Program ini adalah penyelesaian "word search puzzle" dengan menggunakan algoritma brute force. Program diawali dengan input file txt dari user, lalu puzzle akan disimpan ke dalam matriks, setelah itu akan dilakukan pemeriksaan kata yang ingin dicari dengan boolean. Output program berupa matriks hasil dari tiap kata yang ingin dicari, durasi eksekusi program, dan jumlah perbandingan kata.

## Requirements

Compiler untuk bahasa c

## Directory

```sh
wordpuzzle
├── src                     # Berisi source code program
├── bin                     # Berisi executable
├── test                    # Berisi test case dalam format txt 
├── doc                     # Berisi laporan Tugas Kecil 1
```

## How to Run

1. Clone repository : `git clone git@github.com:danielslaim/wordpuzzle.git`
2. Masuk ke directory src
3. Lakukan command berikut 
`gcc -c wordpuzzle.c`;
`gcc wordpuzzle.c -o wordpuzzle`
`./wordpuzzle` 
4. Program akan berjalan, lalu input nama file dengan `../test/{namafile}.txt`