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
	int begin, end, linkIndex;

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
	int index;

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
	int indexSpace, indexN, indexNN;

	while (pos < buff.size())
	{
		buffer.append(buff, pos, lineWidth);
		indexNN = buffer.find("\n\n");
		indexN = buffer.find("\n");

		if (indexN != string::npos || indexNN != string::npos)
		{
			buffer.clear();
			buffer.append(buff, pos, indexN);
			data.append(buffer, 0, indexN);
			buffer.clear();
			if (indexNN != string::npos)
			{
				pos += indexN + 2;
				data.append("\n\n");
			} else {
				pos += indexN + 1;
				data.append("\n");
			}
			
		} else {
			indexSpace = buffer.rfind(' ');
			if (indexSpace != string::npos)
			{
				data.append(buffer, 0, indexSpace);
				data.append("\n");
				buffer.clear();
				pos += indexSpace + 1;
			} else {
				data.append(buffer, 0, lineWidth);
				data.append("\n");
				buffer.clear();
				pos += lineWidth + 1;
			}
		}
	}
	buff = data;
	cout << "         Done" << endl;
}

string Handler::getBuff()
{
	return buff;
}