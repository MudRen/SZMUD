// Code of ShenZhou
//finger ��ǿ���ߣ����ڲ���robot�Ͷ��ص�½
// WriteBy wzfeng 99-2-2
#include <net/dns.h>
#include <ansi.h>
inherit ITEM;
int filter_time(object ob,int a)
{
        if(interactive(ob))
			if((int)query_idle(ob)>=(int)a*60)
        return 1;
        return 0;
}
string finger_idle(int a)
{
	object *ob;
	string msg, fip;
	int i;
	ob = filter_array(objects(), (: userp :));
	ob = filter_array(ob, (: filter_time :),a);
	if(!sizeof(ob))
		return "û�����������";
	msg="";
	for (i=0;i<sizeof(ob);i++)
			if (this_player()->visible(ob[i])) break;
		msg += sprintf("%-13s%-14s%-14s%-14s\n",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"������":query_idle(ob[i])/60 + "����"),
			query_ip_name(ob[i]));
			
		for(i=i+1; i<sizeof(ob); i++) {
			if( !this_player()->visible(ob[i]) ) continue;
		msg += sprintf("%-13s%-14s%-14s%-14s\n",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"������":query_idle(ob[i])/60 + "����"),
			query_ip_number(ob[i]) && query_ip_number(ob[i]) == query_ip_number(ob[i-1])?
				"��ַͬ��":query_ip_name(ob[i]));
			
		}
		return 
		"������������������������������������������������������������������������������\n"
		" ����         �ʺ�          ����          ���ߵ�ַ   \n" +
		"������������������������������������������������������������������������������\n"
		+ msg +
		"������������������������������������������������������������������������������\n"
		"* ��ʾ��¼��\n";
}

string finger_all()
{
	object *ob;
	string msg, fip;
	int i;

	ob = filter_array(objects(), (: userp :));
	msg="";
		for (i=0;i<sizeof(ob);i++)
			if (this_player()->visible(ob[i])) break;
		msg += sprintf("%s%-13s%-14s%-14s%-14s\n",
			environment(ob[i])?" ":"*",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"������":query_idle(ob[i])/60 + "����"),
			query_ip_name(ob[i]));
		for(i=i+1; i<sizeof(ob); i++) {
			if( !this_player()->visible(ob[i]) || ob[i]->query("blocked" ) ) continue;     
			msg += sprintf("%s%-13s%-14s%-14s%-14s\n",
			environment(ob[i])?" ":"*",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"������":query_idle(ob[i])/60 + "����"),
			query_ip_number(ob[i]) && query_ip_number(ob[i]) == query_ip_number(ob[i-1])?
				"��ַͬ��":query_ip_name(ob[i]));
		
		}
		return 
		"������������������������������������������������������������������������������\n"
		" ����         �ʺ�          ����          ���ߵ�ַ   \n" +
		"������������������������������������������������������������������������������\n"
		+ msg +
		"������������������������������������������������������������������������������\n"
		"* ��ʾ��¼��\n";
		

}

void create() 
{
	set_name(HIW"��ʦ���ҹ���"NOR, ({"finger tool"}));
    set("long",
		"������ҷ���ʱ��Ͷ��ص�½����б�Ĺ��ߡ�\n"
		"ָ��cha_ip��ʾ�������ߵ���ҵ���ϸ���ϣ���ͬ��ַ�Ļ��ǳ�����\n"
		"ָ��cha_idle < a ʱ��(����)>�г���������a���ӵ���ҡ�\n"

		);
    set("unit", "��");
    set("value", 100000);
    set("weight", 10);
    setup();
	
}
void init ()
{
		if(wizardp(this_player()))
        add_action ("do_cha_ip", "cha_ip");
		add_action ("do_cha_idle", "cha_idle");
          	
}
int do_cha_ip()
{
	
	this_player()->start_more(finger_all());
	return 1;

}
int do_cha_idle(string arg)
{
	int a;
	if( !arg || !sscanf(arg, "%d", a) )
		return notify_fail("���������ٷ���ʱ�䡣\n");
		printf("��������%d���ӵ�����У�\n",a);
	
	this_player()->start_more(finger_idle(a));
	return 1;

}



