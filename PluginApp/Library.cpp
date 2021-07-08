#include "Library.h"

using namespace std;

Library::Library(const wstring& i_libName)
	{
	m_handle = LoadLibrary(i_libName.data());
	if (!m_handle)
		throw std::system_error(GetLastError(), std::system_category(), "loading library error");
	}

Library::~Library()
	{
	FreeLibrary(m_handle);
	}

Library::Library(Library&& library) noexcept : m_handle(library.m_handle) 
	{
	library.m_handle = nullptr;
	}

Library& Library::operator=(Library&& library) noexcept
	{
	m_handle = library.m_handle;
	library.m_handle = nullptr;
	return *this;
	}
