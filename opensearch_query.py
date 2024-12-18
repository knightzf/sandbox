from requests_aws4auth import AWS4Auth
import requests

REGION = 'us-west-2'
OPENSEARCH_ENDPOINT = 'https://os-staging.sandbox.addeint.com'

awsauth = AWS4Auth(
    AWS_ACCESS_KEY_ID,
    AWS_SECRET_ACCESS_KEY,
    REGION,
    'es'
)

headers = {"Content-Type": "application/json"}
url = OPENSEARCH_ENDPOINT + '/_search'
response = requests.get(url, auth=awsauth, headers=headers)

print(response.text)
