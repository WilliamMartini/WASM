# AWS
## Install AWS CLI
``` shell
sudo apt install awscli
```
## Set Temporary Security Credentials
``` shell
export AWS_ACCESS_KEY_ID=AKIAI44QH8DHBEXAMPLE
export AWS_SECRET_ACCESS_KEY=wJalrXUtnFEMI/K7MDENG/bPxRfiCYEXAMPLEKEY
export AWS_SESSION_TOKEN=AQoDYXdzEJr...<remainder of security token>
```
## Set AWS configuration
``` shell
aws configure
```
Skip the first two with enter (AWS Access Key ID & AWS Secret Access Key).   
Set the region to the one uf your account and the output format to json.
## Links
https://docs.aws.amazon.com/de_de/lambda/latest/dg/nodejs-create-deployment-pkg.html   
https://hackernoon.com/how-did-i-hack-aws-lambda-to-run-docker-containers-7184dc47c09b   
https://github.com/vladgolubev/docker-in-aws-lambda   
https://blog.quiltdata.com/an-easier-way-to-build-lambda-deployment-packages-with-docker-instead-of-ec2-9050cd486ba8   
