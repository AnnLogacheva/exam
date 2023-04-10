FROM ubuntu:20.04
RUN apt-get update && apt-get upgrade -y
RUN apt install qt5-qmake -y
RUN apt install cmake -y
RUN apt-get install qt5-default -y
RUN apt install qtbase5-dev -y
RUN apt install libqt5sql5-psql -y
RUN apt install build-essential -y
RUN apt-get install postgresql -y
RUN apt install git -y
RUN git clone https://github.com/AnnLogacheva/exam.git
COPY . /home/las/
WORKDIR /home/las/exam
RUN rm -f *moc
RUN rm -f Makefile
RUN qmake examen.pro
RUN make
RUN make install
CMD ["./examen"]
