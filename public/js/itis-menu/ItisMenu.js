import { checkLangCookie} from '/js/lang_cookie.js';

const STYLE_CLASS = 'w3-bar w3-light-grey w3-round-large w3-border';

const STYLE_RULES = `
#itisFooter {
	padding: 10px;
}
`;

const STYLE_LINE = `
border-radius: 0.5em 0.5em 0px 0px;
`;

class ItisMenu extends HTMLElement 
{
	constructor() 
	{
		super();
		this._message = "This website use Cookies to ensure you get the best";
		this._language = 'de';
	}
	
	connectedCallback() 
	{
		this.setLanguage();

		this.getMnu();
	}
	
	disconnectedCallback()
	{
		this.getElementById("itisMenu").removeEventListener("click", this.handleClick);
	}

	attributeChangedCallback(name, oldValue, newValue)
	{
		if(oldValue !== newValue)
		{
			if(name === "message")
			{
				this._message = newValue;
				this.updateMessage();
			}
		}
	}
		
	static get observedAttributes()
	{
		return ["message"];
	}

	getMnu() 
	{
	  return new Promise((res, rej) => {
		fetch('/Webmenu/getMnu')
		  .then(data => data.json())
		  .then((json) => {
			this.renderMnu(json);
			res();
		  })
		  .catch((error) => {this.annonymous(error);});
	  })
	}
	
	annonymous(error)
	{
		//document.getElementById("redmsg").innerHTML = error;
		const div = document.createElement("div");
		div.setAttribute("class", STYLE_CLASS);
		div.setAttribute("style", STYLE_LINE);
		div.innerHTML = '<a href="/index.html" class="w3-bar-item w3-button" title="HOME"><img src="/Icons/house.svg"></a>';
		div.innerHTML += '<a href="/account/form" class="w3-bar-item w3-button w3-right">Login</a>';

				//let language = checkLangCookie();
		let lang = (this._language == "de") ? 'Sprache' : 'Language'; 

		var langDown = `<div class="w3-dropdown-hover w3-right"><button class="w3-button" title="Language">${lang}</button>`;
		langDown += '<div class="w3-dropdown-content w3-bar-block w3-card-4">';
		langDown += '<a href="#" onclick="setLanguage(0);" class="w3-bar-item w3-button" title="German">DE</a>';
		langDown += '<a href="#" onclick="setLanguage(1);" class="w3-bar-item w3-button" title="English">EN</a>';
		langDown += '</div></div>';
		div.innerHTML += langDown;
		
		const span = document.createElement("span");
		div.appendChild(span);

		this.appendChild(div);		
	}

	renderMnu(data) 
	{
		const div = document.createElement("div");
		div.setAttribute("class", STYLE_CLASS);
		div.setAttribute("style", STYLE_LINE);
		div.innerHTML = '<a href="/Admin/index" class="w3-bar-item w3-button" title="HOME"><img src="/Icons/house-door.svg"></a>';
		
		if(data.length >= 1)
		{
				
			var i;
			for(i in data)
			{
				div.innerHTML += '<a href="' + data[i].mnu_uri + '" class="w3-bar-item w3-button" title="' + data[i].mnu_item + '">' + data[i].name_de + '</a>';
				
				//var data = [{mnu_uri: `${data[i].mnu_uri}`, mnu_item: `${data[i].mnu_item}`, name_de: `${data[i].name_de}`, name_en: `${data[i].name_en}`, sort: `${data[i].sort}`}];
				//this.itemToDB(data);
			}
			//this.updateMessage();
		}
				
		var dropDown = '<div class="w3-dropdown-hover w3-right"><button class="w3-button" title="Account-Management">Account <img src="/Icons/three-dots-vertical.svg"></button>';
		dropDown += '<div class="w3-dropdown-content w3-bar-block w3-card-4">';
		dropDown += '<a href="/account/logout" class="w3-bar-item w3-button" title="logout">abmelden</a>';
		dropDown += '<a href="/account/userHome" class="w3-bar-item w3-button" title="User Home">meine Seite</a>';
		dropDown += '<a href="/account/userPwd" class="w3-bar-item w3-button" title="change Password">Passwort &auml;ndern</a>';
		dropDown += '</div></div>';
		div.innerHTML += dropDown; 

		//let language = checkLangCookie();
		let lang = (this._language == "de") ? 'Sprache' : 'Language'; 

		var langDown = `<div class="w3-dropdown-hover w3-right"><button class="w3-button" title="Language">${lang}</button>`;
		langDown += '<div class="w3-dropdown-content w3-bar-block w3-card-4">';
		langDown += '<a href="#" onclick="setLanguage(0);" class="w3-bar-item w3-button" title="German">DE</a>';
		langDown += '<a href="#" onclick="setLanguage(1);" class="w3-bar-item w3-button" title="English">EN</a>';
		langDown += '</div></div>';
		div.innerHTML += langDown;

		const span = document.createElement("span");
		div.appendChild(span);

		this.appendChild(div);	
	}
	
	setLanguage()
	{
		this._language = checkLangCookie();
	}
	
	get message()
	{
		return this._message;
	}
	
	set message(value)
	{
		this._message = value;
		this.setAttribute("message", value);
		//this.updateMessage();
	}
	
	updateMessage()
	{
		try
		{
			//this.querySelector("span").innerHTML = this._message;
		}
		catch(e){}
	}

}
customElements.define("itis-menu", ItisMenu);
 
 
