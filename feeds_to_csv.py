import json
import csv

# read file
with open('feeds.json', 'r') as myfile:
    data=myfile.read()

# parse file
obj = json.loads(data)

with open('feeds.csv', 'w', newline='') as csvfile:
    fieldnames = ['Id', 'Name', 'Custodian', 'Account Number Formats']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    for feed in obj['dataFeeds']:
        formats = '\n'.join([format['account_number_format'] + (' (Master)' if format['is_credential'] else '') for format in feed['account_number_formats']])
        writer.writerow({'Id': feed['id'], 'Name': feed['name'], 'Custodian': feed['custodian_name'], 'Account Number Formats': formats})
