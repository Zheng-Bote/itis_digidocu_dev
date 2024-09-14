const VERSION = "v00.00.20";

const STYLE_CLASS = 'w3-bar w3-light-grey w3-round-large w3-border w3-center w3-small';

const STYLE_RULES = `
#itisFooter {
	padding: 10px;
}
`;

class ItisFooter extends HTMLElement 
{
	constructor() 
	{
		super();
		this._message = '<a href="/stdsystem/license" title="licenses">Lizenzen</a>&nbsp;<a href="/stdsystem/imprint" title="Imprint">Impressum</a>';
		//this.attachShadow({mode: "open"});
		//this._onAcceptedListener = null;
	}
	
	connectedCallback() 
	{
			this.createComponent();
	}
	
	disconnectedCallback()
	{
		this.getElementById("itisFooter").removeEventListener("click", this.handleClick);
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
	
	get message()
	{
		return this._message;
	}
	
	set message(value)
	{
		this._message = value;
		this.setAttribute("message", value);
		this.updateMessage();
	}
	
	updateMessage()
	{
		try
		{
			this.querySelector("span").innerHTML = this._message;
		}
		catch(e){}
	}
	
	createComponent() 
	{
		var d = new Date();
		var yy = d.getFullYear();
			
		const style = document.createElement("style");
		style.appendChild(document.createTextNode(STYLE_RULES));
		this.appendChild(style);
		
		const div = document.createElement("div");
		div.setAttribute("class", STYLE_CLASS);
		
		const divtxt = document.createElement("div");
		divtxt.setAttribute("style", "padding-top: 5px; padding-bottom: 1px;");
		divtxt.innerHTML = '<button onclick="window.location.href=\'#body\'" type="button" style="margin-bottom: 5px;">zum Seitenanfang</button><br>Copyright &copy; 2019-' + yy + ' Zheng Robert';
		div.appendChild(divtxt);
			
		const span = document.createElement("span");
		div.appendChild(span);

		this.appendChild(div);		
		
		this.addEventListener("mouseover", ()=>{div.style.backgroundColor = "rgb(35, 122, 152)";});
		this.addEventListener("mouseout", ()=>{div.style.backgroundColor = "";});
		
		//this._message = '<a href="/stdsystem/license" title="licenses">Lizenzen</a>&nbsp;<a href="/stdsystem/imprint" title="Imprint">Impressum</a>';
		this.updateMessage();
		
	}
}
customElements.define("itis-footer", ItisFooter);
 
 
