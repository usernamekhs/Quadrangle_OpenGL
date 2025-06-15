# Quadrangle_OpenGL
- Andong National Universty 국립 안동대학교 
- Computer Engineering 컴퓨터공학과
- 팀장 김현근, 팀원 김다예, 김동건, 조지형, 황규만

이 프로젝트는 Win32 API와 OpenGL을 사용하여 화면에 간단한 **사각형(Rectangle)** 을 렌더링하는 예제입니다.  
사각형은 두 개의 삼각형으로 구성되어 있으며, 각 정점에는 고유한 색상이 지정되어 있습니다.

## 🔧 환경

- 운영체제: Windows
- 컴파일러: Visual Studio / MinGW / 기타 Windows 지원 C++ 컴파일러
- 라이브러리: OpenGL (`opengl32.lib`)
- 헤더: `<windows.h>`, `<gl/GL.h>`

## 🚀 실행 방법

1. Visual Studio를 사용한다면:
   - 새 Win32 프로젝트를 생성하고 `.cpp` 파일을 추가한 뒤, 소스 코드를 붙여넣습니다.
   - `opengl32.lib`가 자동으로 링크되도록 설정되어야 합니다 (또는 `#pragma comment(lib, "opengl32.lib")` 포함됨).
   - 실행(F5)하면 사각형이 렌더링됩니다.

2. MinGW 사용 시:
   ```bash
   g++ main.cpp -lopengl32 -lgdi32 -o rectangle.exe
   ./rectangle.exe
