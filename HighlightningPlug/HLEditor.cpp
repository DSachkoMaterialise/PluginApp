#include <regex>
#include "HLEditor.h"

using namespace std;

HLEditor::HLEditor() : Editor("Highlight syntax")
	{}

std::string HLEditor::codeHighlight(const std::string& i_code) const
	{
	return regex_replace(i_code, regex("\\b((class)|(int)|(char)|(long)|(short)|(const))\\b"), "<color name=blue>$&<\\color>");
	}