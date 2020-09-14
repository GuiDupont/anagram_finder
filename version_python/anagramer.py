def file_to_turples(dico):
    fd = open(dico, "r")
    dico_lst = []
    for line in fd:
        paire = []
        paire.append(line.strip())
        paire.append(str(len(line.strip())))
        dico_lst.append(paire)
    fd.close()
    return dico_lst


def check_word(lst, word):
    list_of_anagram = []
    for val in lst:
        if sorted(val[0]) == sorted(word) and val[0] != word:
            list_of_anagram.append(val[0])
    return (list_of_anagram)


if __name__ == '__main__':
    lst = file_to_turples("../dico/dico.txt")
    while (1):
        word = raw_input("What word would you like to check ?\nEnter a number to stop the program\n")
        if word.isalpha() == True:
            result = check_word(lst, word)
            if len(result) > 0:
                print "\nHere is the list of all the anagrams of \"" + word + "\" in english", result , "\n"
            else:
                print ("\nYour word hasn't got any anagrams\n")
        else:
            break
