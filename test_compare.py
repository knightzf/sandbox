import os

old_tests = set()
with open("/Users/zhenfei.tai/Downloads/old.txt") as file:
    for line in file:
        old_tests.add(line.split()[0])

new_tests = set()
with open("/Users/zhenfei.tai/Downloads/new.txt") as file:
    for line in file:
        new_tests.add(line.split()[0])

for old_test in old_tests:
    if (
        "PositionSearchResourceTest" in old_test
        or "FileJsonServiceTest" in old_test
        or "ExtendedSQSJobPollerTest" in old_test
        or "SQSJobPollerTest" in old_test
        or "AmpSearchResultServiceTest" in old_test
        or "AuditTrailApiServerModuleTest" in old_test
    ):
        continue
    if old_test not in new_tests:
        print("missing ", old_test)

for new_test in new_tests:
    if new_test not in old_tests:
        print("adding ", new_test)
