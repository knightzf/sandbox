import logging
from dataclasses import dataclass

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    handlers=[
        logging.FileHandler("debug.log"),
        logging.StreamHandler()
    ]
)

logger = logging.getLogger(__name__)

@dataclass
class AccountNumberFormat:
    """
    Data class for AMP account number format
    """

    def __init__(
        self, format_id, account_number_format
    ):
        self.format_id = format_id
        self.account_number_format = account_number_format

    def __str__(self):
        return f"id: {self.format_id}, format: {self.account_number_format}"

    def __repr__(self):
        return f"AccountNumberFormat({self.format_id}, {self.account_number_format})"

a = [AccountNumberFormat(1, "aaaa")]
logger.info("someething is %s", a);
