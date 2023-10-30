#define _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>

HANDLE image = NULL;

void MessageProc_WM_CREATE(HWND hWnd)
{
	image = LoadImage(NULL, TEXT("./͸��png����ͼƬ.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_LOADMAP3DCOLORS);
}

void MessageProc_WM_PAINT(HWND hWnd)
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint(hWnd, &ps);

	

	EndPaint(hWnd, &ps);
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	//�ַ���Ϣ����
	switch (msgID)
	{
	case WM_DESTROY:
		PostMessage(hWnd, WM_QUIT, 0, 0);
		return 0;
	case WM_CREATE:

		return 0;
	case WM_PAINT:

		return 0;
	default:
		return DefWindowProc(hWnd, msgID, wParam, lParam);
	}

	return DefWindowProc(hWnd, msgID, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int cmdShow)
{
	TCHAR mainWndClassName[] = TEXT("The Main Window Class");
	TCHAR mainWndName[] = TEXT("The Window");
	MSG userMessage = { 0 };
	HWND hMainWindow = NULL;

	//ע�ᴰ����
	WNDCLASSEX wcEx = { 0 };
	wcEx.cbSize = sizeof(WNDCLASSEX);
	wcEx.lpfnWndProc = MainWndProc;
	wcEx.lpszClassName = mainWndClassName;
	wcEx.hbrBackground = CreateSolidBrush(0xAAAAAA);
	wcEx.hInstance = hInstance;
	wcEx.hIconSm = LoadIcon(NULL, (LPCTSTR)GetStockObject((int)IDI_SHIELD));
	wcEx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClassEx(&wcEx);

	//��ʾ����
	hMainWindow = CreateWindowEx(WS_EX_ACCEPTFILES, mainWndClassName, mainWndName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 500, NULL, NULL, hInstance, NULL);
	ShowWindow(hMainWindow, SW_SHOW);
	UpdateWindow(hMainWindow);

	//��Ϣѭ��
	while (TRUE)
	{
		if (PeekMessage(&userMessage, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&userMessage, NULL, 0, 0))
			{
				//��Ϣ�ַ��뷭��
				TranslateMessage(&userMessage);
				DispatchMessage(&userMessage);
			}
			else
			{
				//��⵽�Ƴ���Ϣ���˳�����
				break;
			}
		}
		else
		{
			//��Ⱦ
		}
	}

	UnregisterClass(mainWndClassName, hInstance);
	return 0;
}