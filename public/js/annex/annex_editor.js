// 2020-12-05 10:10 

function delComment(id)
{
    data = new URLSearchParams([["id", id]]);
	fetch("/AnnexDataComments/remove/" + id, { body: data, method: "post" });
	
	document.getElementById("comment_" + id).setAttribute("width" , "25px");
	document.getElementById("comment_" + id).setAttribute("src" , "/Icons/ok.svg");
	
	let txtcomment = parseInt( document.getElementById("textcomment").innerHTML );
	document.getElementById("textcomment").innerHTML = txtcomment -1;
}


function open_txtcomments(spec_id)
{
	console.log("open_txtcomments: " + spec_id);
	
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
			td.innerHTML = '<img id="comment_' + obj[i].id + '" src="/Icons/trash.svg" onclick="delComment(' + obj[i].id + ');">';
			tr.appendChild(td);
			
			table.appendChild(tr);
        }
        content_list_txtcomments.appendChild(table);
    });
	
	document.getElementById("list_txtcomments").showModal();
}

function open_comment()
{
	document.getElementById("dialog").showModal();
}

function getGalleryImgs()
{
	let imgPlace = document.getElementById('Images');

	let ulcont = document.createElement('ul');
	ulcont.setAttribute('class', 'card-wrapper');
		
	fetch("/annexdata/getImages").then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var Obj = json;	
        let counter = 0;
        for (i in Obj) 
        {
			/*
			let i_li = document.createElement('li');
			i_li.setAttribute('class', 'card');
			i_li.innerHTML = `<img class="imggal" src="${Obj[i].img}" alt=""><h3>${Obj[i].name}</h3><p>Bild-Grö&szlig;e: ${Obj[i].size}kB, <br>URL: <mark>${Obj[i].img}</mark></p>`;
			ulcont.appendChild(i_li);
			*/
			
			let id = "img_" + counter;
			let idclip = "img_" + counter + "_clip";
			let i_li = document.createElement('li');
			i_li.setAttribute('class', 'card');
			i_li.innerHTML = `<img id="${id}" class="imggal" src="${Obj[i].img}" alt="URI: <mark>${Obj[i].img}</mark>"><h3>${Obj[i].name}</h3><p><small>Bild-Grö&szlig;e: ${Obj[i].size}kB</small><br><input class="w3-input" type="text" value="${Obj[i].img}" id="${idclip}"><br><button onclick="copyUri(${idclip})">Copy URI</button></p>`;
			ulcont.appendChild(i_li);
			counter++;
        }
    });

	imgPlace.appendChild(ulcont);

}

function copyUri(id)
{
	console.log("id: " + id);
	id.select();
	id.setSelectionRange(0, 99999); /* For mobile devices */
	document.execCommand("copy");

	alert("das Bild kann nun per STRG+V eingefügt werden:\n " + id.value);
}
	
function getObjects(Obj)
{
    let selectbox = document.getElementById("objects");

    let fs = document.createDocumentFragment() ;
    let cb = document.createElement( 'input' ) ;
    cb.type = 'radio' ;
    cb.checked = false ;
    cb.id = 'objAllgemein';
    cb.name = "cbobj";
    fs.appendChild(cb) ;
    let cbl = document.createTextNode(" Allgemein") ;
    fs.appendChild(cbl) ;
    selectbox.after(fs, "     "); 
    selectbox.appendChild(fs) ;

	Obj.reverse();
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			cb = document.createElement( 'input' ) ;
			cb.type = 'checkbox' ;
			//cb.checked = false ;
			cb.id = Obj[i].cat_sname_en;
			cb.name = "cbobj";
			fs.appendChild(cb) ;
			cbl = document.createTextNode(" " + Obj[i].cat_sname_de) ;
			fs.appendChild(cbl) ;
			selectbox.after(fs, "     "); 
			selectbox.appendChild(fs) ;
			document.getElementById(Obj[i].cat_sname_en).addEventListener("click", cbobjNoAllgemein);
		}
	}
    
    document.getElementById("objAllgemein").addEventListener("change", cbobjAllgemein);	
} 

function getCategories(Obj)
{
    let selectbox = document.getElementById("cat");
    
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			let newOption = new Option(Obj[i].cat_sname_de, Obj[i].cat_sname_en);
			selectbox.add(newOption, undefined);
		}
	}
	selectbox.selectedIndex = "0";
	selectbox.addEventListener("click", getNextLfdnr);
}

function getLanguages(Obj)
{
    let selectbox = document.getElementById("lang");

	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			let newOption = new Option(Obj[i].std_attr, Obj[i].std_val);
			selectbox.add(newOption, undefined);
		}
	}
}

function getAcClasses(Obj)
{
	let fs = document.createDocumentFragment() ;
	let selectbox = document.getElementById("ac_classes");

	Obj.reverse();
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			cb = document.createElement( 'input' );
			cb.setAttribute("type", "checkbox");
			cb.setAttribute("id", 'AC-' + Obj[i].ac_class);
			cb.setAttribute("value", Obj[i].ac_class);
			cb.setAttribute("name", "ac_class");
			fs.appendChild(cb) ;
			cbl = document.createTextNode(" " + 'AC-' + Obj[i].ac_class) ;
			fs.appendChild(cbl) ;
			selectbox.after(fs, "     "); 
			selectbox.appendChild(fs) ;
		}
	}
}

function getPcClasses(Obj)
{
	let fs = document.createDocumentFragment() ;
	let selectbox = document.getElementById("pc_classes");

	Obj.reverse();
	for (i in Obj) 
	{
		if(!Obj[i].hasOwnProperty('ERROR'))
		{
			cb = document.createElement( 'input' );
			cb.setAttribute("type", "checkbox");
			cb.setAttribute("id", 'PC-' + Obj[i].pc_class);
			cb.setAttribute("value", Obj[i].pc_class);
			cb.setAttribute("name", "pc_class");
			fs.appendChild(cb) ;
			cbl = document.createTextNode(" " + 'PC-' + Obj[i].pc_class) ;
			fs.appendChild(cbl) ;
			selectbox.after(fs, "     "); 
			selectbox.appendChild(fs) ;
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

function setSpecValidDate()
{
    var d = new Date();
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
    
    document.getElementById("spec_valid_start").value = datestr;
    yy += 1;
    datestr = yy + "-" + mm + "-" + dd;
    document.getElementById("spec_valid_end").value = datestr;
}

function cbAcPC(tocheck, doit) 
{   
    const classes = document.getElementById(tocheck);
    const cats = document.getElementById('cat');

    if(doit)
    {
        for (i = 1; i < cats.length; i++) 
        {
            cats.options[i].disabled = true;
        }
        document.getElementById("btnAc").disabled = true;
        document.getElementById("btnPc").disabled = true;

        try
        {
			cats.options[0].disabled = false;
        }
        catch(err){}
        toggleCheckboxes("ac_class", true);
        toggleCheckboxes("pc_class", true); 
    }
    else
    {
        for (i = 1; i < cats.length; i++) 
        {
            cats.options[i].disabled = false;
        }
        document.getElementById("btnAc").disabled = false;
        document.getElementById("btnPc").disabled = false;
        toggleCheckboxes("ac_class");
        toggleCheckboxes("pc_class"); 
    }
}

function toggleCheckboxes(tocheck, allgemein) 
{    
    const input = document.getElementsByName(tocheck);
    let i;

    for (i = 0; i < input.length ;i++) 
    {    
        if(input[i].checked == true)
        {
            input[i].checked = false;
            if(allgemein)
			{
				input[i].disabled = true;
			}
        }
        else
        {
			if(! allgemein)
			{
				input[i].disabled = false;
				input[i].checked = true;
			}
        }
    }
    
    if(! allgemein)
    {
		input[0].checked = false;
		input[0].disabled = true;
	}
	else
	{
		input[0].disabled = false;
		input[0].checked = true;
	}
}

function toggleObjCheckboxes(tocheck) 
{
	var checkboxes = document.getElementsByName("cbobj");
	
	for (var i=0; i<checkboxes.length; i++) 
	{
		if (checkboxes[i].checked) 
		{
			checkboxes[i].checked = false;
		}
		else
		{
			checkboxes[i].checked = true;
		}
	}

    if(document.getElementById("objAllgemein").checked)
    {
		document.getElementById("objAllgemein").checked = false;
    }
    
    cbAcPC("ac_class");
    cbAcPC("pc_class"); 
}

function clearLfdnr()
{
	alert("clock");
	document.getElementById('checkLfdnrImg').removeAttribute("class");
}

function getNextLfdnr()
{
	var lfdnrErg = document.getElementById('lfdnrErg').innerHTML = "";
	document.getElementById('checkLfdnrImg').removeAttribute("class");
	document.getElementById('checkLfdnrImg').setAttribute("src", "/Icons/question.svg");
	const cat = document.getElementById("cat").value;
	
    fetch("/annexdata/getHighestLfdnr/" + cat).then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var Obj = json;
        for (i in Obj) 
        {
            if(!Obj[i].hasOwnProperty('ERROR'))
            {
				Obj[0].lfdnr = Number(Obj[0].lfdnr) + 1;
				if(Number(Obj[0].lfdnr) < 10) {Obj[0].lfdnr = "0" + Obj[0].lfdnr;}
				if(Number(Obj[0].lfdnr) < 100) {Obj[0].lfdnr = "0" + Obj[0].lfdnr;}
                document.getElementById('lfdnr').value = Obj[0].lfdnr;
            }
        }
    });    
    

		//document.getElementById('lfdnr').value = Number(Obj[0].lfdnr);
  
}

function checkLfdnr()
{
	var lfdnrErg = document.getElementById('lfdnrErg').innerHTML = "";
	document.getElementById('checkLfdnrImg').removeAttribute("class");
	document.getElementById('checkLfdnrImg').setAttribute("src", "/Icons/question.svg");
	var objs = "";
	
	var lfdnr = document.getElementById('lfdnr').value;
	if(lfdnr.length < 3)
	{
		document.getElementById('lfdnrErg').innerHTML = "keine g&uuml;ltige lfdnr";
		return;
	}
	var cat = document.getElementById("cat").value;
	
	var checkboxes = document.getElementsByName("cbobj");
	
	for (var i=0; i<checkboxes.length; i++) 
	{
		if (checkboxes[i].checked && checkboxes[i].id != undefined) 
		{
			objs += checkboxes[i].id + ",";
		}
	}

    fetch("/annexdata/chkLfdnrEditor/?cat=" + cat + "&lfdnr=" + lfdnr)
    .then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var obj = json;	
		if(obj.length < 1)
		{
			document.getElementById('checkLfdnrImg').setAttribute("src", "/Icons/check-square.svg");
			document.getElementById('checkLfdnrImg').setAttribute("class", "w3-green");
			return;
		}
		
		document.getElementById('lfdnrErg').innerHTML += '<span onclick="document.getElementById(\'lfdnrErg\').style.display=\'none\'" class="w3-button w3-display-topright">&times;</span>';
		
		let table, tr, th, td;
        table = document.createElement("table");  
        table.setAttribute("class", "w3-table-all");
        tr = document.createElement("tr");
        th = document.createElement("th");
        th.innerText = "id";
        tr.appendChild(th);
        th = document.createElement("th");
        th.innerText = "Titel";
        tr.appendChild(th);
        th = document.createElement("th");
        th.innerText = "Objekte";
        tr.appendChild(th);
        th = document.createElement("th");
        th.innerText = "lfdnr";
        tr.appendChild(th);
        th = document.createElement("th");
        th.innerText = "Land";
        tr.appendChild(th);
        th = document.createElement("th");
        th.innerText = "Sprache";
        tr.appendChild(th);
        table.appendChild(tr);
        for (i in obj) 
        {
			document.getElementById('lfdnrErg').setAttribute("class", "w3-tag w3-yellow");
			tr = document.createElement("tr");
			td = document.createElement("td");
			td.innerText = obj[i].id;
			tr.appendChild(td);
			td = document.createElement("td");
			td.innerText = obj[i].spec_title;
			tr.appendChild(td);
			td = document.createElement("td");
			td.innerText = obj[i].obj_sname;
			tr.appendChild(td);
			td = document.createElement("td");
			td.innerText = obj[i].lfdnr;
			tr.appendChild(td);
			td = document.createElement("td");
			td.innerText = obj[i].country;
			tr.appendChild(td);
			td = document.createElement("td");
			td.innerText = obj[i].lang;
			tr.appendChild(td);
			table.appendChild(tr);
        }
        document.getElementById('lfdnrErg').appendChild(table);
        document.getElementById('lfdnrErg').style.display='block'; 
    });
}

function cbobjNoAllgemein()
{
    document.getElementById("objAllgemein").checked = false;
    cbAcPC("ac_classes", false); 
    cbAcPC("pc_classes", false); 
}

function cbobjAllgemein()
{
	const ALLGEMEIN = document.getElementById("objAllgemein");
    if(ALLGEMEIN.checked)
    {
        let cbName = document.getElementsByName("cbobj");
        document.getElementById("cat").selectedIndex = 0;
               
        for(var i=0; i < cbName.length; i++)
        {
            cbName[i].checked = false;
        } 
        cbAcPC("ac_classes", true); 
        cbAcPC("pc_classes", true); 
        ALLGEMEIN.checked = true;
    }
    else
    {
        //ALLGEMEIN.checked = false;
    }
}

function doPopUp(msg)
{
	const mgsTxt = document.getElementById("msg");
	mgsTxt.innerHTML = msg;		
	const test = document.getElementById("test");
	test.setAttribute("style", "display: block;");
	
	window.location.href='#body';
}


