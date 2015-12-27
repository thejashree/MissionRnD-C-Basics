/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
bool isLeap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}
bool isValid(int d_1, int d_2, int m_1, int m_2, int y_1, int y_2)
{
	if (d_1 == 0 || d_2 == 0 || ((1 > d_1) || (d_1> 31)) || ((1 > d_2) || (d_2> 31)))
		return false;
	else if (m_1 == 0 || m_2 == 0 || ((1>m_1) || (m_1>12)) || ((1>m_2) || (m_2>12)))
		return false;
	else if (y_1 == 0 || y_2 == 0)
		return false;
	else if((!isLeap(y_1) && m_1==2 && d_1 > 28) || (!isLeap(y_2) && m_2==2 && d_2 > 28))
		return false;
	else return true;
}

int isOlder(char *dob1, char *dob2) {
	int  i = 0;
	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	while (i < 2)
	{
		d1 = d1 * 10 + dob1[i] - '0';
		d2 = d2 * 10 + dob2[i] - '0';
		i++;
	}
	i++;
	while (i < 5)
	{
		m1 = m1 * 10 + dob1[i] - '0';
		m2 = m2 * 10 + dob2[i] - '0';
		i++;
	}
	i++;
	while (dob1[i] != '\0' && dob2[i] != '\0')
	{
		y1 = y1 * 10 + dob1[i] - '0';
		y2 = y2 * 10 + dob2[i] - '0';
		i++;
	}
	if (isValid(d1, d2, m1, m2, y1, y2))
	{
		if (y1 > y2)
			return 2;
		else if (y1 < y2)
			return 1;
		else if (y1 == y2)
		{
			if (m1>m2)
				return 2;
			else if (m2 > m1)
				return 1;
			else if (m1 == m2)
			{
				if (d1 > d2)
					return 2;
				else if (d2 > d1)
					return 1;
				else if (d1 == d2)
					return 0;
			}
		}
	}
	else return -1;
}
