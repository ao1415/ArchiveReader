# pragma once

#include <hash_map>
# include <Siv3D/BinaryReader.hpp>

namespace s3d
{
	/// <summary>
	/// �t�@�C���A�[�J�C�u
	/// </summary>
	class FileArchive
	{
	private:

		BinaryReader m_reader;
		Array<FilePath> m_contents;
		std::hash_map<FilePath, std::pair<int64, int64>> m_files;

	public:

		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		FileArchive();

		/// <summary>
		/// �t�@�C���A�[�J�C�u���J���܂��B
		/// </summary>
		/// <param name="path">
		/// �t�@�C���p�X
		/// </param>
		explicit FileArchive(const FilePath& path);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~FileArchive();

		/// <summary>
		/// �t�@�C���A�[�J�C�u���J���܂��B
		/// </summary>
		/// <param name="path">
		/// �t�@�C���p�X
		/// </param>
		/// <returns>
		/// �t�@�C���A�[�J�C�u�̃I�[�v���ɐ��������ꍇ true, ����ȊO�̏ꍇ�� false
		/// </returns>
		bool open(const FilePath& path);

		/// <summary>
		/// �t�@�C���A�[�J�C�u���I�[�v������Ă��邩��Ԃ��܂��B
		/// </summary>
		/// <returns>
		/// �t�@�C���A�[�J�C�u���I�[�v������Ă���ꍇ true, ����ȊO�̏ꍇ�� false
		/// </returns>
		bool isOpened() const;

		/// <summary>
		/// �A�[�J�C�u���ꂽ�t�@�C�����̈ꗗ��Ԃ��܂��B
		/// </summary>
		/// <returns>
		/// �A�[�J�C�u���ꂽ�t�@�C�����̈ꗗ
		/// </returns>
		Array<FilePath> contents() const;

		/// <summary>
		/// �t�@�C���A�[�J�C�u���I�[�v������Ă��邩��Ԃ��܂��B
		/// </summary>
		/// <returns>
		/// �t�@�C���A�[�J�C�u���I�[�v������Ă���ꍇ true, ����ȊO�̏ꍇ�� false
		/// </returns>
		explicit operator bool() const { return isOpened(); }

		/// <summary>
		/// �A�[�J�C�u���ꂽ�t�@�C�������[�h���܂��B
		/// </summary>
		/// <param name="path">
		/// �A�[�J�C�u���ꂽ�t�@�C���̃p�X
		/// </param>
		/// <returns>
		/// �A�[�J�C�u���ꂽ�t�@�C���� ByteArray
		/// </returns>
		ByteArray load(const FilePath& path) const;
	};
}
