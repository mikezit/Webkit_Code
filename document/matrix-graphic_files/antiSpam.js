var userSpam={};userSpam.Alert=function(i,e,b,f){var a=b||350;var d=f||100;var c=e||"�ٱ�";var g=new Popup({contentType:4,isReloadOnClose:false,width:a,height:d});g.setContent("title",c);g.setContent("alertCon",i);g.build();g.show();return g};userSpam.ShowTextDialog=function(i,e,b,f){var a=b||500;var d=f||280;var c=e||"�ٱ�";var g=new Popup({contentType:2,isReloadOnClose:false,width:a,height:d});g.setContent("title",c);g.setContent("contentHtml",i);g.build();g.show();return g};userSpam.ShowTipOff=function(){var a='<div style="padding:10px;"><form onsubmit="if(userSpam.checkReason()) setTimeout(function(){userSpam.ShowTipOK();},500); else return false;" name="_antiSpamSubForm" id="_antiSpamSubForm" action="http://act.hi.baidu.com/userspam/submit" method="post" target="_antiSpamSubIfr">        <b>�ٶȿռ���������л������ٱ������ǻᾡ�촦�����ľٱ��� <br>�ռ�������ͬŬ��Ϊ�û��ṩ��ɫ�������Ļ���������������</b>        <div style="border-top:1px solid #ccc; margin-top:5px; height:5px; line-height:0; font-size:0;"> </div>            <input type="hidden" name="spSpamUser" value=""  />            <input type="hidden" name="spBlogID" value=""  />            <input type="hidden" name="spPhotoID" value=""  />            <input type="hidden" name="spMsgID" value=""  />            <input type="hidden" name="spSubType" value="" />            <textarea style="display:none;" name="spSubContent"></textarea>���ʵ�� <br>�����ھٱ����������£�            <div style="margin:10px 20px;padding:10px; border:1px solid #ccc; height:80px; overflow-y:auto;" id="_spSubContentShow"></div>����ȷ�ٱ����ɣ�����ѡ��            <div style="margin:10px 20px;padding:10px; border:1px solid #ccc;">            <label for="_spam_radio1" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="1" id="_spam_radio1" />���</label>            <label for="_spam_radio2" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="2" id="_spam_radio2" />ɧ�š�á��</label>            <label for="_spam_radio3" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="3" id="_spam_radio3" />�н�����թ��Ϣ</label><br>            <label for="_spam_radio4" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="4" id="_spam_radio4" />ɫ����Ϣ</label>            <label for="_spam_radio5" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="5" id="_spam_radio5" />��������</label>            <label for="_spam_radio6" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="6" id="_spam_radio6" />����</label>            <div style="clear:both;"></div>            </div>            <div align="center">            <input type="submit" value=" ȷ�� " />  <input type="button" name="" onclick="g_pop.close();" value=" ȡ�� "  />            </div>        </form>        <iframe style="display:none;" name="_antiSpamSubIfr"></iframe></div>';return userSpam.ShowTextDialog(a)};userSpam.ShowTipOK=function(){var b='<div style="padding:10px;">    <b>�ٶȿռ���������л������ٱ������ǻ����ȡ֤�󣬾��촦�����ľٱ��� <br>�ռ�������ͬŬ��Ϊ�û��ṩ��ɫ�������Ļ���������������</b>    <div style="border-top:1px solid #ccc; margin-top:5px; height:5px; line-height:0; font-size:0;"> </div>    <div style="padding:20px; text-align:center;"><img src="http://img.baidu.com/hi/img/antiuserok.gif" border="0" align="absmiddle" /> �ٱ���ɣ���л�����ύ</div>';var a=userSpam.ShowTextDialog(b,"",500,150);setTimeout(function(){a.close()},1000)};userSpam.submit=function(e,f,a,h,d,c){var b;b=g_pop=userSpam.ShowTipOff();var g=G("_antiSpamSubForm");G("_spSubContentShow").innerHTML=e;g.spSubContent.value=e;g.spSubType.value=f;g.spSpamUser.value=a;g.spMsgID.value=h;g.spBlogID.value=d;g.spPhotoID.value=c};userSpam.tipBlogCmt=function(g,j,a,e){var d=g.parentNode.parentNode.parentNode.parentNode.parentNode;var f=document.createElement("div");f.appendChild(d.cloneNode(true));var b=f.getElementsByTagName("span");for(var h=0,c=b.length;h<c;h++){if(b[h].className=="date"){b[h].parentNode.removeChild(b[h]);break}}userSpam.submit(f.innerHTML.replace('width="10%"','width="65"'),1,j,a,e)};userSpam.tipBoardCmt=function(f,e,d){var g=f.parentNode.parentNode.parentNode.parentNode.parentNode;var b=document.createElement("div");b.appendChild(g.cloneNode(true));var a=b.getElementsByTagName("span");for(var c=0,h=a.length;c<h;c++){if(a[c].className=="date"){a[c].parentNode.removeChild(a[c]);break}}userSpam.submit(b.innerHTML.replace('width="10%"','width="65"'),0,e,d)};userSpam.tipNoteCmt=function(j){var c=j.parentNode.parentNode.getElementsByTagName("div");var m,s,e,p,q,l="",b="",f="";for(var h=0,d=c.length;h<d;h++){if(c[h].getAttribute("name")=="cmtcontent"){m=c[h]}else{if(c[h].className=="userhead"){s=c[h]}else{if(c[h].className=="content"){e=c[h]}else{if(c[h].className=="remsg"){q=c[h]}}}}}if(e.innerHTML.indexOf("������")>-1&&e.innerHTML.indexOf("blog/item")>-1){p=1}else{if(e.innerHTML.indexOf("����")>-1&&e.innerHTML.indexOf("/board")>-1){p=0}}var o=e.getElementsByTagName("a");if(s.innerHTML.indexOf("/sys/portraitn/item")>-1){l=o[0].innerHTML}var r=q.getElementsByTagName("a")[0];if(p==1){var k=r.href.match(/\/blog\/item\/(\w+)\.html\/cmtid\/(\w+)#/);f=k[1];b=k[2]}else{if(p==0){var k=r.href.match(/\/board\/boardid\/(\w+)#/);b=k[1]}}var g=document.createElement("div");g.appendChild(m.cloneNode(true));var a=g.getElementsByTagName("div");for(var h=0,d=a.length;h<d;h++){if(a[h].className=="remsg"){a[h].parentNode.removeChild(a[h]);break}}userSpam.submit(g.innerHTML.replace('class="userhead"','style="float:left; width:70px;"').replace('class="content"','style="float:left; width:330px;"'),p,l,b,f)};userSpam.checkReason=function(){var c=G("_antiSpamSubForm");var a=c.spSubReason;for(var b=0,d=a.length;b<d;b++){if(a[b].checked){return true}}alert("��ѡ��ٱ�ԭ��");return false};