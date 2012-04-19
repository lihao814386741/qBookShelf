var speed = 5;
var currentpos=1;
var timer;

function killErrors() { 
	return true; 
} 
window.onerror = killErrors;

function mhHover(cls)
{
	event.srcElement.className = cls;
}
function bookaddsave(id){
window.open("/user_bookadd.aspx?editsave=save&id="+id,"","width=250,height=200,resizable=no,scrollbars=no,status=no,toolbar=no,menubar=no,location=no");
}
function bookrecomsave(id){
window.open("/user_bookvote.aspx?editsave=save&id="+id,"","width=250,height=200,resizable=no,scrollbars=no,status=no,toolbar=no,menubar=no,location=no");
}
function essayrecomsave(id){
window.open("/essay/essayrecom.aspx?editsave=save&id="+id,"","width=250,height=200,resizable=no,scrollbars=no,status=no,toolbar=no,menubar=no,location=no");
}
function openwins(url)
{
window.open(url,"","width=250,height=200,resizable=no,scrollbars=no,status=no,toolbar=no,menubar=no,location=no");
}
function fontZoom(size){
var Divs=document.getElementById('booktext');
if(Divs!=null){
Divs.style.fontSize=size+"pt";
}
}
function fontColor(color){ 
var Divs=document.getElementById('booktext');
if(Divs!=null){
Divs.style.color=color;
}
}
function setCookies(cookieName,cookieValue, expirehours)
{
  var today = new Date();
  var expire = new Date();
  expire.setTime(today.getTime() + 3600000 * 356 * 24);
  document.cookie = cookieName+'='+escape(cookieValue)+ ';expires='+expire.toGMTString();
}
function ReadCookies(cookieName)
{
	var theCookie=''+document.cookie;
	var ind=theCookie.indexOf(cookieName);
	if (ind==-1 || cookieName=='') return ''; 
	var ind1=theCookie.indexOf(';',ind);
	if (ind1==-1) ind1=theCookie.length;
	return unescape(theCookie.substring(ind+cookieName.length+1,ind1));
}
function saveSet()
{
setCookies("backcolor",booktexts.backcolor.options[booktexts.backcolor.selectedIndex].value);
setCookies("backsize",booktexts.backsize.options[booktexts.backsize.selectedIndex].value);
setCookies("scrollspeed",booktexts.scrollspeed.options[booktexts.scrollspeed.selectedIndex].value);
setCookies("txtcolor",booktexts.txtcolor.options[booktexts.txtcolor.selectedIndex].value);
}
function stopScroll()
{
    clearInterval(timer);
}
function beginScroll()
{
	timer=setInterval("scrolling()",300/speed);
}

function setSpeed()
{
	speed = parseInt(document.booktexts.scrollspeed.options[document.booktexts.scrollspeed.selectedIndex].value);
	if (speed < 1 || speed > 10){
	   speed=5;
	   document.booktexts.scrollspeed.selectedIndex = 5;
	}
}
function scrolling()
{
	currentpos=document.documentElement.scrollTop;
    window.scroll(0,++currentpos);
    if(currentpos!=document.documentElement.scrollTop) clearInterval(timer);
}

function loadSet()
{
	var tmpstr;
	tmpstr = ReadCookies("backcolor");
	if (tmpstr != "")
	{
		for (var i=0;i<document.booktexts.backcolor.length;i++)
		{
			if (document.booktexts.backcolor.options[i].value == tmpstr)
			{
				document.booktexts.backcolor.selectedIndex = i;
				break;
			}
		}
     document.bgColor=tmpstr;
	}

	tmpstr = ReadCookies("backsize");
	if (tmpstr != "")
	{
	 for (var i=0;i<document.booktexts.backsize.length;i++)
		{
			if (document.booktexts.backsize.options[i].value == tmpstr)
			{
				document.booktexts.backsize.selectedIndex = i;
				break;
			}
		}
      fontZoom(tmpstr);
	}
	
    tmpstr = ReadCookies("txtcolor");
	if (tmpstr != "")
	{
	 for (var i=0;i<document.booktexts.txtcolor.length;i++)
		{
			if (document.booktexts.txtcolor.options[i].value == tmpstr)
			{
				document.booktexts.txtcolor.selectedIndex = i;
				break;
			}
		}
      fontColor(tmpstr);
	}
	
    tmpstr = ReadCookies("scrollspeed");
	if (tmpstr != "")
	{
	 for (var i=0;i<document.booktexts.scrollspeed.length;i++)
		{
			if (document.booktexts.scrollspeed.options[i].value == tmpstr)
			{
				document.booktexts.scrollspeed.selectedIndex = i;
				break;
			}
		}
      setSpeed();
	}
}
function getx(e){ 
  var l=e.offsetLeft; 
  while(e=e.offsetParent){ 
    l+=e.offsetLeft; 
  } 
  return(l+'px'); 
} 
function gety(e){ 
  var l=e.offsetTop; 
  while(e=e.offsetParent){ 
    l+=e.offsetTop; 
  } 
  return(l+'px'); 
} 
function resizefront(){
  var obookimage=document.getElementById('imgbook');
  if(obookimage!=null){
	var frontimage=document.getElementById('frontimage');
	var frontdiv=document.getElementById('frontdiv');
    if(frontimage.width != obookimage.width || frontimage.height != obookimage.height){
       frontdiv.style.left=getx(obookimage);
       frontdiv.style.top=gety(obookimage);
       frontimage.width=obookimage.width;
       frontimage.height=obookimage.height;
	}else{
	  window.setTimeout('resizefront()', 1000);
	}
  }
}
function correctPNG() 
{
for(var i=0; i<document.images.length; i++)
{
 var img = document.images[i]
 var imgName = img.src.toUpperCase()
 if (imgName.substring(imgName.length-3, imgName.length) == "PNG")
 {
  var imgID = (img.id) ? "id='" + img.id + "' " : ""
  var imgClass = (img.className) ? "class='" + img.className + "' " : ""
  var imgTitle = (img.title) ? "title='" + img.title + "' " : "title='" + img.alt + "' "
  var imgStyle = "display:inline-block;" + img.style.cssText 
  if (img.align == "left") imgStyle = "float:left;" + imgStyle
  if (img.align == "right") imgStyle = "float:right;" + imgStyle
  if (img.parentElement.href) imgStyle = "cursor:hand;" + imgStyle  
  var strNewHTML = "<span " + imgID + imgClass + imgTitle
  + " style=\"" + "width:" + img.width + "px; height:" + img.height + "px;" + imgStyle + ";"
 + "filter:progid:DXImageTransform.Microsoft.AlphaImageLoader"
  + "(src=\'" + img.src + "\', sizingMethod='scale');\"></span>" 
  img.outerHTML = strNewHTML
  i = i-1
 }
}
}
document.onmousedown=stopScroll;
document.ondblclick=beginScroll;
loadSet();
resizefront();
window.attachEvent("onload", correctPNG);