#include "Editor.h"

using namespace std;

Editor::Editor(const string& i_name) : m_name(i_name) 
	{}

Editor::Editor() : m_name("Default")
	{}

const string& Editor::getName() const
	{
	return m_name;
	}

string Editor::codeHighlight(const string& i_code) const
	{
	return i_code;
	}