function setLangCookie()
{
	//navigator.language || navigator.userLanguage
	let lang = navigator.language || navigator.userLanguage;
	let arrLang = lang.split("-");
	lang = arrLang[0].toLowerCase();
	document.cookie = "lang=" + lang + ";" + ";path=/";
	return lang;
}

/*
export function setLanguage(lang)
{
    if(lang == "0")
    {lang = "de";}
    else{lang = "en";}
    document.cookie = "lang=" + lang + ";" + ";path=/";
    location.reload();
}
*/

function getLangCookie(cname)
{
  var name = cname + "=";
  var decodedCookie = decodeURIComponent(document.cookie);
  var ca = decodedCookie.split(';');
  for(var i = 0; i <ca.length; i++) 
  {
    var c = ca[i];
    while (c.charAt(0) == ' ') 
    {
      c = c.substring(1);
    }
    if (c.indexOf(name) == 0) 
    {
      return c.substring(name.length, c.length);
    }
  }
  return "";
}


export function checkLangCookie() 
{ 
  var lang = getLangCookie("lang");
  if (lang != "") 
  {
	return lang;
  } 
  else 
  {
    lang = setLangCookie();
  }
  return lang;
}

