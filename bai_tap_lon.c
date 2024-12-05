#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **dau_vao(char *input)
{
  char *tmp;
  static char *array[100];
  int i = 0;
  tmp = strtok(input, " ");
  while (tmp != NULL)
  {
    array[i++] = tmp;
    tmp = strtok(NULL, " ");
  }

  return array;
}

void servo(char *goc)
{
  float x = atof(goc);
  if (x < 0 || x > 10)
  {
    printf("-1");
  }
  else
  {
    printf("%d\n", (int)(x * 36));
  }
}

int tinh_tien_thue_nuoc(int tien)
{
  int phi_xu_ly_nuoc = tien * 0.2;
  int thue_phi_xu_ly_nuoc = phi_xu_ly_nuoc * 0.1;
  int phi_gtgt = tien * 0.05;
  return phi_gtgt + thue_phi_xu_ly_nuoc + phi_xu_ly_nuoc + tien;
}

void tinhnuoc(int nhan_khau, int m_current, int m_old)
{
  if (nhan_khau <= 0 || m_current <= 0 || m_old <= 0 || m_current < m_old)
  {
    printf("-1");
    return;
  }

  int so_met_khoi = m_current - m_old;
  int tien_muc1 = tinh_tien_thue_nuoc(6700);
  int tien_muc2 = tinh_tien_thue_nuoc(12900);
  int tien_muc3 = tinh_tien_thue_nuoc(14400);
  long long tong_tien = 0;

  if (so_met_khoi <= 3)
  {
    tong_tien = so_met_khoi * tien_muc1;
  }
  else if (so_met_khoi >= 4 && so_met_khoi <= 6)
  {
    tong_tien = 3 * tien_muc1 + (so_met_khoi - 3) * tien_muc2;
  }
  else
  {
    tong_tien = 3 * tien_muc1 + 3 * tien_muc2 + (so_met_khoi - 6) * tien_muc3;
  }

  printf("%lld", tong_tien * nhan_khau);
}

int thang_a_tieu_thu(bool di_len)
{
  if (di_len == true)
  {
    return 12;
  }
  return 7;
}

int thang_b_tieu_thu(bool di_len)
{
  if (di_len == true)
  {
    return 7;
  }
  return 5;
}

void thangmay(int tang_hien_tai, int tang_can_den, int tai_trong)
{

  if (tai_trong > 2600 || tai_trong <= 0)
  {
    printf("-1");
    return;
  }

  int so_tang_di_chuyen = tang_can_den - tang_hien_tai;
  bool di_len = tang_hien_tai < tang_can_den;

  if (so_tang_di_chuyen < 0)
    so_tang_di_chuyen = -so_tang_di_chuyen;

  int nang_luong = 0;

  if (tai_trong <= 1000)
  {
    nang_luong = thang_b_tieu_thu(di_len) * so_tang_di_chuyen * tai_trong;
  }
  else if (tai_trong <= 1600)
  {
    nang_luong = (thang_b_tieu_thu(di_len) * so_tang_di_chuyen * 1000) + (thang_a_tieu_thu(di_len) * so_tang_di_chuyen * (tai_trong - 1000));
  }
  else if (tai_trong <= 2600)
  {
    nang_luong = (thang_a_tieu_thu(di_len) * so_tang_di_chuyen * 600) + (thang_a_tieu_thu(di_len) * so_tang_di_chuyen * (tai_trong - 600));
  }

  printf("%d\n", nang_luong);
  return;
}
int main()
{
  char input[256];
  fgets(input, sizeof(input), stdin);

  char **array = dau_vao(input);

  if (array[0] != NULL)
  {
    if (strcmp(array[0], "1") == 0)
    {
      servo(array[1]);
    }
    else if (strcmp(array[0], "2") == 0)
    {
      int nhan_khau = atoi(array[1]);
      int m_current = atoi(array[2]);
      int m_old = atoi(array[3]);
      tinhnuoc(nhan_khau, m_current, m_old);
    }
    else if (strcmp(array[0], "3") == 0)
    {
      int tang_hien_tai = atoi(array[1]);
      int tang_can_den = atoi(array[2]);
      int tai_trong = atoi(array[3]);
      thangmay(tang_hien_tai, tang_can_den, tai_trong);
    }
  }

  return 0;
}