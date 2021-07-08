#pragma once
#include <string>
#include <functional>
#include <Windows.h>
#include <system_error>

class Library
  {
	private:
		HMODULE m_handle;
	public:
		Library(const std::wstring& i_libName);
		~Library();
		Library(const Library&) = delete;
		Library& operator=(const Library&) = delete;
		Library(Library&& library) noexcept;
		Library& operator=(Library&& library) noexcept;

		template<class Func>
		std::function<Func> getFunc(const std::string& i_funcName) const
			{
			auto funcPtr = GetProcAddress(m_handle, i_funcName.data());
			if (!funcPtr)
				throw std::system_error(GetLastError(), std::system_category(), "getting function error");
			return reinterpret_cast<Func*>(funcPtr);
			}
	};

