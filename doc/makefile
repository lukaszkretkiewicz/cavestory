PLANT =  java -jar plantuml.jar 

.PHONY: all view

all: png view

view:
	eog class_diagram.png

png:   class_diagram.uml
	$(PLANT) class_diagram.uml

clean:
	rm class_diagram.png


