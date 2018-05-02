#include <iostream>
using namespace std;

class DaysFrom19010101
{
public:
  int m_dSeriesNumber;
  int m_nYear;
  int m_nMonth;
  int m_nDay;
  int m_dWeekDay;
  bool m_bLeap;

  DaysFrom19010101()
  {
    m_dSeriesNumber = 0;
    m_nYear = 0;
    m_nMonth = 0;
    m_nDay = 0;
    m_dWeekDay = -1;
    m_bLeap = false;
  }
};

int main()
{
  int num_days_from_jan_1_1901 = 36525;
  int i, j, k;
  DaysFrom19010101 one_day[36525];
  int days_in_month[12];
  days_in_month[0] = 31;
  days_in_month[1] = 28;
  days_in_month[2] = 31;
  days_in_month[3] = 30;
  days_in_month[4] = 31;
  days_in_month[5] = 30;
  days_in_month[6] = 31;
  days_in_month[7] = 31;
  days_in_month[8] = 30;
  days_in_month[9] = 31;
  days_in_month[10] = 30;
  days_in_month[11] = 31;

  int count = 0;
  int count_first_day_sunday = 0;

  for (i = 0; i < 100; i++)
  {
    bool b_leap_year = false;
    days_in_month[1] = 28;
    if (i % 4 == 3)
    {
      b_leap_year = true;
      days_in_month[1] = 29;
    }

    for (j = 0; j < 12; j++)
    {
      for (k = 0; k < days_in_month[j]; k++)
      {
        one_day[count].m_dSeriesNumber = count + 1;
        one_day[count].m_nYear = 1901 + i;
        one_day[count].m_nMonth = j + 1;
        one_day[count].m_nDay = k + 1;
        one_day[count].m_bLeap = b_leap_year;
        one_day[count].m_dWeekDay = (1 + one_day[count].m_dSeriesNumber) % 7;
        if ((one_day[count].m_nDay == 1) && (one_day[count].m_dWeekDay == 0))
          count_first_day_sunday++;
        count++;
      }
    }
  }

  int answer = count_first_day_sunday;
  cout << answer << endl;

  return 0;
}
