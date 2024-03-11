import os
from urllib import parse

HEADER="""# 
# 백준 & 프로그래머스 문제 풀이 목록

"""

def generate_table_of_contents(content):
    toc = "## 목차\n"
    toc += "| 카테고리 | 문제 | 링크 |\n"
    toc += "| ----- | ----- | ----- |\n"
    
    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        if category in ['.', 'images']:
            continue

        for file in files:
            folder_link = parse.quote(os.path.join(root))
            toc += "|{}|{}|[링크]({})|\n".format(category, file, folder_link)
    
    return toc

def main():
    content = ""
    content += HEADER
    
    directories = [];
    solveds = [];

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        
        if category == 'images':
            continue
        
        directory = os.path.basename(os.path.dirname(root))
        
        if directory == '.':
            continue

        if directory not in directories:
            if directory in ["백준", "프로그래머스"]:
                content += "# 📚 {}\n".format(directory)
            else:
                content += "## 🚀 {}\n".format(directory)
                content += "| 문제 | 링크 |\n"
                content += "| ----- | ----- |\n"
            directories.append(directory)

        index = 0;
        for file in files:
            if category not in solveds:
                folder_link = parse.quote(os.path.join(root))
                content += "|{}|[링크]({})|\n".format(category, folder_link)
                solveds.append(category)
                print("category : " + category)
                index += 1;

    content += generate_table_of_contents(content)

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
