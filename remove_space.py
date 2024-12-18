import re
import os

for path, directory, files in os.walk('/Volumes/code/AMP/ADP/scraper/bai2/'):
  for file in files:
    if file.endswith('.java'):
      file_name = os.path.join(path, file)
      with open(file_name, 'r') as f:
        content = f.read()
        if not 'import org.junit.jupiter.params.provider.MethodSource' in content:
          continue
        content_new = re.sub(r'import org.junit.jupiter.params.provider.MethodSource;\n\n;',
                          'import org.junit.jupiter.params.provider.MethodSource;', content)
        with open(file_name, 'w') as fn:
          fn.write(content_new)
