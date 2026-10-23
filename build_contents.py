import sys
from pathlib import Path

# Filename without extension
def format_name(filename):
    return " ".join(
        x[0].upper() + x[1:]
        for x in filename.split("-") 
        if len(x) > 0)

def remove_number(name):
    return name[name.index(".")+1:]

def main():
    include_cmds = {
        ".cpp": "\\includecpp",
        ".sh": "\\includescript",
        ".tex": "\\input",
        ".texs": "\\includetex",
        ".py": "\\includepy"
        # Can be expanded to more langs if needed
    }
    workdir_path = Path('.').absolute()
    source_path = workdir_path / 'src'

    subdirs: list[Path] = sorted([i for i in source_path.iterdir() if i.is_dir()])
    for dirpath in subdirs:
        section_name = format_name(remove_number(dirpath.name))
        print("\\section{{{}}}".format(section_name))

        files: list[Path] = sorted([i for i in dirpath.iterdir() if i.is_file()])
        for filepath in files:
            filename, fileext = filepath.stem, filepath.suffix
            if fileext not in include_cmds.keys():
                sys.stderr.write("Found unsupported source file {}. Skipping.\n".format(filepath))
                continue
            subsection_name = format_name(remove_number(filename))
            file_relpath = filepath.relative_to(workdir_path)
            if fileext == ".tex":
                print("{}{{\"{}\"}}".format(include_cmds[fileext], file_relpath))
            else:
                print("{}{{{}}}{{\"{}\"}}".format(include_cmds[fileext], subsection_name, file_relpath))

if __name__ == "__main__":
    main()