
function removeSide() {
	var div = document.getElementById("crtSide");
	div.parentNode.removeChild(div);
}
function populateM1()
{
	var div = document.createElement("div");
	div.setAttribute("id","crtSide");	 
	div.style.width = "100%";
	div.style.height = "500px";
	div.style.color = "white";
	div.style.cssFloat = "right";

	
	var c1 = document.createElement("div");
	c1.setAttribute("class","menuItem");
	c1.innerHTML = "Submenu1.1";
	
	var c2 = document.createElement("div");
	c2.setAttribute("class","menuItem");
	c2.innerHTML = "Submenu1.2";
	var c3 = document.createElement("div");
	c3.setAttribute("class","menuItem");
	c3.innerHTML = "Submenu1.3";
	div.appendChild(c1);
	div.appendChild(c2);
	div.appendChild(c3);
	
	document.getElementById("side").appendChild(div);
}

function populateM2()
{
	var div = document.createElement("div");
	div.setAttribute("id","crtSide");	 
	div.style.width = "auto";
	div.style.height = "auto";
	div.style.color = "white";
	div.style.cssFloat = "right";
	div.style.top = "100px";
	
	var c1 = document.createElement("div");
	c1.setAttribute("class","menuItem");
	c1.innerHTML = "Submenu2.1";
			//downWith(c1,30);

			var c2 = document.createElement("div");
			c2.setAttribute("class","menuItem");
			c2.innerHTML = "Submenu2.2";
			//downWith(c2,30);

			var c3 = document.createElement("div");
			c3.setAttribute("class","menuItem");
			c3.innerHTML = "Submenu2.3";
			//downWith(c3,20);

			div.appendChild(c1);
			div.appendChild(c2);
			div.appendChild(c3);
			var t = document.getElementById("m2").getBoundingClientRect().top;
			downWith(div,t);
			document.getElementById("side").appendChild(div);
		}

		function populateM3()
		{
			var div = document.createElement("div");
			div.setAttribute("id","crtSide");	 
			div.style.width = "auto";
			div.style.height = "auto";
			div.style.color = "white";
			div.style.cssFloat = "right";
			div.style.top = "100px";

			var c1 = document.createElement("div");
			c1.setAttribute("class","menuItem");
			c1.innerHTML = "Submenu3.1";

			var c2 = document.createElement("div");
			c2.setAttribute("class","menuItem");
			c2.innerHTML = "Submenu3.2";
			
			var c3 = document.createElement("div");
			c3.setAttribute("class","menuItem");
			c3.innerHTML = "Submenu3.3";

			var c4 = document.createElement("div");
			c4.setAttribute("class","menuItem");
			c4.innerHTML = "Submenu3.4";

			div.appendChild(c1);
			div.appendChild(c2);
			div.appendChild(c3);
			div.appendChild(c4);
			var t = document.getElementById("m3").getBoundingClientRect().top;
			downWith(div,t);
			document.getElementById("side").appendChild(div);
		}

		function populateM5()
		{
			var div = document.createElement("div");
			div.setAttribute("id","crtSide");	 
			div.style.width = "auto";
			div.style.height = "auto";
			div.style.color = "white";
			div.style.cssFloat = "right";
			div.style.top = "100px";

			var c1 = document.createElement("div");
			c1.setAttribute("class","menuItem");
			c1.innerHTML = "Submenu5.1";

			var c2 = document.createElement("div");
			c2.setAttribute("class","menuItem");
			c2.innerHTML = "Submenu5.2";
			
			var c3 = document.createElement("div");
			c3.setAttribute("class","menuItem");
			c3.innerHTML = "Submenu5.3";

			var c4 = document.createElement("div");
			c4.setAttribute("class","menuItem");
			c4.innerHTML = "Submenu5.4";

			var c5 = document.createElement("div");
			c5.setAttribute("class","menuItem");
			c5.innerHTML = "Submenu5.5";

			div.appendChild(c1);
			div.appendChild(c2);
			div.appendChild(c3);
			div.appendChild(c4);
			div.appendChild(c5);
			var t = document.getElementById("m5").getBoundingClientRect().top;
			downWith(div,t);
			document.getElementById("side").appendChild(div);
		}
		function populateM4()
		{
			var div = document.createElement("div");
			div.setAttribute("id","crtSide");	 
			div.style.width = "auto";
			div.style.height = "auto";
			div.style.color = "white";
			div.style.cssFloat = "right";
			div.style.top = "100px";
			
			var c1 = document.createElement("div");
			c1.setAttribute("class","menuItem");
			c1.innerHTML = "Submenu4.1";

			var c2 = document.createElement("div");
			c2.setAttribute("class","menuItem");
			c2.innerHTML = "Submenu4.2";
			
			var c3 = document.createElement("div");
			c3.setAttribute("class","menuItem");
			c3.innerHTML = "Submenu4.3";

			div.appendChild(c1);
			div.appendChild(c2);
			div.appendChild(c3);
			var t = document.getElementById("m4").getBoundingClientRect().top;
			downWith(div,t);
			document.getElementById("side").appendChild(div);
		}

		function downWith(elem,n)
		{
			var elemRect = elem.getBoundingClientRect();
			elem.style.position = "absolute";
			var goDownWith = n + elemRect.top;
			elem.style.top = goDownWith +"px";
		}	