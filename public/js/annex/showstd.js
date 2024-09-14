// 2020-12-25 11:19

function open_show(id) 
{
	window.open("/standardsdata/show/" + id);
}

function open_qedit(id) 
{
	window.open("/standardsdata/save/" + id);
}

function open_edit(id) 
{
	window.open("/standardsdata/editor_upd/" + id);
}

function open_list() 
{
	window.open("/standardsdata/list_all");
}

function getObjects(Obj)
{
    const selectbox = document.getElementById("obj_name");
    const newOption = new Option("Allgemein", "Allgemein");
    selectbox.add(newOption, undefined);

	//Obj.reverse();
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			 if(!Obj[i].hasOwnProperty('ERROR'))
			{
				let newOption = new Option(Obj[i].obj_lname_en, Obj[i].obj_sname);
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
			let newOption = new Option(Obj[i].cat_sname_en, Obj[i].cat_sname_en);
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

function getlLstStds()
{   
    document.getElementById("redmsg").innerHTML = "";
    document.getElementById("greenmsg").innerHTML = "";
    const listErg = document.getElementById("listErg");
    listErg.innerHTML = "";
    
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
        top_toc.setAttribute('id', "top_" + 'Allgemein');
        listErg.appendChild(top_toc);
        
		showListStds(stdObj, 'Allgemein', 'Allgemein');

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
		if(stdObj.obj_sname === "Allgemein")
		{
			let top_toc = document.createElement("span");
			top_toc.setAttribute('id', "top_" + 'Allgemein');
			listErg.appendChild(top_toc);
			
			showListStds(stdObj, 'Allgemein', 'Allgemein');
		}
		else
		{
			let top_toc = document.createElement("span");
			top_toc.setAttribute('id', stdObj.cat_class);
			listErg.appendChild(top_toc);
		
			showListStds(stdObj, stdObj.cat_class);
		}
	}
setTimeout(getToc.bind(null, stdObj), 3000);
setTimeout(() => { document.getElementById("greenmsg").innerHTML += " Bausteine gefunden"; }, 1000);	
}

function showListStds(stdObj, cat, obj_name)
{
	obj_name = (obj_name === undefined) ? stdObj.obj_sname : obj_name;
	data = new URLSearchParams([["getStdType", "show"], ["obj_sname", obj_name], ["cat_sname_en", cat], ["country", stdObj.country], ["lang", stdObj.lang], ["spec_active", stdObj.spec_active], ["ac_class", stdObj.ac_class], ["pc_class", stdObj.pc_class], ["spec_release", stdObj.spec_release]]);
	var top_toc;
	if(obj_name == cat)
	{
		top_toc = document.getElementById("top_" + cat);
	}
	else
	{
		top_toc = document.getElementById(cat);
	}

    fetch("/standardsdata/getStdList", 
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
		if(obj_name != cat && cat == 'Allgemein')
		{
			article.innerHTML = `<h1>${obj_name} ${cat}</h1>`;
		}
		else
		{
			article.innerHTML = `<h1>${cat}</h1>`;
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
			section_mnu += '<a href="javascript:void(0)" onclick="open_show(' + obj[i].id + ')" title="Show Details"><img src="/Icons/eyeglasses.svg"></a>&nbsp;&nbsp;&nbsp;';   
			section_mnu += '<a href="javascript:void(0)" onclick="open_qedit(' + obj[i].id + ')" title="Q-Edit"><img src="/Icons/pencil.svg"></a>&nbsp;&nbsp;&nbsp;';
			section_mnu += '<a href="javascript:void(0)" onclick="open_edit(' + obj[i].id + ')" title="Editor"><img src="/Icons/textarea-t.svg"></a>&nbsp;&nbsp;&nbsp;';   
			section_mnu += '<a href="javascript:void(0)" onclick="open_show(' + obj[i].id + ')" title="Remove"><img src="/Icons/trash.svg"></a>';
			
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
    });    
}

function getSpec(id, sect)
{
    fetch("/standardsdata/getStdSpec?id=" + id, {
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

    }); 
}

function getToc(stdObj)
{
	obj_name = (obj_name === undefined) ? stdObj.obj_sname : obj_name;
	data = new URLSearchParams([["getStdType", "show"], ["obj_sname", stdObj.obj_sname], ["cat_sname_en", stdObj.cat_class], ["country", stdObj.country], ["lang", stdObj.lang], ["spec_active", stdObj.spec_active], ["ac_class", stdObj.ac_class], ["pc_class", stdObj.pc_class], ["spec_release", stdObj.spec_release]]);
	var contentlist = document.getElementById("neuetoc");

    fetch("/standardsdata/getStdToc", 
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
			console.log("getToc no items: " + stdObj.obj_sname);
			return;
		} 
		else if(obj.length == 1)
		{
			try
			{
				if(obj[0].hasOwnProperty('ERROR') && obj[0].ERROR == "1") {console.log("getToc ERROR: " + stdObj.obj_sname);}
			}
			catch(err) 
			{
				//ignore
			}			
		}
		var cat_class = "";
		var catBool = true;
		
		for (i in obj) 
        {
			let item_cat_title = "";
			let item_cat = obj[i].cat_class;

            if(obj[i].cat_class === "Allgemein" && obj[i].obj_sname !== "Allgemein" && catBool === true)
            {
				item_cat_title = obj[i].obj_sname + " " + obj[i].cat_class;
				catBool = false
				
			}
			else
			{
				item_cat_title = obj[i].cat_class;
			}
			
			if(cat_class != item_cat)
			{
				cat_class = item_cat;
				item_class =  document.createElement("span");
				//item_class.setAttribute('id', item_cat);
				item_class.innerHTML = `<li><a href="#${item_cat}"><b>${item_cat_title}</b></a></li>`;
			}

			let item =  document.createElement("span");
			item.innerHTML = obj[i].toc;
			item_class.appendChild(item);
			
			contentlist.appendChild(item_class);
        }
    });    
}
