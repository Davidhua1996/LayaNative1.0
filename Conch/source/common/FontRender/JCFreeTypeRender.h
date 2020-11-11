/**
@file			JCFreeTypeRender.h
@brief			
@author			James
@version		1.0
@date			2016_5_11
*/

#ifndef __JCFreeTypeRender_H__
#define __JCFreeTypeRender_H__

#include <vector>
#include<unordered_map>
#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "../resource/JCResource.h"
#include "../buffer/JCBuffer.h"
#include <thread>
#include <mutex>
#include "../resource/text/JCFontInfo.h"
#include "../imageLib/JCImageRW.h"
#include "../JCIOSFTInterface.h"
#include <math.h>

namespace laya
{
    #define TEXT_SIZE_ALLOWANCE 8
    #define MAX_FONT_SIZE 256
	class JCFreeTypeFontRender
    {
    public:

        struct FTFaceRecord
        {
            FT_Face face;
            char* buffer;
            FTFaceRecord(FT_Face face = nullptr, char* buffer = nullptr)
                :face(face), buffer(buffer)
            {}
            ~FTFaceRecord()
            {
                if (face)
                {
                    FT_Done_Face(face);
                    face = NULL;
                }
                if (buffer)
                {
                    delete[] buffer;
                    buffer = nullptr;
                }
            }
        };
        typedef std::unordered_map<std::string, FTFaceRecord*> MapFTFace;

	public:
        
        JCFreeTypeFontRender();

		~JCFreeTypeFontRender();

        /** @brief ��ʼ��Ĭ�����壬����Ĳ����м��� \4 �ָ�
         *  @return ���سɹ�����ʧ��
        */
		bool initDefaultFont( const char* sDefaultTTFs );


        /** @brief ��ʼ��Ĭ������buffer �� size
        *  @return ���سɹ�����ʧ��
        */
        bool initDefaultFont(char* pBuffer, int nBuferLen);

        /** @brief ����IOSFT��Interface ��Ϊ�Ǵ�IOS�㴫������
         *  @param[in] JCIOSFTInterfaceʵ��
         *  @return 
        */
        void setIOSFTInterface(JCIOSFTInterface* pIOSFTInterface);

        /** @brief ���������FileName�ж�ȡ
         *  @param[in] ��������
         *  @param[in] ttf��·��
         *  @return �Ƿ��ȡ�ɹ�
        */
        bool setFontFaceFromUrl(const char* sFontFamily, const char* sTTFFileName);

        /** @brief ���������buffer�ж�ȡ
         *  @param[in] ���������
         *  @param[in] buffer
         *  @param[in] bufferLength
         *  @return �Ƿ��ȡ�ɹ�
        */
        bool setFontFaceFromBuffer(const char* sFontFamily, char* pBuffer, int nBuferLen );

        /** @brief �Ƴ�����
         *  @param[in] ���������
         *  @return 
        */
        bool removeFont( const char* sFontFamily );


        /** @brief ��������
        *  @param[in] FreeTypeFontRender
        *  @param[in] ����
        *  @param[in] ���ֵ�info
        *  @param[out] ���ؿ��
        *  @param[out] ���ظ߶�
        *  @return
        */
        void measureText( char* p_sWord, JCFontInfo* p_pFontInfo, int& p_nW, int& p_nH);

        /** @brief ����һ������
        *  @param[in] FreeTypeFontRender
        *  @param[in] ����
        *  @param[in] ���ֵ�info
        *  @param[out] ���ؿ��
        *  @param[out] ���ظ߶�
        *  @return
        */
        void measureTexts(char* p_sWord, JCFontInfo* p_pFontInfo, int& p_nW, int& p_nH);

        /** @brief bitmapData �ṩbuffer��buffer�Ĵ�С�� ���ص�ʱ��bitmapData�еĴ�С�Ѿ����ĳ���ʵ�ʵĴ�С��
        *  @param[in] �ַ�
        *  @param[in] bitmapdata
        *  @param[in] colkor
        *  @param[in] ������Ϣ
        *  @param[out] ���buffer��С���㣬�򷵻�false
        *  @return
        */
        bool getTextBitmapData(char* str, BitmapData* bitmapData, int nColor, JCFontInfo* p_pFontInfo, float scaleX, float scaleY);


        /** @brief ����û��Լ����������
        *  @return
        */
        void clearCustomFont();

    private:

        /** @brief ��������
        *  @param[in] ���������
        *  @return �Ƿ����óɹ�
        */
        bool setFont(const char* sFontName);

        /** @brief ����б���ֵ
        *  @param[in] ֵԽ��Խб
        *  @return
        */
        void setItalics(float nValue);

        /** @brief ���������С
        *  @param[in] ��� 0 ��ʾ�ȸ�
        *  @param[in] �߶� 0 ��ʾ�ȿ�
        */
        void setFontSize(int nWidth, int nHeight);

        /** @brief ���bitmapData��freetype��
        *  @param[in] unicode����
        *  @param[out] ��õ�bitmap,���bitmap��Ҫ����ɾ����
        *  @param[out] ���
        *  @param[out] �߶�
        *  @param[out] ���ݵĿ�ȶ�
        *  @param[out] ���ݵĸ߶�
        *  @param[out] ���Ͻǵľ���
        *  @param[out] ���Ͻǵľ���
        *  @return
        */
        void getBitmapData(int nUnicode, unsigned char*& pBitmap, int& nWidth, int& nHeight, int& nDataW, int& nDataH, int& nDataLeft, int& nDataTop, int& nUnderlineTop, int& nUnderlineHeight);

        /** @brief ��������
        *  @param[in] unicode
        *  @param[out] ��ÿ��
        *  @param[out] ��õĸ߶�
        *  @return
        */
        void getMetric(int nUnicode, int& nWidth, int& nHeight);


        /** @brief ͨ��buffer���FT_face
         *  @param[in] buffer
         *  @param[in] bufferSize
         *  @return FT_Face
        */
        FT_Face getFTFaceFromBuffer(char* pBuffer, int nBuferLen);


        /** @brief ͨ���ļ����ֻ��FT
        *  @param[in] �ļ�����
        *  @return FT_Face
        */
        FT_Face getFTFaceFromFile(const char* sFileName);


        /** @brief ���Ĭ�ϵ�font
        */
        void clearDefaultFont();


        /** @brief ���IOSд���font·��
         *  @return ����·��
        */
        std::string getIOSFontTTFPath();

        /** @brief ��ios��fontд���ļ�
         *  @return ����·��
        */
        std::string writeIOSFontTTF();

        static  int32_t RoundToInt(float F)
        {
            #ifdef WIN32
                // Note: the x2 is to workaround the rounding-to-nearest-even-number issue when the fraction is .5
                return _mm_cvt_ss2si(_mm_set_ss(F + F + 0.5f)) >> 1;
            #else
                return (int32_t)(floorf(F + 0.5f));
            #endif
        }
        template <typename TRetType, typename TParamType>
        TRetType Convert26Dot6ToRoundedPixel(TParamType InValue)
        {
            return static_cast<TRetType>(RoundToInt(InValue / 64.0f));
        }
    public:

        static unsigned short                       m_pWordBmpBorder[4 * (MAX_FONT_SIZE + TEXT_SIZE_ALLOWANCE) * (MAX_FONT_SIZE + TEXT_SIZE_ALLOWANCE)];
        static char                                 m_pWordBuff[4 * (MAX_FONT_SIZE + TEXT_SIZE_ALLOWANCE) * (MAX_FONT_SIZE + TEXT_SIZE_ALLOWANCE)];
        std::recursive_mutex	                    m_kLoadGlyphLock;               ///<��

    protected:
        FT_Library		                            m_pFTlibrary;                   ///<FreeType��Ҫ��
        int				                            m_nFontSizeW;                   ///<�����С
        int                                         m_nFontSizeH;	                ///<�����С
        int				                            m_nDevDPIX;                     ///<dpi
        int                                         m_nDevDPIY;                     ///<dpi
        float			                            m_fItalicsValue;                ///<б���
        std::vector<FTFaceRecord*>                        m_vDefaultFT;	                ///<Ĭ�ϵ������

    private:
        FT_Face                                     m_pCurrentFT;                   ///<��ǰ�������
        MapFTFace                                   m_vCustomMadeFT;                ///<�û����Ƶ�����
        JCIOSFTInterface*                           m_pIOSFTInterface;              ///<Ϊ��IOSʹ�õ�
	};
}
//------------------------------------------------------------------------------


#endif //__JCFreeTypeRender_H__

//-----------------------------END FILE--------------------------------