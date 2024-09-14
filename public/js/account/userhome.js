// 2020-12-19 15:35

function getLastLogin(lastLogin)
{}
      
function getlastLogout(lastLogout)
{}

function getlastPwdChangeTime(lastPwdChangeTime)
{}

function setUserData(user)
{
	// const user = {username: "<%==$ username %>", firstname: "<%==$ firstname %>", surname: "<%==$ surname %>", email: "<%==$ email %>", company: "<%==$ company %>", lastLogin: "<%==$ lastLogin %>", lastLogout: "<%==$ lastLogout %>", lastPwdChangeTime: "<%==$ lastPwdChangeTime %>", usertimezone: "<%==$ usertimezone %>", groupname: "<%==$ groupname %>", groups: "<%==$ groups %>", newsletter: "<%==$ newsletter %>"};

	let radios = document.getElementsByName('news');

	for (var i = 0, length = radios.length; i < length; i++) 
	{
		if (radios[i].value === user.newsletter) 
		{
			radios[i].checked = true;
			break;
		}
	}
}

function setUserNewsletter(radioBtn, username)
{
	console.log("Newsletter: " + radioBtn.value + " " + username);
	data = new URLSearchParams([["username", username], ["newsletter", radioBtn.value]]);
	fetch("/account/setUserNewsCfg", { body: data, method: "post" })
  .then(data => data.json())
  .then((json) => 
  {
	if(json[0].ERROR === "0")
	{
		document.getElementById("greenmsg").innerHTML = `<b>Newsletter Einstellung wurde aktualisiert.</b>`;
		doPopUp(`<p style="color: green"><b>Newsletter Einstellung wurde aktualisiert.</b>`);
	}
	else
	{
		document.getElementById("redmsg").innerHTML = "<b>Newsletter Einstellung wurde <u>nicht</u> aktualisiert.</b><br/>" + json[0].ERROR + " " + json[0].errMsg ;
		doPopUp(`<p style="color: red"><b>Newsletter Einstellung wurde <u>nicht</u> aktualisiert.</b><br/>${json[0].ERROR}<br/>${json[0].errMsg}</p>`);
	}
  })
  .catch((error) => { document.getElementById("redmsg").innerHTML = "Fehler: " + error + data; });
} 

function doPopUp(msg)
{
	const mgsTxt = document.getElementById("msg");
	mgsTxt.innerHTML = msg;		
	const pup = document.getElementById("pup");
	pup.setAttribute("style", "display: block;");
	
	window.location.href='#body';
}
