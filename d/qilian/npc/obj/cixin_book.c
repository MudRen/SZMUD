// Code of ShenZhou
// cixin_book.c
//Wzfeng@xkx 99 11
#include <ansi.h>
inherit ITEM;

int do_start(object me);


void create()
{
        set_name("�����ؾ�", ({ "cixin yaojue", "yaojue" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ȱ��ȫ��С����,��������ű�а����ʧ���ѾõĴ����ؾ���\n");
                set("material", "paper");
				set("no_drop","�������������뿪�㡣\n");
				set("no_get",1);
				set("no_steal",1);
                set("value", 300000);

        }
}
void init()
{
  add_action("do_lingwu","lingwu");
  
}
int do_lingwu(string arg)
{
	object me;
	int cost;
	me=this_player();
	 if (me->is_busy())
            return notify_fail("����æ����!\n");

	
	if(arg!=this_object()->query("id")) return notify_fail("��Ҫ����ʲô?\n");
	if(me->query_skill("pixie-jian", 1) <180)
            return notify_fail("��ı�а����������죬�޷�����Ҫ���еİ��\n");
	if(this_object()->query("master")!=me->query("id"))
	{
		me->add("max_neili",-100);
		return notify_fail(HIR"��һ��֮��ֻ���������ȣ��������ۣ�˵���������ܡ�\n"NOR);

	}
	if(this_player()->query_temp("linji/zhixin")
		||this_player()->query_temp("linji/fengyun"))
	{
		me->add("max_neili",-100);
		me->add("max_jingli",-100);
		return notify_fail(HIR"��ͻȻ���ֻ�����������˵�������ѹ���ת�ۼ��ƺ�Ҫ��Ϣ��\n"NOR);

	}


	if(me->query("canuse_cixin")==1)
		    return notify_fail("���Ѿ���������ؾ��ľ�Ҫ��\n");
	if(me->query("neili")<3000||me->query("jingli")<2000)
		return notify_fail("�㾫�񲻼ѣ��޷������ķ��еİ��\n");
	cost=me->query("int");
	if(cost>=30)
		cost=5;
	else
		cost=35-cost;
	me->set_temp("cixin_cost",cost);
	
	message_vision(HIB "$N�ӻ�������һ��С����,ϸϸ�Ŀ���,����¶���������ɫ��\n" NOR, me);
    me->start_busy((: do_start:));
	return 1;

}

int do_start(object me)
{


	if(me->query_temp("cixin_cost")<=0)
	{
		if(random(me->query("int"))>19||random(me->query_int())>40)	
		{
			me->add("pixie-cixin",1);
			tell_object  (me,HIY"���ƺ��Դ���Ҫ����һ˿����\n"NOR);
			
			if(me->query("pixie-cixin")>=20)
			{
				tell_object  (me,HIY"����������������ؾ��ľ�Ҫ��\n"NOR);
				if(me->query("canuse_cixin")!=1)
				me->add("str",1);
        log_file("static/AddGift", sprintf("[%s]   %s   %s(%s)����а�������ĵ� һ �������\n",
                ctime(time())[0..15], me->query("family/family_name"), me->name(), geteuid(me)));
me->add("AddGift/piexie/str",1);
				me->set("canuse_cixin",1);
				me->delete("pixie-cixin");
				
			}
			me->set("neili",0);
			me->set("jingli",0);
	
		}
		else
		{
			
			tell_object  (me,HIR"��ֻ����ͷһ����ģ�ȫ������ת,���ۡ����³�һ����Ѫ��\n"NOR);
		    me->unconcious();

		}
	return 0;
	}
	me->add_temp("cixin_cost",-1);

	
	return 1;
}
