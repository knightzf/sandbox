import argparse

if __name__ == "__main__":
    argparser = argparse.ArgumentParser(description="Release Util")
    argparser.add_argument("--hotfix", help="components to hotfix", nargs='+', default=[])

    args = argparser.parse_args()
    print(args.hotfix)
