#include "vwparser.hpp"

OStreamBuffer::OStreamBuffer(uint8_t *buf, int size)
{
	this->buf = buf;
	this->_size = size;
}

const char *OStreamBuffer::get_buffer()
{
	return reinterpret_cast<const char *>(this->buf);
}
flatbuffers::uoffset_t OStreamBuffer::size()
{
	return this->_size;
}

OStreamBuffer *Parser::createTableRow(std::string a_name, float a_float,
									  bool a_flag)
{
	auto name = fbb.CreateString(a_name);
	auto row = VW::parser::CreateMyTable(fbb, name, a_float, a_flag);

	fbb.Finish(row);
	auto *buf = fbb.GetBufferPointer();
	int size = fbb.GetSize();
	fbb.Clear();

	auto ret = new OStreamBuffer(buf, size);
	return ret;
}

void Parser::writeToDisk(OStreamBuffer *buf, std::string file_name)
{
	std::ofstream ofs(file_name, std::ios::binary);
	if (ofs.is_open())
	{
		ofs.write(buf->get_buffer(), buf->size());
		std::cout << buf->size() << std::endl;
		ofs.close();
	}
	else
	{
		std::cout << "file not open" << std::endl;
	}
}

const VW::parser::MyTable *Parser::readFromDisk(std::string file_name)
{
	const VW::parser::MyTable *ret = nullptr;
	std::ifstream ifs(file_name, std::ios::binary);
	if (ifs.is_open())
	{
		ifs.seekg(0, std::ios::end);
		int size = ifs.tellg();
		ifs.seekg(0, std::ios::beg);

		char *buffer = new char[size];
		ifs.read(buffer, size);
		ifs.close();

		ret = VW::parser::GetMyTable(buffer);
	}
	else
	{
		std::cout << "file not open" << std::endl;
	}

	return ret;
}

void Parser::printRow(const VW::parser::MyTable *row)
{
	std::cout << "a_name: " << row->a_name()->c_str() << std::endl;
	std::cout << "a_value: " << row->a_value() << std::endl;
	std::cout << "a_flag: " << row->a_flag() << std::endl;
}

void Parser::take_input(std::string *a_name, float *a_float, bool *a_flag,
						std::string *file_name)
{
	std::cout << "Input a_name of the object: ";
	std::getline(std::cin, *a_name);
	std::cout << "Input a_float of the object: ";
	std::cin >> *a_float;
	std::cout << "Input a_flag of the object: ";
	std::cin >> *a_flag;
	std::cout << "Input file_name to save the object: ";
	std::cin >> *file_name;
}