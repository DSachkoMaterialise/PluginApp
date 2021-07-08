#include <memory>
#include "HLEditor.h"

extern "C" __declspec(dllexport) Editor* getEditor()
	{
	return new HLEditor;
	}