
const STYLE_CLASS = 'w3-bar w3-light-grey w3-round-large w3-border';

const STYLE_RULES = `
#itisFooter {
	padding: 10px;
}
`;

const STYLE_LINE = `
border-radius: 0px 0px 0.5em 0.5em;
`;

class ItisPage extends HTMLElement 
{
	constructor() 
	{
		super();
		this._pagetitle = "";
	}
	
	connectedCallback() 
	{
			//this.createComponent();
			this.getMnuSub();
	}
	
	disconnectedCallback()
	{
		this.getElementById("itisPage").removeEventListener("click", this.handleClick);
	}

	attributeChangedCallback(name, oldValue, newValue)
	{
		if(oldValue !== newValue)
		{
			if(name === "pagetitle")
			{
				this._pagetitle = newValue;
				this.updatePageTitle();
			}
		}
	}
		
	static get observedAttributes()
	{
		return ["pagetitle", "pagedesc"];
	}
	
	getMnuSub() 
	{
	  return new Promise((res, rej) => {
		fetch('/Webmenu/getMnuSub/?mnu=' + this._message)
		  .then(data => data.json())
		  .then((json) => {
			this.renderMnuSub(json);
			res();
		  })
		  .catch((error) => {this.annonymous(error);});
	  })
	}

	annonymous(error)
	{
		const div = document.createElement("div");
		div.setAttribute("class", STYLE_CLASS);
		div.setAttribute("style", STYLE_LINE);
		div.innerHTML = '<a href="/Webmenu/" class="w3-bar-item w3-button" title="ReST Doku">ReST Doku</a>';
		
		const span = document.createElement("span");
		div.appendChild(span);

		this.appendChild(div);		
	}
		
	renderMnuSub(data) 
	{
		
		if(data.length >= 1)
		{
			const div = document.createElement("div");
			div.setAttribute("class", STYLE_CLASS);
			div.setAttribute("style", STYLE_LINE);
			//div.innerHTML = '<a href="/Webmenu/" class="w3-bar-item w3-button" title="HOME">Home</a>';
			
			//div.innerHTML += '<input type="text" class="w3-bar-item w3-input" placeholder="Search..">';
		
			var i;
			for(i in data)
			{
				var patt = /index$/;
				var result = data[i].mnu_uri.match(patt);
				if(result == "index")
				{
					div.innerHTML += '<a href="' + data[i].mnu_uri + '" class="w3-bar-item w3-button" alt="' + data[i].mnu_item + '" title="' + data[i].desc_de + '"><img src="/Icons/house.svg"></a>';
				}
				else
				{
					div.innerHTML += '<a href="' + data[i].mnu_uri + '" class="w3-bar-item w3-button" alt="' + data[i].mnu_item + '" title="' + data[i].desc_de + '">' + data[i].name_de + '</a>';
				}
			}
			
			const span = document.createElement("span");
			div.appendChild(span);
			this.appendChild(div);	
			//this.updateMessage();
		}
	}

	get pagetitle()
	{
		return this._pagetitle;
	}
	
	set pagetitle(value)
	{
		this._pagetitle = value;
		this.setAttribute("pagetitle", value);
		//this.updateMessage();
	}
	
	updatePageTitle()
	{
		try
		{
			this.getElementById("pagetitle").innerHTML = this._pagetitle;
		}
		catch(e){}
	}
	
	createComponent() 
	{
		var d = new Date();
		var yy = d.getFullYear();
		
		//const style = document.createElement("style");
		//style.appendChild(document.createTextNode(STYLE_RULES));
		//this.appendChild(style);
		
		const div = document.createElement("div");
		div.setAttribute("class", STYLE_CLASS);
		div.setAttribute("style", STYLE_LINE);
		div.innerHTML = '<a href="/Webmenu/" title="HOME">Home</a>';
					
		//const span = document.createElement("span");
		//div.appendChild(span);

		this.appendChild(div);		
				
		//this._message = 'Hello World!';
		//this.updateMessage();
	}
}
customElements.define("itis-page", ItisPage);
 
 
