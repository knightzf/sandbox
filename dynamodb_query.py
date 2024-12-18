import boto3
import json


session = boto3.session.Session()
# session takes aws_access_key_id,aws_secret_access_key aws_session_token and region_name
dynamodb = session.resource('dynamodb')
table = dynamodb.Table('plaid-items')
resp = table.scan(AttributesToGet=['metadata'])

for item in resp['Items']:
    if 'metadata' in item and item['metadata']['status'] != 'OK':
        print(item['metadata']['status'])

print("-----")

for item in resp['Items']:
    if 'metadata' in item and item['metadata']['status'] == 'ERROR':
        print(item['metadata'])
