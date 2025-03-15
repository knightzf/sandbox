import json

def analyze_response():
  with open('/Users/zhenfei.tai/Downloads/users.json', 'r') as f:
    data = json.load(f)
    for user in data["data"]:
      permissioned_entities = user["relationships"]["permissioned_entities"]
      permissioned_groups = user["relationships"]["permissioned_groups"]
      print(user["id"], len(permissioned_entities["data"]), len(permissioned_groups["data"]))

analyze_response()