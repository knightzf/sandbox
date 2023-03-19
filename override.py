class Annotation:
    a: str

    def __init__(self, a: str) -> None:
        self.a = a
        self._validate()

    def _validate(self) -> None:
        pass

class A(Annotation):
    def __init__(self, a: str) -> None:
        super().__init__(a)

    def _validate(self) -> None:
        print("aaa")

a = A("bb")
