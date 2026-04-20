from docx import Document
import sys

def text_to_docx(text, docxfile):
    doc = Document()
    with open(text, "r", encoding="utf-8")as f:
        for line in f:
            doc.add_paragraph(line.strip())
    doc.save(docxfile)

if __name__ == "__main__":
    text_to_docx(sys.argv[1], sys.argv[2])


    