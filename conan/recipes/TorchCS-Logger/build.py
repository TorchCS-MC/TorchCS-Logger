import os
def build():
    os.system("conan create .")

def main():
    build()

if __name__ == "__main__":
    main()