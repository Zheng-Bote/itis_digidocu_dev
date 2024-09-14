// 2020-12-25 16:50

// i18n
var translate;
// pre-release
var prereleaseArr = new Array();


function getLang(lang)
{
	fetch(`/i18n/${lang}.json`).then(function (response) 
	{
		return response.json();
	}).then(function (json) 
	{
		//data = json;
		//i18n.translator.add(data);
		//console.info("translation: " + lang);
		translate = i18n.create(json);
	});
}

function delComment(id, spec_id)
{
    data = new URLSearchParams([["id", id]]);
	fetch("/AnnexDataComments/remove/" + id, { body: data, method: "post" });
	
	document.getElementById("comment_" + id).setAttribute("width" , "25px");
	document.getElementById("comment_" + id).setAttribute("src" , "/Icons/ok.svg");
	
	let txtcomment = parseInt( document.getElementById(spec_id + "_textcomment").innerHTML );
	if(txtcomment === 1)
	{
		document.getElementById(spec_id + "_textcomment").removeAttribute("class");
		document.getElementById(spec_id + "_textcomment").setAttribute('class', 'w3-badge w3-light-blue');
	}
	document.getElementById(spec_id + "_textcomment").innerHTML = txtcomment -1; 
}

function open_txtcomments(spec_id)
{
	//console.log("open_txtcomments: " + spec_id);
	
	var content_list_txtcomments = document.getElementById('content_list_txtcomments');
	content_list_txtcomments.innerHTML = '';

    fetch("/AnnexDataComments/getSpecComments/" + spec_id)
    .then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var obj = json;	
		if(obj.length < 1)
		{
			content_list_txtcomments.innerHTML = 'kein Kommentar<br>';
			return;
		}
			
		let table, tr, th, td;
        table = document.createElement("table");  
        table.setAttribute("class", "w3-table-all");
        tr = document.createElement("tr");
        th = document.createElement("th");
        th.innerText = "id";
        tr.appendChild(th);
        th = document.createElement("th");
        th.innerText = "user_comment";
        tr.appendChild(th);
        th = document.createElement("th");
        th.innerText = "delete";
        tr.appendChild(th);
        
        table.appendChild(tr);
        for (i in obj) 
        {
			tr = document.createElement("tr");
			td = document.createElement("td");
			td.innerText = obj[i].id;
			tr.appendChild(td);
			td = document.createElement("td");
			td.innerText = obj[i].user_comment;
			tr.appendChild(td);
			td = document.createElement("td");
			td.innerHTML = '<img id="comment_' + obj[i].id + '" src="/Icons/trash.svg" onclick="delComment(' + obj[i].id + ',' + obj[i].spec_id + ');">';
			tr.appendChild(td);
			
			table.appendChild(tr);
        }
        content_list_txtcomments.appendChild(table);
    });
	
	document.getElementById("list_txtcomments").showModal();
}

function open_comment(id, title, version)
{
	document.getElementById("savecomment").disabled = false;
	document.getElementById("close-dialog").innerHTML = "abbrechen";
	document.getElementById("spec_title").innerHTML = title;
	document.getElementById("spec_version").innerHTML = version;
	document.getElementById("spec_id").value = id;
	document.getElementById("dialog").showModal();
}

function sendComment()
{
	document.getElementById("savecomment").disabled = true;
	document.getElementById("close-dialog").innerHTML = "schließen";
	
	const spec_title = document.getElementById("spec_title").innerHTML;
	const spec_version = document.getElementById("spec_version").innerHTML;
	const spec_id = document.getElementById("spec_id").value;
	const user_comment = document.getElementById("user_comment").value;
	
	var data = new URLSearchParams([["spec_id", spec_id], ["spec_title", spec_title], ["spec_version", spec_version], ["user_comment", user_comment]]);

	fetch("/AnnexDataComments/createComment", { body: data, method: "post" })
	.then(data => data.json())
	.then((json) => 
	{
		if(json[0].ERROR === "0")
		{
			let msg = '\n\nVielen Dank für Ihren Kommentar.\n\nSie können das Eingabefenster nun schließen.';
			document.getElementById("greenmsg").innerHTML = msg;
			document.getElementById("user_comment").value = msg;
			let txtcomment = parseInt( document.getElementById(spec_id + "_textcomment").innerHTML );
			document.getElementById(spec_id + "_textcomment").innerHTML = txtcomment +1; 
			document.getElementById(spec_id + "_textcomment").removeAttribute("class");
			document.getElementById(spec_id + "_textcomment").setAttribute('class', 'w3-badge w3-yellow');
		}
		else
		{
			let msg = `<b>Bei der Kommentierung ist ein Fehler aufgetreten.</b></br>Bitte versuchen Sie es in Kürze erneut oder wenden Sie sich an Ihren Admin.<br/>${json[0].ERROR} ${json[0].errMsg}`;
			document.getElementById("redmsg").innerHTML = msg;
		}
	})
	.catch((error) => 
	{
		let msg = `<b>Bei der Kommentierung ist ein Fehler aufgetreten.</b></br>Bitte versuchen Sie es in Kürze erneut oder wenden Sie sich an Ihren Admin.<br/>${error}`;
		document.getElementById("redmsg").innerHTML = msg; 
	});	
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
	document.getElementById('countries').value = 'WW';
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
		//console.log("Allg = on");
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
	document.getElementById("rederror").innerHTML = "";
    document.getElementById("greenmsg").innerHTML = "";
	document.getElementById("greennotice").innerHTML = "0";
	document.getElementById("prelCount").innerHTML = "0";
	document.getElementById("prerel").style.visibility = "hidden";
	document.getElementById('prelDoBtn').style.visibility = "hidden";
	prereleaseArr = [];	

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
    stdObj.release_id = document.getElementById("release_id").value;
	stdObj.spec_active = 1;

	// load translation
	getLang(stdObj.lang);
        
	// stupid
	let top_toc = document.createElement("span");
	top_toc.setAttribute('id', "top_" + 'General');
	listErg.appendChild(top_toc);
	
	showListStds(stdObj, 'General', 'General');

		//const x = document.getElementById('cat');
		let x = ["General","Planning", "Environment", "Construction","Power","Safety","Security","Management","Operations","Appendix"];
		
		for (let i = 0; i < x.length; i++) 
		{
			let top_toc = document.createElement("span");
			top_toc.setAttribute('id', x[i]);
			listErg.appendChild(top_toc);
			        
			showListStds(stdObj, x[i]);
		}

	
	document.getElementById('btnprint').style.display='block';
	//setTimeout(() => { document.getElementById("greenmsg").innerHTML = document.getElementById('datacounter').innerHTML + " Bausteine gefunden"; }, 750);
	document.getElementById("greenmsg").innerHTML = "Bausteine gefunden:";

	setTimeout(() => { 
		let pcount = document.querySelectorAll('span[data-title*="title"]'); 
		let counter = 1;
		for(i = 0; i < pcount.length; i++)
		{
			let c = pcount[i].innerHTML;
			//pcount[i].childNodes[0].innerHTML = 1 + " " + c;
			pcount[i].innerHTML = counter++ + ". " + c;
			//console.log("data: " + c + " " + pcount[i].childNodes[0].innerHTML);
		}
	}, 1000);

}

function doPrintAnnex(obj_sname, ac_class, pc_class, country, lang, spec_release, release_id)
{
    const listErg = document.getElementById("listErg");
    listErg.innerHTML = "";
    
    var stdObj = new Object();
    stdObj.obj_sname = obj_sname;
    stdObj.cat_class = document.getElementById("cat").value;
    stdObj.country = country;
    stdObj.lang = lang;
    stdObj.spec_active = 1;
    stdObj.spec_compl = 1;
    stdObj.ac_class = ac_class;
    stdObj.pc_class = pc_class;
    stdObj.spec_release = spec_release;
    stdObj.release_id = release_id;
	stdObj.spec_active = 1;

	// load translation
	getLang(stdObj.lang);
        
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


	setTimeout(() => { 
		let pcount = document.querySelectorAll('span[data-title*="title"]'); 
		let counter = 1;
		for(i = 0; i < pcount.length; i++)
		{
			let c = pcount[i].innerHTML;
			//pcount[i].childNodes[0].innerHTML = 1 + " " + c;
			pcount[i].innerHTML = counter++ + ". " + c;
			//console.log("data: " + c + " " + pcount[i].childNodes[0].innerHTML);
		}
	}, 1000);	
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
	if(obj_name == 'General')
	{
		console.log("General: " + cat + " " + obj_name);
		data = new URLSearchParams([["getStdType", "show"], ["obj_sname", obj_name], ["cat_sname_en", cat], ["country", stdObj.country], ["lang", stdObj.lang], ["spec_active", stdObj.spec_active], ["ac_class", "0"], ["pc_class", "0"], ["spec_release", stdObj.spec_release]]);
	}
	else
	{
		console.log("General else " + obj_name);
		data = new URLSearchParams([["getStdType", "show"], ["obj_sname", obj_name], ["cat_sname_en", cat], ["country", stdObj.country], ["lang", stdObj.lang], ["spec_active", stdObj.spec_active], ["ac_class", stdObj.ac_class], ["pc_class", stdObj.pc_class], ["spec_release", stdObj.spec_release]]);
	}
	
	// console.log("showListStds: " + en("General"));

	var top_toc;
	if(obj_name == cat)
	{
		top_toc = document.getElementById("top_" + cat);
	}
	else
	{
		top_toc = document.getElementById(cat);
	}

    fetch("/releasemgmt/getAnnexList", 
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
			//console.log("showListStds no item: " + `obj_name: ${obj_name} cat: ${cat}`);
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
		let counter = parseInt(document.getElementById("greennotice").innerHTML);
        document.getElementById("greennotice").innerHTML = counter + obj.length;

		let article = document.createElement("article");
		if(obj_name != cat && cat == 'General')
		{
			//article.innerHTML = `<h1 data-title="title">${obj_name} ${translate(cat)}</h1>`;
			article.innerHTML = `<data-pbreak><h6>&nbsp;</h6></data-pbreak><span data-title="title">${obj_name} ${translate(cat)}</span>`;
		}
		else
		{
			// nicht benötigt
			//article.innerHTML = `<h1 data-title="title">${en(cat)}</h1>`;
			if(obj_name != cat && cat != 'General')
            {
				//article.innerHTML = `<h1 data-title="title">${translate(cat)}</h1>`;
				article.innerHTML = `<data-pbreak><h6>&nbsp;</h6></data-pbreak><span data-title="title">${translate(cat)}</span>`;
			}
		}
		
		for (i in obj) 
        {
            let sect = "";
			section = document.createElement("section");
			section.setAttribute('id', obj[i].id);
			let section_head = document.createElement("small");
			section_head.setAttribute('class', "noprint");
			
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

			let section_mnu = '<a class="noprint" style="background: none;" href="#body" title="Suchformular"><img src="/Icons/arrow-up-circle.svg"></a>&nbsp;';
			section_mnu += '<a class="noprint" style="background: none;" href="#contentlist" title="Inhaltsverzeichnis"><img src="/Icons/list-ol.svg"></a>&nbsp;&nbsp;&nbsp;&nbsp;';
			section_mnu += '<a class="noprint" style="background: none;" href="javascript:void(0)" onclick="open_comment(' + `'${obj[i].id}','${obj[i].spec_title}','${obj[i].spec_version}'` + ')" title="add Comment"><img src="/Icons/chat-square-text.svg"></a>&nbsp;';

			if(parseInt(obj[i].comments_count) > 0)
			{
				section_mnu += '<a class="noprint" style="background: none;" href="javascript:void(0)" onClick="open_txtcomments(' + obj[i].id + ')" title="Kommentare"><span id="' + obj[i].id + '_textcomment" class="w3-badge w3-yellow">' + obj[i].comments_count + '</span></a>&nbsp;';
			}
			else
			{
				section_mnu += '<a class="noprint" style="background: none;" href="javascript:void(0)" onClick="open_txtcomments(' + obj[i].id + ')" title="Kommentare"><span id="' + obj[i].id + '_textcomment" class="w3-badge w3-light-blue">0</span></a>&nbsp;&nbsp;&nbsp;&nbsp;';
			}
			
			section_mnu += '<a class="noprint" style="background: none;" href="javascript:void(0)" onclick="open_show(' + obj[i].id + ')" title="Show Details"><img src="/Icons/eyeglasses.svg"></a>&nbsp;';   
			section_mnu += '<a class="noprint" style="background: none;" href="javascript:void(0)" onclick="open_qedit(' + obj[i].id + ')" title="Q-Edit"><img src="/Icons/pencil.svg"></a>&nbsp;';
			section_mnu += '<a class="noprint" style="background: none;" href="javascript:void(0)" onclick="open_edit(' + obj[i].id + ')" title="Editor"><img src="/Icons/textarea-t.svg"></a>&nbsp;&nbsp;&nbsp;&nbsp;';   
			section_mnu += '<a class="noprint" style="background: none;" href="javascript:void(0)" onclick="open_show(' + obj[i].id + ')" title="Remove"><img src="/Icons/trash.svg"></a>&nbsp;&nbsp;&nbsp;&nbsp;';     
			
			// release btn
			if(obj[i].spec_release == 'pre-release')
			{
				section_mnu += '<a class="noprint" style="background: none;" href="#" onclick="MyFunction();return false;" title="approve"><span id="relBtn_' + obj[i].id + '"><img src="/Icons/emoji-smile.svg" onclick="setRelease(' + obj[i].id + ')"></span></a>';
			}
			else if(obj[i].spec_release == 'released')
			{
				let counter = parseInt(document.getElementById("prelCount").innerHTML);
				document.getElementById("prelCount").innerHTML = counter + 1;
				section_mnu += '<span title="pre-released" class="w3-green" id="relBtn_' + obj[i].id + '"><img src="/Icons/emoji-smile.svg" alt="released"></span>';
			}
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

			getSpec(obj[i].id, section, stdObj);
			article.appendChild(section);
        }
        // no toc needed anymore
        top_toc.appendChild(article);
    });    
}

// release btn
function MyFunction()
{
	return;
}
function setRelease(id)
{
	let relBtn = document.getElementById(`relBtn_${id}`);
	let counter = parseInt(document.getElementById("prelCount").innerHTML);
	const txtCounts = parseInt(document.getElementById('greennotice').innerHTML);

	let css = relBtn.getAttribute("class");
	if(css != "w3-green")
	{
		relBtn.setAttribute("class", "w3-green");
		//console.log('setRelease: ' + id + " count: " + `relBtn_${id}`);

		document.getElementById("prelMsg").innerHTML = '&harr; Released:';
		document.getElementById("prelCount").innerHTML = counter + 1;
		document.getElementById("prerel").style.visibility="visible";
		prereleaseArr.push(id);
	}
	else
	{
		relBtn.removeAttribute("class");
		document.getElementById("prelCount").innerHTML = counter - 1;

		let dCount = prereleaseArr.indexOf(id);
		prereleaseArr.splice(dCount, 1); 
	}

	counter = parseInt(document.getElementById("prelCount").innerHTML);
	console.info("Bausteine: " + txtCounts + " Counter: " + counter);
	if(txtCounts === counter)
	{
		document.getElementById("prerel").style.color = "green";
		document.getElementById('prelDoBtn').style.visibility = "visible";
	}
	else
	{
		document.getElementById("prerel").style.color = "black";
		document.getElementById('prelDoBtn').style.visibility = "hidden";
	}
}

function doprelDoBtn()
{

	//console.log(prereleaseArr.join());

	for(let i=0; i < prereleaseArr.length; i++)
	{
		data = new URLSearchParams([["id", prereleaseArr[i]]]);
		fetch("/annexdata/upReleased", { body: data, method: "post" })
		.then(data => data.json())
		.then((json) => 
		{
			if(json[0].ERROR === "0")
			{
				document.getElementById("greenmsg").innerHTML = `Baustein ${prereleaseArr[i]} auf released gesetzt.`;
				document.getElementById("greennotice").innerHTML = "";
			}
			else
			{
				console.error('upRelease NOK: ' + json[0].errMsg + ' ' + json[0].query);
			}
		})
		.catch((error) => { document.getElementById("redmsg").innerHTML = "Fehler upPrelease: " + error + " " + data; });
	}

	//doRelease

	// nicht nötig -> server utc
	var d = new Date();
	var mm = d.getMonth() + 1;
	var dd = d.getDate();
	var yy = d.getFullYear();
	var hh = d.getHours();
	var m = d.getMinutes();

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
	let datestr = yy + "-" + mm + "-" + dd + " " + hh + ":" + m;

	var stdObj = new Object();
    stdObj.obj_sname = document.getElementById("obj_name").value;
    stdObj.cat_class = document.getElementById("cat").value;
    stdObj.country = document.getElementById("countries").value;
    stdObj.lang = document.getElementById("lang").value;
    stdObj.ac_classes = document.getElementById("ac_classes").value;
    stdObj.pc_classes = document.getElementById("pc_classes").value;
	stdObj.relrequest_date = datestr;

	data = new URLSearchParams([["release_id", stdObj.release_id]]);
		fetch("/annexdata/doReleased", { body: data, method: "post" })
		.then(data => data.json())
		.then((json) => 
		{
			if(json[0].ERROR === "0")
			{
				document.getElementById("greenmsg").innerHTML = `${stdObj.obj_sname} auf released gesetzt.`;
				document.getElementById("greennotice").innerHTML = "";
			}
			else
			{
				console.error('doReleased NOK: ' + json[0].errMsg + ' ' + json[0].query);
			}
		})
		.catch((error) => { document.getElementById("redmsg").innerHTML = "Fehler doReleased: " + error + " " + data; });

		document.getElementById('prelDoBtn').style.visibility = "hidden";
}

function getSpec(id, sect, stdObj)
{
    fetch("/releasemgmt/getAnnexSpec?id=" + id, {
    method: "post"
    }).then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var obj = json;
        let txtBlob = document.createElement("span");
        
        // txtBlob.innerHTML = obj[0].spec_content;
        var repl = obj[0].spec_content;
        
        switch(stdObj.obj_sname) 
		{
			case "Annex A": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang A: passive IT-IS Komponenten") : repl = repl.replace("{{obj_name}}", "Annex A: passive IT-IS Components"); break;}
			case "Annex B-1": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang B-1: IT-Rack Design-Guide") : repl = repl.replace("{{obj_name}}", "Annex B-1: IT-Rack Design-Guide"); break;}
			case "Annex B-2": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang B-2: IT-Racks Modelbeschreibungen") : repl = repl.replace("{{obj_name}}", "Annex B-2: IT-Racks Models Descriptions"); break;}
			case "Annex B-3": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang B-3: IT-Rack SDN-Server Bebauungsvorgaben") : repl = repl.replace("{{obj_name}}", "Annex B-3: IT-Rack SDN-Server Setup Requirements"); break;}
			case "Annex C": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang C: Installateure") : repl = repl.replace("{{obj_name}}", "Annex C: Installers"); break;}
			case "Annex D": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang D: Meßtechnik") : repl = repl.replace("{{obj_name}}", "Annex D: Measurements"); break;}
			case "Annex E": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang E: Installations-Ausführungen") : repl = repl.replace("{{obj_name}}", "Annex E: Installations"); break;}
			case "Annex F": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang F: Anforderungen an die Stromversorgung") : repl = repl.replace("{{obj_name}}", "Annex F: Requirements to be met on Power Supply"); break;}
			case "Annex G4": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang G: <br> Mobilfunkanlagen in Gebäude-und Etagenverteilern") : repl = repl.replace("{{obj_name}}", "Annex G: Mobilesystems in Building- and Floordistribution"); break;}
			case "Annex I": {(stdObj.lang == "de_DE") ? repl = repl.replace("{{obj_name}}", "Anhang I: Informationen für Management und Betrieb") : repl = repl.replace("{{obj_name}}", "Annex I: Information for Management and Operations"); break;}
		}
		
		// Annex_a-de_DE.png
		let annexpng = stdObj.obj_sname;
		annexpng = annexpng.replace(" ", "_");
		let obj_struct_img = "/Annexspecs/" + annexpng + "-" + stdObj.lang + ".png";
		//console.log("struct: " + obj_struct_img);
		repl = repl.replace("{{obj_struct_img}}", obj_struct_img); 

		if(stdObj.obj_sname == 'Annex F' || stdObj.obj_sname == 'Annex G4')
		{
			if(stdObj.ac_class <= 2)
			{
				repl = repl.replace("{{GLEGACY}}", "G2: ");
			}
			else if(stdObj.ac_class == 3)
			{
				repl = repl.replace("{{GLEGACY}}", "G3: ");
			}
			else if(stdObj.ac_class == 4)
			{
				repl = repl.replace("{{GLEGACY}}", "");
			}
			
			repl = repl.replace("{{ac}}", `AC-${stdObj.ac_class}`);
			repl = repl.replace("{{pc}}", `PC-${stdObj.pc_class}`);
		}
		else
		{
			repl = repl.replace("{{GLEGACY}}", '');
			repl = repl.replace("{{ac}}", '');
			repl = repl.replace("{{pc}}", '');
		}

		var country;
		if(stdObj.country === "WW" && stdObj.lang === "en_GB"){country = "World Wide";}
		else if(stdObj.country === "WW" && stdObj.lang === "de_DE"){country = "weltweit";}
		else if(stdObj.country === "DE" && stdObj.lang === "de_DE"){country = "Deutschland";}
		else if(stdObj.country === "DE" && stdObj.lang === "en_GB"){country = "Germany";}
		else if(stdObj.country === "SG" && stdObj.lang === "en_GB"){country = "Singapore";}
		else if(stdObj.country === "SG" && stdObj.lang === "de_DE"){country = "Singapur";}
		else {country = stdObj.country;}
		
		switch(stdObj.lang) 
		{
			case "de_DE": {repl = repl.replace("{{country}}", "Land: " + country); repl = repl.replace("{{lang}}", "Sprache: deutsch"); break;}
			case "en_GB": {repl = repl.replace("{{country}}", "Country: " + country); repl = repl.replace("{{lang}}", "Language: english"); break;}
		}
		
		// page-break
		//repl = repl.replace("{{page-break
       
		txtBlob.innerHTML = repl;
        sect.appendChild(txtBlob);

    }); 
}
