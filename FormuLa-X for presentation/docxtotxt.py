from docx import Document
import sys

def docx_to_txt(docx_file,textfile):
    doc = Document(docx_file)
    with open(textfile,"w", encoding="utf-8") as f:
        for para in doc.paragraphs:
            f.write(para.text+"\n")
    

if __name__ == "__main__":
    docx_to_txt(sys.argv[1], sys.argv[2])
    