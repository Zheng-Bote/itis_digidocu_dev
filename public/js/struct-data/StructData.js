var lang = 'de';

try
{
	lang = checkLangCookie();
}
catch(err)
{
	lang = 'de';
}	

class StructData extends HTMLElement 
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
		fetch('/catclasses/getAllJson/1/annex')
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
        let li, repl;
       
        for (let i in Obj) 
        {
            if(!Obj[i].hasOwnProperty('ERROR'))
            {
				li = document.createElement("li");
				let dataaktiv = document.getElementById("obj_name").value;

				if(lang === "de") 
				{
					repl = Obj[i].cat_lname_de;
					//repl = repl.replace(`${Obj[i].cat_sname_de}: `, "");  [data-aktiv*="yepp"] 
					repl = repl.replace(/Anhang.*: /, ""); 
					if(dataaktiv === Obj[i].cat_sname_en)
					{
						li.innerHTML = `<span data-aktiv="yepp"><data-annex style="font-weight: bold;">${Obj[i].cat_sname_de}</data-annex><br><medium>${repl}</medium></span>`;
					}
					else
					{
						li.innerHTML = `<span><data-annex style="font-weight: bold;">${Obj[i].cat_sname_de}</data-annex><br><medium>${repl}</medium></span>`;
					}
				}
				else 
				{
					repl = Obj[i].cat_lname_en;
					//repl = repl.replace(`${Obj[i].cat_sname_de}: `, "");  [data-aktiv*="yepp"] 
					repl = repl.replace(/Annex.*: /, ""); 
					if(dataaktiv === Obj[i].cat_sname_en)
					{
						li.innerHTML = `<span data-aktiv="yepp"><data-annex style="font-weight: bold;">${Obj[i].cat_sname_en}</data-annex><br><medium>${repl}</medium></span>`;
					}
					else
					{
						li.innerHTML = `<span><data-annex style="font-weight: bold;">${Obj[i].cat_sname_en}</data-annex><br><medium>${repl}</medium></span>`;
					}
				}
                
                this.appendChild(li);
            }
        }
	}

}
customElements.define("data-struct", StructData);
 
 
