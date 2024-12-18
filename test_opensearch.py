from opensearchpy import OpenSearch

host = 'localhost'
#host = 'host.docker.internal'
port = 9200
auth = ('admin', 'admin')
index_name = 'python-test-index'

def create_index(client):
    index_body = {
        'settings': {
                'index': {
                'number_of_shards': 4
            }
        }
    }

    response = client.indices.create(index_name, body=index_body)
    print('\nCreating index:')
    print(response)

def get_index(client, name):
    response = client.indices.get(index=name)
    print('\nGet index:')
    print(response)

def add_document(client):
    document = {
        'title': 'Moneyball',
        'director': 'Bennett Miller',
        'year': '2011'
    }
    id = '1'

    response = client.index(
        index = index_name,
        body = document,
        id = id,
        refresh = True
    )

    print('\nAdding document:')
    print(response)

def search_document(client):
    q = 'miller'
    query = {
        'size': 5,
        'query': {
            'multi_match': {
                'query': q,
                'fields': ['title^2', 'director']
            }
        }
    }

    response = client.search(
        body = query,
        index = index_name
    )
    print('\nSearch results:')
    print(response)

def delete_document(client):
    response = client.delete(
        index = index_name,
        id = id
    )

    print('\nDeleting document:')
    print(response)

def delete_index(client, name):
    response = client.indices.delete(
        index = name
    )

    print('\nDeleting index:')
    print(response)

client = OpenSearch(
    hosts = [{'host': host, 'port': port}],
    http_compress = True, # enables gzip compression for request bodies
    http_auth = auth,
    use_ssl = True,
    verify_certs = False,
    ssl_assert_hostname = False,
    ssl_show_warn = False,
)

#create_index(client)
#get_index(client, "sample-index")
delete_index(client, "sample-index")

