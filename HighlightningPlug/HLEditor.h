#pragma once
#include "../Editor/Editor.h"

class HLEditor : public Editor
	{
	public:
		HLEditor();
		std::string codeHighlight(const std::string& i_code) const override;
	};

