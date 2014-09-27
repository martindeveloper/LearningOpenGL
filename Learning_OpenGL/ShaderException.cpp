#include "ShaderException.h"

Engine::ShaderException::ShaderException(std::string ErrorMessage)
{
    Message = ErrorMessage;
}

Engine::ShaderException::~ShaderException()
{
}
