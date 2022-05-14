from multiprocessing import Pool, TimeoutError
import time
import os
import logging
from time import sleep
import multiprocessing
import sys
# from dummy import dummy

# logger = logging.getLogger(__name__)
# logger = multiprocessing.get_logger()

def create_logger():
    import multiprocessing, logging
    logger = multiprocessing.get_logger()
    logger.setLevel(logging.INFO)
    formatter = logging.Formatter(\
        '[%(asctime)s| %(levelname)s| %(processName)s] %(message)s')
    handler = logging.StreamHandler(sys.stdout)
    handler.setFormatter(formatter)

    # this bit will make sure you won't have
    # duplicated messages in the output
    if not len(logger.handlers):
        logger.addHandler(handler)
    return logger


logger = create_logger()

def f(i):
    # logger = create_logger()
    # logger = multiprocessing.get_logger()
    logger.info(f"getting {i}")
    if i == 3:
        raise RuntimeError("aa")
    a = 1
    sleep(3)
    logger.info(f"complete {i}")

if __name__ == '__main__':
    # logger = create_logger()
    # logger.setLevel(logging.INFO)
    logger.info("from main")

    # start 4 worker processes
    results = []
    with Pool(processes=4) as pool:
        for i in range(10):
            results.append(pool.apply_async(f, (i,)))

        try:
            for r in results:
                #print(r.get())
                r.get()
        except RuntimeError as e:
            print("got exception", e)

    # exiting the 'with'-block has stopped the pool
