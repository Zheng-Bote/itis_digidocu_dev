var lang = 'de';
try
{
	lang = checkLangCookie();
}
catch(err)
{
	lang = 'de';
}	

let lenkinfo_de = `
		<table style="width:100%;">
			<tbody>
				<tr>
					<td style="background-color:#D9D9D9;border-bottom:1.0pt solid windowtext;border-left:1.0pt solid windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt solid windowtext;padding:2.85pt;vertical-align:top;width:46.55pt;" rowspan="3">
						<p style="text-align:center;"><strong>BMW Group</strong></p>
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:1.0pt none windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt solid windowtext;padding:2.85pt;vertical-align:top;" colspan="2"><strong>Unterlagenklasse:</strong> 3.2
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:1.0pt none windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt solid windowtext;padding:2.85pt;vertical-align:top;" colspan="3"><strong>Nr.:</strong> 01
					</td>
				</tr>
				<tr>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;padding:2.85pt;vertical-align:top;" colspan="2"><strong>Gültigkeitsbereich:</strong> BMW Group
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;padding:2.85pt;vertical-align:top;" colspan="3"><strong>Version:</strong> <span id="idlenkinfo">{{lenk_version}}</span>
					</td>
				</tr>
				<tr>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="2"><p style="margin-left:0px;">Vorgabedokument der BMW Group</br>für die passive IT Infrastruktur</p><p><strong>{{obj_sname}}<br>{{lenk_title}}</strong></p><p>&nbsp;</p><p>&nbsp;</p>
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="3"><p><strong>Status:</strong> <span id = "lenkinfo_head">{{status}}<br>{{lenk_valid_startdate}}</span></p>
					</td>
				</tr>
				<tr>
					<td style="background-color:#D9D9D9;border-bottom:1.0pt solid windowtext;border-left:1.0pt solid windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt none windowtext;height:1.0pt;padding:2.85pt;vertical-align:top;">&nbsp;
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="2"><p style="text-align:right;"><strong>Beteiligte Personen/Fachstellen/Gremien:&nbsp;</strong></p>
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="3">{{lenk_departments}}
					</td>
				</tr>
			</tbody>
		</table>
		<br>
`;

let lenkinfo_en = `
		<table style="width:100%;">
			<tbody>
				<tr>
					<td style="background-color:#D9D9D9;border-bottom:1.0pt solid windowtext;border-left:1.0pt solid windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt solid windowtext;padding:2.85pt;vertical-align:top;width:46.55pt;" rowspan="3">
						<p style="text-align:center;"><strong>BMW Group</strong></p>
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:1.0pt none windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt solid windowtext;padding:2.85pt;vertical-align:top;" colspan="2"><strong>Document class:</strong> 3.2
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:1.0pt none windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt solid windowtext;padding:2.85pt;vertical-align:top;" colspan="3"><strong>Nr.:</strong> 01
					</td>
				</tr>
				<tr>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;padding:2.85pt;vertical-align:top;" colspan="2"><strong>Range of validity:</strong> BMW Group
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;padding:2.85pt;vertical-align:top;" colspan="3"><strong>Version:</strong> {{lenk_version}}</span>
					</td>
				</tr>
				<tr>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="2"><p style="margin-left:0px;">Specification document of the BMW Group</br>for the passive IT Infrastructure</p><p><strong>{{obj_sname}}<br>{{lenk_title}}</strong></p><p>&nbsp;</p><p>&nbsp;</p>
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="3"><p><strong>Status:</strong> <span id = "lenkinfo_head">{{status}}<br>{{lenk_valid_startdate}}</span></p>
					</td>
				</tr>
				<tr>
					<td style="background-color:#D9D9D9;border-bottom:1.0pt solid windowtext;border-left:1.0pt solid windowtext;border-right:1.0pt solid windowtext;border-top:1.0pt none windowtext;height:1.0pt;padding:2.85pt;vertical-align:top;">&nbsp;
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="2"><p style="text-align:right;"><strong>Coordinated with:&nbsp;</strong></p>
					</td>
					<td style="border-bottom:1.0pt solid windowtext;border-left:none;border-right:1.0pt solid windowtext;border-top:none;height:1.0pt;padding:2.85pt;vertical-align:top;" colspan="3">{{lenk_departments}}
					</td>
				</tr>
			</tbody>
		</table>
		<br>
`;

class LenkInfo extends HTMLElement 
{
	constructor() 
	{
		super();
	}
	
	connectedCallback() 
	{
		if(! this.initialized)
		{
			this.spec_obj = this.getAttribute('spec_obj');
			this.ac_class = this.getAttribute('ac_class');	
			this.pc_class = this.getAttribute('pc_class');	
			this.country = this.getAttribute('country');	
			this.lang = this.getAttribute('lang');		
			
			this.getLenkInfo();
			this.initialized = true;
		}
	}

	attributeChangedCallback(name, oldValue, newValue)
	{
		if(oldValue !== newValue)
		{
			if(name === "spec_obj")
			{
				this.spec_obj = newValue;
			}
			if(name === "ac_class")
			{
				this.ac_class = newValue;
			}
			if(name === "pc_class")
			{
				this.pc_class = newValue;
			}
			if(name === "country")
			{
				this.country = newValue;
			}
			if(name === "lang")
			{
				this.lang = newValue;
			}
			if(name === "specrelease")
			{
				this.specrelease = newValue;
			}
		}
	}
	
	static get observedAttributes()
	{
		return ["lang", "specrelease"];
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
	
	getLenkInfo() 
	{
		let data = new URLSearchParams([["spec_obj", this.spec_obj], ["ac_class", this.ac_class], ["pc_class", this.pc_class], ["country", this.country], ["lang", this.lang]]);
	
		return new Promise((res, rej) => {
			fetch('/lenkinfo/getJson',
			{
				body: data,
				method: "post"
			})
			.then(data => data.json())
			.then((json) => {
				this.renderLenkInfo(json);
				res();
			})
			.catch((error) => {this.annonymous(error);});
		})
	}
	
	annonymous(error)
	{
		console.log("annonymous: " + error);	
	}
	
	convertUTCDateToLocalDate(d) 
	{
		if(! d)
		{
			return "-/-";
		}
		//var d = convertUTCDateToLocalDate(new Date("2020-09-13T10:49:02.174"));
		let zero = true;
		if(d.match(/T00:00:00.000/))
		{
			d = d.replace(/T00:00:00.000/, "");
			zero = true;
		}
		let date = new Date(d);
		var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);

		var offset = date.getTimezoneOffset() / 60;
		var hours = date.getHours();

		newDate.setHours(hours - offset);
		
		var mm = newDate.getMonth() + 1;
		var dd = newDate.getDate();
		var yy = newDate.getFullYear();
		var hh = newDate.getHours();
		var m = newDate.getMinutes();

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
		
		let datestr; 
		if(zero)
		{
			datestr = yy + "-" + mm + "-" + dd;
		}
		else
		{
			datestr = yy + "-" + mm + "-" + dd + " " + hh + ":" + m;
		}
	
		return datestr;   
	}
		
	renderLenkInfo(obj) 
	{
		
		let i, table, thead, th, tr;
		
		table = document.createElement("table");
		table.setAttribute("style", "width:100%;");
		// table.innerHTML = "<caption>Änderungshistorie</caption>";
		thead = document.createElement("thead");
		tr = document.createElement("tr");
		
		th = document.createElement("th");
		th.setAttribute("colspan", "5");
		th.setAttribute("style", "text-align: left;");
		(this.lang === "de_DE") ? th.innerHTML = "Änderungshistorie" : th.innerHTML = "Change History";
		tr.appendChild(th);
		thead.appendChild(tr);
		table.appendChild(thead);

		tr = document.createElement("tr");
		th = document.createElement("th");
		th.setAttribute("style", "min-width:30px;");
		th.innerHTML = "Version";
		tr.appendChild(th);
		
		th = document.createElement("th");
		(this.lang === "de_DE") ? th.innerHTML = "Inhalt" : th.innerHTML = "Content of Changes";
		tr.appendChild(th);
		
		th = document.createElement("th");
		th.setAttribute("style", "min-width:100px;");
		(this.lang === "de_DE") ? th.innerHTML = "Ersteller<br>Kurzzeichen<br>Datum" : th.innerHTML = "Written by<br>Date";
		tr.appendChild(th);
		
		th = document.createElement("th");
		th.setAttribute("style", "min-width:100px;");
		(this.lang === "de_DE") ? th.innerHTML = "Prüfer<br>Kurzzeichen<br>Datum" : th.innerHTML = "Reviewer<br>Date";
		tr.appendChild(th);
		
		th = document.createElement("th");
		th.setAttribute("style", "min-width:100px;");
		(this.lang === "de_DE") ? th.innerHTML = "Freigeber<br>Kurzzeichen<br>Datum" : th.innerHTML = "Approver<br>Date";
		tr.appendChild(th);
		
		thead.appendChild(tr);
		table.appendChild(thead);

		if(obj.length < 1)
		{
			console.log("renderLenkInfo no items: "); 
			let newDate = new Date();
		
			let mm = newDate.getMonth() + 1;
			let dd = newDate.getDate();
			let yy = newDate.getFullYear();
			
			if(mm < 10)
			{
				mm = "0" + mm;
			}
			if(dd < 10)
			{
				dd = "0" + dd;
			}
			
			tr = document.createElement("tr");
			let td = document.createElement("td");
			td =  document.createElement("td");
            td.setAttribute("style", "text-align: center;");
			td.innerHTML = '<mark>tbd.</mark>';
			tr.appendChild(td);           
            
            td =  document.createElement("td");
			td.innerHTML = '<mark>tbd.</mark>';
            tr.appendChild(td);
            
            td =  document.createElement("td");
            let creator = 'creator';
            creator = creator.replace(/,/g, ",<br>");
			td.innerHTML = `<mark>tbd.<br>${yy}-${mm}-${dd}`;
            tr.appendChild(td);
            
            td =  document.createElement("td");
			td.innerHTML = `<mark>S-PDO<br>${yy}-${mm}-${dd}</mark>`;
            tr.appendChild(td);
            
            td =  document.createElement("td");
			td.innerHTML = `<mark>PDO<br>${yy}-${mm}-${dd}</mark>`;
            tr.appendChild(td);
            
            table.appendChild(tr);
            this.appendChild(table);
            
			return;
		} 
		else if(obj.length == 1)
		{
			try
			{
				if(obj[0].hasOwnProperty('ERROR') && obj[0].ERROR == "1") {console.log("renderLenkInfo ERROR: " + obj[0].errMsg);}
			}
			catch(err) 
			{
				//ignore
			}			
		}
		
		if(obj.length >= 1)
		{
			let objlength = obj.length;
			let lenkinfo;
			(this.lang === "de_DE") ? lenkinfo = lenkinfo_de : lenkinfo = lenkinfo_en;
	
			lenkinfo = lenkinfo.replace("{{lenk_version}}", obj[objlength -1].lenk_version);
			lenkinfo = lenkinfo.replace("{{status}}", obj[objlength -1].lenk_status);
			lenkinfo = lenkinfo.replace("{{obj_sname}}", obj[objlength -1].spec_obj);
			lenkinfo = lenkinfo.replace("{{lenk_title}}", obj[objlength -1].spec_title);
			lenkinfo = lenkinfo.replace("{{lenk_valid_startdate}}", this.convertUTCDateToLocalDate(obj[objlength -1].lenk_valid_startdate));
			lenkinfo = lenkinfo.replace("{{lenk_departments}}", obj[objlength -1].lenk_departments);
			
			let info = document.createElement('span');
			info.innerHTML = lenkinfo;
			this.appendChild(info);
		}
		
		for (i in obj) 
        {
			tr = document.createElement("tr");
			let td = document.createElement("td");
			           
            td =  document.createElement("td");
            td.setAttribute("style", "text-align: center;");
			td.innerHTML = obj[i].lenk_version;
			tr.appendChild(td);
			
			/*
			let lenkinfo_spec_release = document.getElementById("lenkinfo_version");
            lenkinfo_spec_release.innerHTML = obj[i].lenk_version;
                        
            let lenkinfo_departments = document.getElementById("lenkinfo_departments");
			lenkinfo_departments.innerHTML = obj[i].lenk_departments;
            */
            
            td =  document.createElement("td");
            let content = obj[i].lenk_content;
            content = content.replace(/,/g, ",<br>");
			td.innerHTML = content;
            tr.appendChild(td);
            
            td =  document.createElement("td");
            td.setAttribute("style", "vertical-align: top;");
            let creator = obj[i].lenk_creator;
            creator = creator.replace(/,/g, ",<br>");
			td.innerHTML = creator + "<br>" + this.convertUTCDateToLocalDate(obj[i].lenk_creator_date);
            tr.appendChild(td);
            
            td =  document.createElement("td");
            td.setAttribute("style", "vertical-align: top;");
            let lenk_auditor = obj[i].lenk_auditor;
            lenk_auditor = lenk_auditor.replace(/,/g, ",<br>");
			td.innerHTML = lenk_auditor + "<br>" + this.convertUTCDateToLocalDate(obj[i].lenk_auditor_date);
            tr.appendChild(td);
            
            td =  document.createElement("td");
            td.setAttribute("style", "vertical-align: top;");
            let lenk_approver = obj[i].lenk_approver;
            lenk_approver = lenk_approver.replace(/,/g, ",<br>");
			td.innerHTML = lenk_approver + "<br>" + this.convertUTCDateToLocalDate(obj[i].lenk_approver_date);
            tr.appendChild(td);
            
            
            table.appendChild(tr);
        }
        
        if(this.specrelease === "draft")
        {
			document.getElementById('lenkinfo_head').innerHTML = '<mark>DRAFT - not released</mark>';
			
			//console.info("specrelease: " + this.specrelease);
			let newDate = new Date();
		
			let mm = newDate.getMonth() + 1;
			let dd = newDate.getDate();
			let yy = newDate.getFullYear();
			
			if(mm < 10)
			{
				mm = "0" + mm;
			}
			if(dd < 10)
			{
				dd = "0" + dd;
			}
			
			tr = document.createElement("tr");
			let td = document.createElement("td");
			td =  document.createElement("td");
            td.setAttribute("style", "text-align: center;");
			td.innerHTML = '<mark>tbd.</mark>';
			tr.appendChild(td);           
            
            td =  document.createElement("td");
			td.innerHTML = '<mark>tbd.</mark>';
            tr.appendChild(td);
            
            td =  document.createElement("td");
            let creator = obj[i].lenk_creator;
            creator = creator.replace(/,/g, ",<br>");
			td.innerHTML = `<mark>tbd.<br>${yy}-${mm}-${dd}`;
            tr.appendChild(td);
            
            td =  document.createElement("td");
			td.innerHTML = `<mark>S-PDO</mark>`;
            tr.appendChild(td);
            
            td =  document.createElement("td");
			td.innerHTML = `<mark>PDO</mark>`;
            tr.appendChild(td);
            
            table.appendChild(tr);
		} 
        
        this.appendChild(table);
	}

}
customElements.define("data-lenkinfo", LenkInfo);
 
 
