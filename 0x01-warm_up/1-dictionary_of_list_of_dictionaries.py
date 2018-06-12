#!/usr/bin/python3
'''
   A Python script which retrieces employee data and stores it in a JSON file
'''


if __name__ == "__main__":
    import json
    import requests

    url = "https://jsonplaceholder.typicode.com/users/"

    user_dict = dict()

    for i in range(1, 11):
        u_url = url + str(i)
        name = requests.get(u_url).json().get("username")
        todos = requests.get(u_url + "/todos").json()
        u_list = list()

        for j in range(len(todos)):
            u_list.append({"username": name, "task": todos[j].get("title"),
                           "completed": todos[j].get("completed")})

        user_dict[str(i)] = u_list

    with open('todo_all_employees.json', 'w', encoding='utf-8') as f:
        json.dump(user_dict, f)
