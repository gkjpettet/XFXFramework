#include <System/IO/BinaryWriter.h>

#if DEBUG
#include <stdio.h>
#endif

namespace System
{
	namespace IO
	{
		const int BinaryWriter::LargeByteBufferSize = 0x100;

		BinaryWriter::BinaryWriter()
		{
			_tmpOneCharBuffer = new char[1];
			OutStream = new Stream();
			_buffer = new byte[0x10];
		}

		BinaryWriter::BinaryWriter(Stream* output)
		{
			_tmpOneCharBuffer = new char[1];

			if (!output)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "output");
#endif
				return;
			}

			OutStream = output;
			_buffer = new byte[0x10];
		}
	}
}