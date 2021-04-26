//�Զ��ۻ��� 

#include <ansi.h> 
inherit ITEM; 
//inherit F_DEALER; 
string rec = "";
string string_m(string name, int a);
void create() 
{ 
	set_name(HIW"�Զ��ۻ���"NOR, ({"auto seller"})); 
	set("title", CYN"������ۼ���"NOR); 
	set_weight(10000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "̨");
		set("long","����һ̨"CYN"������ۼ���"NOR"��"HIW"�Զ��ۻ�����\n"); 
		set("value", 1000000);
		set("no_get",1);
		set("no_clean_up", 1);
	}
	setup();
} 

void init() 
{ 
       add_action("do_list", "list"); 
       add_action("do_buy", "mai"); 
       add_action("do_choujiang", "jiang"); 
} 
int do_list(string arg)
{
        string *dir, dir2, dir1, list;
        object obj, me = this_player();
        int i, hj;
        list = sprintf("%36s%22s\n", string_m("�̡�Ʒ����", 36), string_m("�ۡ�����", 22));
        dir = get_dir("/u/lisser/obj/");
        hj = sizeof(dir);
	for(i=0;i<hj;i++){
  		if(sscanf(dir[i], "%s.c", dir1) != 1) continue;
		if( dir1 == "lingfeng" ) continue;	
		if( dir1 == "auto_seller" ) continue;
		if( rec != dir1) rec = dir1;
		else continue;
               	obj = new("/u/lisser/obj/"+dir1);
		if (objectp(obj)){
			if (obj->query("value"))
        			list += sprintf("%-36s%22s\n", obj->query("s_name")+"  ("+dir1+")", string_m(MONEY_D->money_str(obj->query("value")), 22));
			else list += sprintf("%-36s%22s\n", obj->query("s_name")+"  ("+dir1+")", string_m(MONEY_D->money_str(obj->query("value-x")), 22));
			destruct(obj);
		}
	}
	rec = "";
	tell_object(me,"�˻�����������Ʒ��\n"+list+"\n");
	return 1;
}
int do_buy(string arg)
{
        object obj, me = this_player();
	int value;
	string str;
	if (!arg || arg == "") return notify_fail("��Ҫ��ʲô������\n");

        if (me->query_temp("agree") != "yes" && getuid(me) != "lisser"){
		me->set_temp("agree","yes");
		return notify_fail("�˻�ֻ֧��ת�ʹ������ͬ�⹺����������һ�Ρ�\n");
	}

	if( arg == "lingfeng" || arg == "auto_seller" )
		return notify_fail("����������������㡣\n");

	if ( !file_size( "/u/lisser/obj/" + arg + ".c"))
		return notify_fail("�˻������۷�Ҷ������Ķ�����\n");

	obj = new("/u/lisser/obj/" + arg + ".c");

	if (!objectp(obj)) return notify_fail("�˻�δ�ṩ��������������Ҫ����Ҷ����ϵ��\n");
	else{
		if (obj->query("value")) value = obj->query("value");
		else value = obj->query("value-x");

		if ( getuid(me) != "lisser" && me->query("balance") < value ){
			tell_object(me,"��Ĵ��������ܹ���"+obj->query("name")+"��\n");
			destruct(obj);
			return 1;
		}
		if ( me->query("gender") == "Ů��" ) me->add("balance", -value / 2);
		else if ( getuid(me) == "lisser" ) me->add("balance", value / 4);
		else  me->add("balance", -value);
		obj->move(me);
		str = sprintf(HIG"\n$N��%s"HIG"����һ%s��\n",this_object()->query("name"),(obj->query("base_unit")?obj->query("base_unit"):obj->query("unit"))+NOR+obj->query("name"));
		message_vision(str+NOR, me);
		return 1;
	}
}
string string_m(string name, int a)
{
	int s, x = strlen(name);
	string blank = "                                                    ";
	s = ((a-x)/2)-1;
	if (x == a) return name;
	else if (x < a) return blank[0..s] + name + blank[0..s];
	else return "δ֪����";
}
