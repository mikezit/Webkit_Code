var _BdBrowser={},_Instance={},_BdElement={},_System={};_System.path="/ui/scripts/CommentEditor/";_System.imagePath="http://img.baidu.com/hi/";function _Bd$(a){if(typeof a=="string"){return document.getElementById(a)}return a}_BdElement.addClassName=function(d,c){var a=d.className.split(" ");var b=false;for(var e=0,f=a.length;e<f;e++){if(a[e]==c){b=true;break}}if(!b){d.className=a.concat(c).join(" ")}};_BdElement.removeClassName=function(a,c){var b=new RegExp("(^| )"+c+"( |$)","g");a.className=a.className.replace(b,"$2")};_BdElement._realLeftTop=function(b){var c=parseInt(b.currentStyle.borderTopWidth);var a=parseInt(b.currentStyle.borderLeftWidth);return{left:isNaN(a)?0:a,top:isNaN(c)?0:c}};_BdElement.realOffset=function(c){if(!c){return null}var d=c,h=0,b=0,g=0,f=0,e=this.body();do{g+=d.offsetLeft||0;f+=d.offsetTop||0;if(_BdBrowser.ie&&"tdthdiv".indexOf(d.tagName.toLowerCase())>-1){var a=this._realLeftTop(d);g+=a.left;f+=a.top}if(_BdBrowser.safari&&"tabletdth".indexOf(d.tagName.toLowerCase())>-1){var a=this._realLeftTop(d);g+=a.left;f+=a.top}d=d.offsetParent}while(d);if(!_BdBrowser.opera){do{h+=c.scrollLeft||0;b+=c.scrollTop||0;c=c.offsetParent}while(c)}return{x:g-h+e.scrollLeft,y:f-b+e.scrollTop}};_BdElement.body=function(){var d=0,f=0,i=0,b=0,c=0,e=0;var h=window,a=document,g=a.documentElement;d=g.clientWidth||a.body.clientWidth;f=h.innerHeight||g.clientHeight||a.body.clientHeight;b=a.body.scrollTop||g.scrollTop;i=a.body.scrollLeft||g.scrollLeft;c=Math.max(a.body.scrollWidth,g.scrollWidth||0);e=Math.max(a.body.scrollHeight,g.scrollHeight||0,f);return{scrollTop:b,scrollLeft:i,scrollWidth:c,scrollHeight:e,clientWidth:d,clientHeight:f}};if(typeof(HTMLElement)!="undefined"&&!window.opera){HTMLElement.prototype.__defineGetter__("currentStyle",function(){return this.ownerDocument.defaultView.getComputedStyle(this,null)});HTMLElement.prototype.insertAdjacentHTML=function(a,c){var b=this.ownerDocument.createRange();b.setStartBefore(this);b=b.createContextualFragment(c);this.insertAdjacentElement(a,b)};HTMLElement.prototype.insertAdjacentElement=function(a,b){switch(a){case"beforeBegin":this.parentNode.insertBefore(b,this);break;case"afterBegin":this.insertBefore(b,this.firstChild);break;case"beforeEnd":this.appendChild(b);break;case"afterEnd":if(!this.nextSibling){this.parentNode.appendChild(b)}else{this.parentNode.insertBefore(b,this.nextSibling)}break}}}if(!window.attachEvent&&window.addEventListener){window.attachEvent=HTMLElement.prototype.attachEvent=document.attachEvent=function(d,b,c){var a=c?true:false;this.addEventListener(d.replace(/^on/i,"").toLowerCase(),b,a)};window.detachEvent=HTMLElement.prototype.detachEvent=document.detachEvent=function(d,b,c){var a=c?true:false;this.removeEventListener(d.replace(/^on/i,"").toLowerCase(),b,a)}}_System.extend=function(b,c){for(var a in c){b[a]=c[a]}return b};Function.prototype.Extends=function(a,d){var b=this.prototype,e,c=this.prototype=new a();if(d){c._className=d}for(e in b){c[e]=b[e]}this.prototype.constructor=b.constructor;b=null;if(c.hashCode){delete _Instance[c.hashCode]}return c};function uniqueID(){var b=function(){return Math.round(Math.random()*2147483648)};var a=function(){return b().toString(36)+(b()^(new Date()).getTime()).toString(36)};return a()+a()}function loadCssFile(b){var c=document;var a=c.body;var d=c.createElement("LINK");if(d&&a){d.href=b;d.type="text/css";d.rel="Stylesheet";a.insertBefore(d,a.firstChild)}}(function(){if(_BdBrowser.platform){return}var a=window.navigator.userAgent;_BdBrowser.platform=window.navigator.platform;_BdBrowser.firefox=a.indexOf("Firefox")>0;_BdBrowser.opera=typeof(window.opera)=="object";_BdBrowser.ie=!_BdBrowser.opera&&a.indexOf("MSIE")>0;_BdBrowser.mozilla=window.navigator.product=="Gecko";_BdBrowser.netscape=window.navigator.vendor=="Netscape";_BdBrowser.gecko=a.indexOf("Gecko")>-1&&a.indexOf("KHTML")==-1;_BdBrowser.safari=a.indexOf("Safari")>-1;if(_BdBrowser.firefox){var b=/Firefox(\s|\/)(\d+(\.\d+)?)/}else{if(_BdBrowser.ie){var b=/MSIE( )(\d+(\.\d+)?)/}else{if(_BdBrowser.opera){var b=/Opera(\s|\/)(\d+(\.\d+)?)/}else{if(_BdBrowser.netscape){var b=/Netscape(\s|\/)(\d+(\.\d+)?)/}else{if(_BdBrowser.safari){var b=/Version(\/)(\d+(\.\d+)?)/}else{if(_BdBrowser.mozilla){var b=/rv(\:)(\d+(\.\d+)?)/}}}}}}if("undefined"!=typeof(b)&&b.test(a)){_BdBrowser.version=parseFloat(RegExp.$2)}})();String.prototype.format=function(){if(arguments.length==0){return this}for(var b=this,a=0;a<arguments.length;a++){b=b.replace(new RegExp("\\{"+a+"\\}","g"),arguments[a])}return b};var _BdPopupLayer=function(){_Instance[this.hashCode=uniqueID()]=this;this.busy=false;this.exclusive=false;this.autoFit=true;this.isOpen=false;this.defaultContent="<nobr><div id='Content' nowrap='true' style='border:solid 1px #666666'></div></nobr>";this.hideTrigger={onblur:true,onscroll:true,onmousedown:true};this.initialize()};_BdPopupLayer._layers=[];_BdPopupLayer._focusOnLayer=false;_System.extend(_BdPopupLayer.prototype,{initialize:function(){_BdPopupLayer._layers[_BdPopupLayer._layers.length]=this;var c=this;c.id=c.name="_BdPopupLayer_"+c.hashCode;this.onBlurHandler=function(){setTimeout(function(){if(!_BdPopupLayer._focusOnLayer){c.hide()}},10)};this.onClickHandler=function(){c.hide()};this.onScrollHandler=function(){c.hide()};var b="<iframe frameborder='0' name='"+c.name+"' style='position:absolute; z-index:65001; display:none;' scrolling='no' id='"+c.id+"'></iframe>";if(!document.body){document.write(b)}else{document.body.insertAdjacentHTML("afterBegin",b)}var a=document.getElementsByTagName("IFRAME");for(var d=0;d<a.length;d++){if(a[d].id==this.id){this.layer=a[d]}}frames[this.name].document.write("            <html>                <head>                    <style type='text/css'>                        html *{-moz-user-select:none;}                        body,td,th{font:12px Geneva, Arial, sans-serif; cursor:default;}                        body{margin:0px; background-color:#FFF;}                        .tabPanel{height:253px;width:344px;}                        .tabContent{overflow-y:auto;float:left;width:280px;height:253px;}                        .tabContentHide{display:none;width:263px;height:253px}                        .tabContentShow{display:block;width:263px;height:253px}                        .tabMenu{float:right;width:64px;height:140px;text-align:center;line-height:24px;height:24px;font:'\u5b8b\u4f53';font-size:12px;}                        .tabMenuHover{background:#E8E8FD;}                        .tabMenuNoHover{cursor:pointer;}                        .tableCell{background:#d7d79f;}                        .tableCellOver{background:#ffffbe;}                        .reviewHide{display:block;position:absolute;width:50px;height:50px;left:5px;right:200px;top:3px;bottom:200px;background-color:#FFFFFF;text-align:conter;}                        .review{width:50px;height:50px;background-position:center;background-repeat:no-repeat;border:1px solid #000;}                        .tabStyle{position:absolute;left:356px;right:200px;top:12px;bottom:200px;z-index:65533;width:50px;height:50px;background:#FFFFFF;}                        .jd img{background:transparent url(http://img.baidu.com/hi/default/jxFace2.gif?v=1.1) no-repeat scroll left top; cursor:pointer; display:block; width:35px; height:35px; }                        .pp img{background:transparent url(http://img.baidu.com/hi/default/fFace.gif?v=1.1) no-repeat scroll left top; cursor:pointer; display:block; width:25px; height:25px; }                        .ldw img{background:transparent url(http://img.baidu.com/hi/default/wFace.gif?v=1.1) no-repeat scroll left top; cursor:pointer; display:block; width:35px; height:35px; }                        .tsj img{background:transparent url(http://img.baidu.com/hi/default/tFace.gif?v=1.1) no-repeat scroll left top; cursor:pointer; display:block; width:35px; height:35px; }                        .cat img{background:transparent url(http://img.baidu.com/hi/default/cFace.gif?v=1.1) no-repeat scroll left top; cursor:pointer; display:block; width:35px; height:35px; }                        .bb img{background:transparent url(http://img.baidu.com/hi/default/bFace.gif?v=1.1) no-repeat scroll left top; cursor:pointer; display:block; width:35px; height:35px; }                        .youa img{background:transparent url(http://img.baidu.com/hi/default/yFace.gif?v=1.1) no-repeat scroll left top; cursor:pointer; display:block; width:35px; height:35px; }                    </style>                </head>                <body onfocus='parent._BdPopupLayer._focusOnLayer=true;' onselectstart='return false'>"+this.defaultContent+"</body>            </html>");frames[this.name].document.close();window.attachEvent("onfocus",function(e){_BdPopupLayer._focusOnLayer=false})},write:function(a){this.content.innerHTML=a},showBy:function(c,b,a){this.show(0,0,b,a,c)},showByXYWH:function(d,e,b,c,a){this.show(e,b,c,a,d)},show:function(a,j,c,g,o){var e=a=a?(isNaN(a)?0:parseInt(a,10)):0;var f=j=j?(isNaN(j)?0:parseInt(j,10)):0;c=c?(isNaN(c)?"auto":parseInt(c,10)):"auto";g=g?(isNaN(g)?"auto":parseInt(g,10)):"auto";var n=_BdElement.body(),p=0;if(o&&(o=_Bd$(o))&&o.tagName){p=o.offsetHeight;var k=_BdElement.realOffset(o);a+=k.x;j+=k.y}this.layer.style.top=j+p+"px";this.layer.style.left=a+"px";this.layer.style.width="2px";this.layer.style.height="2px";if(_BdBrowser.netscape&&_BdBrowser.netscape.version<7.2){this.layer.style.visibility=""}else{this.layer.style.display=""}var b=this.layer.offsetWidth;var h=this.layer.offsetHeight;if(n.scrollLeft+n.clientWidth<a+b){if(a-b>=n.scrollLeft){a-=b}else{a=n.scrollLeft+n.clientWidth-b}}if(n.scrollTop+n.clientHeight<j+h+p){if(j-h>=n.scrollTop){j-=h}else{j=n.scrollTop+n.clientHeight-h}}else{j+=p}var l=this.document,m=dsh=0;var d=l.body.scrollWidth;var i=l.body.scrollHeight;if(l.documentElement){m=l.documentElement.scrollWidth;dsh=l.documentElement.scrollHeight}if(isNaN(c)){c=Math.max(m,d,this.content.offsetWidth)}if(isNaN(g)){g=Math.max(dsh,i,this.content.offsetHeight)}this.width=c||2;this.height=g||2;this.layer.style.top=(this.top=j)+"px";this.layer.style.left=(this.left=a)+"px";this.layer.style.width=this.width+"px";this.layer.style.height=this.height+"px";if(this.hideTrigger.onblur){window.attachEvent("onblur",this.onBlurHandler)}if(this.hideTrigger.onscroll){window.attachEvent("onscroll",this.onScrollHandler)}if(this.hideTrigger.onmousedown){document.attachEvent("onmousedown",this.onClickHandler)}this.isOpen=true;this.onshow()},hide:function(){this.isOpen=false;this.layer.style.zIndex=65001;if(_BdBrowser.netscape&&_BdBrowser.netscape.version<7.2){this.layer.style.visibility="hidden"}else{this.layer.style.display="none"}if(this.hideTrigger.onblur){window.detachEvent("onblur",this.onBlurHandler)}if(this.hideTrigger.onscroll){window.detachEvent("onscroll",this.onScrollHandler)}if(this.hideTrigger.onmousedown){document.detachEvent("onmousedown",this.onClickHandler)}if(!this.exclusive){this.document.body.innerHTML=this.defaultContent;this.width=this.height=0;this.style=this.busy=false}this.onhide()},getElementById:function(a){return this.document.getElementById(a)}});window.attachEvent("onload",function(){new _BdPopupLayer()});_BdPopupLayer.provider=function(b){var c,a=0;for(;a<this._layers.length;a++){if(!this._layers[a].busy){c=this._layers[a];break}}if(a==this._layers.length-1){new _BdPopupLayer()}if(a==this._layers.length){c=new _BdPopupLayer(b)}c.busy=true;c.window=c.layer.contentWindow;c.document=c.window.document;c.content=c.document.getElementById("Content");c.style=c.content.style;return c};function BdEditor(a,b){this.textarea=_Bd$(a);this.width=b.width||"100%";this.height=b.height||"300px";this.modules={};BdEditor.instance=_Instance[this.hashCode=uniqueID()]=this}BdEditor.prototype.render=function(){loadCssFile(_System.path+"css/default/bdeditor.css");var a="        <div id='bdeditor_container_{2}'>            <table width='{0}' height='{1}' cellpadding='0' cellspacing='0' border='0'>                <tr>                    <td id='editor_toolbar_{2}' class='ToolbarContainer'></td>                </tr>                <tr>                    <td id='editor_area_{2}' class='EditorContainer'></td>                </tr>            </table>        </div>    ".format(this.width,this.height,this.hashCode);this.textarea.insertAdjacentHTML("beforeBegin",a);this.renderToolbar();this.renderEditorArea();this.makeEditable();this.attachEventListener();this.isLightFont=false};BdEditor.prototype.setCookie=function(a,b){document.cookie=a+"="+escape(b)+";expires=Wed, 28-Nov-02 01:45:46 GMT;path=/;domain=.baidu.com";document.cookie=a+"="+escape(b)+";expires=Wed, 28-Nov-37 01:45:46 GMT;path=/"};BdEditor.prototype.getCookie=function(c){var a,b=new RegExp("(^| )"+c+"=([^;]*)(;|$)");if(a=document.cookie.match(b)){return unescape(a[2])}};BdEditor.prototype.renderToolbar=function(){var e=["<div class='ToolbarStrip'><table border='0' cellspacing='0' cellpadding='0'><tr>"];var a=["_TiSmiley"];if(_BdBrowser.ie){a=["_TiSmiley","_LightFont"]}for(var f=0,g=a.length;f<g;f++){var c=this.modules[a[f]]=new window[a[f]]();if(f==1){var d='<input  type="checkbox" name="_LightFont" id="_LightFont'+this.hashCode+'" onclick="switchLightFont(this.checked)" />';e.push("<td width='100%'  align='right' valign='middle'><div class='ToolbarItem'>"+d+"</div></td>")}var b=(f==0)?"nowrap='nowrap'":"";e.push("<td nowrap='nowrap'>"+c.render()+"</td>")}"editor.lightFontModule.switchLightFont";e.push("</tr></table></div>");var h=_Bd$("editor_toolbar_"+this.hashCode);h.innerHTML=e.join("");if(_BdBrowser.ie){this.lightFontModule=_Bd$("_LightFont"+this.hashCode);this.lightFontModule.handler=this;this.lightFontColor="#0000FF";this.lightFontModule.switchLightFont=function(j){this.handler.isLightFont=j;var l=j?this.handler.lightFontColor:"0";if(l!="0"){l=l.replace("#","")}this.handler.setCookie("BDLFONT",l);if(!j){var k=this.handler.modules._LightFont.layer;if(k){k.hide()}}};var i=this.getCookie("BDLFONT");if(typeof i=="undefined"){i="0"}if(i!="0"){this.lightFontModule.checked=true;this.lightFontModule.switchLightFont(true);_Bd$("LightFont_Font_"+this.hashCode).style.color="#"+i;this.lightFontColor="#"+i;this.setCookie("BDLFONT",i)}else{this.lightFontModule.checked=false;this.lightFontModule.switchLightFont(false);_Bd$("LightFont_Font_"+this.hashCode).style.color="#0000FF";this.lightFontColor="#0000FF";this.setCookie("BDLFONT",i)}}};BdEditor.prototype.renderEditorArea=function(){var editor_area=_Bd$("editor_area_"+this.hashCode);editor_area.innerHTML="<iframe width='100%' height='"+this.height+"' frameborder='0' src='javascript:void(0)'></iframe>";this.iframe=editor_area.lastChild;var w=this.window=this.iframe.contentWindow;var d=this.document=this.window.document;d.open();d.write('<html><head><style type="text/css">    /*<![CDATA[*/    body{ background-color: #ffffff; padding: 5px 5px 5px 5px; margin: 0px; }     body, td { font-family: Arial, Verdana, sans-serif; font-size: 14px; }    p{ margin:0px; }    /*]]>*/    </style></head><body></body></html>');d.close();var code=";window.onerror=function(e){return true;}";if(window.execScript){w.execScript(code)}else{if(_BdBrowser.safari){var s=d.createElement("SCRIPT");s.type="text/javascript";s.appendChild(d.createTextNode(code));d.documentElement.appendChild(s)}else{eval.call(w,code)}}};BdEditor.prototype.makeEditable=function(){var b=this.document;if(_BdBrowser.ie){b.body.disabled=true;b.body.contentEditable=true;b.body.removeAttribute("disabled");try{b.execCommand("BackgroundImageCache",false,true)}catch(c){}}else{try{b.body.spellcheck=false;b.designMode="on";try{b.execCommand("styleWithCSS",false,false)}catch(d){b.execCommand("useCSS",false,true)}b.execCommand("enableObjectResizing",false,true);b.execCommand("enableInlineTableEditing",false,false)}catch(a){}}this.textarea.style.display="none"};BdEditor.prototype.attachEventListener=function(){var a=this,c=a.document;var b=function(){var e=a.modules._TiSmiley.layer;if(e){e.hide()}if(_BdBrowser.ie){e=a.modules._LightFont.layer;if(e){e.hide()}}};if(_BdBrowser.ie){c.body.attachEvent("onfocus",b)}else{c.addEventListener("focus",b,false)}if(!_BdBrowser.ie){return false}c.attachEvent("onbeforedeactivate",function(e){var f=c.selection;var g=f.createRange();a.ieSelectionType=f.type.toLowerCase();if("control"==a.ieSelectionType){a.ieSelectionControl=g(0)}else{a.ieSelectionBookmark=g.getBookmark()}});c.attachEvent("onactivate",function(e){var f;try{if("control"==a.ieSelectionType){f=c.body.createControlRange();f.add(a.ieSelectionControl)}else{f=c.body.createTextRange();f.moveToBookmark(a.ieSelectionBookmark)}f.select();a.ieSelectionControl=a.ieSelectionBookmark=null}catch(e){}});function d(){var e=c.selection;var f=e.type.toLowerCase();if("control"==f){var h=e.createRange();for(var g=h.length-1;g>=0;g--){h(g).parentNode.removeChild(h(g))}return false}return true}c.attachEvent("onkeydown",function(e){var e=a.window.event||e;var f=e.which||e.keyCode||e.charCode;var h=0;if(e.ctrlKey||e.metaKey){h+=1000}if(e.shiftKey){h+=2000}if(e.altKey){h+=4000}var g=f+h;if(g==8){return(e.returnValue=d())}return(e.returnValue=true)});return false};BdEditor.prototype.getHtml=function(){var b=this.document.body.innerHTML.replace(/<(p|div)[^>]*>/gi,"<br/>").replace(/<\/\s*(p|div)\s*>/gi,"");var a=b.replace(/^(<br([^>])*\/?>)+/gi,"");if(_BdBrowser.ie){if(this.lightFontModule.checked){a='<span style="filter:glow(color='+this.lightFontColor+',strength=2);height:0px;color:#FFFFFF">'+a+"</span>"}}return a};function _ToolbarItemBase(){this.tooltipname="";this.tooltip="";this.cssName="Lightfont";this.commandName="";this.disabled=false;this.editor=BdEditor.instance;_Instance[this.hashCode=uniqueID()]=this}_System.extend(_ToolbarItemBase.prototype,{execute:function(){},render:function(){var a="<div class='ToolbarItem' title='"+this.tooltip+"' id='ToolbarItem_{0}'  onclick=\"_Instance['{0}'].clickHandler(this)\" onmouseup=\"_Instance['{0}'].mouseUpHandler(this)\" onmousedown=\"_Instance['{0}'].mouseDownHandler(this)\" onmouseout=\"_Instance['{0}'].mouseOutHandler(this)\" onmouseover=\"_Instance['{0}'].mouseOverHandler(this)\" ><div class='img "+this.cssName+"' alt='"+this.tooltip+"' /><font style='font-size:12px'>"+this.tooltipname+"</font></div>";return a.format(this.hashCode)},getContainer:function(){return _Bd$("ToolbarItem_"+this.hashCode)},_ac:function(a){_BdElement.addClassName(this.getContainer(),a)},_rc:function(a){_BdElement.removeClassName(this.getContainer(),a)},mouseUpHandler:function(a){if(!this.disabled){this._rc("mousedown")}},mouseDownHandler:function(a){if(!this.disabled){this._ac("mousedown")}},mouseOutHandler:function(a){if(!this.disabled){this._rc("mouseover");this._rc("mousedown")}},mouseOverHandler:function(a){if(!this.disabled){this._ac("mouseover")}},clickHandler:function(){if(this.disabled){return}this.execute();if(!_BdBrowser.ie){this.editor.window.focus()}}});function _LightFont(){_ToolbarItemBase.call(this);this.tooltip="\u95ea\u5149\u5b57";this.tooltipname='<font id="LightFont_Font_'+parent.BdEditor.instance.hashCode+'" style="font-size:10px; color:#000000;">\u25bc</font>&nbsp;\u95ea\u5149\u5b57';this.layer=_BdPopupLayer.provider();this.layer.exclusive=true;this._isFirstExecute=true;this._isCreated=false;this.disabled=false;this.initialize()}_LightFont.Extends(_ToolbarItemBase);_LightFont.prototype.initialize=function(){var a=this;this.layer.onshow=function(){var b=a.getContainer();b.onmouseover=b.onmouseout=function(){return false};a._ac("mouseover")};this.layer.onhide=function(){var b=a.getContainer();b.onmouseover=function(){a.mouseOverHandler(this)};b.onmouseout=function(){a.mouseOutHandler(this)};a._rc("mouseover")}};_LightFont.prototype.clickHandler=function(){if(!this._isCreated){this._isCreated=true;var g=["00","33","66","99","cc","ff","00","33","66","99","cc","ff"];var c=[];var d,e,i;for(var m=0;m<12;m++){d=g[m];for(var n=0;n<3;n++){if(m>=6){i=g[n+3]}else{i=g[n]}for(var f=0;f<6;f++){e=g[f];c[c.length]="#"+i+e+d}}}var j=['<table width="199px" height="133px" cellspacing="1" cellpadding="0" bgcolor="#000000" >'];var h=0;var b=_BdBrowser.ie?10:8;for(var m=0;m<12;m++){j.push("<tr>");for(var n=0;n<18;n++){var a=c[h++];j.push('<td bgcolor="'+a+'" width="10px" height="10px" style="cursor:pointer;font-size:1px"><div style="width:'+b+"px; height:"+b+"px; border:#000 solid 0px\" onmouseover=\"parent.BdEditor.instance.modules['_LightFont'].over(this);\" onmouseout=\"parent.BdEditor.instance.modules['_LightFont'].out(this);\" onclick=\"parent.BdEditor.instance.modules['_LightFont'].execute('"+a+"',this);\"></div></td>")}j.push("</tr>")}j.push("</table>");c=g=i=e=d=b=h=null;var k=j.join("");var l=["<html><head><title>color panel</title></head><body>"];l.push('<div id="colorPanel" style="width:180px;height:120px">');l.push(k);l.push("</div></body></html>");l=l.join("");this.layer.write(l);this.layer.style.border="solid 1px #A9CCDD"}else{}this.layer.style.height="133px";this.layer.showByXYWH(this.getContainer(),-125,0,_BdBrowser.ie?"201":"201",_BdBrowser.ie?"135":"135")};_LightFont.prototype.execute=function(a,b){b.style.border="#000 solid 0px";var c=this;c.layer.hide();parent.BdEditor.instance.lightFontColor=a;_Bd$("LightFont_Font_"+parent.BdEditor.instance.hashCode).style.color=a;if(_Bd$("_LightFont"+parent.BdEditor.instance.hashCode).checked){parent.BdEditor.instance.setCookie("BDLFONT",a.replace("#",""))}};_LightFont.prototype.over=function(a){a.style.border="#000 solid 1px"};_LightFont.prototype.out=function(a){a.style.border="#000 solid 0px"};function _TiSmiley(){_ToolbarItemBase.call(this);this.tabFlags=[0,0,0,0,0];this.tooltip="\u63d2\u5165\u8868\u60c5";this.tooltipname="\u63d2\u5165\u8868\u60c5";this.cssName="Smiley";this.commandName="InsertSmiley";this.smileyPath="http://img.baidu.com/hi/face/";this.smileyImages=[];this.layer=_BdPopupLayer.provider();this.layer.exclusive=true;this._isFirstExecute=true;this.initialize()}_TiSmiley.Extends(_ToolbarItemBase);_TiSmiley.prototype.initialize=function(){var a=this;this.layer.onshow=function(){var b=a.getContainer();b.onmouseover=b.onmouseout=function(){return false};a._ac("mouseover")};this.layer.onhide=function(){var b=a.getContainer();b.onmouseover=function(){a.mouseOverHandler(this)};b.onmouseout=function(){a.mouseOutHandler(this)};a._rc("mouseover")}};_TiSmiley.prototype.over=function(b,a){var c=this.layer.getElementById("tabIconReview");this.layer.getElementById("faceReview").style.backgroundImage="url("+b+")";if(a==1){c.style.display="block";c.style.left="4px";c.style.top="3px"}else{c.style.display="block";c.style.left="228px";c.style.top="3px"}};_TiSmiley.prototype.out=function(b){var a=this.layer.getElementById("tabIconReview");a.style.display="none"};_TiSmiley.prototype.switchTab=function(d){var e=7;if(d==4){this.layer.getElementById("tab4").style.height="150px"}for(var c=0;c<e;c++){var b=this.layer.getElementById("tab"+c);var a=this.layer.getElementById("tab"+c+"M");if(c==d){if(this.tabFlags[d]==0){this.tabFlags[d]=1;this.createTab("tab"+d)}b.style.display="block";a.className="tabMenuHover"}else{b.style.display="none";a.className="tabMenuNoHover"}}};FCKConfig={};FCKConfig.SmileyInfor={tab0:[],tab1:[],tab2:[],tab3:[],tab4:[],tab5:[],tab6:[]};FCKConfig.SmileyInfor.tab0=["Kiss","Love","Yeah","\u554a\uff01","\u80cc\u626d","\u9876","\u6296\u80f8","88","\u6c57","\u778c\u7761","\u9c81\u62c9","\u62cd\u7816","\u63c9\u8138","\u751f\u65e5\u5feb\u4e50","\u5927\u7b11","\u7011\u5e03\u6c57~","\u60ca\u8bb6","\u81ed\u7f8e","\u50bb\u7b11","\u629b\u5a9a\u773c","\u53d1\u6012","\u6253\u9171\u6cb9","\u4fef\u5367\u6491","\u6c14\u6124","\u56e7","\u543b","\u6012","\u80dc\u5229","HI","KISS","\u4e0d\u8bf4","\u4e0d\u8981","\u626f\u82b1","\u5927\u5fc3","\u9876","\u5927\u60ca","\u98de\u543b","\u9b3c\u8138","\u5bb3\u7f9e","\u53e3\u6c34","\u72c2\u54ed","\u6765","\u53d1\u8d22\u4e86","\u5403\u897f\u74dc","\u5957\u7262","\u5bb3\u7f9e","\u5e86\u795d","\u6211\u6765\u4e86","\u6572\u6253","\u6655\u4e86","\u80dc\u5229","\u81ed\u7f8e","\u88ab\u6253\u4e86","\u8d2a\u5403","\u8fce\u63a5","\u9177","","","","","","","","","","","","","","","\u5f00\u5fc3","\u5077\u7b11","\u5927\u54ed","\u6ef4\u6c57","\u53f9\u6c14","\u8d85\u8d5e","\u56e7\u56e7","\u98de\u543b","\u5929\u4f7f","\u6492\u82b1","\u751f\u6c14","\u88ab\u7838","\u5413\u50bb","\u968f\u610f\u5410"];FCKConfig.SmileyInfor.tab1=["Kiss","Love","Yeah","\u554a\uff01","\u80cc\u626d","\u9876","\u6296\u80f8","88","\u6c57","\u778c\u7761","\u9c81\u62c9","\u62cd\u7816","\u63c9\u8138","\u751f\u65e5\u5feb\u4e50","\u644a\u624b","\u7761\u89c9","\u762b\u5750","\u65e0\u804a","\u661f\u661f\u95ea","\u65cb\u8f6c","\u4e5f\u4e0d\u884c","\u90c1\u95f7","\u6b63Music","\u6293\u5899","\u649e\u5899\u81f3\u6b7b","\u6b6a\u5934","\u6233\u773c","\u98d8\u8fc7","\u4e92\u76f8\u62cd\u7816","\u780d\u6b7b\u4f60","\u6254\u684c\u5b50","\u5c11\u6797\u5bfa","\u4ec0\u4e48\uff1f","\u8f6c\u5934","\u6211\u7231\u725b\u5976","\u6211\u8e22","\u6447\u6643","\u6655\u53a5","\u5728\u7b3c\u5b50\u91cc","\u9707\u8361"];FCKConfig.SmileyInfor.tab2=["\u5927\u7b11","\u7011\u5e03\u6c57~","\u60ca\u8bb6","\u81ed\u7f8e","\u50bb\u7b11","\u629b\u5a9a\u773c","\u53d1\u6012","\u6211\u9519\u4e86","money","\u6c14\u6124","\u6311\u9017","\u543b","\u6012","\u80dc\u5229","\u59d4\u5c48","\u53d7\u4f24","\u8bf4\u5565\u5462\uff1f","\u95ed\u5634","\u4e0d","\u9017\u4f60\u73a9\u513f","\u98de\u543b","\u7729\u6655","\u9b54\u6cd5","\u6211\u6765\u4e86","\u7761\u4e86","\u6211\u6253","\u95ed\u5634","\u6253","\u6253\u6655\u4e86","\u5237\u7259","\u7206\u63cd","\u70b8\u5f39","\u5012\u7acb","\u522e\u80e1\u5b50","\u90aa\u6076\u7684\u7b11","\u4e0d\u8981\u4e0d\u8981","\u7231\u604b\u4e2d","\u653e\u5927\u4ed4\u7ec6\u770b","\u5077\u7aa5","\u8d85\u9ad8\u5174","\u6655","\u677e\u53e3\u6c14","\u6211\u8dd1","\u4eab\u53d7","\u4fee\u517b","\u54ed","\u6c57","\u554a~","\u70ed\u70c8\u6b22\u8fce","\u6253\u9171\u6cb9","\u4fef\u5367\u6491","\u56e7"];FCKConfig.SmileyInfor.tab3=["HI","KISS","\u4e0d\u8bf4","\u4e0d\u8981","\u626f\u82b1","\u5927\u5fc3","\u9876","\u5927\u60ca","\u98de\u543b","\u9b3c\u8138","\u5bb3\u7f9e","\u53e3\u6c34","\u72c2\u54ed","\u6765","\u6cea\u773c","\u6d41\u6cea","\u751f\u6c14","\u5410\u820c","\u559c\u6b22","\u65cb\u8f6c","\u518d\u89c1","\u6293\u72c2","\u6c57","\u9119\u89c6","\u62dc","\u5410\u8840","\u5618","\u6253\u4eba","\u8e66\u8df3","\u53d8\u8138","\u626f\u8089","\u5403To","\u5403\u82b1","\u5439\u6ce1\u6ce1\u7cd6","\u5927\u53d8\u8eab","\u98de\u5929\u821e","\u56de\u7738","\u53ef\u601c","\u731b\u62bd","\u6ce1\u6ce1","\u82f9\u679c","\u4eb2","","\u9a9a\u821e","\u70e7\u9999","\u7761","\u5957\u5a03\u5a03","\u6345\u6345","\u821e\u5012","\u897f\u7ea2\u67ff","\u7231\u6155","\u6447","\u6447\u6446","\u6742\u800d","\u62db\u8d22","\u88ab\u6bb4","\u88ab\u7403\u95f7","\u5927\u60ca","\u7406\u60f3","\u6b27\u6253","\u5455\u5410","\u788e","\u5410\u75f0"];FCKConfig.SmileyInfor.tab4=["\u53d1\u8d22\u4e86","\u5403\u897f\u74dc","\u5957\u7262","\u5bb3\u7f9e","\u5e86\u795d","\u6211\u6765\u4e86","\u6572\u6253","\u6655\u4e86","\u80dc\u5229","\u81ed\u7f8e","\u88ab\u6253\u4e86","\u8d2a\u5403","\u8fce\u63a5","\u9177","\u9876","\u5e78\u8fd0","\u7231\u5fc3","\u8eb2","\u9001\u82b1","\u9009\u62e9"];FCKConfig.SmileyInfor.tab5=["","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""];FCKConfig.SmileyInfor.tab6=["\u7537\u515c","\u5973\u515c","\u5f00\u5fc3","\u4e56\u4e56","\u5077\u7b11","\u5927\u7b11","\u62bd\u6ce3","\u5927\u54ed","\u65e0\u5948","\u6ef4\u6c57","\u53f9\u6c14","\u72c2\u6655","\u59d4\u5c48","\u8d85\u8d5e","\u56e7\u56e7","\u7591\u95ee","\u98de\u543b","\u5929\u4f7f","\u6492\u82b1","\u751f\u6c14","\u88ab\u7838","\u53e3\u6c34","\u6cea\u5954","\u5413\u50bb","\u5410\u820c\u5934","\u70b9\u5934","\u968f\u610f\u5410","\u65cb\u8f6c","\u56f0\u56f0","\u9119\u89c6","\u72c2\u9876","\u7bee\u7403","\u518d\u89c1","\u6b22\u8fce\u5149\u4e34","\u606d\u559c\u53d1\u8d22","\u7a0d\u7b49","\u6211\u5728\u7ebf","\u6055\u4e0d\u8bae\u4ef7","\u5e93\u623f\u6709\u8d27","\u8d27\u5728\u8def\u4e0a"];FCKConfig.SmileyBox={tab0:[],tab1:[],tab2:[],tab3:[],tab4:[],tab5:[],tab6:[]};function initImgBox(c,b,e){if(c.length){return}var a="";for(var d=1;d<=e;d++){a=b;if(d<10){a=a+"0"}a=a+d+".gif";c.push(a)}}initImgBox(FCKConfig.SmileyBox.tab0,"j_00",84);initImgBox(FCKConfig.SmileyBox.tab1,"t_00",40);initImgBox(FCKConfig.SmileyBox.tab2,"w_00",52);initImgBox(FCKConfig.SmileyBox.tab3,"B_00",63);initImgBox(FCKConfig.SmileyBox.tab4,"C_00",20);initImgBox(FCKConfig.SmileyBox.tab5,"i_f",50);initImgBox(FCKConfig.SmileyBox.tab6,"y_00",40);var faceBox=FCKConfig.SmileyBox;var inforBox=FCKConfig.SmileyInfor;_TiSmiley.prototype.createTab=function(x){var q=_System.imagePath;var s="?v=1.1";FaceHandler={imageFolders:{tab0:"jx2/",tab1:"tsj/",tab2:"ldw/",tab3:"bobo/",tab4:"babycat/",tab5:"face/",tab6:"youa/"},imageReviewFolders:{tab0:"jx_review/",tab1:"tsj_review/",tab2:"bobo_review/",tab3:"tsj_review/",tab4:"babycat_review/",tab5:"face/",tab6:"youa/"},imageWidth:{tab0:36,tab1:35,tab2:35,tab3:36,tab4:35,tab5:25,tab6:35},imageCols:{tab0:7,tab1:7,tab2:7,tab3:7,tab4:7,tab5:7,tab6:7},imageColWidth:{tab0:35,tab1:35,tab2:35,tab3:35,tab4:35,tab5:35,tab6:35},tableWidth:{tab0:263,tab1:280,tab2:263,tab3:263,tab4:280,tab5:263,tab6:280},imageCss:{tab0:"jd",tab1:"tsj",tab2:"ldw",tab3:"bb",tab4:"cat",tab5:"pp",tab6:"youa"},imageCssOffset:{tab0:35,tab1:35,tab2:35,tab3:35,tab4:35,tab5:25,tab6:35}};var m=q+FaceHandler.imageFolders[x];var k=q+FaceHandler.imageReviewFolders[x];var d=FaceHandler.tableWidth;var n=FaceHandler.imageWidth;var c=FaceHandler.imageCols[x];var o=c/2;var i=FaceHandler.imageColWidth;var w=FaceHandler.imageCss[x];var p=FaceHandler.imageCssOffset[x];var u=this.layer.getElementById(x);var l=['<table cellpadding="0" cellspacing="0"  style="border-collapse:collapse;" border="1" bordercolor="#B8B3FF" width='+d[x]+'  height="100%">'];for(var f=0,v=faceBox[x].length;f<v;){l.push("<tr>");for(var g=0;g<c;g++,f++){var e=faceBox[x][f];if(e){var j=m+e+s;var a=m+e;var h=k+e;var t=g<o?0:1;var r=p*f*(-1)-1;var b=inforBox[x][f];l.push('<td width="'+i[x]+'"  height="'+i[x]+'" align="center" valign="middle" style="background-color:#FFFFFF;" onmouseover="this.style.backgroundColor=\'#E8E8FD\'"  onmouseout="this.style.backgroundColor=\'#FFFFFF\'" >');l.push('<span class="'+w+'"  style="display:block;">');l.push('<img title="'+b+'" style="background-position:left '+r+'px;"  width="'+n[x]+'" height="'+n[x]+"\" onclick=\"parent.BdEditor.instance.modules['_TiSmiley'].execute('"+a+"');\" src=\"http://img.baidu.com/hi/default/0.gif\" onmouseover=\"parent.BdEditor.instance.modules['_TiSmiley'].over('"+j+"',"+t+');"  onmouseout="parent.BdEditor.instance.modules[\'_TiSmiley\'].out();" /></td>');l.push("</span>")}else{l.push("<td>&nbsp;")}l.push("</td>")}l.push("</tr>")}l.push("</table>");l=l.join("");u.innerHTML=l};_TiSmiley.prototype.clickHandler=function(){this.tabFlags=[0,0,0,0,0,0,0];var a=[];a.push('<div id="tabPanel" class="tabPanel" >');a.push('	<div id="tabContent" class="tabContent">');a.push('		<div id="tab0" class="tabContentShow">0__tabContent</div>');a.push('		<div id="tab1" class="tabContentHide">1__tabContent</div>');a.push('		<div id="tab2" class="tabContentHide">2__tabContent</div>');a.push('		<div id="tab3" class="tabContentHide">3__tabContent</div>');a.push('      	<div id="tab4" class="tabContentHide">4__tabContent</div>');a.push('         <div id="tab5" class="tabContentHide">5__tabContent</div>');a.push('         <div id="tab6" class="tabContentHide">6__tabContent</div>');a.push("	</div>");a.push('	<div id="tabMenu" class="tabMenu" >');a.push('		<div id="tab0M" class="tabMenuHover"   		onClick="parent.BdEditor.instance.modules[\'_TiSmiley\'].switchTab(0)">&nbsp;&nbsp;&nbsp;<u>\u7cbe\u9009</u>&nbsp;&nbsp;&nbsp;</div>');a.push('		<div id="tab1M" class="tabMenuNoHover" 	onClick="parent.BdEditor.instance.modules[\'_TiSmiley\'].switchTab(1)">&nbsp;<u>\u5154\u65af\u57fa</u>&nbsp;</div>');a.push('		<div id="tab2M" class="tabMenuNoHover" 	onClick="parent.BdEditor.instance.modules[\'_TiSmiley\'].switchTab(2)">&nbsp;<u>\u7eff\u8c46\u86d9</u>&nbsp;</div>');a.push('		<div id="tab3M" class="tabMenuNoHover" 	onClick="parent.BdEditor.instance.modules[\'_TiSmiley\'].switchTab(3)">&nbsp;&nbsp;<u>BOBO</u>&nbsp;&nbsp;</div>');a.push('       <div id="tab4M" class="tabMenuNoHover" 	onClick="parent.BdEditor.instance.modules[\'_TiSmiley\'].switchTab(4)">&nbsp;&nbsp;<u>baby\u732b</u>&nbsp;&nbsp;</div>');a.push('       <div id="tab5M" class="tabMenuNoHover" 	onClick="parent.BdEditor.instance.modules[\'_TiSmiley\'].switchTab(5)">&nbsp;&nbsp;<u>\u6ce1\u6ce1</u>&nbsp;&nbsp;</div>');a.push('       <div id="tab6M" class="tabMenuNoHover"    onClick="parent.BdEditor.instance.modules[\'_TiSmiley\'].switchTab(6)">&nbsp;&nbsp;<u>\u6709\u554a</u>&nbsp;&nbsp;</div>');a.push("	</div>");a.push("</div>");a.push('<div id="tabIconReview" class="tabStyle">');var b=_System.imagePath;a.push('<img id="faceReview" class="review"  src="http://img.baidu.com/hi/default/0.gif"/>');a.push("</div>");a=a.join("");this.layer.write(a);this.layer.style.border="solid 1px #A9CCDD";this.layer.showBy(this.getContainer(),_BdBrowser.ie?"346":"346",_BdBrowser.ie?"255":"255");this.createTab("tab0");this.switchTab(0)};_TiSmiley.prototype.execute=function(d){var i=this;i.layer.hide();i.editor.window.focus();if(_BdBrowser.ie){var f=i.editor.document.selection;var h=f.type.toLowerCase();if("control"==h){var e=f.createRange();var a=e(0);a.insertAdjacentHTML("beforeBegin",'<img src="'+d+'">');for(var b=e.length-1;b>=0;b--){e(b).parentNode.removeChild(e(b))}}else{var j=f.createRange();j.pasteHTML('<img src="'+d+'"/>')}}else{var c=i.editor.document.createElement("IMG");c.src=d;var f=i.editor.window.getSelection();var j=f.getRangeAt(0);j.deleteContents();j.insertNode(c);var g=i.editor.document.createRange();g.selectNode(c);f.removeAllRanges();f.addRange(g);f.collapseToEnd();if(i._isFirstExecute){i.editor.document.execCommand("insertHTML",false,"<br>\x00");i._isFirstExecute=false}}};