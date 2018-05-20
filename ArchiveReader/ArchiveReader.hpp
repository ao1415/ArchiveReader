# pragma once

#include <hash_map>
# include <Siv3D/BinaryReader.hpp>

namespace s3d
{
	/// <summary>
	/// ファイルアーカイブ
	/// </summary>
	class FileArchive
	{
	private:

		BinaryReader m_reader;
		Array<FilePath> m_contents;
		std::hash_map<FilePath, std::pair<int64, int64>> m_files;

	public:

		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		FileArchive();

		/// <summary>
		/// ファイルアーカイブを開きます。
		/// </summary>
		/// <param name="path">
		/// ファイルパス
		/// </param>
		explicit FileArchive(const FilePath& path);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~FileArchive();

		/// <summary>
		/// ファイルアーカイブを開きます。
		/// </summary>
		/// <param name="path">
		/// ファイルパス
		/// </param>
		/// <returns>
		/// ファイルアーカイブのオープンに成功した場合 true, それ以外の場合は false
		/// </returns>
		bool open(const FilePath& path);

		/// <summary>
		/// ファイルアーカイブがオープンされているかを返します。
		/// </summary>
		/// <returns>
		/// ファイルアーカイブがオープンされている場合 true, それ以外の場合は false
		/// </returns>
		bool isOpened() const;

		/// <summary>
		/// アーカイブされたファイル名の一覧を返します。
		/// </summary>
		/// <returns>
		/// アーカイブされたファイル名の一覧
		/// </returns>
		Array<FilePath> contents() const;

		/// <summary>
		/// ファイルアーカイブがオープンされているかを返します。
		/// </summary>
		/// <returns>
		/// ファイルアーカイブがオープンされている場合 true, それ以外の場合は false
		/// </returns>
		explicit operator bool() const { return isOpened(); }

		/// <summary>
		/// アーカイブされたファイルをロードします。
		/// </summary>
		/// <param name="path">
		/// アーカイブされたファイルのパス
		/// </param>
		/// <returns>
		/// アーカイブされたファイルの ByteArray
		/// </returns>
		ByteArray load(const FilePath& path) const;
	};
}
