TARGET = libreria.pdf
SOURCE = libreria.tex
LATEX = pdflatex

all::$(TARGET)

$(TARGET):
	$(LATEX) $(SOURCE)

.PHONY: clean
clean:
	rm $(TARGET)
