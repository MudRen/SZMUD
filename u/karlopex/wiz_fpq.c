//code for shenzhou
//��ʦ��������
//create by Karlopex@sz

#include <ansi.h>
#include "/clone/misc/string.h"
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define WIZFGS NPCDATA + "wiz_fg"
#define WIZFPQ "/clone/wiz/wiz_fpq"
inherit F_SAVE;
inherit ITEM;
string query_save_file()
{
	return WIZFGS;
}
void create()
{
	set_name("��ʦ���������", ({"wizard renwu", "wiz_rw"}));
	set_weight(0);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("long", "��ʦ�����������\n");
		set("unit", "̨");
		set("material", "iron");
		set("value", 0);
	}
	seteuid(getuid());
	if (!restore()) save();
}
void set_group(string grp_name, string name) { 
	restore();
	this_object()->set("group/"+grp_name+"/name", name);
	save();
}
void delete_group(string grp_name) { 
	restore();
	this_object()->delete("group/"+grp_name, 1);
	save();
}
void delete_wizard_renwu(string wiz_name) { 
	restore();
	this_object()->delete("wiz_renwu/"+wiz_name, 1);
	save();
}
void delete_wizard_chengyuan(string grp_name, string wiz_name) { 
	restore();
	this_object()->delete("group/"+grp_name+"/chengyuan/"+wiz_name, 1);
	save();
}
void set_group_chengyuan(string grp_name, string zhiwei, string name, int a) { 
	object ob;
	restore();
	if (!objectp(ob = find_player(name)))
	{
		ob = new(USER_OB);
	        ob->set("id", name);   
		if( !ob->restore() ) {
			destruct(ob);
	                write(name+"�����޴��ˡ�\n");
			return;
		}
	}
	this_object()->set("group/"+grp_name+"/chengyuan/"+name+"/zhiwei", zhiwei);
	this_object()->set("group/"+grp_name+"/chengyuan/"+name+"/name", ob->query("name"));
	if (a == 2) this_object()->set("group/"+grp_name+"/chengyuan/"+name+"/attrib"+grp_name, "player");
	if (!objectp(ob)) destruct(ob);
	save();
}
void set_group_renwu(string grp_name, string renwu, int a) { 
	restore();
	this_object()->set("group/"+grp_name+"/renwu", renwu);
	if (a == 2) this_object()->set("group/"+grp_name+"/attrib", "player");
	save();
}
void set_group_yinxiang(string grp_name, string yinxiang, int a) { 
	restore();
	this_object()->set("group/"+grp_name+"/yinxiang", yinxiang);
	if (a == 2) this_object()->set("group/"+grp_name+"/attrib", "player");
	save();
}
void set_wizard_renwu(string name, string renwu, string i, int a) { 
	object ob;
	restore();
	if (!objectp(ob = find_player(name)))
	{
		ob = new(USER_OB);
	        ob->set("id", name);   
		if( !ob->restore() ) {
			destruct(ob);
	                write(name+"�����޴��ˡ�\n");
			return;
		}
	}
	this_object()->set("wiz_renwu/"+name+"/renwu/"+i, renwu);
	if (a == 2) this_object()->set("wiz_renwu/"+name+"/renwu/attrib"+i, "player");
	if (!objectp(ob)) destruct(ob);
	save();
}
void set_wizard_yinxiang(string name, string yinxiang, string i, int a) { 
	object ob;
	restore();
	if (!objectp(ob = find_player(name)))
	{
		ob = new(USER_OB);
	        ob->set("id", name);   
		if( !ob->restore() ) {
			destruct(ob);
	                write("���޴��ˡ�\n");
			return;
		}
	}
	this_object()->set("wiz_renwu/"+name+"/yinxiang/"+i, yinxiang);
	if (a == 2) this_object()->set("wiz_renwu/"+name+"/yinxiang/attrib"+i, "player");
	if (!objectp(ob)) destruct(ob);
	save();
}
string query_group(object me) { 
	mapping group;
	string *wiz_grp, wizlist;
	int i;
	restore();
	group = this_object()->query("group");
	if (!mapp(group) || sizeof(keys(group)) == 0)
		return string_m("Ŀǰ��û��Ϊ��ʦ���顣", 64)+"\n";
	wiz_grp = keys(group);
	for(wizlist = "", i=0; i<sizeof(wiz_grp); i++)
		wizlist += sprintf("%10s������%s\n", string_m(wiz_grp[i], 10), group[wiz_grp[i]]["name"]);
	return "Ŀǰ��"+chinese_number(sizeof(wiz_grp))+"���飬�ֱ��ǣ�\n"+wizlist;
}

string query_group_chengyuan(object me) { 
	mapping group, group_e;
	string *wiz_grp, wizlist, *wiz_cy;
	int i, j;
	restore();
	group = this_object()->query("group");
	if (!mapp(group) || sizeof(keys(group)) == 0)
		return string_m("Ŀǰ��û��Ϊ��ʦ���顣", 64)+"\n";
	wiz_grp = keys(group);
	for(wizlist = "", i=0; i<sizeof(wiz_grp); i++){
		wizlist += group[wiz_grp[i]]["name"]+"("+wiz_grp[i]+")�������������£�\n";
		group_e = group[wiz_grp[i]]["chengyuan"];
		if (!mapp(group_e) || sizeof(keys(group_e)) == 0) continue;
		wiz_cy = keys(group_e);
		for(j=0; j<sizeof(wiz_cy); j++)
			wizlist += sprintf("%10s��%s(%s)\n",string_m(group_e[wiz_cy[i]]["zhiwei"], 10), group_e[wiz_cy[i]]["name"], wiz_cy[i]);
	}
	return "Ŀǰ��"+chinese_number(sizeof(wiz_grp))+"���飬�����Ա�������£�\n"+wizlist;
}
string query_group_renwu(object me) { 
	mapping group;
	string *wiz_grp, wizlist;
	int i;
	restore();
	group = this_object()->query("group");
	if (!mapp(group) || sizeof(keys(group)) == 0)
		return string_m("Ŀǰ��û��Ϊ��ʦ���顣", 64)+"\n";
	wiz_grp = keys(group);
	for(wizlist = "", i=0; i<sizeof(wiz_grp); i++){
		if (!wizardp(me) && group[wiz_grp[i]]["attrib"] != "player") continue;
		wizlist += sprintf("%-20s�������ǣ�%s\n",group[wiz_grp[i]]["name"]+"("+wiz_grp[i]+")", group[wiz_grp[i]]["renwu"]);
	}
	return "Ŀǰ��"+chinese_number(sizeof(wiz_grp))+"���飬����������ֱ��ǣ�\n"+wizlist;
}
string query_group_yinxiang(object me) { 
	mapping group;
	string *wiz_grp, wizlist;
	int i;
	restore();
	group = this_object()->query("group");
	if (!mapp(group) || sizeof(keys(group)) == 0)
		return string_m("Ŀǰ��û��Ϊ��ʦ���顣", 64)+"\n";
	wiz_grp = keys(group);
	for(wizlist = "", i=0; i<sizeof(wiz_grp); i++){
		if (!wizardp(me) && group[wiz_grp[i]]["attrib"] != "player") continue;
		wizlist += sprintf("%-20s�������ǣ�%s��%s��\n",group[wiz_grp[i]]["name"]+"("+wiz_grp[i]+")",group[wiz_grp[i]]["renwu"],group[wiz_grp[i]]["yinxiang"]);
	}
	return "Ŀǰ��"+chinese_number(sizeof(wiz_grp))+"���飬��������\n"+wizlist;
}
string query_wizard_renwu(object me) { 
	mapping group, group_e, renwu;
	string *wiz_grp, wizlist, *wiz_cy, *wiz_rw;
	int i, j, k;
	restore();
	group = this_object()->query("group");
	if (!mapp(group) || sizeof(keys(group)) == 0)
		return string_m("Ŀǰ��û��Ϊ��ʦ���顣", 64)+"\n";
	wiz_grp = keys(group);
	for(wizlist = "", i=0; i<sizeof(wiz_grp); i++){
		wizlist += sprintf("%s", group[wiz_grp[i]]["name"]+"("+wiz_grp[i]+")")+setcolor("$SPARK$===>")+group[wiz_grp[i]]["renwu"];
		group_e = group[wiz_grp[i]]["chengyuan"];
		if (!mapp(group_e) || sizeof(keys(group_e)) == 0){
			wizlist += "\n";
			continue;
		}
		wizlist +="��\n";
		wiz_cy = keys(group_e);
		for(j=0; j<sizeof(wiz_cy); j++){
			if (wiz_cy[j] == "attrib") continue;
			if (!wizardp(me) && group_e[wiz_cy[j]]["attrib"] != "player") continue;
			wizlist += sprintf("\t%20s��%s", string_m(group_e[wiz_cy[j]]["name"]+"("+wiz_cy[j]+")",20), group_e[wiz_cy[j]]["zhiwei"]);
			renwu = this_object()->query("wiz_renwu/"+wiz_cy[i]);
			if (!mapp(renwu) || sizeof(keys(renwu)) == 0){
				wizlist += "\n";
				continue;
			}
			if (!stringp(renwu[wiz_grp[i]])){
				wizlist += "\n";
				continue;
			}
			wizlist += "   �������£�\n";
			if (!wizardp(me) && renwu["attrib"+wiz_grp[i]] != "player") continue;
			wizlist += sprintf("\t\t�����ǣ�%s\n",renwu["renwu"][wiz_grp[i]]);
		}
	}
	return "Ŀǰ��"+chinese_number(sizeof(wiz_grp))+"���飬�����Ա�������������£�\n"+wizlist;
}
string query_wizard_yinxiang(object me) { 
	mapping group, group_e, renwu;
	string *wiz_grp, wizlist, *wiz_cy, *wiz_rw, wiz_yx;
	int i, j, k;
	restore();
	group = this_object()->query("group");
	if (!mapp(group) || sizeof(keys(group)) == 0)
		return string_m("Ŀǰ��û��Ϊ��ʦ���顣", 64)+"\n";
	wiz_grp = keys(group);
	for(wizlist = "", i=0; i<sizeof(wiz_grp); i++){
		wizlist += group[wiz_grp[i]]["name"]+"("+wiz_grp[i]+")"+setcolor("$SPARK$===>")+group[wiz_grp[i]]["renwu"];
		group_e = group[wiz_grp[i]]["chengyuan"];
		if (!mapp(group_e) || sizeof(keys(group_e)) == 0){
			wizlist += "\n";
			continue;
		}
		wizlist +="��\n";
		wiz_cy = keys(group_e);
		for(j=0; j<sizeof(wiz_cy); j++){
			if (wiz_cy[j] == "attrib") continue;
			if (!wizardp(me) && group_e[wiz_cy[j]]["attrib"] != "player") continue;
			wizlist += sprintf("\t%20s��%s", string_m(group_e[wiz_cy[j]]["name"]+"("+wiz_cy[j]+")",20), group_e[wiz_cy[j]]["zhiwei"]);
			renwu = this_object()->query("wiz_renwu/"+wiz_cy[j]);
			if (!mapp(renwu) || sizeof(keys(renwu)) == 0){
				wizlist += "\n";
				continue;
			}
			if (!stringp(renwu[wiz_grp[i]])){
				wizlist += "\n";
				continue;
			}
			wizlist += "   �������������£�\n";
			if (!mapp(renwu["yinxiang"]) || sizeof(keys(renwu["yinxiang"])) == 0)
				wiz_yx = "δ������";
			else wiz_yx = renwu["yinxiang"][wiz_grp[i]];
			if (!wizardp(me) && renwu["attrib"+wiz_grp[i]] != "player") continue;
			wizlist += sprintf("\t\t�����ǣ�%-40s%s\n",renwu["renwu"][wiz_grp[i]],"��"+wiz_yx+"��");
		}
	}
	return "Ŀǰ��"+chinese_number(sizeof(wiz_grp))+"���飬�����Ա�������������������£�\n"+wizlist;
}
void set_last(int time)
{
	restore();
	this_object()->set("last_time", time);
	save();
}
string query_time()
{
	int t;
        string msg;
        t = query("last_time");
 	msg = ctime(t);
        msg = msg[4..6] + "/" + msg[8..9] + "/" +
              msg[20..23] + " " + msg[11..18];
        return string_m("�����޸��ڣ�"+msg, 64);
}
