
function getAnnexCdPDFs()
{
	let place = document.getElementById('annex');
			
	fetch("/releasemgmt/getAnnexCdPDFs").then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var Obj = json;	
        if(Obj.length < 1)
        {
			return;
		}
		let table = document.createElement("table");
		table.setAttribute("class", "w3-table-all w3-hoverable sortable");
		
		let tr = document.createElement("tr");
		tr.setAttribute("class", "w3-text-grey");

		let th = document.createElement("th");
		th.innerHTML = "Name";
		tr.appendChild(th);
		th = document.createElement("th");
		th.innerHTML = "zuletzt aktualisiert";
		tr.appendChild(th);
		th = document.createElement("th");
		th.innerHTML = "download";
		tr.appendChild(th);
		table.appendChild(tr);
        for (i in Obj) 
        {
			let tr = document.createElement('tr');
			
			let name = document.createElement('td');
			name.innerHTML = Obj[i].name;
			tr.appendChild(name);
			
			let modified = document.createElement('td');
			modified.innerHTML = Obj[i].last_modified;
			tr.appendChild(modified);
			
			let download = document.createElement('td');
			download.innerHTML = `<a href="${Obj[i].uri}" alt="" download>${Obj[i].name} (${Obj[i].size}kB)</a>`;
			tr.appendChild(download);

			table.appendChild(tr);
        }
        place.appendChild(table);
    });
} 

function getStdCdPDFs()
{
	let place = document.getElementById('standard');
		
	fetch("/releasemgmt/getStdCdPDFs").then(function (response) 
    {
        return response.json();
    }).then(function (json) 
    {
        var Obj = json;	
        if(Obj.length < 1)
        {
			return;
		}
		let table = document.createElement("table");
		table.setAttribute("class", "w3-table-all w3-hoverable sortable");
		
		let tr = document.createElement("tr");
		tr.setAttribute("class", "w3-text-grey");

		let th = document.createElement("th");
		th.innerHTML = "Name";
		tr.appendChild(th);
		th = document.createElement("th");
		th.innerHTML = "zuletzt aktualisiert";
		tr.appendChild(th);
		th = document.createElement("th");
		th.innerHTML = "download";
		tr.appendChild(th);
		table.appendChild(tr);
        for (i in Obj) 
        {
			let tr = document.createElement('tr');
			
			let name = document.createElement('td');
			name.innerHTML = Obj[i].name;
			tr.appendChild(name);
			
			let modified = document.createElement('td');
			modified.innerHTML = Obj[i].last_modified;
			tr.appendChild(modified);
			
			let download = document.createElement('td');
			download.innerHTML = `<a href="${Obj[i].uri}" alt="" download>${Obj[i].name} (${Obj[i].size}kB)</a>`;
			tr.appendChild(download);

			table.appendChild(tr);
        }
        place.appendChild(table);
    });
} 
