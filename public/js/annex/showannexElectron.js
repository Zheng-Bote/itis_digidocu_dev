// 2020-12-25 16:50

function open_show(id) 
{
	
}

function open_qedit(id) 
{
	
}

function open_edit(id) 
{
	
}

function open_list() 
{
	
}

function getObjects(Obj)
{
    const selectbox = document.getElementById("obj_name");
    const newOption = new Option("Allgemein", "General");
    selectbox.add(newOption, undefined);

	//Obj.reverse();
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			 if(!Obj[i].hasOwnProperty('ERROR'))
			{
				let newOption = new Option(Obj[i].cat_lname_de, Obj[i].cat_sname_en);
				selectbox.add(newOption, undefined);
			}
		}
	}
	document.getElementById("obj_name").addEventListener("click", getAcPc);
}  

function getCategories(Obj)
{
    const selectbox = document.getElementById("cat");
    
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			let newOption = new Option(Obj[i].cat_sname_de, Obj[i].cat_sname_en);
			selectbox.add(newOption, undefined);
		}
	}
	selectbox.selectedIndex = "0";
	document.getElementById("spec_complete").addEventListener("click", catSelection);
}

function getLanguages(Obj)
{
    const selectbox = document.getElementById("lang");

	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			let newOption = new Option(Obj[i].std_attr, Obj[i].std_val);
			selectbox.add(newOption, undefined);
		}
	}
}

function getReleaseTypes(Obj)
{
    let selectbox = document.getElementById("releases");
	
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			let newOption = new Option(Obj[i].std_attr, Obj[i].std_attr);
			selectbox.add(newOption, undefined);
		}
	} 
}

function getjsonExistCountries(Obj)
{
    const selectbox = document.getElementById("countries");
    
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			let newOption = new Option(Obj[i].country, Obj[i].country);
			selectbox.add(newOption, undefined);
		}
	}
}

// #####
function getAcPc()
{
    let ac_selectbox = document.getElementById("ac_classes");
    ac_selectbox.innerHTML = "";
    let pc_selectbox = document.getElementById("pc_classes");
    pc_selectbox.innerHTML = "";
    
    let iObj = document.getElementById("obj_name").selectedIndex;
    let oObj = document.getElementById("obj_name").options;
    let obj = oObj[iObj].value;

    if(obj === "Allgemein")
    {
        let newOption = new Option("AC-0", "0");
        ac_selectbox.add(newOption, undefined);
        newOption = new Option("PC-0", "0");
        pc_selectbox.add(newOption, undefined);
        document.getElementById("cat").selectedIndex = 0;
        document.getElementById("cat").disabled=true;
        return;
    }
    else
    {
        document.getElementById("cat").disabled=false;
    }
   
	if(document.getElementById("spec_complete").checked)
	{
		console.log("Allg = on");
		let cats = document.getElementById('cat');
		cats.selectedIndex = 0;
		for (i = 1; i < cats.length; i++) 
		{
			cats.options[i].disabled = true;
		}
	}
	else
	{
		document.getElementById("cat").disabled=false;
		let cats = document.getElementById('cat');
		for (i = 1; i < cats.length; i++) 
		{
			cats.options[i].disabled = false;
		}
	}
	
    fetch("/acclasses/getObjAcJson?obj=" + obj + "&active=1").then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var Obj = json;
        for (i in Obj) 
        {
            if(!Obj[i].hasOwnProperty('ERROR'))
            {
                let ac = "AC-" + Obj[i].ac_class;
                let newOption = new Option(ac, Obj[i].ac_class);
                ac_selectbox.add(newOption, undefined);
            }
        }
    });
        
    fetch("/pcclasses/getObjPcJson?obj=" + obj + "&active=1").then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var Obj = json;
        for (i in Obj) 
        {
            if(!Obj[i].hasOwnProperty('ERROR'))
            {
                let pc = "PC-" + Obj[i].pc_class;
                let newOption = new Option(pc, Obj[i].pc_class);
                pc_selectbox.add(newOption, undefined);
            }
        }
    });
}

function catSelection()
{
    if(document.getElementById("spec_complete").checked)
    {
        document.getElementById("cat").disabled=true;
    }
    else
    {
        document.getElementById("cat").disabled=false;
		let cats = document.getElementById('cat');
		for (i = 1; i < cats.length; i++) 
		{
			cats.options[i].disabled = false;
		}
    }
}

function getlListAnnex()
{   
    document.getElementById("redmsg").innerHTML = "";
    document.getElementById("greenmsg").innerHTML = "";
    const listErg = document.getElementById("listErg");
    listErg.innerHTML = "";
    document.getElementById("toc_tmp").innerHTML = "";
    
    var stdObj = new Object();
    stdObj.obj_sname = document.getElementById("obj_name").value;
    if(stdObj.obj_sname == "0")
    {
		document.getElementById("redmsg").innerHTML = "Bitte ein Objekt auswählen";
		return;
	}

    stdObj.cat_class = document.getElementById("cat").value;
    stdObj.country = document.getElementById("countries").value;
    stdObj.lang = document.getElementById("lang").value;
    stdObj.spec_active = document.getElementById("spec_active").checked;
    stdObj.spec_compl = document.getElementById("spec_complete").checked;
    stdObj.ac_class = document.getElementById("ac_classes").value;
    stdObj.pc_class = document.getElementById("pc_classes").value;
    stdObj.spec_release = document.getElementById("releases").value;

	stdObj.spec_active = (stdObj.spec_active == true) ? 1 : 0;

	// stupid
    switch(stdObj.spec_release)
    {
        case '0': stdObj.spec_release = "draft"; break;
        case '1': stdObj.spec_release = "pre-release"; break;
        case '2': stdObj.spec_release = "released"; break;
        case '3': stdObj.spec_release = "expired"; break; 
    }
        
	if(stdObj.spec_compl == true)
	{
		// stupid
		let top_toc = document.createElement("span");
        top_toc.setAttribute('id', "top_" + 'General');
        listErg.appendChild(top_toc);
        
		showListStds(stdObj, 'General', 'General');

		const x = document.getElementById('cat');
		for (let i = 0; i < x.length; i++) 
		{
			let top_toc = document.createElement("span");
			top_toc.setAttribute('id', x[i].value);
			listErg.appendChild(top_toc);
        
			showListStds(stdObj, x[i].value);
		}
	}
	else
	{
		if(stdObj.obj_sname === "General")
		{
			let top_toc = document.createElement("span");
			top_toc.setAttribute('id', "top_" + 'General');
			listErg.appendChild(top_toc);
			
			showListStds(stdObj, 'General', 'General');
		}
		else
		{
			let top_toc = document.createElement("span");
			top_toc.setAttribute('id', stdObj.cat_class);
			listErg.appendChild(top_toc);
		
			showListStds(stdObj, stdObj.cat_class);
		}
	}
//setTimeout(getToc.bind(null, stdObj), 3000);
setTimeout(() => { document.getElementById("greenmsg").innerHTML += " Bausteine gefunden"; }, 1000);	
setTimeout(doTocCopy, 2000);
}

function doTocCopy()
{
	var itm = document.getElementById("toc_tmp");
	var cln = itm.cloneNode(true);
	document.getElementById("toc").appendChild(cln);	

	//itm.innerHTML = "";
}

function showListStds(stdObj, cat, obj_name)
{
	obj_name = (obj_name === undefined) ? stdObj.obj_sname : obj_name;
	data = new URLSearchParams([["getStdType", "show"], ["obj_sname", obj_name], ["cat_sname_en", cat], ["country", stdObj.country], ["lang", stdObj.lang], ["spec_active", stdObj.spec_active], ["ac_class", stdObj.ac_class], ["pc_class", stdObj.pc_class], ["spec_release", stdObj.spec_release]]);
	var top_toc;
var toc_tmp = document.getElementById('toc_tmp');
	
	if(obj_name == cat)
	{
		top_toc = document.getElementById("top_" + cat);
	}
	else
	{
		top_toc = document.getElementById(cat);
	}

    fetch("/annexdata/getAnnexList", 
    {
		body: data,
		method: "post"
	}).then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
		var obj = json;

		if(obj.length < 1)
		{
			console.log("showListStds no item: " + `obj_name: ${obj_name} cat: ${cat}`);
			return;
		} 
		else if(obj.length == 1)
		{
			try
			{
				if(obj[0].hasOwnProperty('ERROR') && obj[0].ERROR == "1") {console.log(`showListStds ERROR: obj_name: ${obj_name} cat: ${cat} Msg: ${obj[0].errMsg}`);}
			}
			catch(err) 
			{
				//ignore
			}			
		}
		let counter = document.getElementById("greenmsg").innerHTML;
        document.getElementById("greenmsg").innerHTML = Number(counter) + obj.length;

		let article = document.createElement("article");
let toc_article = document.createElement('li');
		if(obj_name != cat && cat == 'General')
		{
			article.innerHTML = `<h1>${obj_name} ${cat}</h1>`;
//toc_article.innerHTML = `<ol id="tmptoc_${obj_name}_${cat}"><b>${obj_name} ${cat}</b><br/></ol>`;			
		}
		else
		{
			article.innerHTML = `<h1>${cat}</h1>`;
//toc_article.innerHTML =  `<ol id="tmptoc_${cat}"><b>${cat}</b><br/></ol>`;
toc_article.innerHTML =  `<ol id="tmptoc_${cat}"><a href="#${cat}"><b>${cat}</b></a><br/></ol>`;
		}
		
		for (i in obj) 
        {
            let sect = "";
			section = document.createElement("section");
			section.setAttribute('id', obj[i].id);
			let section_head = document.createElement("small");
			
			var d = new Date(obj[i].spec_last_modified);
			var mm = d.getMonth() + 1;
			var dd = d.getDate();
			var yy = d.getFullYear();

			if(mm < 10)
			{
				mm = "0" + mm;
			}
			if(dd < 10)
			{
				dd = "0" + dd;
			}
			let datestr = yy + "-" + mm + "-" + dd;

			let section_mnu = '<a href="#body" title="Suchformular"><img src="/Icons/arrow-up-circle.svg"></a>&nbsp;&nbsp;&nbsp;';
			section_mnu += '<a href="#contentlist" title="Inhaltsverzeichnis"><img src="/Icons/justify.svg"></a>&nbsp;&nbsp;&nbsp;';
			
			section_head.innerHTML = obj[i].spec_title + " (" + obj[i].lfdnr + ") " + obj[i].spec_version + " vom " + datestr + "<data-rnav>" + section_mnu + "</data-rnav>";
			
			if(obj[i].responsibility)
			{
				section_head.innerHTML += ' (Verantwortlich: ' + obj[i].responsibility + ')';
			}
			if(obj[i].spec_marker !== "nomark")
			{
				switch(obj[i].spec_marker)
				{
					case 'green': {section_head.innerHTML += '<br><span class="w3-opacity w3-light-green w3-border-green">' + obj[i].spec_comment + '</span>'; break;}
					case 'yellow': {section_head.innerHTML += '<br><span class="w3-opacity w3-yellow w3-border-amber">' + obj[i].spec_comment + '</span>'; break;}
					case 'red': {section_head.innerHTML += '<br><span class="w3-opacity w3-deep-orange w3-border-red">' + obj[i].spec_comment + '</span>'; break;}
				}
			}
			
			section.appendChild(section_head);

			getSpec(obj[i].id, section);
			article.appendChild(section);
        }
        top_toc.appendChild(article);
toc_tmp.appendChild(toc_article);
    });    
}

function getSpec(id, sect)
{
    fetch("/annexdata/getAnnexSpec?id=" + id, {
    method: "post"
    }).then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var obj = json;
        let txtBlob = document.createElement("span");
       
        txtBlob.innerHTML = obj[0].spec_content;
        sect.appendChild(txtBlob);

let toc_tmp;
if(obj[0].obj_sname === 'General' && obj[0].cat_class === 'General')
{        
	toc_tmp = document.getElementById("tmptoc_" + obj[0].obj_sname + "_" + obj[0].cat_class);
}
else
{
	toc_tmp = document.getElementById("tmptoc_" + obj[0].cat_class);
}
let toctmp = document.createElement("span");
toctmp.innerHTML = obj[0].toc;
toc_tmp.appendChild(toctmp);

    }); 
}
