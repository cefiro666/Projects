#include "pch.h"
#include "Connection.h"
#include "Parser.h"
#include "File.h"

int main(int argc, char* argv[])
{
	// задание локали (только Windows)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// переменные параметры
	int lineWidth = 80;
	vector<string> extraItems = { "<span>", "<br>", "<i>", "<sup>", "<em>", "<strong>", "</span>",
		"</i>", "</sup>", "</em>", "</strong>", "&quot;", "&nbsp;", "&copy;", "&laquo;", "&raquo;", "<br />" };

	// подключение к ресурсу по адресу url(argv[1]) и скачивание данных в буфер
	Connection connect(argv[1]);
	// конвертация кодировки данных в буфере
	connect.UTF8ToANSI();

	// создание объекта для обработки буфера
	Parser pars;
	// парсинг буфера (вытяжка заголовков и параграфов)
	pars.parser(connect.getData());
	// форматирование ссылок в буфере
	pars.formatLink();
	// удаление лишних элементов из буфера
	pars.delExtraItems(extraItems);
	// выравнивание по 80 символов в строке с переносом слов
	pars.lineWidth(lineWidth);

	// создание объекта с формированием имени будущего файла по url(argv[1])
	File textFile(argv[1]);
	// запись из буфера в тестовый фаил в папке приложения
	textFile.write(pars.getBuff());
}