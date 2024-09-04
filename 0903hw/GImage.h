#pragma once
//CImage가 명칭상 더 맞지만 예약어라서 변경
//GDI Image

//enum class IMAGE_LOAD_KIND : uint64_t
//{
//
//};// 일반적으로 class가 유리하지만 public으로 잡을 것이기 때문에 class가 맞지 않음

class GImage
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0, LOAD_FILE,
		LOAD_EMPTY, LOAD_END
	};
	//BYTE	-> unsigned char
	//WORD	-> unsigned short
	//DWORD	-> unsigned long
	typedef struct tagImage//필요시 재정의 가능하도록 typedef으로 확장성 부여
	{
		DWORD	resId;		// 리소스 ID
		HDC		hMemDC;		// 메모리 DC 
		HBITMAP hBit;		// 비트맵
		HBITMAP hOBit;		// 올드 비트맵
		int		width;		// 이미지 가로
		int		height;		// 이미지 세로
		BYTE	loadType;	// 이미지 로드타입

		tagImage()
		{
			resId = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	char*			_fileName;
	bool			_isTrans;
	COLORREF		_transColor;
	// COLORREF : 부호 없는 32비트 정수 -> 윈도우에서 색상값 표현에 사용되는 녀석

public:
	HRESULT init(int width, int height);

	//HRESULT init(const DWORD resID, int width, int height, bool isTrans = false, COLORREF tranColor = RGB(0, 0, 0));
	
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	void setTransColor(bool isTrans, COLORREF transcolor);

	void release(void);

	void render(HDC hdc);// 위치가 없으므로 0,0에 출력(배경에 적합)
	void render(HDC hdc, int destX, int destY);// destX, destY에 출력

	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }


	GImage();
	~GImage() {}
};

