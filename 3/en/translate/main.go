/*
 Developers: Lorena Valle & Christian Hernandez
*/

package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"net/url"
	"os"
)

type GoogleTranslateData struct {
	Sentences []struct {
		Trans   string `json:"trans"`
		Orig    string `json:"orig"`
		Backend int    `json:"backend"`
	} `json:"sentences"`
	Src        string  `json:"src"`
	Confidence float64 `json:"confidence"`
	Spell      struct {
	} `json:"spell"`
	LdResult struct {
		Srclangs            []string  `json:"srclangs"`
		SrclangsConfidences []float64 `json:"srclangs_confidences"`
		ExtendedSrclangs    []string  `json:"extended_srclangs"`
	} `json:"ld_result"`
}

const (
  urlBase = "https://translate.google.com/translate_a/single?client=at&dt=t&dt=ld&dt=qca&dt=rm&dt=bd&dj=1&hl=es-ES&ie=UTF-8&oe=UTF-8&inputm=2&otf=2&iid=1dd3b944-fa62-4b55-b330-74909a99969e&"
)

func main() {
	args := os.Args

	if len(args)-1 < 3 {
		log.Fatal("cannot run without args")
	}

  // input language ej: ES
  inLang := args[1]
  // output language ej: 
  ouLang := args[2]
  // text to translate
  textToTranslate := args[3]

	url, err := url.Parse(fmt.Sprintf(`%ssl=%s&tl=%s&q=%s`, urlBase, inLang, ouLang,textToTranslate))
	if err != nil {
		log.Fatal("cannot parse url", err)
	}

	header := map[string][]string{
		"Accept-Charset": {"UTF-8"},
		"User-Agent":     {"AndroidTranslate/5.3.0.RC02.130475354-53000263 5.1 phone TRANSLATE_OPM5_TEST_1"},
	}

	client := http.Client{}
	req := &http.Request{
		URL:    url,
		Method: http.MethodPost,
		Header: header,
	}

	res, err := client.Do(req)
	if err != nil {
		log.Fatal("cannot make request ", err)
	}

	if res.StatusCode != http.StatusOK {
		log.Fatal("error http status")
	}

	var data GoogleTranslateData

	err = json.NewDecoder(res.Body).Decode(&data)
	if err != nil {
		log.Fatal("cannot decode as json", err)
	}

	fmt.Printf("translated from %s to %s: %s",inLang, ouLang, data.Sentences[0].Trans)
}
