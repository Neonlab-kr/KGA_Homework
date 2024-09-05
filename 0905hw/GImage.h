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
		float x;
		float y;
		int		width;		// 이미지 가로
		int		height;		// 이미지 세로
		int currentFrameX;
		int currentFrameY;
		int maxFrameX;
		int maxFrameY;
		int frameWidth;
		int frameHeight;
		BYTE	loadType;	// 이미지 로드타입


		tagImage()
		{
			resId = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = y = 0;
			width = 0;
			height = 0;
			int currentFrameX = 0;
			int currentFrameY = 0;
			int maxFrameX = 0;
			int maxFrameY = 0;
			int frameWidth = 0;
			int frameHeight = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, * LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	char* _fileName;
	bool			_isTrans;
	COLORREF		_transColor;
	// COLORREF : 부호 없는 32비트 정수 -> 윈도우에서 색상값 표현에 사용되는 녀석

	BLENDFUNCTION _blendFunction;
	LPIMAGE_INFO _blendImage;

public:
	HRESULT init(int width, int height);

	//HRESULT init(const DWORD resID, int width, int height, bool isTrans = false, COLORREF tranColor = RGB(0, 0, 0));

	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	HRESULT init(const char* fileName, float x, float y, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	HRESULT init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	HRESULT init(const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	//HRESULT init(const char* fileName, float x, float y, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0), int[] ...);

	HRESULT initForAlphaBlend(void);

	void setTransColor(bool isTrans, COLORREF transcolor);

	void release(void);

	void render(HDC hdc);// 위치가 없으므로 0,0에 출력(배경에 적합)
	void render(HDC hdc, int destX, int destY);// destX, destY에 출력

	// 클리핑을 전제하는 렌더함수
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	// 알파
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	// void alphaRender(HDC gdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);


	// # 인라인 함수 #
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }

	inline float getX(void) { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }

	inline float getY(void) { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }

	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline int getWidth(void) { return _imageInfo->width; }
	inline int getHeight(void) { return _imageInfo->height; }

	inline RECT boundingBox(void)
	{
		RECT rc =
		{
			(int)_imageInfo->x,
			(int)_imageInfo->y,
			(int)_imageInfo->x + _imageInfo->width,
			(int)_imageInfo->y + _imageInfo->height
		};

		return rc;
	}

	inline RECT boundingBoxWithFrame(void)
	{
		RECT rc =
		{
			(int)_imageInfo->x,
			(int)_imageInfo->y,
			(int)_imageInfo->x + _imageInfo->frameWidth,
			(int)_imageInfo->y + _imageInfo->frameHeight
		};

		return rc;
	}

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline void setFrameX(float frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}

	inline int getFrameY(void) { return _imageInfo->currentFrameY; }
	inline void setFrameY(float frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	GImage();
	~GImage() {};
};

