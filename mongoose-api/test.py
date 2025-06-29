import urllib3

# Reading the text file from local storage.
with open("test.txt") as fp:
    file_data = fp.read()

# Sending the request.
resp = urllib3.request(
    "POST",
    "http://192.168.68.116:8000/api/upload",
    fields={
       "filefield": ("test.txt", file_data),
    }
)

print(resp.data.decode())
