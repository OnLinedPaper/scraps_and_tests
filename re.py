import re

word_ls = ['some', 
  'sample', 
  'words']

def extract_keyword(q):
  question = q

  regex2 = re.compile(r"\b({})\b".format("|".join(word_ls)))

  match2 = re.findall(regex2, question)
  if(match2 == []):
    match2 = 'No TopicWord'
  return match2

print(extract_keyword('i need some words'))
print(extract_keyword("nothing"))
