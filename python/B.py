import numbers
from app import VeryImportantClass, decorator


class HackedClass(VeryImportantClass):
    def __init__(self):
        super().__init__()
        for name in dir(self):
            if callable(getattr(HackedClass, name)) and not name[0] == '_':
                VeryImportantClass.__setattr__(self, name, decorator(name))

    def __getattribute__(self, item):
        if item[0] == "_":
            return VeryImportantClass.__getattribute__(self, item)
        elif isinstance(VeryImportantClass.__getattribute__(self, item),
                        numbers.Number):
            return VeryImportantClass.__getattribute__(self, item) * 2
        elif isinstance(VeryImportantClass.__getattribute__(self, item),
                        (dict, list, set, tuple)):
            return type(VeryImportantClass.__getattribute__(self, item))()
        return VeryImportantClass.__getattribute__(self, item)

