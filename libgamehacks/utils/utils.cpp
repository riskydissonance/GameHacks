#include <iomanip>

void hexdump(const int counter, std::basic_ostream<char>& out, const BYTE data[], const int length){
    out << std::hex << std::setfill('0');
    int j = 0;
    while (j < length)
    {
        int nread;
        char buf[16];

        for( nread = 0; nread < 16 && j < length; nread++){
            buf[nread] = data[j];
            j++;
        }

        if( nread == 0 ) break;

        out << std::setw(8) << counter;

        for( int i = 0; i < 16; i++ )
        {
            if( i % 8 == 0 ) out << ' ';
            if( i < nread )
                out << ' ' << std::setw(2) << (unsigned int)(unsigned char)buf[i];
            else
                out << "   ";
        }

        out << "  ";
        for( int i = 0; i < nread; i++)
        {
            if( buf[i] < 32 ) out << '.';
            else out << buf[i];
        }
        out << std::endl;
    }
}
