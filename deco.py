import functools

class Test:
    def __init__(self, name):
        self._name = name;

    def maintenance_mode(func):
        """ wrapper to toggle maintenance mode before and after release """
        @functools.wraps(func)
        def wrapper(self, *args, **kwargs) -> None:
            print(type(args))
            # turn on maintenance mode
            print(self._name)
            func(self, *args, **kwargs)
            # turn off maintenance mode

        return wrapper

    @maintenance_mode
    def aaa(self, a, b, c):
        print(a + b + c)

if __name__ == "__main__":
    a = Test("abc")
    a.aaa(1, 2, 3)
