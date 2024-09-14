var lang = 'de';
try
{
	lang = checkLangCookie();
}
catch(err)
{
	lang = 'de';
}	

class ObjectsData extends HTMLElement 
{
	constructor() 
	{
		super();
		this._lang = 'de';
	}
	
	connectedCallback() 
	{
		this.getGlossar();
	}

	attributeChangedCallback(name, oldValue, newValue)
	{
		if(oldValue !== newValue)
		{
			if(name === "lang")
			{
				this._lang = newValue;
				this.updateMessage();
			}
		}
	}
	
	static get observedAttributes()
	{
		return ["lang"];
	}
	
	get message()
	{
		return this._lang;
	}
	
	set message(value)
	{
		this._lang = value;
		this.updateMessage();
	}
	
	updateMessage()
	{
		try
		{
			lang = this._lang;
		}
		catch(e){}
	}
	
	getGlossar() 
	{
	  return new Promise((res, rej) => {
		fetch('/objects/getAllJson')
		  .then(data => data.json())
		  .then((json) => {
			this.renderObjects(json);
			res();
		  })
		  .catch((error) => {this.annonymous(error);});
	  })
	}
	
	annonymous(error)
	{
		const div = document.createElement("div");
		div.innerHTML = error;

		this.appendChild(div);		
	}
	
	renderObjects(data) 
	{
		var Obj = data;

        let table, tr, th, td;
        table = document.createElement("table");  
        table.setAttribute("class", "w3-table w3-table-all w3-bordered w3-hoverable");
        tr = document.createElement("tr");

        th = document.createElement("th");
        if(lang === "de") 
        {
			th.innerText = "Objekt";
		}
        else 
        {
			th.innerText = "Object";
		}
        tr.appendChild(th);
        
        th = document.createElement("th");
		th.innerText = "Name";
        tr.appendChild(th);

        th = document.createElement("th");
        if(lang === "de") 
        {
			th.innerText = "Beschreibung";
		}
        else 
        {
			th.innerText = "Description";
		}
        tr.appendChild(th);
        
        table.appendChild(tr);
       
        for (let i in Obj) 
        {
            if(!Obj[i].hasOwnProperty('ERROR'))
            {
                tr = document.createElement("tr");
                
                td = document.createElement("td");
                td.innerText = Obj[i].objSname;
                tr.appendChild(td);
                
                td = document.createElement("td");
                if(lang === "de") 
                {
					td.innerText = Obj[i].objLnameDe;
				}
				else
				{
					td.innerText = Obj[i].objLnameEn;
				}
                tr.appendChild(td);
                
                td = document.createElement("td");
                if(lang === "de") 
                {
					td.innerText = Obj[i].descDe;
				}
				else 
				{
					td.innerText = Obj[i].descEn;
				}
                tr.appendChild(td);
                
                table.appendChild(tr);
            }
        }
        if(Obj.length >= 1)
        {
            this.appendChild(table);
        }
		//this.updateMessage();
	}

}
customElements.define("data-objects", ObjectsData);
 
 
