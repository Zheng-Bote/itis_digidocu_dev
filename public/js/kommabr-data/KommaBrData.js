
class KommaBrData extends HTMLElement 
{
	constructor() 
	{
		super();
	}
	
	connectedCallback() 
	{
		if(! this.initialized)
		{
			this.txtdata = this.getAttribute('txtdata');	
			this.setUtc(this.txtdata);
			this.initialized = true;
		}
	}

	attributeChangedCallback(name, oldValue, newValue)
	{
		if(oldValue !== newValue)
		{
			if(name === "txtdata")
			{
				this._txtdata = newValue;
				this.setUtc(newValue);
			}
		}
	}
	
	static get observedAttributes()
	{
		return ["txtdata"];
	}
	
	get txtdata()
	{
		return this._txtdata;
	}
	
	set txtdata(value)
	{
		this._txtdata = value;
		this.updateUtc();
	}
	
	updateUtc()
	{
		try
		{
			txtdata = this._txtdata;
			setUtc(txtdata);
		}
		catch(e){}
	}
	
	setUtc(value) 
	{
        this.innerHTML = value.replace(/,/g, ",<br>");
	}

}
customElements.define("data-kommabr", KommaBrData);
 
 
