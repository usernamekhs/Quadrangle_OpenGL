#pragma comment(lib, "opengl32.lib")

#include <windows.h>
#include <gl/GL.h>

LRESULT CALLBACK WndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    if (m == WM_DESTROY) { PostQuitMessage(0); return 0; }
    return DefWindowProc(h, m, w, l);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmd) {
    WNDCLASS wc = { CS_OWNDC, WndProc, 0, 0, hInst, 0, 0, 0, 0, L"GL" };
    RegisterClass(&wc);
    HWND hwnd = CreateWindow(L"GL", L"Rectangle", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, 0, 0, hInst, 0);
    ShowWindow(hwnd, nCmd);

    HDC dc = GetDC(hwnd);
    PIXELFORMATDESCRIPTOR pfd = { sizeof(pfd), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA };
    SetPixelFormat(dc, ChoosePixelFormat(dc, &pfd), &pfd);
    HGLRC rc = wglCreateContext(dc); wglMakeCurrent(dc, rc);

    // »ç°¢ÇüÀ» ±¸¼ºÇÏ´Â µÎ °³ÀÇ »ï°¢Çü (CCW ¹æÇâ)
    float v[] = {
        // Ã¹ ¹øÂ° »ï°¢Çü
        -0.5f, -0.5f, 1, 0, 0,   // ÁÂÇÏ (»¡°­)
         0.5f, -0.5f, 0, 1, 0,   // ¿ìÇÏ (ÃÊ·Ï)
        -0.5f,  0.5f, 0, 0, 1,   // ÁÂ»ó (ÆÄ¶û)

        // µÎ ¹øÂ° »ï°¢Çü
         0.5f, -0.5f, 0, 1, 0,   // ¿ìÇÏ (ÃÊ·Ï)
         0.5f,  0.5f, 1, 1, 0,   // ¿ì»ó (³ë¶û)
        -0.5f,  0.5f, 0, 0, 1    // ÁÂ»ó (ÆÄ¶û)
    };

    MSG msg;
    while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE) || 1) {
        if (msg.message == WM_QUIT) break;
        TranslateMessage(&msg); DispatchMessage(&msg);

        glClearColor(0.1f, 0.1f, 0.4f, 1);  // ¹è°æ»ö (Â£Àº ÆÄ¶û)
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(2, GL_FLOAT, 5 * sizeof(float), v);
        glColorPointer(3, GL_FLOAT, 5 * sizeof(float), v + 2);
        glDrawArrays(GL_TRIANGLES, 0, 6);  // »ï°¢Çü 2°³ ¡æ ÃÑ 6°³ Á¤Á¡
        SwapBuffers(dc);
    }

    wglMakeCurrent(0, 0); wglDeleteContext(rc); ReleaseDC(hwnd, dc);
    return 0;
}
