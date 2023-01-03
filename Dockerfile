FROM gcc:latest
WORKDIR /usr/src/proiect
COPY proiectmap.c .
RUN gcc proiectmap.c -o proiect 
CMD ["./proiect"]