from contextlib import contextmanager


@contextmanager
def supresser(*args):
    try:
        yield
    except args:
        pass

@contextmanager
def retyper(type_from, type_to):
    try:
        yield
    except type_from as ex:
        exception = type_to()
        # exception.args = ex.args
        raise exception


class dumper:
    def __init__(self, stream):
        self.stream = stream

    # def __enter__(self):
    #     pass

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.stream.write(str(exc_val))
