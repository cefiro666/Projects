#include "pch.h"
#include "Handler.h"

Handler::Handler()
{
	// теги для парсинга
	arrTegOpen = { "<title>", "<p>" };
	arrTegClose = { "</title>", "</p>" };
	pos = 0;
	cout << " -Processing the data... ";
}

void Handler::parsing(string data)
{
	for (unsigned int i = 0; i < arrTegOpen.size(); i++)
	{
		if (data.find(arrTegOpen[i], pos) != string::npos)
		{
			arrBegin.push_back(data.find(arrTegOpen[i], pos));
		}
	}

	if (!arrBegin.empty())
	{
		arrBegin.sort();
		int begin = data.find(">", arrBegin.front());
		arrBegin.clear();

		for (unsigned int i = 0; i < arrTegClose.size(); i++)
		{
			if (data.find(arrTegClose[i], begin + 1) != string::npos)
			{
				arrBegin.push_back(data.find(arrTegClose[i], begin + 1));
			}
		}

		arrBegin.sort();
		int end = data.find(">", arrBegin.front());

		if (!(data.substr(begin + 1, arrBegin.front() - begin - 1).empty()))
		{
			buff.append(data.substr(begin + 1, arrBegin.front() - begin - 1) + "\n\n");
		}

		pos = end + 1;
		arrBegin.clear();
		parsing(data);
	}
}

void Handler::formatLink()
{
	string openTeg, closeTeg, link;
	unsigned int pos = 0;
	unsigned int begin, end, linkIndex;

	while (true)
	{
		openTeg = "<a ";
		closeTeg = "href=\"";
		begin = buff.find(openTeg, pos);
		if (begin == string::npos) break;
		end = buff.find(closeTeg, begin);
		linkIndex = buff.find("\"", end + closeTeg.size());
		link = " [" + buff.substr(end + closeTeg.size(), linkIndex - end - closeTeg.size()) + "]";

		closeTeg = ">";
		end = buff.find(closeTeg, begin);
		buff.erase(begin, end - begin + closeTeg.size());

		openTeg = "</a>";
		begin = buff.find(openTeg, pos);
		buff.erase(begin, openTeg.size());
		buff.insert(begin, link);

		pos = begin + link.size();
	}
}

void Handler::delExtraItems(vector<string> extraItems)
{
	string items;
	unsigned int index;

	for (unsigned int i = 0; i < extraItems.size(); i++)
	{
		while (true)
		{
			items = extraItems[i];
			index = buff.find(items);
			if (index == string::npos) break;
			buff.erase(index, items.size());
		}
	}
}

void Handler::lineWidth(int lineWidth)
{
	string data, buffer;
	unsigned int pos = 0;
	unsigned int space, x;

	while (pos < buff.size())
	{
		buffer.append(buff, pos, lineWidth);
		x = buffer.find("\n");

		if (x != string::npos)
		{
			buffer.clear();
			buffer.append(buff, pos, x);
			data.append(buffer, 0, x);
			data.append("\n\n");
			buffer.clear();
			pos += x + 2;
		} else {
			space = buffer.rfind(' ');
			data.append(buffer, 0, space);
			data.append("\n");
			buffer.clear();
			pos += space + 1;
		}
	}

	buff = data;
	cout << "         Done" << endl;
}

string Handler::getBuff()
{
	return buff;
}