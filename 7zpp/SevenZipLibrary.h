#pragma once


#include "SevenZipException.h"
#include "CompressionFormat.h"
#include <7zip/Archive/IArchive.h>

namespace SevenZip
{
	class SevenZipLibrary
	{
	private:

		typedef UINT32 (WINAPI * CreateObjectFunc)( const GUID* clsID, const GUID* interfaceID, void** outObject );

		HMODULE				m_dll;
		CreateObjectFunc	m_func;

	public:

		SevenZipLibrary();
		~SevenZipLibrary();

		bool Load();
		bool Load( const TString& libraryPath );
		void Free();

		bool CreateObject( const GUID& clsID, const GUID& interfaceID, void** outObject ) const;
	};

	class UsefulFunctions
	{
		public:
			static const GUID* GetCompressionGUID(const CompressionFormatEnum& format);
			static CComPtr< IInArchive > GetArchiveReader(const SevenZipLibrary& library, const CompressionFormatEnum& format);
			static CComPtr< IInArchiveGetStream > GetArchiveStreamer(const SevenZipLibrary& library, const CompressionFormatEnum& format);
	};
}
