#include <stdio.h>

#define MAX 100

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bhyt[MAX];

    int n;
    int k;
    int doanh_thu = 0;
    int so_uu_tien = 0;

    do {
        printf("Nhap so luong benh nhan (0-%d): ", MAX);
        scanf("%d", &n);

        if (n < 0 || n > MAX) {
            printf("So luong khong hop le!\n");
        }
    } while (n < 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        ma_so[i] = 1001 + i;

        do {
            printf("Nhap tuoi benh nhan %d: ", i + 1);
            scanf("%d", &tuoi[i]);

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi khong hop le! Vui long nhap lai.\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Nhap BHYT benh nhan %d (0: Khong, 1: Co): ", i + 1);
            scanf("%d", &bhyt[i]);

            if (bhyt[i] != 0 && bhyt[i] != 1) {
                printf("Trang thai BHYT khong hop le! Vui long nhap lai.\n");
            }
        } while (bhyt[i] != 0 && bhyt[i] != 1);
    }

    doanh_thu = 0;
    so_uu_tien = 0;

    printf("\n========== HANG CHO BAN DAU ==========\n");

    for (int i = 0; i < n; i++) {
        int phi;

        if (bhyt[i] == 1) {
            phi = 30000;
        } else {
            phi = 150000;
        }

        doanh_thu += phi;

        if (tuoi[i] >= 70) {
            so_uu_tien++;
        }

        printf("Index %d - So thu tu: %d - Tuoi: %d - BHYT: %d - Phi: %d VNĐ",
               i, ma_so[i], tuoi[i], bhyt[i], phi);

        if (tuoi[i] >= 70) {
            printf(" - UU TIEN");
        }

        printf("\n");
    }

    printf("Tong doanh thu du kien: %d VNĐ\n", doanh_thu);
    printf("So benh nhan uu tien: %d\n", so_uu_tien);

    if (n == 0) {
        printf("\nHang cho dang rong, khong the huy.\n");
    } else {
        do {
            printf("\nNhap vi tri index K can huy (0-%d): ", n - 1);
            scanf("%d", &k);

            if (k < 0 || k >= n) {
                printf("Vi tri K khong hop le!\n");
            }
        } while (k < 0 || k >= n);

        for (int i = k; i < n - 1; i++) {
            ma_so[i] = ma_so[i + 1];
            tuoi[i] = tuoi[i + 1];
            bhyt[i] = bhyt[i + 1];
        }

        n--;

        doanh_thu = 0;
        so_uu_tien = 0;

        for (int i = 0; i < n; i++) {
            if (bhyt[i] == 1) {
                doanh_thu += 30000;
            } else {
                doanh_thu += 150000;
            }

            if (tuoi[i] >= 70) {
                so_uu_tien++;
            }
        }

        printf("\n========== HANG CHO SAU KHI HUY ==========\n");

        for (int i = 0; i < n; i++) {
            int phi;

            if (bhyt[i] == 1) {
                phi = 30000;
            } else {
                phi = 150000;
            }

            printf("Index %d - So thu tu: %d - Tuoi: %d - BHYT: %d - Phi: %d VNĐ",
                   i, ma_so[i], tuoi[i], bhyt[i], phi);

            if (tuoi[i] >= 70) {
                printf(" - UU TIEN");
            }

            printf("\n");
        }

        printf("Tong doanh thu sau khi huy: %d VNĐ\n", doanh_thu);
        printf("So benh nhan uu tien sau khi huy: %d\n", so_uu_tien);
    }

    return 0;
}