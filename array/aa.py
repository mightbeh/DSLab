import wikipedia as wiki
from SPARQLWrapper import SPARQLWrapper, JSON
import urllib.request

def getWikiSearch(keyword):
	a = wiki.search(keyword)
	return a[0]
def getAltKeywords(keyword):
	sparql1 = SPARQLWrapper("http://dbpedia.org/sparql")
	sparql1.setQuery("""
	    SELECT ?c WHERE 
	{	
	?a rdfs:label 	"%s"@en. 
	?b <http://dbpedia.org/ontology/wikiPageRedirects>  ?a. 
	?b rdfs:label ?c FILTER (lang(?c)="en").
	}
	""" %(keyword))

	sparql1.setReturnFormat(JSON)
	results = sparql1.query().convert()
	#print(results)
	array = []
	for result in results["results"]["bindings"]:
	    #print(result["d"]["value"])
	    array.append(result["c"]["value"])
	return(array)

def makeDBQuery(keyword):
	sparql = SPARQLWrapper("http://dbpedia.org/sparql")
	sparql.setQuery("""
	    SELECT ?d WHERE
	{{
	?a rdfs:label "%s"@en.
	?a <http://dbpedia.org/ontology/wikiPageRedirects> ?b.
	?b rdfs:label ?c FILTER (lang(?c)="en").
	?d <http://purl.org/dc/terms/subject> ?e.
	?e rdfs:label ?c.
	   }
	      UNION
	  {
	?e <http://purl.org/dc/terms/subject> ?d.
	?e rdfs:label "%s"@en.
	   }
	}
	""" % (keyword,keyword))

	sparql.setReturnFormat(JSON)
	results = sparql.query().convert()
	array =[]
	for result in results["results"]["bindings"]:
    		#print(result["d"]["value"])
    		array.append(result["d"]["value"])
	return(array)
	

wikiRes = getWikiSearch(input("Enter Keyword: "))
print(wikiRes)
AltKeywords = getAltKeywords(wikiRes)
print(AltKeywords)
DBQuery = makeDBQuery(wikiRes)
print(DBQuery)
wikipage = wiki.page(DBQuery[0][37:])
#print(wikipage.content)

file1 = open(wikiRes,"a")
file1.write(wikipage.content)





'''
keyword = input("Enter the Keyword: ")

list = wiki.search(keyword)

print (list[0])

sparql = SPARQLWrapper("http://dbpedia.org/sparql")
sparql.setQuery("""
    SELECT ?d WHERE
{{
?a rdfs:label "%s"@en.
?a <http://dbpedia.org/ontology/wikiPageRedirects> ?b.
?b rdfs:label ?c FILTER (lang(?c)="en").
?d <http://purl.org/dc/terms/subject> ?e.
?e rdfs:label ?c.
   }
      UNION
  {
?e <http://purl.org/dc/terms/subject> ?d.
?e rdfs:label "%s"@en.
   }
}
"""% (list[0],list[0]))

sparql.setReturnFormat(JSON)
results = sparql.query().convert()
#print(results)


sparql1 = SPARQLWrapper("http://dbpedia.org/sparql")
sparql1.setQuery("""
    SELECT ?c WHERE 
{	
?a rdfs:label 	"%s"@en. 
?b <http://dbpedia.org/ontology/wikiPageRedirects>  ?a. 
?b rdfs:label ?c FILTER (lang(?c)="en").
}
"""%(list[0]))

sparql1.setReturnFormat(JSON)
results = sparql1.query().convert()
#print(results)
array = []
for result in results["results"]["bindings"]:
    #print(result["d"]["value"])
    array.append(result["c"]["value"])
print(array)
'''

