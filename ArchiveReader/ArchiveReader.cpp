# include "ArchiveReader.hpp"

namespace s3d
{
	FileArchive::FileArchive()
	{

	}

	FileArchive::FileArchive(const FilePath & path)
	{
		open(path);
	}

	FileArchive::~FileArchive()
	{

	}

	bool FileArchive::open(const FilePath & path)
	{
		m_reader.open(path);

		return false;
	}

	bool FileArchive::isOpened() const
	{
		return m_reader.isOpened();
	}

	Array<FilePath> FileArchive::contents() const
	{
		return m_contents;
	}

	ByteArray FileArchive::load(const FilePath & path) const
	{
		return ByteArray();
	}
}
