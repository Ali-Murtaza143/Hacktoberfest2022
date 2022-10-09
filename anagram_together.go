package main

import (
	"fmt"
	"sort"
)

func main() {
	strs := []string{"art", "tap", "rat", "pat", "tar", "arm"}
	output := groupAnagrams(strs)
	fmt.Println(output)

	strs = []string{""}
	output = groupAnagrams(strs)
	fmt.Println(output)

	strs = []string{"a"}
	output = groupAnagrams(strs)
	fmt.Println(output)
}

type sortRune []rune

func (s sortRune) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s sortRune) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortRune) Len() int {
	return len(s)
}

func groupAnagrams(strs []string) [][]string {

	anagramMap := make(map[string][]int)
	var anagrams [][]string
	trie := &trie{root: &trieNode{}}

	lenStrs := len(strs)

	var strsDup []string

	for i := 0; i < lenStrs; i++ {
		runeCurrent := []rune(strs[i])
		sort.Sort(sortRune(runeCurrent))
		strsDup = append(strsDup, string(runeCurrent))
	}

	for i := 0; i < lenStrs; i++ {
		anagramMap = trie.insert(strsDup[i], i, anagramMap)
	}

	for _, value := range anagramMap {
		var combinedTemp []string
		for i := 0; i < len(value); i++ {
			combinedTemp = append(combinedTemp, strs[value[i]])
		}
		anagrams = append(anagrams, combinedTemp)
	}

	return anagrams
}

type trieNode struct {
	isWord    bool
	childrens [26]*trieNode
}

type trie struct {
	root *trieNode
}

func (t *trie) insert(input string, wordIndex int, anagramMap map[string][]int) map[string][]int {
	inputLen := len(input)
	current := t.root

	for i := 0; i < inputLen; i++ {
		index := input[i] - 'a'
		if current.childrens[index] == nil {
			current.childrens[index] = &trieNode{}
		}
		current = current.childrens[index]
	}
	current.isWord = true
	if anagramMap[input] == nil {
		anagramMap[input] = []int{wordIndex}
	} else {
		anagramMap[input] = append(anagramMap[input], wordIndex)
	}
	return anagramMap
}
