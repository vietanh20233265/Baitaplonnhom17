#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SO_BENH_NHAN_TOI_DA 100
#define DO_DAI_TEN 100
#define DO_DAI_LICH_SU 500
#define DO_DAI_CHAN_DOAN 500
#define DO_DAI_DON_THUOC 500
#define DO_DAI_KET_QUA 500
#define SO_HOA_DON_TOI_DA 100
#define DO_DAI_TEN 100
#define DO_DAI_MO_TA 500
#define MAX_THUOC 100
#define MAX_LICH_HEN 100
#define SO_NHAN_SU_TOI_DA 100
#define DO_DAI_TEN 100
#define CHUC_VU 100
#define DO_DAI_GT 10
#define MAX_LENGTH 100
#define MAX_FEEDBACK 10
#define MAX_KHACHHANG 100
#define MAX_CHIENDICH 100
#define MAX_DICHVU 100
#define MAX_TUVAN 100
#define MAX_KHAM 100

void pressAnyKey() {
    printf("\n\nBam phim bat ky de tiep tuc...");
    getchar();
    system("cls");
}
void printLine(int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("_");
    }
    printf("\n");
}

typedef struct {
    int id;
    char ten[DO_DAI_TEN];
    int tuoi;
    char lich_su[DO_DAI_LICH_SU];
    char chan_doan[DO_DAI_CHAN_DOAN];
    char don_thuoc[DO_DAI_DON_THUOC];
    char ket_qua_xet_nghiem[DO_DAI_KET_QUA];
} BenhNhan;




BenhNhan benh_nhan[SO_BENH_NHAN_TOI_DA]; // Mang luu tru cac benh nhan
int so_luong_benh_nhan = 0; // Dem so luong benh nhan

// Ham tao benh nhan moi
void tao_benh_nhan() {
    if (so_luong_benh_nhan >= SO_BENH_NHAN_TOI_DA) {
        printf("Khong the them benh nhan moi. Bo nho day.\n");
        return;
    }
    BenhNhan benh_nhan_moi;
    benh_nhan_moi.id = so_luong_benh_nhan + 1;
    printf("Nhap ten benh nhan: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.ten);
    printf("Nhap tuoi benh nhan: ");
    scanf("%d", &benh_nhan_moi.tuoi);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap lich su kham benh: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.lich_su);
    printf("Nhap chan doan: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.chan_doan);
    printf("Nhap don thuoc: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.don_thuoc);
    printf("Nhap ket qua xet nghiem: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.ket_qua_xet_nghiem);
    benh_nhan[so_luong_benh_nhan] = benh_nhan_moi;
    so_luong_benh_nhan++;
    printf("Da them benh nhan thanh cong!\n");
}

// Ham cap nhat thong tin benh nhan
void cap_nhat_benh_nhan() {
    int id;
    printf("Nhap ID benh nhan can cap nhat: ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_benh_nhan) {
        printf("ID benh nhan khong hop le.\n");
        return;
    }
    BenhNhan *bn = &benh_nhan[id - 1];
    printf("Nhap ten moi cho benh nhan: ");
    scanf(" %[^\n]%*c", bn->ten);
    printf("Nhap tuoi moi cho benh nhan: ");
    scanf("%d", &bn->tuoi);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap lich su kham benh moi: ");
    scanf(" %[^\n]%*c", bn->lich_su);
    printf("Nhap chan doan moi: ");
    scanf(" %[^\n]%*c", bn->chan_doan);
    printf("Nhap don thuoc moi: ");
    scanf(" %[^\n]%*c", bn->don_thuoc);
    printf("Nhap ket qua xet nghiem moi: ");
    scanf(" %[^\n]%*c", bn->ket_qua_xet_nghiem);
    printf("Cap nhat thong tin benh nhan thanh cong!\n");
}

// Ham tim kiem benh nhan
void tim_kiem_benh_nhan() {
    int id;
    printf("Nhap ID benh nhan can tim kiem: ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_benh_nhan) {
        printf("Khong tim thay benh nhan.\n");
        return;
    }
    BenhNhan bn = benh_nhan[id - 1];
    printf("ID benh nhan: %d\n", bn.id);
    printf("Ten: %s\n", bn.ten);
    printf("Tuoi: %d\n", bn.tuoi);
    printf("Lich su kham benh: %s\n", bn.lich_su);
    printf("Chan doan: %s\n", bn.chan_doan);
    printf("Don thuoc: %s\n", bn.don_thuoc);
    printf("Ket qua xet nghiem: %s\n", bn.ket_qua_xet_nghiem);
}

// Ham liet ke danh sach benh nhan
void danh_sach_benh_nhan() {
    if (so_luong_benh_nhan == 0) {
        printf("Chua co benh nhan nao.\n");
        return;
    }
    for (int i = 0; i < so_luong_benh_nhan; i++) {
        printf("ID benh nhan: %d\n", benh_nhan[i].id);
        printf("Ten: %s\n", benh_nhan[i].ten);
        printf("Tuoi: %d\n", benh_nhan[i].tuoi);
        printf("Lich su kham benh: %s\n", benh_nhan[i].lich_su);
        printf("Chan doan: %s\n", benh_nhan[i].chan_doan);
        printf("Don thuoc: %s\n", benh_nhan[i].don_thuoc);
        printf("Ket qua xet nghiem: %s\n", benh_nhan[i].ket_qua_xet_nghiem);
        printf("----------------------\n");
    }
}

// Ham ghi nhan thong tin kham benh, chan doan va dieu tri
void ghi_nhan_kham_benh() {
    int id;
    printf("Nhap ID benh nhan can ghi nhan thong tin kham benh: ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_benh_nhan) {
        printf("ID benh nhan khong hop le.\n");
        return;
    }
    BenhNhan *bn = &benh_nhan[id - 1];
    printf("Nhap thong tin chan doan: ");
    scanf(" %[^\n]%*c", bn->chan_doan);
    printf("Nhap don thuoc: ");
    scanf(" %[^\n]%*c", bn->don_thuoc);
    printf("Nhap ket qua xet nghiem: ");
    scanf(" %[^\n]%*c", bn->ket_qua_xet_nghiem);
    printf("Ghi nhan thong tin kham benh thanh cong!\n");
}


// Cau truc du lieu hoa don
typedef struct {
    int id;
    char ten[DO_DAI_TEN];
    char mo_ta[DO_DAI_MO_TA];
    float so_tien;
    char ngay[11];
} HoaDon;

HoaDon hoa_don[SO_HOA_DON_TOI_DA]; // Mang luu tru cac hoa don
int so_luong_hoa_don = 0; // Ðem so luong hoa don

// Ham tao hoa don moi
void tao_hoa_don() {
    if (so_luong_hoa_don >= SO_HOA_DON_TOI_DA) {
        printf("Khong the them hoa don moi, bo nho day.\n");
        return;
    }
    HoaDon hoa_don_moi;
    hoa_don_moi.id = so_luong_hoa_don + 1;
    printf("Nhap ten hoa don: ");
    scanf(" %[^\n]%*c", hoa_don_moi.ten);
    printf("Nhap mo ta hoa don: ");
    scanf(" %[^\n]%*c", hoa_don_moi.mo_ta);
    printf("Nhap so tien: ");
    scanf("%f", &hoa_don_moi.so_tien);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap ngay (dd/mm/yyyy): ");
    scanf(" %[^\n]%*c", hoa_don_moi.ngay);
    hoa_don[so_luong_hoa_don] = hoa_don_moi;
    so_luong_hoa_don++;
    printf("Ða them hoa don thanh cong!\n");
}

// Ham cap nhat hoa don
void cap_nhat_hoa_don() {
    int id;
    printf("Nhap ID hoa don can cap nhat: ");
    scanf("%d", &id);
    getchar(); // Ðe tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_hoa_don) {
        printf("ID hoa don khong hop le.\n");
        return;
    }
    HoaDon *hd = &hoa_don[id - 1];
    printf("Nhap ten moi cho hoa don: ");
    scanf(" %[^\n]%*c", hd->ten);
    printf("Nhap mo ta moi cho hoa don: ");
    scanf(" %[^\n]%*c", hd->mo_ta);
    printf("Nhap so tien moi: ");
    scanf("%f", &hd->so_tien);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap ngay moi (dd/mm/yyyy): ");
    scanf(" %[^\n]%*c", hd->ngay);
    printf("Cap nhat hoa don thanh cong!\n");
}

// Ham tim kiem hoa don
void tim_kiem_hoa_don() {
    int id;
    printf("Nhap ID hoa don can tim kiem : ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_hoa_don) {
        printf("Khong tim thay hoa don.\n");
        return;
    }
    HoaDon hd = hoa_don[id - 1];
    printf("ID hoa don: %d\n", hd.id);
    printf("Ten: %s\n", hd.ten);
    printf("Mo ta: %s\n", hd.mo_ta);
    printf("So tien: %.2f\n", hd.so_tien);
    printf("Ngay: %s\n", hd.ngay);
}

// ham liet ke danh sach hoa don
void danh_sach_hoa_don() {
    if (so_luong_hoa_don == 0) {
        printf("Chua co hoa don nao.\n");
        return;
    }
    for (int i = 0; i < so_luong_hoa_don; i++) {
        printf("ID hoa don: %d\n", hoa_don[i].id);
        printf("Ten: %s\n", hoa_don[i].ten);
        printf("Mo ta: %s\n", hoa_don[i].mo_ta);
        printf("So tien: %.2f\n", hoa_don[i].so_tien);
        printf("Ngay: %s\n", hoa_don[i].ngay);
        printf("----------------------\n");
    }
}

// Hsm theo doi va lap bao cao doanh thu, chi phi
void bao_cao_doanh_thu_chi_phi() {
    float tong_doanh_thu = 0, tong_chi_phi = 0;
    for (int i = 0; i < so_luong_hoa_don; i++) {
        if (hoa_don[i].so_tien > 0) {
            tong_doanh_thu += hoa_don[i].so_tien;
        } else {
            tong_chi_phi += hoa_don[i].so_tien;
        }
    }
    printf("Tong danh thu: %.2f\n", tong_doanh_thu);
    printf("Tang chi phi: %.2f\n", tong_chi_phi);
    printf("Loi nhuan: %.2f\n", tong_doanh_thu + tong_chi_phi);
}

// Ham quan ly bao hiem y te
void quan_ly_bao_hiem_y_te() {
    // Gia dinh rang thong tin bao hiem duoc quan ly trong cac hoa don
    printf("Danh sách các hóa don b?o hi?m y t?:\n");
    for (int i = 0; i < so_luong_hoa_don; i++) {
        if (strstr(hoa_don[i].mo_ta, "b?o hi?m") != NULL) {
            printf("ID hóa don: %d\n", hoa_don[i].id);
            printf("Ten: %s\n", hoa_don[i].ten);
            printf("Mo ta: %s\n", hoa_don[i].mo_ta);
            printf("So tien: %.2f\n", hoa_don[i].so_tien);
            printf("Ngay: %s\n", hoa_don[i].ngay);
            printf("----------------------\n");
        }
    }
}



typedef struct {
    char ten[50];
    int soLuong;
    time_t ngayHetHan;
} Thuoc;

typedef struct {
    char tenBenhNhan[50];
    char tenBacSi[50];
    time_t ngayHen;
} LichHen;

Thuoc kho[MAX_THUOC];
int soLuongThuoc = 0;

LichHen lichHen[MAX_LICH_HEN];
int soLuongLichHen = 0;

int daHetHan(time_t ngayHetHan) {
    time_t bayGio = time(0);
    return difftime(ngayHetHan, bayGio) < 0;
}

void themThuoc(const char* ten, int soLuong, time_t ngayHetHan) {
    if (soLuongThuoc < MAX_THUOC) {
        strcpy(kho[soLuongThuoc].ten, ten);
        kho[soLuongThuoc].soLuong = soLuong;
        kho[soLuongThuoc].ngayHetHan = ngayHetHan;
        soLuongThuoc++;
    } else {
        printf("Kho da day, khong the them thuoc moi.\n");
    }
}

void capNhatThuoc(const char* ten, int soLuong) {
    for (int i = 0; i < soLuongThuoc; i++) {
        if (strcmp(kho[i].ten, ten) == 0) {
            kho[i].soLuong = soLuong;
            return;
        }
    }
    printf("Khong tim thay thuoc trong kho.\n");
}

void kiemTraTonKho() {
    for (int i = 0; i < soLuongThuoc; i++) {
        if (kho[i].soLuong <= 5) {
            printf("Canh bao: Thuoc %s sap het hang.\n", kho[i].ten);
        }
        if (daHetHan(kho[i].ngayHetHan)) {
            printf("Canh bao: Thuoc %s da het han.\n", kho[i].ten);
        }
    }
}

void hienThiKho() {
    for (int i = 0; i < soLuongThuoc; i++) {
        printf("Thuoc: %s, So luong: %d, Ngay het han: %s", kho[i].ten, kho[i].soLuong, ctime(&kho[i].ngayHetHan));
    }
}

void themLichHen(const char* tenBenhNhan, const char* tenBacSi, time_t ngayHen) {
    if (soLuongLichHen < MAX_LICH_HEN) {
        strcpy(lichHen[soLuongLichHen].tenBenhNhan, tenBenhNhan);
        strcpy(lichHen[soLuongLichHen].tenBacSi, tenBacSi);
        lichHen[soLuongLichHen].ngayHen = ngayHen;
        soLuongLichHen++;
    } else {
        printf("Khong the them lich hen moi.\n");
    }
}

void hienThiLichHen() {
    for (int i = 0; i < soLuongLichHen; i++) {
        printf("Benh nhan: %s, Bac si: %s, Ngay hen: %s", lichHen[i].tenBenhNhan, lichHen[i].tenBacSi, ctime(&lichHen[i].ngayHen));
    }
}

void nhapThongTinThuoc(char* ten, int* soLuong, time_t* ngayHetHan) {
    printf("Nhap ten thuoc: ");
    fgets(ten, 50, stdin);
    ten[strcspn(ten, "\n")] = '\0'; // Remove newline character

    printf("Nhap so luong thuoc: ");
    scanf("%d", soLuong);
    getchar(); // clear newline character

    printf("Nhap ngay het han (dd/mm/yyyy): ");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    getchar(); // clear newline character

    struct tm tm = {0};
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    *ngayHetHan = mktime(&tm);
}

void nhapThongTinLichHen(char* tenBenhNhan, char* tenBacSi, time_t* ngayHen) {
    printf("Nhap ten benh nhan: ");
    fgets(tenBenhNhan, 50, stdin);
    tenBenhNhan[strcspn(tenBenhNhan, "\n")] = '\0'; // Remove newline character

    printf("Nhap ten bac si: ");
    fgets(tenBacSi, 50, stdin);
    tenBacSi[strcspn(tenBacSi, "\n")] = '\0'; // Remove newline character

    printf("Nhap ngay hen (dd/mm/yyyy): ");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    getchar(); // clear newline character

    struct tm tm = {0};
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    *ngayHen = mktime(&tm);
}



typedef struct {
    int id;
    char ten[DO_DAI_TEN];
    int tuoi;
    char gioi_tinh[DO_DAI_GT];
    char chucvu[CHUC_VU];
    int luong;
} NhanSu;

NhanSu nhan_su[SO_NHAN_SU_TOI_DA];
int so_luong_nhan_su = 0;



// Ham tao nhan su moi
void tao_nhan_su() {
    if (so_luong_nhan_su >= SO_NHAN_SU_TOI_DA) {
        printf("Khong the them nhan su moi. Bo nho day.\n");
        return;
    }
    NhanSu nhan_su_moi;
    nhan_su_moi.id = so_luong_nhan_su + 1;
    printf("Nhap ten: ");
    scanf(" %[^\n]%*c", nhan_su_moi.ten);
    printf("Nhap gioi tinh: ");
    scanf(" %[^\n]%*c", nhan_su_moi.gioi_tinh);
    printf("Nhap tuoi: ");
    scanf("%d", &nhan_su_moi.tuoi);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap luong:");
    scanf("%d",&nhan_su_moi.luong);
    nhan_su[so_luong_nhan_su] = nhan_su_moi;
    so_luong_nhan_su++;
    printf("Da them nhan su thanh cong!\n");
}

void cap_nhat_nhan_su() {
    int id;
    printf("Nhap ID nhan su can cap nhat: ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_nhan_su) {
        printf("ID nhan su khong hop le.\n");
        return;
    }
    NhanSu *ns = &nhan_su[id - 1];
    printf("Nhap ten moi: ");
    scanf(" %[^\n]%*c", ns->ten);
    printf("Nhap tuoi moi: ");
    scanf("%d", &ns->tuoi);
    printf("Nhap chuc vu moi: ");
    scanf(" %[^\n]%*c", ns->chucvu);
    printf("Nhap luong moi: ");
    scanf(" %[^\n]%*c", ns->luong);
    printf("Cap nhat thong tin thanh cong!\n");
}

// Ham tim kiem benh nhan
void tim_kiem_nhan_su() {
    int id;
    printf("Nhap ID can tim kiem: ");
    scanf("%d", &id);
    getchar();
    if (id < 1 || id > so_luong_nhan_su) {
        printf("Khong tim thay nhan su.\n");
        return;
    }
    NhanSu ns = nhan_su[id - 1];
    printf("ID: %d\n", ns.id);
    printf("Ten: %s\n", ns.ten);
    printf("Tuoi: %d\n", ns.tuoi);
    printf("Chuc vu: %s\n", ns.chucvu);
    printf("Luong: %s\n", ns.luong);
}
// Ham liet ke danh sach nhan su
void danh_sach_nhan_su() {
    if (so_luong_nhan_su == 0) {
        printf("Chua co nhan su nao.\n");
        return;
    }
   printLine(69);
    for (int i = 0; i < so_luong_nhan_su; i++) {
        printf("|ID |Ho ten                        |Gt   |Chuc vu   |Tuoi|Luong     |");
        printf("\n|%-3d|",nhan_su[i].id);
        printf("%-30s|", nhan_su[i].ten);
        printf("%-5s|", nhan_su[i].gioi_tinh);
        printf("%-10s|", nhan_su[i].chucvu);
        printf("%-4d|", nhan_su[i].tuoi);
        printf("%-10d|", nhan_su[i].luong);
    }
   printLine(69);
}


typedef struct {
    char ten[MAX_LENGTH];
    char email[MAX_LENGTH];
    char soDienThoai[MAX_LENGTH];
    char diaChiKhachHang[MAX_LENGTH];
    char phanHoi[MAX_FEEDBACK][MAX_LENGTH];
    int soPhanHoi;
} KhachHang;

typedef struct {
    char tieuDe[MAX_LENGTH];
    char noiDung[MAX_LENGTH];
    char loai[MAX_LENGTH]; // vd: thông báo, bản tin, khuyến mãi
} ChienDich;

typedef struct {
    char tenDichVu[MAX_LENGTH];
    double mucGiamGia;
} DichVuChamSoc;

typedef struct {
    char tinhTrangSucKhoe[MAX_LENGTH];
    char chuanDoan[MAX_LENGTH];
    char cachTriLieuTamThoi[MAX_LENGTH];
    char ghiChu[MAX_LENGTH];
} TuVanOnline;

typedef struct {
    char tinhTrangSucKhoe[MAX_LENGTH];
    char chuanDoan[MAX_LENGTH];
    char cachTriLieuTamThoi[MAX_LENGTH];
    char ghiChu[MAX_LENGTH];
} KhamTaiNha;

typedef struct {
    KhachHang khachHangs[MAX_KHACHHANG];
    ChienDich chienDichs[MAX_CHIENDICH];
    DichVuChamSoc dichVus[MAX_DICHVU];
    TuVanOnline tuVans[MAX_TUVAN];
    KhamTaiNha khams[MAX_KHAM];
    int soKhachHang;
    int soChienDich;
    int soDichVu;
    int soTuVan;
    int soKham;
} HeThongQuanLyMarketing;


void themKhachHang(HeThongQuanLyMarketing *heThong) {
    if (heThong->soKhachHang >= MAX_KHACHHANG) {
        printf("Không thể thêm khách hàng mới, danh sách đã đầy.\n");
        return;
    }
    KhachHang *kh = &heThong->khachHangs[heThong->soKhachHang];
    printf("Nhập tên khách hàng: ");
    fgets(kh->ten, MAX_LENGTH, stdin);
    kh->ten[strcspn(kh->ten, "\n")] = '\0';

    printf("Nhập email khách hàng: ");
    fgets(kh->email, MAX_LENGTH, stdin);
    kh->email[strcspn(kh->email, "\n")] = '\0';

    printf("Nhập số điện thoại khách hàng: ");
    fgets(kh->soDienThoai, MAX_LENGTH, stdin);
    kh->soDienThoai[strcspn(kh->soDienThoai, "\n")] = '\0';

    printf("Nhập địa chỉ khách hàng: ");
    fgets(kh->diaChiKhachHang, MAX_LENGTH, stdin);
    kh->diaChiKhachHang[strcspn(kh->diaChiKhachHang, "\n")] = '\0';

    kh->soPhanHoi = 0;
    heThong->soKhachHang++;
}

void themChienDich(HeThongQuanLyMarketing *heThong) {
    if (heThong->soChienDich >= MAX_CHIENDICH) {
        printf("Không thể thêm chiến dịch mới, danh sách đã đầy.\n");
        return;
    }
    ChienDich *cd = &heThong->chienDichs[heThong->soChienDich];
    printf("Nhập tiêu đề chiến dịch: ");
    fgets(cd->tieuDe, MAX_LENGTH, stdin);
    cd->tieuDe[strcspn(cd->tieuDe, "\n")] = '\0';

    printf("Nhập nội dung chiến dịch: ");
    fgets(cd->noiDung, MAX_LENGTH, stdin);
    cd->noiDung[strcspn(cd->noiDung, "\n")] = '\0';

    printf("Nhập loại chiến dịch (thông báo, bản tin, khuyến mãi): ");
    fgets(cd->loai, MAX_LENGTH, stdin);
    cd->loai[strcspn(cd->loai, "\n")] = '\0';

    heThong->soChienDich++;
}

void themDichVu(HeThongQuanLyMarketing *heThong) {
    if (heThong->soDichVu >= MAX_DICHVU) {
        printf("Không thể thêm dịch vụ mới, danh sách đã đầy.\n");
        return;
    }
    DichVuChamSoc *dv = &heThong->dichVus[heThong->soDichVu];
    printf("Nhập tên dịch vụ: ");
    fgets(dv->tenDichVu, MAX_LENGTH, stdin);
    dv->tenDichVu[strcspn(dv->tenDichVu, "\n")] = '\0';

    printf("Nhập mức giảm giá: ");
    scanf("%lf", &dv->mucGiamGia);
    getchar(); // clear the newline character from the input buffer

    heThong->soDichVu++;
}

void guiThongBao(HeThongQuanLyMarketing *heThong, const char *tieuDe, const char *noiDung) {
    for (int i = 0; i < heThong->soKhachHang; i++) {
        printf("Gửi thông báo tới %s: %s - %s\n", heThong->khachHangs[i].email, tieuDe, noiDung);
    }
}

void guiKhuyenMai(HeThongQuanLyMarketing *heThong, const char *tieuDe, const char *noiDung, double mucGiamGia) {
    for (int i = 0; i < heThong->soKhachHang; i++) {
        printf("Gửi khuyến mãi tới %s: %s - %s với %.2f%% giảm giá.\n", heThong->khachHangs[i].email, tieuDe, noiDung, mucGiamGia);
    }
}

void thuThapPhanHoi(HeThongQuanLyMarketing *heThong, const char *tenKhachHang, const char *phanHoi) {
    for (int i = 0; i < heThong->soKhachHang; i++) {
        if (strcmp(heThong->khachHangs[i].ten, tenKhachHang) == 0) {
            if (heThong->khachHangs[i].soPhanHoi < MAX_FEEDBACK) {
                strcpy(heThong->khachHangs[i].phanHoi[heThong->khachHangs[i].soPhanHoi], phanHoi);
                heThong->khachHangs[i].soPhanHoi++;
                printf("Đã thu thập phản hồi từ %s: %s\n", tenKhachHang, phanHoi);
            } else {
                printf("Không thể thu thập phản hồi mới, danh sách phản hồi đã đầy.\n");
            }
            return;
        }
    }
    printf("Không tìm thấy khách hàng tên %s.\n", tenKhachHang);
}

void quanLyTuVanOnline(HeThongQuanLyMarketing *heThong, const char *tenKhachHang) {
    if (heThong->soTuVan >= MAX_TUVAN) {
        printf("Không thể thêm tư vấn online mới, danh sách đã đầy.\n");
        return;
    }
    TuVanOnline *tv = &heThong->tuVans[heThong->soTuVan];
    printf("Nhập tình trạng sức khỏe: ");
    fgets(tv->tinhTrangSucKhoe, MAX_LENGTH, stdin);
    tv->tinhTrangSucKhoe[strcspn(tv->tinhTrangSucKhoe, "\n")] = '\0';

    printf("Nhập chuẩn đoán: ");
    fgets(tv->chuanDoan, MAX_LENGTH, stdin);
    tv->chuanDoan[strcspn(tv->chuanDoan, "\n")] = '\0';

    printf("Nhập cách trị liệu tạm thời: ");
    fgets(tv->cachTriLieuTamThoi, MAX_LENGTH, stdin);
    tv->cachTriLieuTamThoi[strcspn(tv->cachTriLieuTamThoi, "\n")] = '\0';

    printf("Nhập ghi chú: ");
    fgets(tv->ghiChu, MAX_LENGTH, stdin);
    tv->ghiChu[strcspn(tv->ghiChu, "\n")] = '\0';

    heThong->soTuVan++;
    printf("Đã thêm tư vấn online cho khách hàng %s.\n", tenKhachHang);
}

void quanLyKhamTaiNha(HeThongQuanLyMarketing *heThong, const char *tenKhachHang) {
    if (heThong->soKham >= MAX_KHAM) {
        printf("Không thể thêm khám tại nhà mới, danh sách đã đầy.\n");
        return;
    }
    KhamTaiNha *kt = &heThong->khams[heThong->soKham];
    printf("Nhập tình trạng sức khỏe: ");
    fgets(kt->tinhTrangSucKhoe, MAX_LENGTH, stdin);
    kt->tinhTrangSucKhoe[strcspn(kt->tinhTrangSucKhoe, "\n")] = '\0';

    printf("Nhập chuẩn đoán: ");
    fgets(kt->chuanDoan, MAX_LENGTH, stdin);
    kt->chuanDoan[strcspn(kt->chuanDoan, "\n")] = '\0';

    printf("Nhập cách trị liệu tạm thời: ");
    fgets(kt->cachTriLieuTamThoi, MAX_LENGTH, stdin);
    kt->cachTriLieuTamThoi[strcspn(kt->cachTriLieuTamThoi, "\n")] = '\0';

    printf("Nhập ghi chú: ");
    fgets(kt->ghiChu, MAX_LENGTH, stdin);
    kt->ghiChu[strcspn(kt->ghiChu, "\n")] = '\0';

    heThong->soKham++;
    printf("Đã thêm khám tại nhà cho khách hàng %s.\n", tenKhachHang);
}

int main(){
    int a;
    do{
        printf("HE THONG QUAN LY PHONG KHAM TU NHAN:\n");
        printf("1. Quan ly ho so benh nhan.\n");
        printf("2. Quan ly kham benh.\n");
        printf("3. Quan ly hoa don va thanh toan.\n");
        printf("4. Quan ly kho duoc pham.\n");
        printf("5. Quan ly lich hen.\n");
        printf("6. Quan ly nhan su.\n");
        printf("7. Quan ly marketing va cham soc khach hang.\n");
        printf("8. THOAT\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &a);
        getchar();
        switch(a){
            case 1: {
                int b1;
                do {
                    printf("QUAN LY HO SO BENH NHAN\n");
                    printf("1. Tao ho so benh nhan\n");
                    printf("2. Cap nhat thong tin benh nhan\n");
                    printf("3. Tra cuu thong tin benh nhan\n");
                    printf("4. Danh sach benh nhan\n");
                    printf("5. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &b1);
                    getchar();
                    pressAnyKey();

                    switch (b1) {
                        case 1:
                            tao_benh_nhan();
                            break;
                        case 2:
                            cap_nhat_benh_nhan();
                            break;
                        case 3:
                            tim_kiem_benh_nhan();
                            break;
                        case 4:
                            danh_sach_benh_nhan();
                            break;
                        case 5:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                    }
                } while (b1 != 5);
                break;
            }


            case 2: {
                int b2;
                do {
                    printf("QUAN LY KHAM BENH\n");
                    printf("1. Ghi nhan thong tin kham benh, chan doan va dieu tri\n");
                    printf("2. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &b2);
                    getchar(); // De tieu thu ky tu newline sau scanf
                    pressAnyKey();
                    switch (b2) {
                        case 1:
                            ghi_nhan_kham_benh();
                            break;
                        case 2:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                    }
                } while (b2 != 2);
                break;
            }

            case 3: {
                int b3;
                do {
                    printf("QUAN LY HOA DON VA THANH TOAN\n");
                    printf("1. Tao hoa don\n");
                    printf("2. Cap nhat hoa don\n");
                    printf("3. Tra cuu hoa don\n");
                    printf("4. Danh sach hoa don\n");
                    printf("5. Bao cao doanh thu.\n");
                    printf("6. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &b3);
                    getchar(); // De tieu thu ky tu newline sau scanf
                    pressAnyKey();
                    switch (b3) {
                        case 1:
                            tao_hoa_don();
                            break;
                        case 2:
                            cap_nhat_hoa_don();
                            break;
                        case 3:
                            tim_kiem_hoa_don();
                            break;
                        case 4:
                            danh_sach_hoa_don();
                            break;
                        case 5:
                            bao_cao_doanh_thu_chi_phi(); // Gui ham theo doi va bao cao doanh thu, chi phi
                            break;

                        case 6:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                    }
                } while (b3 != 6);
                break;
            }

            case 4:{
                int b4;
                char ten[50];
                int soLuong;
                time_t ngayHetHan;
                do{
                    printf("QUAN LY KHO DUOC PHAM\n");
                    printf("1. Them thuoc\n");
                    printf("2. Cap nhat thuoc\n");
                    printf("3. Kiem tra ton kho\n");
                    printf("4. Hien thi kho\n");
                    printf("5. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &b4);
                    getchar();
                    pressAnyKey();
                    switch(b4){
                        case 1:
                            nhapThongTinThuoc(ten, &soLuong, &ngayHetHan);
                            themThuoc(ten, soLuong, ngayHetHan);
                                break;
                        case 2:
                            printf("Nhap ten thuoc can cap nhat: ");
                            fgets(ten, sizeof(ten), stdin);
                            ten[strcspn(ten, "\n")] = '\0';
                            printf("Nhap so luong moi: ");
                            scanf("%d", &soLuong);
                            getchar(); // clear newline character
                            capNhatThuoc(ten, soLuong);
                            break;
                        case 3:
                            kiemTraTonKho();
                            break;
                        case 4:
                            hienThiKho();
                            break;
                        case 5:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le.\n");
                        }
                    }while(b4 !=5);
                    break;
                }

            case 5:{
                int b5;
                char tenBenhNhan[50];
                char tenBacSi[50];
                time_t ngayHen;
                do{
                    printf("QUAN LY LICH HEN.\n");
                    printf("1. Them lich hen\n");
                    printf("2. Hien thi lich hen\n");
                    printf("3. Quay lai.\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &b5);
                    getchar();
                    pressAnyKey();
                    switch(b5){
                        case 1:
                            nhapThongTinLichHen(tenBenhNhan, tenBacSi, &ngayHen);
                            themLichHen(tenBenhNhan, tenBacSi, ngayHen);
                            break;
                        case 2:
                            hienThiLichHen();
                            break;
                        case 3:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le.\n");
                        }
                    }while(b5 !=3);
                    break;
                }

            case 6:{
                int b6;
                do{
                    printf("QUAN LY NHAN SU\n");
                    printf("1. Tao ho so moi\n");
                    printf("2. Cap nhat thong tin nhan su\n");
                    printf("3. Tra cuu thong tin nhan su\n");
                    printf("4. Danh sach nhan su\n");
                    printf("5. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &b6);
                    getchar();
                    pressAnyKey();
                    switch(b6){
                        case 1:
                            tao_nhan_su();
                            break;
                        case 2:
                            cap_nhat_nhan_su();
                            break;
                        case 3:
                            tim_kiem_nhan_su();
                            break;
                        case 4:
                            danh_sach_nhan_su();
                            break;
                        case 5:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                    }
                } while (b6 != 5);
                break;
            }

            case 7:{
                int b7;
                HeThongQuanLyMarketing heThong;
                heThong.soKhachHang = 0;
                heThong.soChienDich = 0;
                heThong.soDichVu = 0;
                heThong.soTuVan = 0;
                heThong.soKham = 0;
                do{
                    printf("QUAN LY MARKETING VA CSKH\n");
                    printf("1. Them khach hang\n");
                    printf("2. Them chien dich\n");
                    printf("3. Them dich vu\n");
                    printf("4. Gui thong bao\n");
                    printf("5. Gui khuyen mai\n");
                    printf("6. Thu nhap phan hoi\n");
                    printf("7. Quan ly tu van online\n");
                    printf("8. Quan ly tu van tai nha\n");
                    printf("9. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &b7);
                    getchar();
                    pressAnyKey();
                    switch(b7){
                        case 1:
                            themKhachHang(&heThong);
                            break;
                        case 2:
                            themChienDich(&heThong);
                            break;
                        case 3:
                            themDichVu(&heThong);
                            break;
                        case 4: {
                            char tieuDe[MAX_LENGTH], noiDung[MAX_LENGTH];
                            printf("Nhập tiêu đề thông báo: ");
                            fgets(tieuDe, MAX_LENGTH, stdin);
                            tieuDe[strcspn(tieuDe, "\n")] = '\0';
                            printf("Nhập nội dung thông báo: ");
                            fgets(noiDung, MAX_LENGTH, stdin);
                            noiDung[strcspn(noiDung, "\n")] = '\0';
                            guiThongBao(&heThong, tieuDe, noiDung);
                            break;
                                }
                        case 5: {
                            char tieuDe[MAX_LENGTH], noiDung[MAX_LENGTH];
                            double mucGiamGia;
                            printf("Nhập tiêu đề khuyến mãi: ");
                            fgets(tieuDe, MAX_LENGTH, stdin);
                            tieuDe[strcspn(tieuDe, "\n")] = '\0';
                            printf("Nhập nội dung khuyến mãi: ");
                            fgets(noiDung, MAX_LENGTH, stdin);
                            noiDung[strcspn(noiDung, "\n")] = '\0';
                            printf("Nhập mức giảm giá: ");
                            scanf("%lf", &mucGiamGia);
                            getchar(); // clear the newline character from the input buffer
                            guiKhuyenMai(&heThong, tieuDe, noiDung, mucGiamGia);
                            break;
                                }
                        case 6: {
                            char tenKhachHang[MAX_LENGTH], phanHoi[MAX_LENGTH];
                            printf("Nhập tên khách hàng: ");
                            fgets(tenKhachHang, MAX_LENGTH, stdin);
                            tenKhachHang[strcspn(tenKhachHang, "\n")] = '\0';
                            printf("Nhập phản hồi: ");
                            fgets(phanHoi, MAX_LENGTH, stdin);
                            phanHoi[strcspn(phanHoi, "\n")] = '\0';
                            thuThapPhanHoi(&heThong, tenKhachHang, phanHoi);
                            break;
                                }
                        case 7: {
                            char tenKhachHang[MAX_LENGTH];
                            printf("Nhập tên khách hàng cần tư vấn online: ");
                            fgets(tenKhachHang, MAX_LENGTH, stdin);
                            tenKhachHang[strcspn(tenKhachHang, "\n")] = '\0';
                            quanLyTuVanOnline(&heThong, tenKhachHang);
                            break;
                                }
                        case 8: {
                            char tenKhachHang[MAX_LENGTH];
                            printf("Nhập tên khách hàng cần khám tại nhà: ");
                            fgets(tenKhachHang, MAX_LENGTH, stdin);
                            tenKhachHang[strcspn(tenKhachHang, "\n")] = '\0';
                            quanLyKhamTaiNha(&heThong, tenKhachHang);
                            break;
                                }
                        case 9:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                                }
                        } while (b7 != 9);
                    break;
                    }
            case 8:
                printf("Thoat chuong trinh...\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                pressAnyKey();
        }
    } while (a != 8); // Sua phong lap de thoat chuong trinh
    return 0;
}
