
class UtcData extends HTMLElement 
{
	constructor() 
	{
		super();
	}
	
	connectedCallback() 
	{
		if(! this.initialized)
		{
			this.utctime = this.getAttribute('utctime');	
			this.setUtc(this.utctime);
			this.initialized = true;
		}
	}

	attributeChangedCallback(name, oldValue, newValue)
	{
		if(oldValue !== newValue)
		{
			if(name === "utctime")
			{
				this._utctime = newValue;
				this.setUtc(newValue);
			}
		}
	}
	
	static get observedAttributes()
	{
		return ["utctime"];
	}
	
	get utctime()
	{
		return this._utctime;
	}
	
	set utctime(value)
	{
		this._utctime = value;
		this.updateUtc();
	}

	convertUTCDateToLocalDate(d) 
	{
		//var d = convertUTCDateToLocalDate(new Date("2020-09-13T10:49:02.174"));
		let zero = false;
		if(d.match(/T00:00:00.000/))
		{
			d = d.replace(/T00:00:00.000/, "");
			zero = true;
		}
		let date = new Date(d);
		var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);

		var offset = date.getTimezoneOffset() / 60;
		var hours = date.getHours();

		newDate.setHours(hours - offset);
		
		var mm = newDate.getMonth() + 1;
		var dd = newDate.getDate();
		var yy = newDate.getFullYear();
		var hh = newDate.getHours();
		var m = newDate.getMinutes();

		if(mm < 10)
		{
			mm = "0" + mm;
		}
		if(dd < 10)
		{
			dd = "0" + dd;
		}
		if(hh < 10)
		{
			hh = "0" + hh;
		}
		if(m < 10)
		{
			m = "0" + m;
		}
		
		let datestr; 
		if(zero)
		{
			datestr = yy + "-" + mm + "-" + dd;
		}
		else
		{
			datestr = yy + "-" + mm + "-" + dd + " " + hh + ":" + m;
		}
	
		return datestr;   
	}
		
	updateUtc()
	{
		try
		{
			utctime = this._utctime;
			setUtc(utctime);
		}
		catch(e){}
	}
	
	setUtc(value) 
	{
		if(this.utctime)
		{
			this.innerHTML = this.convertUTCDateToLocalDate(this.utctime);
		}
	}

}
customElements.define("data-utc", UtcData);
 
 
