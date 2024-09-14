// 2020-12-17 12:00 


function addopen_comment(id, title, version)
{
	document.getElementById("savecomment").disabled = false;
	document.getElementById("addclose-dialog").innerHTML = "abbrechen";
	document.getElementById("addspec_title").innerHTML = title;
	document.getElementById("addspec_version").innerHTML = version;
	document.getElementById("addspec_id").value = id;
	document.getElementById("adddialog").showModal();
}

function sendComment()
{
	document.getElementById("savecomment").disabled = true;
	document.getElementById("addclose-dialog").innerHTML = "schließen";
	
	const spec_title = document.getElementById("addspec_title").innerHTML;
	const spec_version = document.getElementById("addspec_version").innerHTML;
	const spec_id = document.getElementById("addspec_id").value;
	const user_comment = document.getElementById("adduser_comment").value;
	
	var data = new URLSearchParams([["spec_id", spec_id], ["spec_title", spec_title], ["spec_version", spec_version], ["user_comment", user_comment]]);

	fetch("/AnnexDataComments/createComment", { body: data, method: "post" })
	.then(data => data.json())
	.then((json) => 
	{
		if(json[0].ERROR === "0")
		{
			let msg = '\n\nVielen Dank für Ihren Kommentar.\n\nSie können das Eingabefenster nun schließen.';
			document.getElementById("greenmsg").innerHTML = msg;
			document.getElementById("adduser_comment").value = msg;
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

function setTitle(specTitle)
{
	
}

function setDesc(specDesc)
{
	
}

function setObjects(objSname)
{
	let res = objSname.split(",");
                
	for (i = 0; i < res.length; i++) 
	{
		try
		{
			document.getElementById(res[i]).checked = true;
		}
		catch(err)
		{
			if(res[i] == '') 
			{
				// nix, harmlos
			}
			else if(res[i] == "General")
			{
				document.getElementById('objAllgemein').checked = true;
			}
			else
			{
				console.log("setObjects item: " + res[i] + " ERR: " + err);
			}
		}
	}	
}

function setCategories(catClass)
{
	let selectbox = document.getElementById("cat");
    var options = selectbox.options.length;
    
	for (i = 0; i < options; i++) 
	{
		if(selectbox.options[i].value === catClass)
		{
			selectbox.selectedIndex = i;	
		}
	}
}

function setCountry(country)
{
	
}

function setLanguages(lang)
{
	let selectbox = document.getElementById("lang");
    var options = selectbox.options.length;
    
	for (i = 0; i < options; i++) 
	{
		if(selectbox.options[i].value === lang)
		{
			selectbox.selectedIndex = i;	
		}
	}	
}

function setResponsibility(responsibility)
{
	
}

function setAcClasses(acClasses)
{
	let res = acClasses.split(",");
                
	for (i = 0; i < res.length; i++) 
	{
		try
		{
			document.getElementById('AC-' + res[i]).checked = true;
		}
		catch(err)
		{
			if(res[i] == '') 
			{
				// nix, harmlos
			}
			else
			{
				console.log("setAcClasses item: " + res[i] + " ERR: " + err);
			}
		}
	}
}

function setPcClasses(pcClasses)
{
	let res = pcClasses.split(",");
                
	for (i = 0; i < res.length; i++) 
	{
		try
		{
			document.getElementById('PC-' + res[i]).checked = true;
		}
		catch(err)
		{
			if(res[i] == '') 
			{
				// nix, harmlos
			}
			else
			{
				console.log("setPcClasses item: " + res[i] + " ERR: " + err);
			}
		}
	}	
}

function setReleaseTypes(specRelease)
{
	let selectbox = document.getElementById("releases");
    
	if(specRelease === "draft")
	{
		selectbox.selectedIndex = "0";
	}
	else if(specRelease === "pre-release")
	{
		selectbox.selectedIndex = "1";
	}
	else if(specRelease === "released")
	{
		selectbox.selectedIndex = "2";
	}
	else if(specRelease === "expired")
	{
		selectbox.selectedIndex = "3";
	}
	else
	{
		selectbox.selectedIndex = "0";
	}	
	
	selectbox.options[2].disabled = true;
    selectbox.options[3].disabled = true;
}

function setLfdnr(lfdnr)
{
	document.getElementById("lfdnr").value = lfdnr;	
}

function setComment(specComment)
{
	
}

function setActive(specActive)
{
	if(specActive == 0)
	{
		document.getElementById('spec_active').checked = false;
	}
	else
	{
		document.getElementById('spec_active').checked = true;
	}
	
}

function setLegacy(gLegacy)
{
	let res = gLegacy.split(",");
                
	for (i = 0; i < res.length; i++) 
	{
		try
		{
			document.getElementById(res[i]).checked = true;
		}
		catch(err)
		{
			if(res[i] == '') 
			{
				// nix, harmlos
			}
			else
			{
				console.log("setLegacy item: " + res[i] + " ERR: " + err);
			}
		}
	}		
}

function setMarker(specMarker)
{
	let selectbox = document.getElementById("marker");
    var options = selectbox.options.length;
    
	for (i = 0; i < options; i++) 
	{
		if(selectbox.options[i].value === specMarker)
		{
			selectbox.selectedIndex = i;	
		}
	}	
}

function setNextVersion(specVersion)
{
	let items = specVersion.split(".");
	let patchlevel = Number(items[items.length -1]) + 1;
	if(patchlevel < 10)
	{
		patchlevel = "0" + patchlevel
	}
	items[items.length -1] = patchlevel;
		
	document.getElementById("spec_version_new").value = items.join('.');
}
