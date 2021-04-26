//Cracked by Yujie
// changle/clsifang1.c

inherit ROOM;

#include <ansi.h>

#define SIFANG "/d/forest/sifang/sifang1_file"
#define DDR "/d/forest/"

void create()
{	string msg;
	set("short", "����������˽��");
        if (file_size(SIFANG) < 1 )
        	set("long","����һ���տ���Ҳ�����ݡ�\n");
        else
        	set("long",read_file(SIFANG));
        
        set("exits", ([
		"west" : DDR + "clhoulang1",
        ]));
	
        set("object",([
        	DDR+"npc/shicong" : 1,
        ]));
        
        set("can_sleep", 1);
        
        set("no_clean_up",1);
        set("valid_startroom", 1);

        
        set("no_steal", 1);

        set("cost", 0);

        setup();
       
}

void reset()
{
	::reset();
	set("no_clean_up",1);
	return;
}

void init()
{
	object me=this_player();
	string pos;
        
        if (stringp (pos = me->query("clbpos")) && (pos != "������"))
        {	call_out("pos_leave",1,me);
        	return;	
        }
        
        if (!stringp (pos = me->query("clbpos")) && (me->query_temp("invite")!= "������"))
        {	call_out("other_leave",1,me);
        	return;	
        }
              
        add_action("do_get", "get");
        add_action("do_invite","invite");
        add_action("do_invite","yaoqing");
        add_action("do_modify","modify");
        add_action("do_nofight","nofight");
        add_action("do_canfight","canfight");
}

int do_get(string arg)
{
        object obj;
        string usr;
        
        
        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && userp(obj) ) {
                write("�㲻�ܰᶯ��ҵ����塣\n");
                return 1;
        }
        
        if ( (sscanf(arg,"%*s from %s",usr) == 2)
        && objectp (obj = find_player(usr))
        && userp (obj) )
        {
        	write("�㲻������������ҵ����塣\n");
        	return 1;
        }
        return 0;
} 

int do_invite(string arg)
{
	object ob;
	object me = this_player();
	
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="������")
	{	write("�㲻����������ˣ���������������ˡ�\n");
		return 1;
	}        		

	if ( arg
	&& objectp (ob = find_player(arg))
	&& userp (ob) )
	{	
		ob->set_temp("invite","������");
		write("�Ѿ�����������"+ob->query("name")+"��\n");
		tell_object(ob,HIM"�����롿��" + "���ְ����������� " + me->query("name")+"������ȥ��������˽����\n"NOR);
		return 1;
	}
	
	if ( arg && !objectp (ob = find_player(arg)) )
	{	write("����û�������ҡ�\n");
		return 1;
	}
	
	write("ָ���ʽ��invite | yaoqing < ���id > \n");
	return 1;
}

void pos_leave(object me)
{	
	tell_object(me,"�������ˣ����˽���������\n");
        me->move(DDR+"clhoulang1");
        tell_object(this_object(),me->query("name") + "������˷��䡣\n");
        return;
}

void other_leave(object me)
{	
	tell_object(me,"�㲢�����������˵Ļ�ӭ�����ǿ��߰ɡ�\n");
        me->move(DDR+"clhoulang1");
        tell_object(this_object(),me->query("name") + "������˷��䡣\n");
        return;
}

int do_nofight(string arg)
{
	object me = this_player();
	
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="������")
	{	write("�㲻����������ˣ����ܽ������á�\n");
		return 1;
	}        			
	
	write("�˷�����ʱ����Ϊ������ս����\n");	
	set("no_fight",1);
	return 1;
}

int do_canfight(string arg)
{
	object me = this_player();
	
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="������")
	{	write("�㲻����������ˣ����ܽ������á�\n");
		return 1;
	}        			
		
	write("�˷���ָ�Ϊ����ս��������\n");
	set("no_fight",0);
	return 1;
}

int do_modify(string arg)
{
	object me = this_player();
		
	if ( !stringp(me->query("clbpos")) || me->query("clbpos")!="������")
	{	write("�㲻����������ˣ����ܽ����������á�\n");
		return 1;
	}       

	if ( ! arg )
	{	write("����������������÷����������\n");
		write("ָ���ʽΪ��modify <����> \n");
		return 1;
	}
	
	arg = arg + "\n";
	set("long",arg);
	if (!write_file(SIFANG,arg,1))
		write("�ļ�����ʧ�ܣ�����������ʦ��ϵ��\n");
	else
		write("���óɹ���\n");
	
	return 1;
}
	