def mac_to_eui64(mac):
  if not mac:
      return ''
  b = [int(c, 16) for c in mac.split(':')]
  print([hex(i) for i in b])
  b[0] ^= 2
  b.insert(3, 0xfe)
  b.insert(3, 0xff)
  print([hex(i) for i in b])
  idx = range(0, len(b)-1, 2)
  print([i for i in idx])
  return ':'.join([format(b[i]*0x100 + b[i+1], '04x') for i in idx])

def main():
  print(mac_to_eui64('a2:d5:9d:6c:6f:01'))


if __name__ == '__main__':
  main()
