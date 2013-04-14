#ifndef DATE_HPP
#define DATE_HPP

class Date
{
	private:
		static time_t t;
		static struct tm * timeinfo;
		static int days_in_month[2][13];
		static int dfboty[2][13];
		
		bool check_date(void);
		double days(void) const;
	protected:
		static bool is_leap_year(int);
	public:
		const int day, month, year;
		
		Date(void);
		Date(const Date&);
		Date(int,int,int);
		static double days_from_to(const Date&, const Date&);
};

#endif