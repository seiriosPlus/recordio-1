import ctypes

# TODO(helin): automate following build command:
# go build -buildmode=c-shared ../c && rm c.h && mv c librecordio.so
lib = ctypes.cdll.LoadLibrary("librecordio.so")


class writer(object):
    """
    writer is a recordio writer.
    """

    def __init__(self, path):
        self.w = lib.create_recordio_writer(path)

    def close(self):
        lib.release_recordio_writer(self.w)
        self.w = None

    def write(self, record):
        lib.recordio_write(self.w, ctypes.c_char_p(record), len(record))


class reader(object):
    """
    reader is a recordio reader.
    """

    def __init__(self, path):
        self.r = lib.create_recordio_reader(path)

    def close(self):
        lib.release_recordio_reader(self.r)
        self.r = None

    def read(self):
        p = ctypes.c_char_p()
        ret = ctypes.pointer(p)
        size = lib.recordio_read(self.r, ret)
        if size < 0:
            # EOF
            return None
        if size == 0:
            # empty record
            return ""
        record = ret.contents.value[:size]
        # memory created from C should be freed.
        lib.mem_free(ret.contents)
        return record
