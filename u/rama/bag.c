/* /kungfu/class/movie/obj/pinang.c
** ����Ƥ��
** created by yujie
** created in 11/2001
*/

#include <ansi.h>


#define CAIPIAO "/kungfu/class/movie/obj/caipiao"
#define DATAFILE "/data/movie/caipiao/pinang"
#define CPSYS "/adm/single/cpsys"

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;


#include <inttostr.h>

int do_check(string);
int do_getout(string);
int do_putin(string);


void create()
{
	
        set_name(YEL"����Ƥ��"NOR, ({ "pi nang","nang" }));
        set_weight(10);
        set("long","����һ��װ������Ʊ��Ƥ�ҡ�\n�������checkָ�����鿴Ƥ����Ĳ�Ʊ�ĺ��롣\ngetout��putin�ֱ�����ȡָ������Ĳ�Ʊ�ͰѲ�Ʊ�Ž�Ƥ�ҡ�\n");
        set("unit", "��");
        set("value", 0);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_give",1);
        
        setup();      
}

int query_autoload() {return 1;}
/*
void save_data(object me , string include)
{
	int i;
	string own,name;
	string msg , *data ,newdata;
	
	name = me->query("id");
	newdata = "";
	if ( me->query("get_pinang"))
	{
		msg = read_file(DATAFILE);
		data = explode(msg,"*");
		
		for(i=0; i < sizeof(data) ;i++)
		{	
			if (sscanf(data[i],"%s-%s",own,include) != 2)
				tell_object(me,"���ݳ����뾡�����ʦ��ϵ��\n");
	
			if (name == own)
				newdata = newdata + name + "-" + include +"*";
			else
				newdata = newdata + data[i] + "*";
		}
		write_file(DATAFILE,newdata,1);
		
	}
}
*/	
	
void init()
{
	object me;
	string name , msg ,*data , own, include;
	int i;
	
	
	me = this_player();
	
	if ( me->query("get_pinang"))
	{
		name = me->query("id");
		if (!query("owner"))	set("owner",name);
		msg = read_file(DATAFILE);
		data = explode(msg,"*");
		for (i=0; i<sizeof(data) ;i++)
		{	
			if (sscanf(data[i],"%s-%s",own,include) != 2)
				write("���ݳ����뾡�����ʦ��ϵ��\n");
			
			if (name == own)
				set("include",include);
		}
	}
	
	if ( query("owner") == me->query("id"))
	{	
		add_action("do_check" , "check");
		add_action("do_getout" , "getout");
		add_action("do_putin" , "putin");
	}
}

int do_check(string arg)
{
	object me = this_player();
	string *nums , msg;
	int i;
		
	if ( stringp (query("include")))
	{	
		msg = query("include");
		CPSYS->save_data(me,msg);
		nums = explode(msg,"\n");
		msg = "";
		for(i=0 ; i<sizeof(nums) ;i++)
			msg = msg + nums[i] + "    ";
		if (sizeof(nums) == 0)
			msg = "����Ƥ����û���κβ�Ʊ��\n";
		else 
			msg = "����Ƥ������еĲ�Ʊ����ֱ��ǣ�\n" + msg + "\n";
		
		write(msg);
		return 1;
	}
	write("����Ƥ����û���κβ�Ʊ��\n");
	return 1;
}

int do_getout(string arg)
{
	object me = this_player();
	string *nums , msg ,newmsg;
	int num ,i ,got;
	object cp;
	
	if (!arg)
		return notify_fail("ָ���ʽ��getout <��Ʊ����>\n");
		
	if ( sscanf(arg,"%d",num)!= 1)
		return notify_fail("ָ���ʽ��getout <��Ʊ����>\n");
		
	msg = tostring(num);
	newmsg = "";
	got = 0;
	
	if( !stringp(query("include")) )
	{	write("Ƥ����û���κβ�Ʊ��\n");
		return 1;
	}
	
	nums = explode(query("include"),"\n");
	for(i=0 ; i<sizeof(nums) ;i++)
	{	if(msg == nums[i])
		{	tell_room(environment(me),me->name()+"��Ƥ�Ҵ�ȡ��һ�Ÿ�����Ʊ��\n",me);
			write("���Ƥ����ȡ��һ�ź���Ϊ��"+HIW+msg+NOR+" �ĸ�����Ʊ��\n");
			cp = new(CAIPIAO);
			cp->set("number",num);
			cp->move(me);
			got = 1;
		}
		else 
			newmsg = newmsg + nums[i] + "\n";
	}
			
	set("include",newmsg);
		
	if(got == 1)
	{	CPSYS->save_data(me,newmsg);
		return 1;	
	}
			
	if( sizeof(nums) == 0)
	{	write("����Ƥ����û���κβ�Ʊ��\n");
		return 1;
	}
	write("����Ƥ����û���������Ĳ�Ʊ������check��ѯƤ�������еĲ�Ʊ���롣\n");
	return 1;
}

int do_putin(string arg)
{
	object cp ,me = this_player();
	string *nums , msg ;
	int num ,i ,j;
	
	if (!arg)
		return notify_fail("��Ҫ��ʲô�Ž�Ƥ�ҡ�\n");
	
	if ((arg != "caipiao") && (arg != "lottery") )
		return notify_fail("��ֻ�ܰѲ�Ʊ�Ž�Ƥ�ҡ�\n");
		
	if (!present("caipiao",me) )
		return notify_fail("������û�в�Ʊ��\n");
		
	i = 0;
	j = 0;
	
	while (objectp(present("caipiao",me)))
	{	cp = present("caipiao",me);
		if (base_name(cp) == CAIPIAO )
		{
		if ( num = cp->query("number"))
		{	
			msg = tostring(num)+"\n";
			add("include",msg);
                        CPSYS->save_data(me,query("include"));
		}
		else
			i++;
		destruct(cp);
		j++;
		}
	}
	
	j = j - i;
	write("������ϵ�"+chinese_number(j)+"�Ų�Ʊ���Ž���Ƥ���\n");
	tell_room(environment(me),me->name()+"�����ϵĸ�����Ʊ���Ž���Ƥ���\n",me);
	if (i > 0)
		write("������"+chinese_number(i)+"���Ƿ�Ʊ���������ӵ��ˡ�\n");
	
	return 1;
}

