import os

def index(params,cherrypy):
    out = str(dir(os))
    return(out)
    
datareturned,response = (index(params,cherrypy),200)