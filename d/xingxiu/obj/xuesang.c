// Code of ShenZhou
// xuesang.c  
// By Haowen 1/14/98

#include <ansi.h>

inherit ITEM;


void create()
{
        set_name("ѩɣ",({"xue sang","sang"}));
        set_weight(900000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɽ���е�������ѩ���ѩɣ����
��˵��һ��ѩ����ϲ����������ѩɣ֮�ϣ�����������Ѱ��(search)� \n");
                set("unit", "��");
                set("value", 8);
                set("no_get", 1);
		set("leaves",20);
       }
       
        setup();
}

void init()
{
        add_action("do_search", "search");
        add_action("do_feed", "fed");
	add_action("do_look", "look");
	add_action("do_look", "l");
}

int do_search()
{
object obj=this_object(),me=this_player();

if (me->query_temp("find_can"))
	return notify_fail("ѩ���Ѿ���ѩɣ���ˣ��㻹��ʲôѽ��\n");

if(random(me->query("kar"))>15)
	{
        tell_object(me,HIG"����ϸ�ķ���ѩɣҶ������Ѱ��������\n" NOR);
	if(random(10)>5)
		{
                tell_object(me,HIR"���Ȼ��ǰһ����һ����Өѩ�׵�ѩ��(can)������һƬѩɣҶ�ϣ�\n"NOR);
		me->set_temp("find_can",1);
		}
        me->add("neili",-10);
        return 1;
	}
else    {
        me->add("neili",-10);
        return notify_fail("�����˰���ʲôҲû�ҵ���\n");
        }
}

int do_feed(string arg)
{
object ob,obj=this_object(),me=this_player();
string what;

//message_vision(arg);
if (!arg || sscanf(arg,"%s",what)!=1)
	return notify_fail("��Ҫιʲô��\n");

if (what!="can")
	return notify_fail("�����ѩɣҶֻ����ɽѩ�ϰ��ԣ�\n");

if (!me->query_temp("find_can"))
	return notify_fail("��ѩɣ��ʲôҲû�У���Ҫιʲô��\n");

if (me->query_temp("get_si"))
	return notify_fail("ѩ�ϸ��¹�˿���������ڲ��������ˣ�\n");

if (obj->query("leaves")>1)
	{
        tell_object(me,HIY "��ժ��һƬѩɣҶι��ѩ�ϳԡ�ѩ����ϸ�ĳ���������\n" NOR);
	obj->set("leaves",obj->query("leaves")-1);
		if (random(10)>5)
			{
                        tell_object(me,HIY "ѩ�ϳ�����ɣҶ��ͷһ�����³�һ����˿����Ͻ����ֽ�ס��\n" NOR);
                        me->set_temp("get_si",1);
			ob=new("/d/xingxiu/obj/xuecan-si");
			ob->move(me);
			}
	return 1;}
else 
	{
	call_out("grow",200,obj);
	return notify_fail("ѩɣ�ϵ�Ҷ�Ӷ�ժ���ˣ�����������������ι�ɣ�\n");
	}
}

int do_look(string arg)
{
        object ob,me=this_player();
	string what;
        ob=this_object();
 
        if( !arg || arg == "" || sscanf(arg,"%s",what)!=1) return 0;

	
        if(what=="sang" || what=="xue sang")
		{	
		if(me->query_temp("find_can"))
                        tell_object( me, ob->query("long") + "����������һֻѩ��(can)���������ڵ���ι(fed)����\n");
		else	tell_object( me, ob->query("long"));
                return 1;
                }

return 0;

}

int grow(object ob)
{
	message_vision(HIG "ѩɣ�ϵ�ɣҶ�ֳ������ˣ�\n");
	ob->set("leaves",20);
}
