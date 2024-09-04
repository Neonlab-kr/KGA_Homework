#pragma once
//CImage�� ��Ī�� �� ������ ������ ����
//GDI Image

//enum class IMAGE_LOAD_KIND : uint64_t
//{
//
//};// �Ϲ������� class�� ���������� public���� ���� ���̱� ������ class�� ���� ����

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
	typedef struct tagImage//�ʿ�� ������ �����ϵ��� typedef���� Ȯ�强 �ο�
	{
		DWORD	resId;		// ���ҽ� ID
		HDC		hMemDC;		// �޸� DC 
		HBITMAP hBit;		// ��Ʈ��
		HBITMAP hOBit;		// �õ� ��Ʈ��
		int		width;		// �̹��� ����
		int		height;		// �̹��� ����
		BYTE	loadType;	// �̹��� �ε�Ÿ��

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
	// COLORREF : ��ȣ ���� 32��Ʈ ���� -> �����쿡�� ���� ǥ���� ���Ǵ� �༮

public:
	HRESULT init(int width, int height);

	//HRESULT init(const DWORD resID, int width, int height, bool isTrans = false, COLORREF tranColor = RGB(0, 0, 0));
	
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	void setTransColor(bool isTrans, COLORREF transcolor);

	void release(void);

	void render(HDC hdc);// ��ġ�� �����Ƿ� 0,0�� ���(��濡 ����)
	void render(HDC hdc, int destX, int destY);// destX, destY�� ���

	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }


	GImage();
	~GImage() {}
};

