import boto3
import json


session = boto3.session.Session(aws_access_key_id='ASIAXXGQHDSVDEDFGVKM',
                                aws_secret_access_key='ZrF4whT72YPk/5zQ1PecfEMcET6smKAba2XX1ADk',
                                aws_session_token = 'IQoJb3JpZ2luX2VjECkaCXVzLXdlc3QtMiJGMEQCIBzjB2YrhQ+D5CZYwYqoKOobwVwySigo5cOSFBsHtB2PAiBytiT87vEHu85xS5zxz41BioYf8bQkdJyCYsSNiUDZByqYAwhiEAAaDDUzMDg2NTEzNDc2MiIMy17kz9loV+RbtdE3KvUC5BhJQAZag991eUGYVbvLnCVIdZcqB0LJgkTBcMI6tZXCK0GPwA7VvceJtEvwVbFF4PXS/sxozdVyZi8wj/qZbL2MdHFwtxQAD6fgJRznmRjILHVAeD1RDqQFr+vZDLY7vjxrfQnj9uvmJl5MosjnclHeJtXdhVTGltOcLAcEG64dpdJ7v27Khf1PcqQY2aKPmbLRaw+DxLreCuBIbRVPB9FYh4pv1RSshhtFabYHFuy2rHzpj6ClzwGDWksJ19eiiHjdl0d4s14fShooWMLfAUyeok1/wneX8AAgOdytjLPtpzm1CiHXXfzGp/kxpXp9O1apL1NDaUvJG7ZXT581JJymAcYJ68pFDCSr3q/4V6XfmIfzlDKbV0daHJZB5rD73WbL8y2wb3YMz/cqCV2U13D84Rau0XjC7yEMgxCdMjk9wWq+CkCATbOXhDCBfcEDF/HTNwk2yFLyBsx4Y8aYA6WwPTTHiITM6Hb6soMf+mnywkXQcDC+uLG3BjqnAU+v0FpkUM+zpHYNeyqvB3d+eZPuaBr41c7Qr2rRPDyv+JVkjyPHTJw3XUUK5ffLZr14Arhcvyi6VaYoBAwnZhMLPHvmgTO+9u9EUhw8lzCdwUjaUf9JZCxxnJNUGaFGxokPt3pWwmLUbpd11aRwfZNApidPtGb4Dmv19mNtCffY67Ywekv8G/KwhwC83qFKs1s7xTI0bevo+Q2qJbdcWubRoMY7n5ol',
                                region_name='us-west-2')
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
