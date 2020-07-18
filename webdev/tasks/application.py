from flask import *

app = Flask(__name__)

todos = []

@app.route("/")
def mainpage():
    return render_template("tasks.html", todos=todos)
    
@app.route("/add", methods=["GET", "POST"])
def addtask():
    if request.method == "POST":
        todo = request.form.get("task")
        todos.append(todo)
        return redirect("/")
    elif request.method == "GET":
        return render_template("add.html")

@app.route("/remove", methods=["GET", "POST"])
def removetask():
    if request.method == "POST":
        toremove = request.form.get('task')
        print(toremove)
        todos.remove(toremove)
        return redirect("/")
    else:
        pass