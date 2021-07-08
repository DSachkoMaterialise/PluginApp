#include <iostream>
#include <filesystem>
#include <vector>
#include <memory>
#include <fstream>
#include "Library.h"
#include "../Editor/Editor.h"

using namespace std;

vector<Library> getPlugins(const string& i_folder)
	{
	vector<Library> libs;
	for (auto& file : filesystem::directory_iterator(i_folder))
		{
		if (file.is_regular_file() && file.path().extension() == ".dll")
			libs.emplace_back(file.path().native());
		}
	return libs;
	}

int main(int argc, char** args)
	{
	try
		{
		auto plugs = getPlugins("..\\Debug\\plugins");										//Как сделать так, чтобы при запуске проекта с Visual Studio, он запускался относительно папки Debug, а не PluginApp???
		vector<shared_ptr<Editor>> editors = {make_shared<Editor>()};
		for (const auto& plug : plugs)
			editors.emplace_back(plug.getFunc<Editor* ()>("getEditor")());  //taking function and calling it

		cout << "Choose the editor plugin:\n";
		for (int i = 0; i < editors.size(); i++)
			cout << i + 1 << ") " << editors[i]->getName() << endl;

		int numPlug;
		cin >> numPlug;

		if (argc >= 2)
			{
			ifstream fin(args[1]);
			string code, line;
			while (getline(fin, line))
				{
				code += line + "\n";
				}
			cout << editors[numPlug - 1]->codeHighlight(code);
			}
		}
	catch (system_error& er)
		{
		cerr << er.what();
		}
	}