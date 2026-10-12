def zadanie_3_1(n: int) -> int:
    m = 0
    p = 1
    
    while n > 0:
        cyfra = n % 10
        if cyfra % 2 == 1:
            m += cyfra * p
            p *= 10
        n //= 10
    return m


def main() -> None:
    print(zadanie_3_1(294762))  
    print(zadanie_3_1(39101))  
    
    
if __name__ == "__main__":
    main()    
          