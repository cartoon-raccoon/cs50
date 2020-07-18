from flask import *

app = Flask(__name__)

@app.route("/")
def homepage():
    return render_template("index.html")

@app.route("/about.html")
def about():
    return render_template("about.html")

@app.route("/index.html")
def index():
    return render_template("index.html")