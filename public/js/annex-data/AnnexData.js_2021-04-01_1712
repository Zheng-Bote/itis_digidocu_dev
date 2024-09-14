

class AnnexData extends HTMLElement 
{
	constructor() 
	{
		super();
		//this.attachShadow({mode: "open"});
	}
	
	connectedCallback() 
	{
		this.getAnnexStatistic();
	}

	getAnnexStatistic() 
	{
	  return new Promise((res, rej) => {
		fetch('/annexdata/getStatistics')
		  .then(data => data.json())
		  .then((json) => {
			this.renderAnnexStatistic(json);
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
	
	renderAnnexStatistic(data) 
	{
		var Obj = data;
		let i = 0;
		var section = document.createElement("section"); 

		var row = document.createElement("div");
		row.setAttribute("class", "w3-cell-row");

		var cell1 = document.createElement("div");
		cell1.setAttribute("class", "w3-container w3-cell");


		var head = document.createElement("h4");
		head.innerText = 'Bausteine';
		cell1.appendChild(head);

		var node = document.createElement("p");  
		var textnode = document.createTextNode("Anzahl Bausteine: " + Obj[i].count_id);
		node.appendChild(textnode);
		cell1.appendChild(node);
		
		node = document.createElement("p");
		textnode = document.createTextNode("aktive Bausteine: " + Obj[i].count_active);
		node.appendChild(textnode);
		cell1.appendChild(node);
		
		node = document.createElement("p");
		textnode = document.createTextNode("landesspezifische Bausteine: " + Obj[i].count_countries);
		node.appendChild(textnode);
		cell1.appendChild(node);

		node = document.createElement("p");
		textnode = document.createTextNode("Bausteine deutsch: " + Obj[i].count_language_de);
		node.appendChild(textnode);
		cell1.appendChild(node);   
		
		node = document.createElement("p");
		textnode = document.createTextNode("Bausteine englisch: " + Obj[i].count_language_en);
		node.appendChild(textnode);
		cell1.appendChild(node); 
		
		node = document.createElement("p");
        if(Obj[i].countCheckLfdnrCat > 0) {node.setAttribute("style", "color: red");}
        else{node.setAttribute("style", "color: green");}
		textnode = document.createTextNode("unvollständige Bausteine: " + Obj[i].countCheckLfdnrCat);
		node.appendChild(textnode);
		cell1.appendChild(node);

		node = document.createElement("p");
        if(Obj[i].count_Annexwaste > 0) {node.setAttribute("style", "color: Tomato");}
        else{node.setAttribute("style", "color: green");}
		textnode = document.createTextNode("gelöschte Bausteine: " + Obj[i].count_Annexwaste);
		node.appendChild(textnode);
		cell1.appendChild(node);
		
		row.appendChild(cell1);

		var cell2 = document.createElement("div");
		cell2.setAttribute("class", "w3-container w3-cell");

		head = document.createElement("h4");
		head.innerText = 'Release Status';
		cell2.appendChild(head);
		
        for (i in Obj[1]) 
        {           
			node = document.createElement("p");    
			textnode = document.createTextNode(Obj[1][i].release_type + ': ' + Obj[1][i].count_release_type);
			node.appendChild(textnode);
			cell2.appendChild(node); 
		}
		
		row.appendChild(cell2);
		section.appendChild(row);

		//this.shadowRoot.appendChild(section);
		this.appendChild(section);
	}

}
customElements.define("annex-data", AnnexData);
 
 
