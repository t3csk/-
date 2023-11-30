#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>

struct schedule
{
    bool operator <(const schedule& obj) const 
	{ 
		return (sortnum < obj.sortnum); 
	}

	int year;
    int month;
    int day;
	std::string content;
	int sortnum;
};

class schedule_mgr
{
	public:

    schedule sh;

    void Set_shedule(const unsigned y, const unsigned int m, const unsigned d, const std::string& c)
    {
        sh.year = y;
        sh.month = m;
        sh.day = d;
        sh.content = c;
        sh.sortnum = y * 12 * 31 + m * 31 + d;

        s_array.push_back(sh);
    }

	void Delete_shedule(const unsigned int y, const unsigned m, const unsigned d)
	{
        int sortn = y * 12 * 31 + m * 31 + d;

		for(std::vector< schedule >::iterator sn = s_array.begin(); sn != s_array.end(); ++sn)
		{
			if(sn->sortnum == sortn) 
			{ 
				s_array.erase(sn); 
				break; 
			}
		}
	}

	void Show()
	{
	    std::sort(s_array.begin(), s_array.end(), std::less< schedule >()); 

		for(size_t i = 0; i < s_array.size(); ++i)
		{
			std::cout << s_array[i].year << " " << s_array[i].month << " " << s_array[i].day << " " << s_array[i].content << std::endl;
		}
	}

    void Input()
    {
        std::ifstream ifs("output.txt");
        std::string line;

        for(int i = 0; ifs >> line; ++i)
	    {
            if((i % 4) == 1)
            {
                sh.year = stoi(line);
            }
            else if((i % 4) == 2)
            {
                sh.month = stoi(line);
            }
            else if((i % 4) == 3)
            {
                sh.day = stoi(line);
            }
            else if((i % 4) == 0 && i != 0)
            {
                sh.content = line;
                s_array.push_back(sh);
            }
	    }
    }

	void Output(std::string c)
	{
		std::ofstream ofs("output.txt");	

		ofs << c << std::endl;

		for(size_t i = 0; i < s_array.size(); ++i)
		{
			ofs << s_array[i].year << " " << s_array[i].month << " " << s_array[i].day << " " << s_array[i].content << std::endl;
		}

		ofs.close();
	}

	private:
	std::vector< schedule > s_array;
};


int main(void)
{
	schedule_mgr sm;
    int a;
    std::string x("guest");
	int y, m, d;
	std::string c;
	bool flag = true;

    std::cout << "選んだ方の数字を入力してください" << std::endl;
    std::cout << "1 ニックネーム設定、2 ニックネーム設定なし※半角入力" << std::endl;
    try
	{	
		std::cin >> a;
	}
	catch(...)
	{
		std::cout << "Exception" << std::endl;
	}

	while(a != 1 && a != 2)
	{
		std::cout << "指定の数字を入力してください" << std::endl;
		std::cout << "1 ニックネーム設定、2 ニックネーム設定なし※半角入力" << std::endl;
		try
		{
			std::cin >> a;
		}
		catch(...)
		{
			std::cout << "Exception" << std::endl;
		}	
	}

    if(a == 1)
    {
		try
		{
        	std::cout << "ニックネームを入力してください※半角アルファベット入力、スペースなど不可、例 aiu_is_eo" << std::endl;
        	std::cin >> x;
		}
		catch(...)
		{
			std::cout << "Exception" << std::endl;
		}
    }

    std::cout << "前回の出力ファイルを使用しますか、選んだ方の数字を入力してください" << std::endl;
    std::cout << "1 使用する、2 使用しない※半角入力" << std::endl;

    try
	{	
		std::cin >> a;
	}
	catch(...)
	{
		std::cout << "Exception" << std::endl;
	}

    while(a != 1 && a != 2)
	{
		std::cout << "指定の数字を入力してください" << std::endl;
		std::cout << "1 使用する、2 使用しない※半角入力" << std::endl;
		try
		{
			std::cin >> a;
		}
		catch(...)
		{
			std::cout << "Exception" << std::endl;
		}	
	}

    if(a == 1)
    {
        sm.Input();
        sm.Show();
    }

	std::cout << "指示に従って予定を入力してください" << std::endl;

	std::cout << "予定の日付を入力してください" << std::endl;

	std::cout << "年(西暦) 月 日※半角入力、例 2023 1 1 : ";
	try
	{
		std::cin >> y >> m >> d;
	}
	catch(...)
	{
		std::cout << "Exception" << std::endl;
	}

	std::cout << "次に予定の内容を入力してください※半角アルファベット入力、スペースなど不可、例 aiu_is_eo" << std::endl;
	try
	{
		std::cin >> c;
	}
	catch(...)
	{
		std::cout << "Exception" << std::endl;
	}

	sm.Set_shedule(y, m, d, c);

	while(flag)
	{
		std::cout << "他の予定の入力を行いますか、当てはまる数字を入力してください" << std::endl;
        std::cout << "1 行う、2 行わない※半角入力" << std::endl;
		try
		{
			std::cin >> a;
		}
		catch(...)
		{
			std::cout << "Exception" << std::endl;
		}

		while(a != 1 && a != 2)
		{
			std::cout << "指定の数字を入力してください" << std::endl;
			std::cout << "1 行う、2 行わない※半角入力" << std::endl;
			try
			{
				std::cin >> a;
			}
			catch(...)
			{
				std::cout << "Exception" << std::endl;
			}	
		}

		if(a == 1)
		{
			std::cout << "指示に従って予定を入力してください" << std::endl;

			std::cout << "予定の日付を入力してください" << std::endl;

			std::cout << "年(西暦) 月 日※半角入力、例 2023 1 1 : ";
			try
			{
				std::cin >> y >> m >> d;
			}
			catch(...)
			{
				std::cout << "Exception" << std::endl;
			}

			std::cout << "次に予定の内容を入力してください※半角アルファベット入力、スペースなど不可、例 aiu_is_eo" << std::endl;
			try
			{
				std::cin >> c;
			}
			catch(...)
			{
				std::cout << "Exception" << std::endl;
			}

			sm.Set_shedule(y, m, d, c);
		}
		else
		{
			flag = false;
		}
	}

	sm.Show();

    flag = true;
	
	while(flag)
	{
        std::cout << "予定の削除を行いますか、当てはまる数字を入力してください" << std::endl;
        std::cout << "1 行う、2 行わない※半角入力" << std::endl;
	    try
	    {
		    std::cin >> a;
	    }
	    catch(...)
	    {
    	    std::cout << "Exception" << std::endl;
	    }
        
		while(a != 1 && a != 2)
		{
			std::cout << "指定の数字を入力してください" << std::endl;
			std::cout << "1 行う、2 行わない※半角入力" << std::endl;
			try
			{
				std::cin >> a;
			}
			catch(...)
			{
				std::cout << "Exception" << std::endl;
			}	
		}

		if(a == 1)
		{
			std::cout << "消したい予定の年月日を入力してください" << std::endl;

			std::cout << "年(西暦) 月 日※半角入力、例 2023 1 1 : ";
			try
			{
				std::cin >> y >> m >> d;
			}
			catch(...)
			{
				std::cout << "Exception" << std::endl;
			}

			sm.Delete_shedule(y, m, d);

			sm.Show();
		}
		else
		{
			flag = false;
		}
	}

	sm.Show();

	std::cout << "入力した予定がテキストに出力されます" << std::endl;
	std::cout << "ファイルの名前、内容をそのままにしておくと今後の予定の調整に使用できます" << std::endl;

	sm.Output(x);

}