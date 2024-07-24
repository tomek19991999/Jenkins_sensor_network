# SensorNetwork Project

This repository contains a C++ project for simulating a network of sensors on Raspberry Pi in docker container. It includes CI/CD integration using Jenkins and unit tests using Google Test.

## Prerequisites

- Docker
- Jenkins
- CMake
- GCC
- Google Test
- Nlohmann/json: for JSON parsing

## Jenkins installation on Raspberry Pi on Linux
### Build the Jenkins BlueOcean Docker Image in catalog Jenkins_master
```
docker build -t myjenkins-blueocean:2.414.2 .
```

### Create the network 'jenkins'
```
docker network create jenkins
```

### Run the Container on Linux
```
docker run --name jenkins-blueocean --restart=on-failure --detach \
  --network jenkins --env DOCKER_HOST=tcp://docker:2376 \
  --env DOCKER_CERT_PATH=/certs/client --env DOCKER_TLS_VERIFY=1 \
  --publish 8080:8080 --publish 50000:50000 \
  --volume jenkins-data:/var/jenkins_home \
  --volume jenkins-docker-certs:/certs/client:ro \
  myjenkins-blueocean:2.414.2
```

### Get the Password
```
docker exec jenkins-blueocean cat /var/jenkins_home/secrets/initialAdminPassword
```

### Connect to the Jenkins
```
https://localhost:8080/
```

### Installation Reference:
https://www.jenkins.io/doc/book/installing/docker/


### Make socat container to forward traffic from Jenkins to Docker daemon

https://stackoverflow.com/questions/47709208/how-to-find-docker-host-uri-to-be-used-in-jenkins-docker-plugin
```
docker run -d --restart=always -p 127.0.0.1:2376:2375 --network jenkins -v /var/run/docker.sock:/var/run/docker.sock alpine/socat tcp-listen:2375,fork,reuseaddr unix-connect:/var/run/docker.sock
docker inspect <container_id> | grep IPAddress
```

### Use my image for Jenkins Agent c++ or make it yourself in catalog Jenkins_agent
```
docker pull tomek199919999/jenkins-agent:complete
```
or build new image, with ARM64 and push to dockerhub:
```
docker buildx build --platform linux/arm64 -t your-dockerhub-username/yourimagename:yourtag .
```


## Program building

### Linux
Build instructions:

Create a build directory in your project root:
```bash
mkdir build
```
Change to the build directory:
```bash
cd build
```
Run cmake to generate the build files:
```bash
cmake ..
```
Build the project using the generated build files:
```bash
cmake --build .
```

