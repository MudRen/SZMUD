//Cracked by Kafei
// wizlist.c
// by rider 7-12-01

#include <ansi.h>
#include "/clone/misc/string.h"
inherit F_CLEAN_UP;
string repl(string msg, int a);
object data=load_object("/clone/wiz/wiz_fpq");
int main(object me, string arg)
{
	mapping groups, group_e, renwu;
	string *wiz_grp, wizlist, *wiz_cy, *wiz_rw, wiz_yx, g_rw;
	int i, j, k;

	data->restore();
	write(MUD_NAME + "Ŀǰ����ʦ���������\n");

	groups = data->query("group");
	if (!mapp(groups) || sizeof(keys(groups)) == 0){
		write(string_m("Ŀǰ��û��Ϊ��ʦ���顣", 64)+"\n");
		return 1;
	}
	wiz_grp = keys(groups);
	for(wizlist = "", i=0; i<sizeof(wiz_grp); i++){
		wizlist += repl("�� "+groups[wiz_grp[i]]["name"]+" ��", 64)+"\n";
		if (!stringp(groups[wiz_grp[i]]["renwu"]))
			wizlist += string_m(WHT"��������"NOR, 64)+"\n";
		else wizlist += string_m(groups[wiz_grp[i]]["renwu"], 64)+"\n";
		wizlist += "----------------------------------------------------------------\n";
		group_e = groups[wiz_grp[i]]["chengyuan"];
		if (!mapp(group_e) || sizeof(keys(group_e)) == 0) continue;
		wiz_cy = keys(group_e);
		for(j=0; j<sizeof(wiz_cy); j++){
			if (wiz_cy[j] == "attrib") continue;
//			if (!wizardp(me) && group_e[wiz_cy[j]]["attrib"] != "player") continue;
			wizlist += sprintf("%20s��%s\n", string_m(group_e[wiz_cy[j]]["name"]+"("+wiz_cy[j]+")",20), group_e[wiz_cy[j]]["zhiwei"]);
			renwu = data->query("wiz_renwu/"+wiz_cy[j]);
			if (!mapp(renwu) || sizeof(keys(renwu)) == 0) continue;
			if (!stringp(renwu["renwu"][wiz_grp[i]])) continue;
			if (!mapp(renwu["yinxiang"]) || sizeof(keys(renwu["yinxiang"])) == 0)
				wiz_yx = CYN"δ������"NOR;
			else wiz_yx = renwu["yinxiang"][wiz_grp[i]];
			if (!wizardp(me) && renwu["renwu"]["attrib"+wiz_grp[i]] != "player") continue;
			wizlist += sprintf("\t�ڴ˲��ŵ������ǣ�%-40s%s\n",renwu["renwu"][wiz_grp[i]],HIB"��"NOR+wiz_yx+HIB"��"NOR);
		}
		wizlist += "\n\n";
	}
	wizlist += "\n����������������������������������������������������������������\n\n";
	wizlist += data->query_time()+"\n";
	wizlist += "\n����������������������������������������������������������������";
	write(wizlist+"\n\n\n");
	return 1;
}
string repl(string msg, int a)
{
	string newstring, blk ="*******************************************************************************";
	int j, i = string_l(msg, 1);
	if ( a > i )
		j = ( a - i ) /2;
	else j = 0;
	msg = blk[0..(j-1)]+msg+blk[0..(j-1)];
	return msg;
}
int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}								