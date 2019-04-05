#include "pch.h"
#include "ReadConf.h"
#include "Connect.h"
#include "Handler.h"
#include "CreatFile.h"

int main(int argc, char* argv[])
{
	//******************************************************
	// задание локали (только Windows)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//******************************************************
	// создание объекта-конфигуратора
	ReadConf config;
	// чтение конфигурационного файла и установка параметров
	config.readConf();

	//******************************************************
	// подключение к ресурсу по адресу url(argv[1])
	// и скачивание данных html в буфер
	Connect htmlData(argv[1]);
	// конвертация кодировки в буфере, если utf-8
	if (htmlData.is_valid_utf8()) htmlData.utf8toAnsi();
	
	//******************************************************
	// создание объекта-обработчика
	Handler article;
	// передача буфера в обработчик и парсинг заголовков
	// и параграфов
	article.parsing(htmlData.getData());
	// форматирование ссылок в буфере
	article.formatLink();
	// удаление лишних элементов из буфера
	article.delExtraItems(config.getExtraItems());
	// выравнивание буфера по ширине строки с переносом
	article.lineWidth(config.getLineWidth());

	//******************************************************
	// создание объекта с формированием имени файла
	// по url(argv[1])
	CreatFile textFile(argv[1]);
	// запись данных из буфера в текстовый файл 
	textFile.write(article.getBuff());
}