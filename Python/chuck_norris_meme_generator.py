import requests

def get_joke():
    try:
        r = requests.get("https://api.chucknorris.io/jokes/random")
        content = r.json()
        return content["value"]
    except e:
        print(e)
    return ""

print(get_joke())
