import io, contextlib, logging, sys

message = 'dummy test'

def logcfg():
    root = logging.getLogger()
    root.setLevel(logging.INFO)
    ch = logging.StreamHandler(sys.stdout)
    ch.setLevel(logging.INFO)
    formatter = logging.Formatter(
        "[%(asctime)s][%(levelname)s][%(processName)s]"
        "[pid=%(process)d][%(filename)s:%(lineno)d]: %(message)s"
    )
    ch.setFormatter(formatter)
    root.addHandler(ch)

logcfg()
logger = logging.getLogger()
logger.info("xyz")
with io.StringIO() as sio:
    with contextlib.redirect_stdout(sio), contextlib.redirect_stderr(sio):
        logcfg()
        #logger = logging.getLogger("test")
        logger.info(message)
        print("xxx")
        output = sio.getvalue()
    print("---")
    print(output)

# class Logger(object):
#     def __init__(self, filename="Default.log"):
#         self.terminal = sys.stdout
#         self.log = open(filename, "w")

#     def write(self, message):
#         self.terminal.write(message)
#         self.log.write(message)

#     def flush(self):
#         pass

# sys.stdout = Logger("yourlogfilename.txt")

# logcfg()
# logger = logging.getLogger("test")
# logger.info(message)
# print("xxx")