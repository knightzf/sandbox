import time
from functools import wraps


def wait_until(cycle=10, timeout=300):
    def wrapper(f):
        @wraps(f)
        def wrapper_f(*args, **kwargs):
            waited = 0
            name = f.__name__
            while not f(*args, **kwargs):
                if waited >= timeout:
                    raise Exception(
                        f"Waited {timeout} seconds for {name}, considering this an error"
                    )
                time.sleep(cycle)
                waited += cycle

        return wrapper_f

    return wrapper


@wait_until(cycle=2, timeout=20)
def wait_until_ssh(host: str, use_ssh_bastion: bool) -> bool:
    print("wait_until_ssh")
    return True

@wait_until(cycle=2, timeout=20)
def run_over_ssh(host: str, command: str, use_ssh_bastion: bool) -> bool:
    print("run_over_ssh")
    return True

wait_until_ssh("aa", True)
run_over_ssh("aa", "bb", True)