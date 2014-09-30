TARGET = libreria.pdf
SOURCE = libreria.tex
LATEX = pdflatex

all::$(TARGET)

$(TARGET):
	$(LATEX) $(SOURCE)
	rm *.log *.aux

.PHONY: clean
clean:
	rm $(TARGET)
