FROM ubuntu:latest as build
ENTRYPOINT ["bash","-c"]

RUN apt-get update && \
    apt-get -y install gcc && \
    rm -rf /var/lib/apt/lists/*

COPY ./C-Programs /tmp/proj
WORKDIR /tmp/proj
RUN rm -rf TICKET AGECALC
RUN gcc 'LRT TICKET.c' -o TICKET
RUN gcc 'AGE CALCULATOR.c' -o AGECALC

FROM ubuntu:latest
COPY --from=build /tmp/proj /tmp/proj
WORKDIR /tmp/proj/
CMD ["./TICKET", "./AGECALC"]

