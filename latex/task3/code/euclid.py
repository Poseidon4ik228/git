# Реализация алгоритма Евклида для нахождения НОД


def gcd_recursive(a: int, b: int) -> int:
    """Рекурсивная реализация алгоритма Евклида."""
    if b == 0:
        return a
    return gcd_recursive(b, a % b)


def gcd_iterative(a: int, b: int) -> int:
    """Итеративная реализация алгоритма Евклида."""
    while b != 0:
        a, b = b, a % b
    return a


if __name__ == "__main__":
    pairs = [(48, 18), (1071, 462), (100, 75)]
    for a, b in pairs:
        result = gcd_iterative(a, b)
        print(f"gcd({a}, {b}) = {result}")
