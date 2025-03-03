copy = {}
with open('/Users/zhenfei.tai/Downloads/cluster.csv', 'r') as file:
  for line in file:
    items = line.split(',')
    key = items[0] + '-' + items[1].strip()
    value = int(items[2].strip())
    copy[key] = value

origin = {}
with open('/Users/zhenfei.tai/Downloads/origin.csv', 'r') as file:
  for line in file:
    if 'firm' not in line:
      continue
    items = line.split(',')
    key = items[0].replace('firm_', '').replace('euprod-audit-', '')
    value = int(items[1].strip())
    origin[key] = value

for key in origin:
  if key in copy:
    if origin[key] > copy[key]:
      print(f"{key}, {origin[key]}, {copy[key]}")
  else:
    print(f"Key {key} not found in copy")
