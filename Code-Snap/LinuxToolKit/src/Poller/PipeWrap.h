
#ifndef PipeWarp_h
#define PipeWarp_h

namespace toolkit
{

class PipeWrap
{
public:
    PipeWrap();
    ~PipeWrap();
    int write(const void *buf, int n);
    int read(void *buf, int n);
    int readFD() const
    {
        return _pipe_fd[0];
    }
    int writeFD() const
    {
        return _pipe_fd[1];
    }
private:
    int _pipe_fd[2] = {-1, -1};
    void clearFD();
};

} /* namespace toolkit */

#endif // !PipeWarp_h

