var lang = 'de';

try
{
	lang = checkLangCookie();
}
catch(err)
{
	lang = 'de';
}	

class AnnexlistData extends HTMLElement 
{
	constructor() 
	{
		super();
		this.lang = 'de';
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
				this.lang = newValue;
				this.updateMessage();
			}
			if(name === 'annex')
			{
				this.annex = newValue;
				this.updateMessage();
			}
		}
	}
	
	static get observedAttributes()
	{
		return ["lang", 'annex'];
	}
	
	get message()
	{
		return this.lang;
	}
	
	set message(value)
	{
		this.lang = value;
		this.updateMessage();
	}
	
	updateMessage()
	{
		try
		{
			lang = this.lang;
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
				
				//console.log("Dok: " + this.annex + " - " + Obj[i].cat_sname_en);
				
				if(this.annex !== Obj[i].cat_sname_en)
				{

					if(this.lang === "de") 
					{
						repl = Obj[i].cat_lname_de;
						//repl = repl.replace(`${Obj[i].cat_sname_de}: `, "");  [data-aktiv*="yepp"] 
						repl = repl.replace(/Anhang.*: /, ""); 
						if(dataaktiv === Obj[i].cat_sname_en)
						{
							li.innerHTML = `<span style="font-weight: bold;">${Obj[i].cat_sname_de} - ${repl}</span>`;
						}
						else
						{
							li.innerHTML = `<span style="font-weight: bold;">${Obj[i].cat_sname_de} - ${repl}</span>`;
						}
					}
					else 
					{
						repl = Obj[i].cat_lname_en;
						//repl = repl.replace(`${Obj[i].cat_sname_de}: `, "");  [data-aktiv*="yepp"] 
						repl = repl.replace(/Annex.*: /, ""); 
						if(dataaktiv === Obj[i].cat_sname_en)
						{
							li.innerHTML = `<span style="font-weight: bold;">${Obj[i].cat_sname_en} - ${repl}</span>`;
						}
						else
						{
							li.innerHTML = `<span style="font-weight: bold;">${Obj[i].cat_sname_en} - ${repl}</span>`;
						}
					}
					
					this.appendChild(li);
				}
            }
        }
	}

}
customElements.define("data-annexlist", AnnexlistData);
 
 
