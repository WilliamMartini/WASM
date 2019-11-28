# AWS
aws lambda update-function-code --function-name wasm_add fileb://action.zip

aws lambda invoke --function-name wasm_add --payload '{ "a":1,"b":2}' response.json

## Links
https://hackernoon.com/how-did-i-hack-aws-lambda-to-run-docker-containers-7184dc47c09b
https://github.com/vladgolubev/docker-in-aws-lambda
https://blog.quiltdata.com/an-easier-way-to-build-lambda-deployment-packages-with-docker-instead-of-ec2-9050cd486ba8