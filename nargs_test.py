import argparse

if __name__ == "__main__":
    argparser = argparse.ArgumentParser(description="Acervus infrastructure deployment script")
    argparser.add_argument("service", help="service")
    argparser.add_argument("rest", nargs=argparse.REMAINDER)
    args = argparser.parse_args()

    print(type(args.rest))
    print(args.rest)