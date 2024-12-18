from dataclasses import dataclass, field

@dataclass
class C:
    a: float
    b: float
    c: float = field(init=False)
    d: list[str] | None = None
    e: str | None = None

    def __post_init__(self):
        self.c = self.a + self.b
        self.d = self.d.split(";") if self.d else self.d

if __name__ == "__main__":
    c = C(1, 3, d="a;b", e="a")
    print(c.e)
