#pragma once
#include <string>

class Editor
	{
	protected:
		std::string m_name;
	public:
		const std::string& getName() const;
		virtual std::string codeHighlight(const std::string& i_code) const;
	};