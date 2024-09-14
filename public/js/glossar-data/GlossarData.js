var lang = 'de';
try
{
	lang = checkLangCookie();
}
catch(err)
{
	lang = 'de';
}	

class GlossarData extends HTMLElement 
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
		fetch('/glossar/getAllJsonSorted')
		  .then(data => data.json())
		  .then((json) => {
			this.renderGlossar(json);
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
	
	renderGlossar(data) 
	{
		var Obj = data;

        let table, tr, th, td, thead, tbody, caption;
        table = document.createElement("table");  
        // table.setAttribute("class", "w3-table w3-table-all w3-bordered w3-hoverable");
		caption = document.createElement("caption");
		caption.innerText = 'Glossar / Acronyms';
		table.appendChild(caption);

        thead = document.createElement("thead");
		tr = document.createElement("tr");

        th = document.createElement("th");
        if(lang === "de") 
        {
			th.innerText = "Akronym";
		}
        else 
        {
			th.innerText = "Acronym";
		}
        tr.appendChild(th);
        
        th = document.createElement("th");
		th.innerText = "Term";
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

        thead.appendChild(tr);
        table.appendChild(thead);
       
        for (let i in Obj) 
        {
            if(!Obj[i].hasOwnProperty('ERROR'))
            {
                tr = document.createElement("tr");
                
                td = document.createElement("td");
                td.innerText = Obj[i].acronym;
                tr.appendChild(td);
                
                td = document.createElement("td");
                if(lang === "de") 
                {
					td.innerText = Obj[i].termDe;
				}
				else
				{
					td.innerText = Obj[i].termEn;
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
customElements.define("glossar-data", GlossarData);
 
 
