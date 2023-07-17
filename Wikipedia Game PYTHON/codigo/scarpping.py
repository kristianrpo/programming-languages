import requests
import string
from bs4 import BeautifulSoup
import spacy
def get_url_2 (url, diccionario,contador,posicion,cont2):
    nlp = spacy.load("es_core_news_sm")
    html_text = requests.get(url).text
    soup = BeautifulSoup(html_text, 'html.parser')
    todos_hiper = soup.find_all("a",href=True, title = True)
    for i in range(len(todos_hiper)):
        todos_hiper[i] = 'https://es.wikipedia.org' + todos_hiper[i]['href'], todos_hiper[i]['title']
    for i in range(len(todos_hiper)):
        doc = nlp(todos_hiper[i][1])
        if todos_hiper[i][1].find("Anexo:")==-1:
            if todos_hiper[i][1].find("Editar")==-1:
                if todos_hiper[i][1].find("(aún no redactado)")==-1:
                    if todos_hiper[i][1].find(" ")>=0:
                        if todos_hiper[i][1].find("Categoría:")==-1:
                            if todos_hiper[i][1].find("(")==-1:
                                if todos_hiper[i][1].find(":")==-1:
                                    for ent in doc.ents:
                                        if ent.label_ == "PER":
                                            if todos_hiper[i] not in diccionario:
                                                if cont2<1:
                                                    diccionario[list(diccionario.keys())[0]].append(todos_hiper[i])
                                                    diccionario[todos_hiper[i]] = []
                                                else:
                                                    diccionario[list(diccionario.values())[posicion][contador]].append(todos_hiper[i])
                                                    diccionario[todos_hiper[i]] = []



def dfs(visited, graph, node,fin):
    if node not in visited:
        visited.append(node)
        for neighbour in graph[node]:
            if neighbour == fin:
                visited.append(neighbour)
                print("Si existe relacion entre {} y {}".format(nombreInicial,nombreBuscada))
                break
            else:
                dfs(visited, graph, neighbour,fin)
while True:
    url = input("Ingrese url de wikipedia de la persona 1: ")
    nombreInicial = input("Ingrese nombre de la persona inicial (tal cual escrito en wikipedia): ")
    urlFin = input("Ingrese url de wikipedia de la persona 2: ")
    nombreBuscada = input("Ingrese nombre de la persona buscada (tal cual escrito en wikipedia): ")
    if url == '':
        break 
    else:
        contador = -1
        posicion = 0
        diccionario = {(url, nombreInicial):[]}
        get_url_2(url,diccionario,0,0,0)
        for j in range(2):
            for i in range(len(diccionario[list(diccionario.keys())[j]])):
                contador+=1
                get_url_2(list(diccionario.values())[j][i][0],diccionario,contador,j,2)
            contador=-1
        visited = []
        dfs(visited,diccionario,(url, nombreInicial),(urlFin,nombreBuscada))
        print("El grafo generado fué: ", diccionario)
        break
