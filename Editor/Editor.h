#pragma once
#include <string>

#ifdef DLLEXPORT
#define DLLFUNC __declspec(dllexport)
#else
#define DLLFUNC __declspec(dllimport)
#endif // DLLEXPORT


class DLLFUNC Editor
	{
	protected:
		std::string m_name;
		Editor(const std::string& i_name);
	public:
		Editor();
		const std::string& getName() const;
		virtual std::string codeHighlight(const std::string& i_code) const;
		~Editor() = default;
	};