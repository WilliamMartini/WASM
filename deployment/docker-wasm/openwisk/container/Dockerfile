FROM python:latest

# Upgrade and install basic Python dependencies.
RUN apt-get update \
  && apt-get install bash perl jq zip git curl wget openssl ca-certificates sed openssh-client -y\
  && apt-get install bzip2 gcc libc-dev -y\
  && pip install --upgrade pip setuptools six \
  && pip install --no-cache-dir gevent==1.3.6 flask==1.0.2

ENV FLASK_PROXY_PORT 8080

RUN mkdir -p /actionProxy
ADD actionproxy.py /actionProxy/

RUN mkdir -p /action
ADD exec /action/exec
RUN chmod +x /action/exec
ADD hello.wasm /action/myfile.wasm

#Install wasmer
RUN curl -L https://github.com/wasmerio/wasmer/releases/latest/download/wasmer-linux-amd64.tar.gz -o /action/wasmer.tar.gz && cd action && tar xvzf wasmer.tar.gz bin/wasmer --strip-components=1 && rm wasmer.tar.gz
 
CMD ["/bin/bash", "-c", "cd actionProxy && python -u actionproxy.py"]
