#include "Shader.h"

Engine::Shader::Shader(const char* VertexPath, const char* FragmentPath)
{
    this->FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    this->VertexShader = glCreateShader(GL_VERTEX_SHADER);

    this->VertexShaderString = this->ReadFile(VertexPath);
    this->FragmentShaderString = this->ReadFile(FragmentPath);

    this->VertexShaderSource = VertexShaderString.c_str();
    this->FragmentShaderSource = FragmentShaderString.c_str();
}

Engine::Shader::~Shader()
{
    glDeleteShader(this->VertexShader);
    glDeleteShader(this->FragmentShader);
}

GLint Engine::Shader::CheckCompilation(GLuint CompiledShader)
{
    GLint CompileResult = GL_FALSE;
    int LogLength;

    glGetShaderiv(CompiledShader, GL_COMPILE_STATUS, &CompileResult);
    glGetShaderiv(CompiledShader, GL_INFO_LOG_LENGTH, &LogLength);
    char* ShaderError = new char[LogLength];
    glGetShaderInfoLog(CompiledShader, LogLength, NULL, ShaderError);
    std::cout << "Check error: " << (char*)ShaderError << std::endl;

    delete ShaderError;

    return CompileResult;
}

void Engine::Shader::Compile()
{
    glShaderSource(this->VertexShader, 1, &this->VertexShaderSource, NULL);
    glCompileShader(this->VertexShader);

    if (this->DebugEnabled) {
        // Check vertex shader
        std::cout << "Compiling vertex shader." << std::endl;
        this->CheckCompilation(this->VertexShader);
    }

    glShaderSource(this->FragmentShader, 1, &this->FragmentShaderSource, NULL);
    glCompileShader(this->FragmentShader);

    if (this->DebugEnabled) {
        // Check fragment shader
        std::cout << "Compiling fragment shader." << std::endl;
        this->CheckCompilation(this->FragmentShader);

        std::cout << "Linking program" << std::endl;
    }

    GLuint ShaderProgram = glCreateProgram();
    glAttachShader(ShaderProgram, this->VertexShader);
    glAttachShader(ShaderProgram, this->FragmentShader);
    glLinkProgram(ShaderProgram);

    this->bShaderIsCompiled = true;

    this->ShaderProgramID = ShaderProgram;
}

bool Engine::Shader::IsShaderCompiled()
{
    return this->bShaderIsCompiled;
}

GLuint Engine::Shader::GetProgramID()
{
    if (!this->IsShaderCompiled()) {
        throw new ShaderException("Shader is not compiled yet!");
    }

    return ShaderProgramID;
}

std::string Engine::Shader::ReadFile(const char* FilePath)
{
    std::string content;
    std::ifstream FileStream(FilePath, std::ios::in);

    if (!FileStream.is_open()) {
        throw new ShaderException("Can not open shader file!");
    }

    std::string line = "";
    while (!FileStream.eof()) {
        std::getline(FileStream, line);
        content.append(line + "\n");
    }

    FileStream.close();
    return content;
}